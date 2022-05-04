/*
 Shodak_main.ino- The main program of Shodak.
 Created by Lakshmi Priya Saragadam, March 26, 2022.
 To be released into public domain soon.
 */
#include <Movement.h>                         // Movement library written by Lakshmi Priya Saragadam
#include <UltraSonic.h>                       // UltraSonic library written by Lakshmi Priya Saragadam
Movement movement(2,3,4,5,9,10);              //Functions available: MoveForward(),MoveRight(),MoveLeft(),MoveBackward(),MoveFastForward(), donotMove()
UltraSonic ultra_sonic(A0,A1);
#define pirSignal_left 12
#define pirSignal_right 7
void setup()
{
  pinMode(pirSignal_left, INPUT);
  pinMode(pirSignal_right, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int left,right,i=1,c=0,j=1;
  float dist;
  dist = ultra_sonic.Dist();
  Serial.print("Dist = ");
  Serial.println(dist);
jyo:  if((dist < 6.00) || (dist > 2000.00))
  {
    Serial.println("Inside less than 6cm loop");
    movement.donotMove();
    left = digitalRead(pirSignal_left);
    right = digitalRead(pirSignal_right);
    if ((left == 0) && (right ==1))
    {
      movement.MoveBackward();
      movement.MoveRight();
      Serial.println("Inside less than 6cm loop and RIGHT");
    }
    else if ((left == 1) && (right ==0))
    {
      movement.MoveBackward();
      movement.MoveLeft();
      Serial.println("Inside less than 6cm loop and LEFT");
    }
    else if ((left == 1) && (right ==1))
    {
      for(i=1;i<=3;i++)
      {
        movement.MoveBackward();
        Serial.println("Inside less than 6cm loop and forBACKWARD");
      }
      goto samba;
    }
    else if ((left == 0) && (right ==0))
    {
      while((left == 0) && (right ==0))
      {
        movement.MoveBackward();
        left = digitalRead(pirSignal_left);
        right = digitalRead(pirSignal_right);
        Serial.print("Counter = ");
        Serial.println(c);
        c=c+1;
        Serial.println("Inside less than 6cm loop and whileBACKWARD");
      }
      movement.MoveBackward();
samba: left = digitalRead(pirSignal_left);
      right = digitalRead(pirSignal_right);
      if((left ==1) &&(right==0))
      {
        movement.MoveLeft();
        Serial.println("after whileBACKWARD, move left");
      }
      else if(((left ==0) &&(right==1)) || ((left == 1) && (right == 1)))
      {
        movement.MoveRight();
        Serial.println("after whileBACKWARD, move right");
      }
    }
  }
  else if((dist >= 6.00) && (dist <2000.00))
  {
    while(((dist >= 6.00) && (dist <2000.00)) && (j<=6))
    {
    movement.MoveForward();
    Serial.print("Moving Forward Shodak. Dist =");
    Serial.println(dist);
    dist = ultra_sonic.Dist();
    movement.donotMove();
    j=j+1;
    }
    dist = ultra_sonic.Dist();
    if((dist < 6.00) || (dist > 2000.00))
    {
      goto jyo; 
    }
    else
    {
      for(j=1;j<=6;j++)
      {
        movement.MoveBackward();
      }
      dist = ultra_sonic.Dist();
      if((dist < 6.00) || (dist > 2000.00))
      {
        goto jyo; 
      }
      else
      {
        left = digitalRead(pirSignal_left);
        right = digitalRead(pirSignal_right);
        if (((right ==1) && (left==1)) || ((right ==1) && (left==0)))
        {
          movement.MoveRight();
          movement.MoveRight();
          movement.MoveLeft();
        }
        else if((right ==0) && (left==1))
        {
           movement.MoveLeft();
           movement.MoveLeft();
           movement.MoveRight();
        }
      }
    }
  }
}
