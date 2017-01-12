#include "interfaceelement1.h"

InterfaceElement1::InterfaceElement1(QString name, QString surname, QGraphicsItem *)
{
     IDwTabeli = -1;

    setRect(0,0,240,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    // dodawanie napisu
    sklejanie = surname + " " + name;
    text = new QGraphicsTextItem(sklejanie,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = 10;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}

InterfaceElement1::InterfaceElement1(QString name, QString surname, QString ID, QGraphicsItem*)
{
    IDwTabeli = ID;

    setRect(0,0,240,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    // dodawanie napisu
    sklejanie = surname + " " + name;
    text = new QGraphicsTextItem(sklejanie,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = 10;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}

void InterfaceElement1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << IDwTabeli ;
}
