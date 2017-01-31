#include "Game.h"
#include <QApplication>
#include <QTime>
#include <qglobal.h>

#include <ustawienia.h>

Game* game;
Ustawienia* ustawienia;
int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);



    game = new Game();
    ustawienia = new Ustawienia();

    game->show();
    game->gamemenu();


    return a.exec();
}
