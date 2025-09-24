#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

class Display
{
private:
    Image bg_img;
public:
    /* Returns water meter image with digits on top */
    Image assemble(std::string digits);
};

#endif