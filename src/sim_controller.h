#ifndef SIM_CONTROLLER_H
#define SIM_CONTROLLER_H

#include <string>

#include "water_meter.h"

struct SimConfig {
    //std::string file_path,
    std::string meter_config_paths[],
    int n_meters
};

class SimController
{
private:
    const int maxMeters = 5;
    int n_meters;
    WaterMeter *meters[maxMeters];
public:
    SimController();
    //SimController(std::string config_file);
    //SimController(struct SimConfig* config);
    ~SimController();
    void startSim(void);
};

#endif
