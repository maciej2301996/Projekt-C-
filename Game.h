#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QPushButton>

#include "Button.h"
#include "poleplanszy.h"
#include "okret.h"
#include "ramka.h"



class Game: public QGraphicsView{
    Q_OBJECT
public:
    // konstruktor
    Game(QWidget* parent=0);


    // dekonsturktor
    ~Game();

    // metody
    void gamemenu();
    void dodawanieStatkow();
    void rozstawianieStatkow();

    // attrybuty
    QList<PolePlanszy*> PolaGracza1;
    QList<PolePlanszy*> PolaPrzeciwnika;

    Okret* frame ;
    Ramka* ramka ;

    int X;
    int Y;

    int a;
    int b;

    int iloscJednomasztowcow;
    int iloscDwumasztowcow;
    int iloscTrojmasztowcow;
    int iloscCzteromasztowcow;

    int liczbaDoRozstawieniaJednomasztowcow;
    int liczbaDoRozstawieniaDwumasztowcow;
    int liczbaDoRozstawieniaTrojmasztowcow;
    int liczbaDoRozstawieniaCzteromasztowcow;

    int rodzajStatku ;

    QString tablicaRozstawieniaStatkowGracza1[10][10];
    QString tablicaRozstawieniaStatkowGracza2[10][10];

    QString tablicaStrzelaniaGracza1[10][10];
    QString tablicaStrzelaniaGracza2[10][10];


    QGraphicsScene* scene;
    QGraphicsScene* scene2;
public slots:
    void start();
    void ruchStatku();
    void sprawdzRuch();
};



#endif // GAME_H
