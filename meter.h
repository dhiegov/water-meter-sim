#ifndef METER_H
#define METER_H

#include "pipe.h"

class Meter
{
private:
    float count_mm3_;
    float seconds_passed;
public:
    Meter() : count_mm3_(0), seconds_passed(0) {}
    /* Calculates how much water passed and increments counter */
    float measureFlow(Pipe in, Pipe out, float time_ms);
    /* Returns count without passing time */
    float count_mm3() const;
    float count_m3() const;
};

#endif