#include "Game.h"
#include <QApplication>
#include <QTime>
#include <qglobal.h>

Game* game;

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->gamemenu();


    return a.exec();
}
