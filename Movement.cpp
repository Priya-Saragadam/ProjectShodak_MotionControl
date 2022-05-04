/*Movement.cpp - Library for controlling the wheels of Shodak.
  Created by Lakshmi Priya Saragadam, March 26, 2022.
  Functions available: MoveForward(),MoveRight(),MoveLeft(),MoveBackward(),MoveFastForward(), donotMove()
 */
#include "Arduino.h"
#include "Movement.h"

Movement::Movement(int in1motor1,int in2motor1,int in3motor2,int in4motor2,int speedOfMotorA, int speedOfMotorB)
{
  pinMode(in1motor1, OUTPUT);
  pinMode(in2motor1, OUTPUT);
  pinMode(in3motor2, OUTPUT);
  pinMode(in4motor2, OUTPUT);
  pinMode(speedOfMotorA, OUTPUT);
  pinMode(speedOfMotorB, OUTPUT);
  _in1motor1 = in1motor1;
  _in2motor1 = in2motor1;
  _in3motor2 = in3motor2;
  _in4motor2 = in4motor2;
  _speedOfMotorA = speedOfMotorA;
  _speedOfMotorB = speedOfMotorB;
}
void Movement::MoveForward()
{
  analogWrite(_speedOfMotorA, 50);
  analogWrite(_speedOfMotorB, 50);
  digitalWrite(_in1motor1,HIGH);
  digitalWrite(_in2motor1,LOW);
  digitalWrite(_in3motor2,HIGH);
  digitalWrite(_in4motor2,LOW);
  delay(1000);
}
void Movement::MoveRight()
{
  analogWrite(_speedOfMotorA, 50);
  analogWrite(_speedOfMotorB, 30);
  digitalWrite(_in1motor1,HIGH);
  digitalWrite(_in2motor1,LOW);
  digitalWrite(_in3motor2,HIGH);
  digitalWrite(_in4motor2,LOW);
  delay(1000);
}
void Movement::MoveLeft()
{
  analogWrite(_speedOfMotorA, 30);
  analogWrite(_speedOfMotorB, 50);
  digitalWrite(_in1motor1,HIGH);
  digitalWrite(_in2motor1,LOW);
  digitalWrite(_in3motor2,HIGH);
  digitalWrite(_in4motor2,LOW);
  delay(1000);
}
void Movement::MoveBackward()
{
  analogWrite(_speedOfMotorA, 40);
  analogWrite(_speedOfMotorB, 40);
  digitalWrite(_in1motor1,LOW);
  digitalWrite(_in2motor1,HIGH);
  digitalWrite(_in3motor2,LOW);
  digitalWrite(_in4motor2,HIGH);
  delay(1000);
}
void Movement::MoveFastForward()
{
  analogWrite(_speedOfMotorA, 255);
  analogWrite(_speedOfMotorB, 255);
  digitalWrite(_in1motor1,HIGH);
  digitalWrite(_in2motor1,LOW);
  digitalWrite(_in3motor2,HIGH);
  digitalWrite(_in4motor2,LOW);
  delay(1000);
}
void Movement::donotMove()
{
  analogWrite(_speedOfMotorA, 0);
  analogWrite(_speedOfMotorB, 0);
  digitalWrite(_in1motor1,HIGH);
  digitalWrite(_in2motor1,LOW);
  digitalWrite(_in3motor2,HIGH);
  digitalWrite(_in4motor2,LOW);
  delay(1000);
}


