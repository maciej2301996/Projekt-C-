#include "addfunction.h"




void Connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("dziennik");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
            qDebug() << "Nieudane polaczenie z baza danych";
    else
        {
            qDebug() << "Polaczenie z baza danych udało sie";

            QStringList tables = db.tables();
                    for(int i=0;i<tables.size();i++)
                        qDebug() << tables.at(i);
        }


   // db.close();
    qDebug() << "Zamknięto bazę danych " ;
}


void SelectData()
{

    QSqlQuery download;
    if(!download.exec("SELECT * FROM 1a_chemia "))
        {
            qDebug() << "Brak rekordów ";
        }

    while(download.next())
    {
    QString imie = download.value(1).toString();
    QString nazwisko = download.value(2).toString();
    qDebug() << imie << nazwisko ;

    }
}

void AddData()
{

    QSqlQuery upload;
    upload.exec("INSERT INTO 'dziennik'.'1a-jezykpolski'('1auczenid','IMIE'','NAZWISKO') VALUES (NULL,'Stefan','Kowalski')");
    upload.exec("INSERT INTO 'dziennik'.'1a-jezykpolski'('1auczenid','IMIE'','NAZWISKO') VALUES (NULL,'Stefan','Michalski')");

}


