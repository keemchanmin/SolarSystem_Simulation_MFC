#pragma once
#include "Planet.h"
class Satellite :public Planet
{
private:
    char* Moon_flag;

public:
    Satellite(const char* name, int speed, int life, double angle, int spin)
        :Planet(name,speed,life,angle,spin)
    {
        Moon_flag = "NO";
    }
    
    char* GetMoonFlag()
    {
        return Moon_flag;
    }
    void SetMoonFlag(int flag)
    {
        if(flag)
            Moon_flag ="YES";
        else 
            Moon_flag ="NO";
    }


};

