#include "interface3.h"

interface3::interface3(QString name, QGraphicsItem *parent):  QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,240);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    // dodawanie napisu
    text = new QGraphicsTextItem(name,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = rect().width()  + 19- text->boundingRect().width()/2;
    int yPos = rect().height() - 55 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setRotation(this->rotation()-90);
}

interface3::interface3(QGraphicsItem* parent): QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,240);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}
