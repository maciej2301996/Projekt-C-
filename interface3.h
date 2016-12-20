#ifndef INTERFACE3_H
#define INTERFACE3_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>

class interface3 : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    interface3(QString name,QGraphicsItem* parent = 0);
private:
    QGraphicsTextItem* text;
};

#endif // INTERFACE3_H
