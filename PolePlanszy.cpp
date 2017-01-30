#include "PolePlanszy.h"
#include "Game.h"

extern Game* game;
PolePlanszy::PolePlanszy(int k)
{
    statusPola = k;
    setRect(0,0,40,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);

    setBrush(brush);

}

void PolePlanszy::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if(statusPola == 1)
    {

    }
}


