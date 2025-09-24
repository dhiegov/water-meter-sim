#ifndef SIM_CONTROLLER_H
#define SIM_CONTROLLER_H

#include "water_meter.h"

class SimController
{
private:
    float sample_rate;
    WaterMeter water_meter;
public:
    SimController() : sample_rate(2) {}
    SimController(float rate) : sample_rate(rate) {}
    int startSimulation();
};

#endif