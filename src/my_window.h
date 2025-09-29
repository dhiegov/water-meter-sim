#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include <string>

#include <raylib.h>

class MyWindow
{
private:
    Image bg_img;
    Image canvas;
    /* top left corner of cubic meters digits display */
    int digits_pos[2];
public:
    MyWindow(std::string bg_img_path);
    virtual ~MyWindow();
    virtual void clearCanvas();
    /* Returns water meter image with digits on top */
    virtual void drawDigits(std::string d);
    /* Draws meter on canvas */
    virtual void drawMeter(void);
    virtual void exportCanvasToFile(std::string path);
    /* Renders canvas on screen */
    virtual void renderCanvas(void);
    /* Top left corner of where the digits start
       TODO: make padding, font_size, vertical digit offset
             and cover sizes settable */
    virtual void setDigitsPos(int x1, int y1);
    /* Returns true when Esc or the window close button is pressed */
    virtual bool shouldClose(void);
};

#endif
