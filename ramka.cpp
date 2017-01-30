#include "ramka.h"

Ramka::Ramka()
{
    QBrush brush;
    setRect(0,0,200,200);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);

    setBrush(brush);
}
