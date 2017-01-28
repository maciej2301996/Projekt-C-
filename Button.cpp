#include "Button.h"



Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    // dodawanie napisu
    text = new QGraphicsTextItem(name,this);
    QFont buttonFont1("Times New Roman",30);
    text->setFont(buttonFont1);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}
Button::~Button()
{

}
void Button::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit clicked();
}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}


void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
