#ifndef INTERFACE2_H
#define INTERFACE2_H


#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QLineEdit>

#include "school.h"



class interface2 : public QObject,public QGraphicsRectItem{
     Q_OBJECT
public:
    interface2(int x,int y,QGraphicsItem* parent = 0);
    interface2(int x,int y,QString name,QGraphicsItem* parent = 0);


    void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);
    void keyPressEvent(QKeyEvent *event);
signals:
    void sygnal();
private:
    QGraphicsTextItem* text;
    int X;
    int Y;
    QLineEdit* linia;
};

#endif // INTERFACE2_H
