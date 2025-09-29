
#include <string>

#include "sim_controller.h"
#include "water_meter.h"

SimController()
{
    this->n_meters = 1;
    this->meters[0] = new WaterMeter();
}

~SimController()
{
    for (int i = 0; i < n_meters; i++) {
        delete this->meters + i;
    }
}

void startSim(void)
{
    this->meters[0].startMeter();
}
