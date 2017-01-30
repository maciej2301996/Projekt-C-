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
    void dodawanieStatkow(QString a);
    void rozstawianieStatkow();
    void rozstawianieStatkowKomputera();
    void sprawdzRuchKomputera(QString obrazek, int losowaOrientacja, int liczbaMasztow);


    void plansza();
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

    int ktoryStatekObrocic;

    int rozstawionychStatkow ;

    bool czyObrocony ;

    QString obrazekjednomasztowca ;
    QString obrazekdwumasztowca   ;
    QString obrazektrojmasztowca  ;
    QString obrazekczteromasztowca;

    QString obrazekjednomasztowcaobrocony;
    QString obrazekdwumasztowcaobrocony;
    QString obrazektrojmasztowcaobrocony;
    QString obrazekczteromasztowcaobrocony;

    QString tablicaRozstawieniaStatkowGracza1[11][11];
    QString tablicaRozstawieniaStatkowGracza2[11][11];

    QString tablicaStrzelaniaGracza1[10][10];
    QString tablicaStrzelaniaGracza2[10][10];

    QPushButton* przycisk ;
    QPushButton* przycisk1;

    QGraphicsScene* scene;
    QGraphicsScene* scene2;
public slots:
    void start();
    void ruchStatku();
    void sprawdzRuch();
    void obrocStatek();
};



#endif // GAME_H
