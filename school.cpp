#include "school.h"


School::School(QWidget *)
{
    // ustawienia ekranu
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1310,1000);

    // ustawienia sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1310,1000);
    setScene(scene);
}

School::~School()
{

}


void School::polaczenie()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("dziennik");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
            qDebug() << "Nieudane polaczenie z baza danych";
    else
        {
            qDebug() << "Polaczenie z baza danych udało sie";
    }
}

void School::classwindow()
{   int l = 0;
    int xelementinterface1 = 50;
    int yelementinterface1 = 400;
    int licznikOcenPojedynczegoUcznia;
    int numerKolumnyPobieranej;
    int xelementinterface3=290;
    int yelementinterface3=160;
    int xelementinterface23;
    int xelementinterface2;
    int yelementinterface2 = 400;
    QString i="SELECT * FROM 1a_chemia ";
    QString jj="SHOW COLUMNS FROM 1a_chemia";
    QString nazwisko;
    QString imie;
    QString elementKolumny;
    QString nazwa1;
    QSqlQuery download;
    QSqlQuery download1;

    if(!download.exec(i))
        {
            qDebug() << "Brak rekordów ";
        }

    while(download.next())
    {
         imie = download.value(1).toString();                           //przypisanie pobranego elementu z tabeli do zmiennej
         nazwisko = download.value(2).toString();                       //przypisanie pobranego elementu z tabeli do zmiennej
         InterfaceElement1* a = new InterfaceElement1(imie,nazwisko);   //stworzenie obiektu
         a->setPos(xelementinterface1,yelementinterface1);              //ustawienie pozycji obiektu
         elementlist1.append(a);                                        //lista elementow interface1
         scene->addItem(a);                                             //dodawanie do sceny
         yelementinterface1 += 26 ;                                     //zmiana wspolrzednej y dla nastepnego obiektu

         qDebug()<< elementlist1 << "/n";
    }

    download.exec(i);
    licznikOcenPojedynczegoUcznia = download.record().count();
        for(int d =0; d<download.size() ;d++)
        {
         download.next();
         numerKolumnyPobieranej = 0;
         xelementinterface2  = 290;

         while(numerKolumnyPobieranej + 3 < licznikOcenPojedynczegoUcznia)
         {
            elementKolumny = download.value(numerKolumnyPobieranej+3).toString();
            InterfaceElement2* b = new InterfaceElement2(xelementinterface2,yelementinterface2,elementKolumny);
            b->setPos(xelementinterface2,yelementinterface2);
            elementlist2.append(b);
            scene->addItem(b);
            xelementinterface2 += 26;
            numerKolumnyPobieranej += 1 ;
         }
         yelementinterface2 += 26;
        }

        if(licznikOcenPojedynczegoUcznia< 30)
            {
              yelementinterface2=400;
              for(int liczba1=0;liczba1<download.size();liczba1++)
              {
              xelementinterface23 = 290+ numerKolumnyPobieranej*26;
                for (int liczba2 = 0; liczba2 < 30 ;liczba2++)
                {
                    InterfaceElement2* b = new InterfaceElement2(xelementinterface23,yelementinterface2);
                    b->setPos(xelementinterface23,yelementinterface2);
                    elementlist2.append(b);
                    scene->addItem(b);


                    InterfaceElement3* c = new InterfaceElement3();
                    c->setPos(xelementinterface23,yelementinterface3);
                    elementlist3.append(c);
                    scene->addItem(c);

                    xelementinterface23 += 26;
            }

                yelementinterface2+=26;
              }

            }
        else
            {

            }


    download1.exec(jj);
        while(download1.next())
        {   if(l==1)
            {
             nazwa1 = download1.value(0).toString();
            }
            else if(l==2)
            {
            InterfaceElement1* a = new InterfaceElement1(nazwa1,download1.value(0).toString());
            a->setPos(xelementinterface1,374);
            elementlist1.append(a);
            scene->addItem(a);
            }
            else if (l>2)
            {
            InterfaceElement3* c = new InterfaceElement3(download1.value(0).toString());
            c->setPos(xelementinterface3,yelementinterface3);
            elementlist3.append(c);
            scene->addItem(c);
            xelementinterface3+=26;
            }
            else{}

            l++ ;
        }


}


void School::proba()
{
    Input* jeden = new Input();
    scene->addWidget(jeden);
    qDebug()<< "Działa1";
}
