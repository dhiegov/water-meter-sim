#ifndef WATER_METER_H
#define WATER_METER_H

#include "raylib.h"

#include "display.h"
#include "meter.h"
#include "pipe.h"

class WaterMeter
{
private:
    Display disp;
    Meter meter;
    Pipe in, out;
public:
    WaterMeter();
    Image sample(int time_ms);
};

#endif