#include "school.h"

#include "interface1.h"




School::School(QWidget *parent)
{
    // ustawienia ekranu
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1910,1000);

    // ustawienia sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1910,1000);
    setScene(scene);
}

School::~School()
{

}


void School::drawTabel()
{

    interface1* a = new interface1(QString("Andrzej"),QString("Strzygielski"));
    int x = 50;
    int y = 300;
    a->setPos(x,y);
    scene->addItem(a);
    //12

}
