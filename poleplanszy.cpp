#include "PolePlanszy.h"



PolePlanszy::PolePlanszy()
{
    setRect(0,0,40,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);

    setBrush(brush);

}

void PolePlanszy::mousePressEvent()
{

}
