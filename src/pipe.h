#ifndef PIPE_H
#define PIPE_H

class Pipe
{
private:
    float max_flow_rate_lps;
    float curr_flow_rate_lps;
public:
    Pipe(float init_flow, float max_flow);
    float flowLps(void) const; // liters per second
    float maxFlowLps(void) const;
    void setFlowLps(float f);
};

#endif
