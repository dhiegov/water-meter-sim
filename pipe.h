#ifndef PIPE_H
#define PIPE_H

class Pipe
{
private:
    float fluid_vel_mps;
    const float diameter_mm;
public:
    Pipe() : fluid_vel_mps(1), diameter_mm(10) {}
    /* Returns flow rate in mm^3 per second */
    float flow();
};

#endif