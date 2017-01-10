#include "school.h"


School::School(QWidget *)
{
    // ustawienia ekranu
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1310,1000);
    X = 1310;
    Y = 1000;

    // ustawienia sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1310,1000);
    setScene(scene);

    klasa = "1a" ;
    przedmiot = "chemia" ;
    XElementInterface1 = 50;
    YElementInterface1 = 400;
    XElementInterface2 = 290;
    YElementInterface2 = 400;
    XElementInterface3 = 290;
    YElementInterface3 = 160;
    IndeksKomorki      = 0;
    LicznikWierszy = 0;
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
{
    QString i=sklej();
    QString jj=sklej1();
    QSqlQuery download;
    qDebug()<< "Działa klasa1";
    if(!download.exec(i))
        {
            qDebug() << "Brak rekordów ";
        }
    else
    {
    tworzenieElementuPierwszego(i);
    tworzenieElementuDrugiego(i);
    tworzenieElementuDrugiegoiTrzeciego(i);
    tworzenieElementuPierwszegoiTrzeciego(jj);
    }
    buttonZatwierdzZmiany = new PrzyciskClassWindow(X -200 , YElementInterface1,"Zatwierdź zmiany");
    scene->addWidget(buttonZatwierdzZmiany);
    buttonDodajKolumne = new PrzyciskClassWindow(X+200,YElementInterface1,"Dodaj kolumne");
    scene->addWidget(buttonDodajKolumne);

    qDebug()<< "Działa klasa1";
    comboxPrzedmioty = new Lista(170,200,1,this->db);
    scene->addWidget(comboxPrzedmioty);
    comboxKlasy  = new Lista(80,200,0,this->db);
    scene->addWidget(comboxKlasy);

    emit zmianaStanu();
    qDebug()<< "Działa klasa1";

}
void School::tworzenieElementuPierwszego(QString i)
{
    QSqlQuery download;
    QString imie;
    QString nazwisko;
    download.exec(i);
    while(download.next())
    {
         imie = download.value(1).toString();                           //przypisanie pobranego elementu z tabeli do zmiennej
         nazwisko = download.value(2).toString();                       //przypisanie pobranego elementu z tabeli do zmiennej
         InterfaceElement1* a = new InterfaceElement1(imie,nazwisko);   //stworzenie obiektu
         a->setPos(XElementInterface1,YElementInterface1);            //ustawienie pozycji obiektu
         elementlist1.append(a);                                        //lista elementow interface1
         scene->addItem(a);                                             //dodawanie do sceny
         YElementInterface1 += 26 ;                                    //zmiana wspolrzednej y dla nastepnego obiektu
         LicznikWierszy += 1;

    }
}
void School::tworzenieElementuDrugiego(QString i)
{   QSqlQuery download;
    QString elementKolumny;
    download.exec(i);
    LicznikOcenPojedynczegoUcznia = download.record().count();
        for(int d =0; d<download.size() ;d++)
        {
         download.next();
         NumerKolumnyPobieranej = 0;
         XElementInterface2  = 290;

         while(NumerKolumnyPobieranej + 3 < LicznikOcenPojedynczegoUcznia)
         {
            elementKolumny = download.value(NumerKolumnyPobieranej+3).toString();
            InterfaceElement2* b = new InterfaceElement2(XElementInterface2,YElementInterface2,IndeksKomorki,elementKolumny);
            b->setPos(XElementInterface2,YElementInterface2);
            elementlist2.append(b);
            scene->addItem(b);
            XElementInterface2 += 26;
            NumerKolumnyPobieranej += 1 ;
            IndeksKomorki +=1;

         }
         YElementInterface2 += 26;
        }
}
void School::tworzenieElementuDrugiegoiTrzeciego(QString i)
{   QSqlQuery download;
    download.exec(i);
    if(LicznikOcenPojedynczegoUcznia< 30)
        {
          YElementInterface2=400;
          for(int liczba1=0;liczba1<download.size();liczba1++)
          {
          XElementInterface23 = 290+ NumerKolumnyPobieranej*26;
            for (int liczba2 = 0; liczba2 < 30 ;liczba2++)
            {
                InterfaceElement2* b = new InterfaceElement2(XElementInterface23,YElementInterface2,IndeksKomorki);
                b->setPos(XElementInterface23,YElementInterface2);
                elementlist2.append(b);
                scene->addItem(b);
                IndeksKomorki +=1 ;
                //qDebug() << xelementinterface2;

                InterfaceElement3* c = new InterfaceElement3();
                c->setPos(XElementInterface23,YElementInterface3);
                elementlist3.append(c);
                scene->addItem(c);

                XElementInterface23 += 26;
        }

            YElementInterface2+=26;
          }

    }
}
void School::tworzenieElementuPierwszegoiTrzeciego(QString i)
{   int l = 0;
    QSqlQuery download;
    QString nazwa1;
    download.exec(i);
       while(download.next())
       {   if(l==1)
           {
            nazwa1 = download.value(0).toString();
           }
           else if(l==2)
           {
           InterfaceElement1* a = new InterfaceElement1(nazwa1,download.value(0).toString());
           a->setPos(XElementInterface1,374);
           elementlist1.append(a);
           scene->addItem(a);
           }
           else if (l>2)
           {
           InterfaceElement3* c = new InterfaceElement3(download.value(0).toString());
           c->setPos(XElementInterface3,YElementInterface3);
           elementlist3.append(c);
           scene->addItem(c);
           XElementInterface3+=26;
           }
           else{}

           l++ ;
       }
}
QString School::sklej()
{
    QString i="SELECT * FROM";
    i.append(" ");
    i.append(klasa);
    i.append("_");
    i.append(przedmiot);
    return i;
}
QString School::sklej1()
{
    QString jj="SHOW COLUMNS FROM";
    jj.append(" ");
    jj.append(klasa);
    jj.append("_");
    jj.append(przedmiot);
    return jj;
}
void School::proba(int value)
{
    Input* jeden = new Input(elementlist2[value]->X,elementlist2[value]->Y,value);
    inputlist.append(jeden);
    QGraphicsProxyWidget* proxy = scene->addWidget(jeden) ;
    inputlist1.append(proxy);
    emit stworzPolaczeniezInputem();
}
void School::zbieranie()
{
    qDebug()<<"Działa2";
}
void School::zatwierdzzmiany()
{
    if(!inputlist1.isEmpty())
        {   zbieranie() ;
            for(size_t i=0, n = inputlist1.size();i<n; ++i)
            {
                QString zmienna = inputlist[i]->text();
                elementlist2[inputlist[i]->Value]->uzupelnijDane(zmienna) ;
                inputlist1.removeAt(0);
            }
            for(size_t i=0, n = inputlist.size();i<n; ++i)
            {
                Input* a = inputlist[0] ;
                inputlist.removeAt(0);
                a->~Input();
            }

          scene->update();

    }
}
void School::dodajKolumne()
{   int zmiennaY = YElementInterface1 - 26*LicznikWierszy;

    for (int i = 0; i<LicznikWierszy; i++)
    {
        InterfaceElement2* b = new InterfaceElement2(XElementInterface23,zmiennaY,IndeksKomorki);
        b->setPos(XElementInterface23,zmiennaY);
        elementlist2.append(b);
        scene->addItem(b);
        IndeksKomorki +=1 ;
        zmiennaY +=26;
     }
    InterfaceElement3* c = new InterfaceElement3();
    c->setPos(XElementInterface23,YElementInterface3);
    elementlist3.append(c);
    scene->addItem(c);

    XElementInterface23 +=26;
    emit stworzPolaczeniezInputemdlaDodatkowychKolumn();
}
void School::zmienKlase(QString value)
{
    klasa = value ;
    XElementInterface1 = 50;
    YElementInterface1 = 400;
    XElementInterface2 = 290;
    YElementInterface2 = 400;
    XElementInterface3 = 290;
    YElementInterface3 = 160;
    IndeksKomorki      = 0;
    LicznikWierszy = 0;

    for (size_t i = 0, n = elementlist1.size(); i < n; ++i)
    {
        InterfaceElement1* a = elementlist1[0];
        elementlist1.removeAt(0);
        a->~InterfaceElement1();
    }
    for (size_t i = 0, n = elementlist2.size(); i < n; ++i)
    {
        InterfaceElement2* a = elementlist2[0];
        elementlist2.removeAt(0);
        a->~InterfaceElement2();
    }
    for (size_t i = 0, n = elementlist3.size(); i < n; ++i)
    {
        InterfaceElement3* a = elementlist3[0];
        elementlist3.removeAt(0);
        a->~InterfaceElement3();
    }
    QObject::disconnect(buttonZatwierdzZmiany,SIGNAL(clicked()),this,SLOT(zatwierdzzmiany()));
    buttonZatwierdzZmiany->~PrzyciskClassWindow();
    QObject::disconnect(buttonDodajKolumne,SIGNAL(clicked()),this,SLOT(dodajKolumne()));
    buttonDodajKolumne->~PrzyciskClassWindow();
    QObject::disconnect(comboxKlasy,SIGNAL(activated(QString)),this,SLOT(zmienKlase(QString)));
    QObject::disconnect(comboxPrzedmioty,SIGNAL(activated(QString)),this,SLOT(zmienPrzedmiot(QString)));
    scene->update();
    classwindow();
    scene->update();
}
void School::zmienPrzedmiot(QString value)
{
    przedmiot = value ;
    XElementInterface1 = 50;
    YElementInterface1 = 400;
    XElementInterface2 = 290;
    YElementInterface2 = 400;
    XElementInterface3 = 290;
    YElementInterface3 = 160;
    IndeksKomorki      = 0;
    LicznikWierszy = 0;

    for (size_t i = 0, n = elementlist1.size(); i < n; ++i)
    {
        InterfaceElement1* a = elementlist1[0];
        elementlist1.removeAt(0);
        a->~InterfaceElement1();
    }
    for (size_t i = 0, n = elementlist2.size(); i < n; ++i)
    {
        InterfaceElement2* a = elementlist2[0];
        elementlist2.removeAt(0);
        a->~InterfaceElement2();
    }
    for (size_t i = 0, n = elementlist3.size(); i < n; ++i)
    {
        InterfaceElement3* a = elementlist3[0];
        elementlist3.removeAt(0);
        a->~InterfaceElement3();
    }
    QObject::disconnect(buttonZatwierdzZmiany,SIGNAL(clicked()),this,SLOT(zatwierdzzmiany()));
    buttonZatwierdzZmiany->~PrzyciskClassWindow();
    QObject::disconnect(buttonDodajKolumne,SIGNAL(clicked()),this,SLOT(dodajKolumne()));
    buttonDodajKolumne->~PrzyciskClassWindow();
    QObject::disconnect(comboxKlasy,SIGNAL(activated(QString)),this,SLOT(zmienKlase(QString)));
    QObject::disconnect(comboxPrzedmioty,SIGNAL(activated(QString)),this,SLOT(zmienPrzedmiot(QString)));
    scene->update();
    classwindow();
    scene->update();

}
