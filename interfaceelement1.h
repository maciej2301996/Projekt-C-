#ifndef INTERFACEELEMENT1_H
#define INTERFACEELEMENT1_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

class InterfaceElement1 : public QGraphicsRectItem
{
public:
    InterfaceElement1(QString name,QString surname,QGraphicsItem* parent=0);

private:
    QString sklejanie;
    QGraphicsTextItem* text;
};

#endif // INTERFACEELEMENT1_H
