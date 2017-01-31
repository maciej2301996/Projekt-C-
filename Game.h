#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QtAlgorithms>
#include <QApplication>

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
    void strzelanieKomputera();
    void czyKtosWygral1();
    void czyKtosWygral2();
    void ustawLiczbeStatkow();
    void plansza();
    void startZWczytania();
    void sprawdzanieZatopien();
    void sprawdzanieZatopienKomputera();
    void rysowanieTabelki();
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
    int iloscStatkow ;
    int fazaGry ;

    int liczbaPunktow;
    int liczbaRuchowGracza;
    int liczbaRuchowKomputera;

    int liczbaJednoMasztowcowGracza;
    int liczbaDwuMasztowcowGracza;
    int liczbaTrzyMasztowcowGracza;
    int liczbaCzteroMasztowcowGracza;

    int liczbaJednoMasztowcowKomputera;
    int liczbaDwuMasztowcowKomputera;
    int liczbaTrzyMasztowcowKomputera;
    int liczbaCzteroMasztowcowKomputera;

    bool czyObrocony ;
    bool rozlacz ;
    bool wczytuje;

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

    QString tablicaStrzelaniaGracza1[11][11];
    QString tablicaStrzelaniaGracza2[11][11];

    QPushButton* przycisk ;
    QPushButton* przycisk1;
    QPushButton* zapis;
    QPushButton* wrocDomenu;

    QGraphicsScene* scene;
    QGraphicsScene* scene2;
    QGraphicsScene* scenaKoncowa;
    QGraphicsScene* scenaUstawien;
public slots:
    void start();
    void ruchStatku();
    void sprawdzRuch();
    void obrocStatek();
    void czyTrafiony(int x,int y,int tablicaXpos,int tablicaYpos);
    void ustawScene();
    void wrocDoMenu();
    void zapiszGre();
    void wczytajZapis();

signals :
    void poStrzale(bool a,int tablicaXpos,int tablicaYpos);
    void strzalKomputera(bool a,int tablicaXpos,int tablicaYpos);

};



#endif // GAME_H
