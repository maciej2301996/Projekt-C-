#include "addfunction.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


void Connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("dziennikucznia");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
            qDebug() << "Nieudane polaczenie z baza danych";
    else
        {
            qDebug() << "Polaczenie z baza danych udało sie";
        }


    db.close();
    qDebug() << "Zamknięto bazę danych " ;

}
