#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "Button.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    // konstruktor
    Game(QWidget* parent=0);


    // dekonsturktor
    ~Game();

    // metody
    void gamemenu();


    // attrybuty
    QGraphicsScene* scene;
public slots:
    // void start();

};



#endif // GAME_H
