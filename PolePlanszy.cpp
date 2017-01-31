#include "PolePlanszy.h"
#include "Game.h"

extern Game* game;
PolePlanszy::PolePlanszy(int k, int j, int i)
{
    tablicaXpos = j;
    tablicaYpos = i;
    statusPola = k;
    setRect(0,0,40,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);

    setBrush(brush);

    nieWcisnieta = true ;

}

void PolePlanszy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(game->fazaGry == 1 && nieWcisnieta == true)
    {
       int x = event->scenePos().x();
       int y = event->scenePos().y();


       nieWcisnieta=false;
       emit strzal(x,y,tablicaXpos,tablicaYpos);
    }
}



void PolePlanszy::poStrzale(bool a,int j, int i)
{
    if(a == true && j == tablicaXpos && i == tablicaYpos )
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
        game->fazaGry = 1;
    }
    else if(a == false && j == tablicaXpos && i == tablicaYpos)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::white);

        setBrush(brush);
        game->fazaGry = 2;
        if(game->wczytuje == false)
        {
        game->strzelanieKomputera();
        }
    }
    else
    {

    }
}

void PolePlanszy::strzalKomputera(bool a, int j, int i)
{
    if(a == true && j == tablicaXpos && i == tablicaYpos)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
        game->fazaGry = 2;
        if(game->wczytuje == false)
        {
         game->strzelanieKomputera();
        }
    }
    else if(a == false && j == tablicaXpos && i == tablicaYpos)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::white);

        setBrush(brush);
        game->fazaGry = 1;

    }
    else
    {

    }
}


