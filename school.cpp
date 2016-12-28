#include "school.h"

School::School(QWidget *parent)
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
void School::connect()
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

void School::drawTabel()
{
    int p = 0;
    int licznik;
    int xinterface1 = 50;
    int yinterface1 = 400;
    int k = 400;
    int l = 0;
    int yinterface3=160;
    int xinterface3=290;


    QString i="SELECT * FROM 1a_chemia";
    QString jj="SHOW COLUMNS FROM 1a_chemia";
    QSqlQuery download;
    QSqlQuery download1;
    QString kolumna ;
    QString nazwisko;
    QString imie;
    QString nazwa1;

    if(!download.exec(i))
        {
            qDebug() << "Brak rekordów ";
        }

    while(download.next())
    {
         imie = download.value(1).toString();
         nazwisko = download.value(2).toString();
         interface1* a = new interface1(imie,nazwisko);
         a->setPos(xinterface1,yinterface1);
         scene->addItem(a);
         yinterface1 += 26 ;
    }


download.exec(i);
licznik = download.record().count();
    for(int d =0; d<download.size() ;d++)
    {
     download.next();
     p = 0;
     int j = 290;

     while(p + 3 < licznik)
     {
        kolumna = download.value(p+3).toString();
        interface2* b = new interface2(j,k,kolumna);
        b->setPos(j,k);
        scene->addItem(b);
        j += 26;
        p += 1 ;
     }
     k += 26;
    }

    if(licznik < 30)
        {
          k=400;
          for(int liczba1=0;liczba1<download.size();liczba1++)
          {
          int t = 290+ p*26;
            for (int liczba2 = 0; liczba2 < 30 ;liczba2++)
            {
                interface2* b = new interface2(t,k);
                b->setPos(t,k);
                scene->addItem(b);


                interface3* c = new interface3();
                c->setPos(t,yinterface3);
                scene->addItem(c);

                t += 26;
        }

            k+=26;
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
        interface1* a = new interface1(nazwa1,download1.value(0).toString());
        a->setPos(xinterface1,374);
        scene->addItem(a);
        }
        else if (l>2)
        {
        interface3* c = new interface3(download1.value(0).toString());
        c->setPos(xinterface3,yinterface3);
        scene->addItem(c);
        xinterface3+=26;
        }
        else{}

        l++ ;
    }


}
void School::addCombos()
{
    combo = new QComboBox();
    combo1= new QComboBox();

    QStringList a,klasy,przedmioty;
    QStringList tables = db.tables();


    for(int i=0;i<tables.size();i++)
       {

           a = tables[i].split(QRegExp("_"));
           klasy.append(a[0]);
           przedmioty.append(a[1]);
        }

    klasy.removeDuplicates();
    przedmioty.removeDuplicates();


    combo->addItems(klasy);
    combo1->addItems(przedmioty);

    combo->setGeometry(80,200,80,20);
    combo1->setGeometry(170,200,80,20);

    scene->addWidget(combo);
    scene->addWidget(combo1);
}

//void School::QComboBox::currentIndexChanged(const QString)

