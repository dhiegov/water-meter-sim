#ifndef METER_H
#define METER_H

#include "pipe.h"

class Meter
{
private:
    double count_liters;
    unsigned int ms_passed;
    Pipe *in;
    Pipe *out;
public:
    Meter(Pipe *in, Pipe *out);
    Meter(Pipe *in, Pipe *out, int init_count_m3);
    /* Calculates how much water passed and increments counters */
    void measureFlow(int time_ms);
    unsigned int countLiters(void) const;
    unsigned int count_m3(void) const;
    unsigned int count_mm3(void) const;
};

#endif
