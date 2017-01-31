#include "ramka.h"
#include "Game.h"

extern Game* game ;

Ramka::Ramka()
{
    QBrush brush;
    setRect(0,0,200,200);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);

    setBrush(brush);
}

void Ramka::iloscOkretow()
{   QBrush brush;
    setRect(0,0,500,300);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    QFont titleFont("Times New Roman",16);

    QGraphicsSimpleTextItem* titleText2 = new QGraphicsSimpleTextItem("Rodzaj okrętu",this);
    titleText2->setFont(titleFont);
    int textxPos2 = 50;
    int textyPos2 = 10;
    titleText2->setPos(textxPos2,textyPos2);


    QGraphicsSimpleTextItem* titleText = new QGraphicsSimpleTextItem("Gracz",this);
    titleText->setFont(titleFont);
    int textxPos = 260;
    int textyPos = 10;
    titleText->setPos(textxPos,textyPos);

    QGraphicsSimpleTextItem* titleText1 = new QGraphicsSimpleTextItem("Komputer",this);
    titleText1->setFont(titleFont);
    int textxPos1 = 360;
    int textyPos1 = 10;
    titleText1->setPos(textxPos1,textyPos1);


    QGraphicsSimpleTextItem* jedno = new QGraphicsSimpleTextItem("Jednomasztowce",this);
    jedno->setFont(titleFont);
    int jednoxPos1 = 40;
    int jednoyPos1 = 70;
    jedno->setPos(jednoxPos1,jednoyPos1);


    QGraphicsSimpleTextItem* dwu = new QGraphicsSimpleTextItem("Dwumasztowce",this);
    dwu->setFont(titleFont);
    int dwuxPos1 = 40;
    int dwuyPos1 = 130;
    dwu->setPos(dwuxPos1,dwuyPos1);

    QGraphicsSimpleTextItem* troj = new QGraphicsSimpleTextItem("Trójmasztowce",this);
    troj->setFont(titleFont);
    int trojxPos1 = 40;
    int trojyPos1 = 190;
    troj->setPos(trojxPos1,trojyPos1);

    QGraphicsSimpleTextItem* cztero = new QGraphicsSimpleTextItem("Czteromasztowce",this);
    cztero->setFont(titleFont);
    int czteroxPos1 = 40;
    int czteroyPos1 = 250;
    cztero->setPos(czteroxPos1,czteroyPos1);


    QGraphicsSimpleTextItem* graczjedno = new QGraphicsSimpleTextItem(QString::number(game->liczbaJednoMasztowcowGracza),this);
    graczjedno->setFont(titleFont);
    int graczjednoxPos1 = 280;
    int graczjednoyPos1 = 70;
    graczjedno->setPos(graczjednoxPos1,graczjednoyPos1);

    QGraphicsSimpleTextItem* graczdwu = new QGraphicsSimpleTextItem(QString::number(game->liczbaDwuMasztowcowGracza),this);
    graczdwu->setFont(titleFont);
    int graczdwuxPos1 = 280;
    int graczdwuyPos1 = 130;
    graczdwu->setPos(graczdwuxPos1,graczdwuyPos1);

    QGraphicsSimpleTextItem* gracztrzy = new QGraphicsSimpleTextItem(QString::number(game->liczbaTrzyMasztowcowGracza),this);
    gracztrzy->setFont(titleFont);
    int gracztrzyxPos1 = 280;
    int gracztrzyyPos1 = 190;
    gracztrzy->setPos(gracztrzyxPos1,gracztrzyyPos1);

    QGraphicsSimpleTextItem* graczcztery = new QGraphicsSimpleTextItem(QString::number(game->liczbaCzteroMasztowcowGracza),this);
    graczcztery->setFont(titleFont);
    int graczczteryxPos1 = 280;
    int graczczteryyPos1 = 250;
    graczcztery->setPos(graczczteryxPos1,graczczteryyPos1);


    QGraphicsSimpleTextItem* komputerjedno = new QGraphicsSimpleTextItem(QString::number(game->liczbaJednoMasztowcowKomputera),this);
    komputerjedno->setFont(titleFont);
    int komputerjednoxPos1 = 400;
    int komputerjednoyPos1 = 70;
    komputerjedno->setPos(komputerjednoxPos1,komputerjednoyPos1);

    QGraphicsSimpleTextItem* komputerdwu = new QGraphicsSimpleTextItem(QString::number(game->liczbaDwuMasztowcowKomputera),this);
    komputerdwu->setFont(titleFont);
    int komputerdwuxPos1 = 400;
    int komputerdwuyPos1 = 130;
    komputerdwu->setPos(komputerdwuxPos1,komputerdwuyPos1);

    QGraphicsSimpleTextItem* komputertrzy = new QGraphicsSimpleTextItem(QString::number(game->liczbaTrzyMasztowcowKomputera),this);
    komputertrzy->setFont(titleFont);
    int komputertrzyxPos1 = 400;
    int komputertrzyyPos1 = 190;
    komputertrzy->setPos(komputertrzyxPos1,komputertrzyyPos1);

    QGraphicsSimpleTextItem* komputercztery = new QGraphicsSimpleTextItem(QString::number(game->liczbaCzteroMasztowcowKomputera),this);
    komputercztery->setFont(titleFont);
    int komputerczteryxPos1 = 400;
    int komputerczteryyPos1 = 250;
    komputercztery->setPos(komputerczteryxPos1,komputerczteryyPos1);



}
