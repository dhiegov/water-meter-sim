
// std::min, std::max
#include <algorithm>

#include "meter.h"
#include "pipe.h"

Meter::Meter(Pipe *in, Pipe *out)
: in(in), out(out), count_liters(0), ms_passed(0)
{}

Meter::Meter(Pipe *in, Pipe *out, int init_count_m3)
: in(in), out(out), ms_passed(0)
{
    this->count_liters = std::max(0, init_count_m3*1000);
}

/* Calculates how much water passed and increments counters */
void Meter::measureFlow(int time_ms)
{
    this->ms_passed += time_ms;
    double time_s = time_ms / 1000.0d;
    double flow = std::min(this->in->flowLps(), this->out->flowLps());
    this->count_liters += flow * time_s;
}

unsigned int Meter::countLiters(void) const
{
    return static_cast<unsigned int>(this->count_liters);
}

unsigned int Meter::count_m3(void) const
{
    return static_cast<unsigned int>(this->count_liters / 1000);
}

//unsigned int Meter::count_mm3(void) const;

