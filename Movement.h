/*Movement.h - Library for controlling the wheels of Shodak.
  Created by Lakshmi Priya Saragadam, March 26, 2022.
  Released into public domain.
  re-edited on March 31, 2022
 */

#ifndef Movement_h
#define Movement_h
#include "Arduino.h"

class Movement
{
  public:
     Movement(int in1motor1,int in2motor1,int in3motor2,int in4motor2,int speedOfMotorA, int speedOfMotorB);
     void MoveForward();
     void MoveRight();
     void MoveLeft();
     void MoveBackward();
     void MoveFastForward();
     void donotMove();
  private:
     int _in1motor1;
     int _in2motor1;
     int _in3motor2;
     int _in4motor2;
     int _speedOfMotorA;
     int _speedOfMotorB;
};

#endif
