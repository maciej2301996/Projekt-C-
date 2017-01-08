#ifndef INTERFACEELEMENT2_H
#define INTERFACEELEMENT2_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QLineEdit>
#include <QValidator>
#include <QObject>
#include <QDebug>

#include "input.h"

class InterfaceElement2 : public QObject , public QGraphicsRectItem{
    Q_OBJECT
public:
    InterfaceElement2(int x,int y,QGraphicsItem* parent = 0);
    InterfaceElement2(int x,int y,QString name, QGraphicsItem *parent = 0);

    ~InterfaceElement2();

    void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);

signals:
    void create();
public slots:


private:
    int X;
    int Y;
    QGraphicsTextItem* text1;
    QLineEdit* linia;
};

#endif // INTERFACEELEMENT2_H
