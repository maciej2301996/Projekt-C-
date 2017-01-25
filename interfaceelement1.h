#ifndef INTERFACEELEMENT1_H
#define INTERFACEELEMENT1_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QFont>
#include <QDebug>

class InterfaceElement1 : public QGraphicsRectItem
{
public:
    InterfaceElement1(QString name, QString surname, QGraphicsItem* parent=0);
    InterfaceElement1(QString name,QString surname,QString ID ,QGraphicsItem* parent=0);

    QString IDwTabeli;


    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QString sklejanie;
    QGraphicsTextItem* text;
};

#endif // INTERFACEELEMENT1_H
