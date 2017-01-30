#ifndef POLEPLANSZY_H
#define POLEPLANSZY_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QDebug>

class PolePlanszy : public QObject , public QGraphicsRectItem{
public:
   // konstruktor
        PolePlanszy(int k);


void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);

public slots:


private:
      int statusPola ;
};

#endif // POLEPLANSZY_H
