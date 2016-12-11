#ifndef INTERFACE2_H
#define INTERFACE2_H


#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>

class interface2 : public QObject,public QGraphicsRectItem{
     Q_OBJECT
public:
    interface2(QString name,QGraphicsItem* parent = 0);
private:
    QGraphicsTextItem* text;
};

#endif // INTERFACE2_H
