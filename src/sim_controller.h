#ifndef SIM_CONTROLLER_H
#define SIM_CONTROLLER_H

#include <string>

#include "water_meter.h"

class SimController
{
private:
    int n_meters;
    WaterMeter *meters[];
public:
    SimController(std::string config_file);
    ~SimController();
    void startSim(void);
};

#endif
