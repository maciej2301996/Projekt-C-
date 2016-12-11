#include "interface1.h"

interface1::interface1(QString name, QString surname, QGraphicsItem* parent) :  QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,180,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    // dodawanie napisu
    sklejanie += surname += ' ';
    sklejanie += name;
    text = new QGraphicsTextItem(sklejanie,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}


