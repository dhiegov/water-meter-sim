
// std::max, std::min
#include <algorithm>

#include "pipe.h"

Pipe::Pipe(float init_flow, float max_flow)
{
    init_flow = std::max(init_flow, 0.0f);
    max_flow = std::max(max_flow, 0.0f);
    if (init_flow >= max_flow) {
        this->curr_flow_rate_lps = max_flow;
        this->max_flow_rate_lps = max_flow;
    } else {
        this->curr_flow_rate_lps = init_flow;
        this->max_flow_rate_lps = max_flow;
    }
}

float Pipe::flowLps(void) const
{
    if (this->curr_flow_rate_lps >= this->maxFlowLps()) {
        return this->maxFlowLps();
    } else {
        return this->curr_flow_rate_lps;
    }
}

float Pipe::maxFlowLps(void) const
{
    return this->max_flow_rate_lps;
}

void Pipe::setFlowLps(float f)
{
    if (f <= 0.0f) {
        this->curr_flow_rate_lps = 0.0f;
    } else {
        this->curr_flow_rate_lps = std::min(f, this->maxFlowLps());
    }
}
