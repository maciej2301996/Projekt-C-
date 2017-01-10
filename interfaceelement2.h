#ifndef INTERFACEELEMENT2_H
#define INTERFACEELEMENT2_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSimpleTextItem>
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
    InterfaceElement2(int x,int y,int IndeksKomorki,QGraphicsItem* parent = 0);
    InterfaceElement2(int x,int y,int IndeksKomorki,QString name, QGraphicsItem *parent = 0);

    ~InterfaceElement2();

    void uzupelnijDane(QString napis);

    void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);
    int X;
    int Y;
    int unikatowaliczba;
signals:
    void create(int i);
    void stworzPolaczenie();
public slots:


private:

    QGraphicsSimpleTextItem* text1;
    QLineEdit* linia;
};

#endif // INTERFACEELEMENT2_H
