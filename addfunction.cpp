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

}


void SelectData()
{
    QString i ="SELECT * FROM 1a_chemia ";
    QSqlQuery download;



    if(!download.exec(i))
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

int Liczenie()
{
    QSqlQuery licznik;
    licznik.size();
    qDebug() << licznik.size();

    int i=3;
    return  i;
}
