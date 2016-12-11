#include "interface2.h"

interface2::interface2(QString name,QGraphicsItem* parent) :  QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,100,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    // dodawanie napisu
    text = new QGraphicsTextItem(name,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}
