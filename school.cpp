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
    //AddData();
    //SelectData();

    interface1* a = new interface1(QString("Andrzej"),QString("Strzygielski"));
    int x = 50;
    int y = 300;
    a->setPos(x,y);
    scene->addItem(a);

    //Button* playButton = new Button(QString("Graj"));
   // int button1xPos = this->width()/2 - playButton->boundingRect().width()/2;
    //int button1yPos = this->height() * 2 /6;
    //playButton->setPos(button1xPos,button1yPos);
   // scene->addItem(playButton);

}
