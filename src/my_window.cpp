
#include <raylib.h>
#include <string>

#include "my_window.h"

MyWindow::MyWindow(std::string bg_img_path)
: digits_pos{50, 50}
{
    SetTargetFPS(20);
    this->bg_img = LoadImage("meter_bg.png");
    InitWindow(this->bg_img.width, this->bg_img.height, "Water meter simulation");
}

MyWindow::~MyWindow()
{
    CloseWindow();
}

void MyWindow::clearCanvas() {}

void MyWindow::drawDigits(std::string d)
{
    const int pad = 10;
    const int cover_width = 18;
    const int cover_height = 35;
    const int font_size = 36;
    int x = this->digits_pos[0];
    int y = this->digits_pos[1];
    int i;

    for (i = 0; i < 6; i++) {
        // covering the digits in the original image
        ImageDrawRectangle(&(this->canvas),
            x, y, cover_width, cover_height, WHITE);
        x += cover_width + pad;
    }

    x = this->digits_pos[0];
    // pushes digits a bit down, centering vertically
    y = this->digits_pos[1] + 2;
    char digit[2] = {0, '\0'};
    for (i = 0; i < 4; i++) {
        digit[0] = d.c_str()[i];
        // cubic meters digits
        ImageDrawText(&(this->canvas), digit,
            x, y, font_size, BLACK);
        x += cover_width + pad;
    }

    for (i = 4; i < 6; i++) {
        digit[0] = d.c_str()[i];
        // hundreds and tens of liters digits
        ImageDrawText(&(this->canvas), digit,
            x, y, font_size, RED);
        x += cover_width + pad;
    }
}

/* Draws meter on canvas */
void MyWindow::drawMeter(void)
{
    this->canvas = ImageCopy(this->bg_img);
}

void MyWindow::exportCanvasToFile(std::string path) {}

/* Renders canvas on screen */
void MyWindow::renderCanvas(void)
{
    Texture2D texture = LoadTextureFromImage(this->canvas);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
}

void MyWindow::setDigitsPos(int x1, int y1)
{
    this->digits_pos[0] = x1;
    this->digits_pos[1] = y1;
}

/* Returns true when Esc or the window close button is pressed */
bool MyWindow::shouldClose(void)
{
    return WindowShouldClose();
}
