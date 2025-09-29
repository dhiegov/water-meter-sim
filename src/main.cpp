
#include <iostream>

#include "my_window.h"

int main()
{
    /* water meter image from
     * Grupo Águas do Brasil; Como usar o seu hidrômetro; opened 2025-09-28
     * https://www.grupoaguasdobrasil.com.br/wp-content/uploads/2018/04/como-usar-seu-hidrometro.pdf
     */
    MyWindow win("meter_bg.png");

    while (! win.shouldClose())
    {
        win.drawMeter();
        win.setDigitsPos(435, 290);
        win.drawDigits("123456");
        win.renderCanvas();
    }
}