/*UltraSonic.cpp - Library for Ultrasonic sensor interface with Arduino Uno.
  Created by Lakshmi Priya Saragadam, March 28, 2022.
 */
#include "Arduino.h"
#include "UltraSonic.h"

UltraSonic::UltraSonic(int trigPin,int echoPin)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    _trigPin=trigPin;
    _echoPin=echoPin;
}
float UltraSonic::Dist()
{
    digitalWrite(_trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin,LOW);
    _duration = pulseIn(_echoPin, HIGH);
    _distance = (_duration/2)/29.4;
    return _distance;
}
