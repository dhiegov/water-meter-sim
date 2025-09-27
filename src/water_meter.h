#ifndef WATER_METER_H
#define WATER_METER_H

#include <fstream>
#include <string>

#include "meter.h"
#include "my_window.h"

class WaterMeter
{
private:
    std::string config_path;
    std::string dir_path;
    std::ifstream file;
    unsigned int update_interval_ms;
    unsigned int reload_interval_ms; // zero means no reload
    Meter meter;
    MyWindow *window;
public:
    WaterMeter(std::string config_file);
    ~WaterMeter();
    void startMeter(void);
private:
    void update(int time_ms);
    void reloadConfig(void);
};

#endif
