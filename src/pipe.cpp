
#include "pipe.h"

Pipe::Pipe(float init_flow, float max_flow)
: curr_flow_rate_lps(init_flow), max_flow_rate_lps(max_flow)
{}

float Pipe::flowLps(void) const
{
    return this->curr_flow_rate_lps;
}

float Pipe::maxFlowLps(void) const
{
    return this->max_flow_rate_lps;
}

void Pipe::setFlowLps(float f)
{
    if (f <= 0.0f) {
        this->curr_flow_rate_lps = 0;
    } else {
        this->curr_flow_rate_lps = f;
    }
}
