
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "meter.h"
#include "my_window.h"
#include "pipe.h"
#include "water_meter.h"

WaterMeter::WaterMeter()
{
    this->config_path = "config/m1.conf";
    this->dir_path = "samples/m1/";
    this->update_interval_ms = 500;
    this->reload_interval_ms = 0;
    // exaggerated so we can see numbers changing
    Pipe *in = new Pipe(2.0d, 5.0d);
    Pipe *out = new Pipe(2.0d, 5.0d);
    this->meter = new Meter(in, out, 42);
    this->window = new MyWindow("meter_bg.png");
    this->window->setDigitsPos(435, 290);
}

WaterMeter::~WaterMeter()
{
    delete this->window;
    delete this->meter;
}

void WaterMeter::startMeter(void)
{
    this->update(this->update_interval_ms);
}

void WaterMeter::update(int time_ms)
{
    std::string m3, tens_of_liters;
    int i_m3;
    std::stringstream ss;
    
    this->meter->measureFlow(time_ms);
    std::chrono::time_point last_update =
        std::chrono::high_resolution_clock::now();
    
    while (! this->window->shouldClose()) {
        std::chrono::duration<float, std::milli> delta_ms =
                std::chrono::high_resolution_clock::now() - last_update;
        std::cout << "[debug] it has passed " << delta_ms.count()
                << " ms since last update." << std::endl;

        if (delta_ms.count() > time_ms) {
            this->meter->measureFlow(delta_ms.count());
            last_update = std::chrono::high_resolution_clock::now();
            std::cout << "[debug] updated!" << std::endl;

            i_m3 = this->meter->count_m3();
            ss << std::setw(4) << std::setfill('0') << i_m3;
            m3 = ss.str();
            ss.str("");
            ss.clear();
            ss << std::setw(2) << std::setfill('0')
                    << (this->meter->countLiters() % 1000) / 10;
            tens_of_liters = ss.str();
            ss.str("");
            ss.clear();
            std::cout << "[debug] total liters passed: "
                    << this->meter->countLiters() << std::endl;
            std::cout << "[debug] display: " << m3 << tens_of_liters << std::endl; 
            
            this->window->drawMeter();
            this->window->drawDigits(m3 + tens_of_liters);
            this->window->renderCanvas();
        }
    }
}

//void WaterMeter::reloadConfig(void);
