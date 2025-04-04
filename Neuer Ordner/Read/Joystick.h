#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class Joystick {
    public:     Joystick(int, int, int);
                int printX(String, int, int);
                int printY(String, int, int);
                bool printZ(String);
                void print(String, String, String, int, int);
                String toString();
    private:    int pinX;
                int pinY;
                int pinZ;
};

#endif
