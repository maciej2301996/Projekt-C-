#ifndef POLEPLANSZY_H
#define POLEPLANSZY_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>

class PolePlanszy : public QObject , public QGraphicsRectItem{
public:
   // konstruktor
        PolePlanszy();


void mousePressEvent();
};

#endif // POLEPLANSZY_H
