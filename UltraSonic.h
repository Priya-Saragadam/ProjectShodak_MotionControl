/*UltraSonic.h - Library for Ultrasonic sensor interface with Arduino Uno.
  Created by Lakshmi Priya Saragadam, March 28, 2022.
  Released into public domain.
 */
 #ifndef UltraSonic_h
 #define UltaSonic_h
 #include "Arduino.h"
 class UltraSonic
 {
 public:
    UltraSonic(int trigPin,int echoPin);
    float Dist();
 private:
    int _trigPin;
    int _echoPin;
    unsigned long int _duration;
    float _distance;
 };
 #endif // UltraSonic_h
