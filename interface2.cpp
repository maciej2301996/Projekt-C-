#include "interface2.h"

extern School* school;

interface2::interface2(int x, int y, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
    X=x;
    Y=y;

}

interface2::interface2(int x, int y, QString name, QGraphicsItem *parent) :  QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    // dodawanie napisu
    text = new QGraphicsTextItem(name,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    X=x;
    Y=y;
}

void interface2::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    linia = new QLineEdit();
    linia->setGeometry(X,Y,25,25);
    linia->setMaxLength(2);
    school->scene->addWidget(linia);
}

void interface2::keyPressEvent(QKeyEvent *event)
{

}
