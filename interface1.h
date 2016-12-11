#ifndef INTERFACE1_H
#define INTERFACE1_H


#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>


class interface1 : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    interface1(QString name,QString surname,QGraphicsItem* parent = 0);


private:
    QString sklejanie;
    QGraphicsTextItem* text;
};

#endif // INTERFACE1_H
























