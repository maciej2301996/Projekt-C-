#ifndef SCHOOL_H
#define SCHOOL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "addfunction.h"


class School : public QGraphicsView{
    Q_OBJECT
public:
    // konstruktor
    School(QWidget* parent=0);


    // dekonsturktor
    ~School();

    // metody
    void drawTabel();


    // attrybuty
    QGraphicsScene* scene;
public slots:


};

#endif // SCHOOL_H
