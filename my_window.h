#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include <string>

struct MyImage;

class MyWindow
{
private:
    MyImage bg_img;
    MyImage canvas;
    int digits_pos[4];
public:
    MyWindow(std::string bg_img_path);
    virtual ~MyWindow() {}
    virtual void clearCanvas();
    /* Returns water meter image with digits on top */
    virtual void drawDigits(std::string d);
    /* Draws meter on canvas */
    virtual void drawMeter(void);
    virtual void exportCanvasToFile(std::string path);
    /* Renders canvas on screen */
    virtual void renderCanvas(void);
    virtual void setDigitsPos(int x1, int y1, int x2, int y2);
};

#endif
