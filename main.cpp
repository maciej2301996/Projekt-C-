#include <QApplication>

#include "school.h"
#include "funkcje.h"
#include "logowanie.h"
#include "dodajuczen.h"
#include "dodajprzedmiot.h"
#include "dodajuzytkownik.h"
#include "usunuczen.h"
#include "usunprzedmiot.h"
#include "usunuzytkownik.h"

School* school;
DodajUczen* uczen;
UsunUczen* okno;
DodajPrzedmiot* Przedmiot;
UsunPrzedmiot* Przedmiot1;
DodajUzytkownik* konto;
UsunUzytkownik* konto1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    school = new School();
    uczen = new DodajUczen();
    okno = new UsunUczen();
    Przedmiot = new DodajPrzedmiot();
    Przedmiot1 = new UsunPrzedmiot();
    konto =new DodajUzytkownik();
    konto1 =new UsunUzytkownik();

    funkcje* przekaznik = new funkcje();
    Logowanie* logowanie = new Logowanie();


  // uczen->show();
  //  uczen->pola();

    logowanie->show();
    logowanie->bazadaych();



   // school->show();
    //school->polaczenie();
    //school->classwindow();

    QObject::connect(school,SIGNAL(zmianaStanu()),przekaznik,SLOT(polaczSchool()));
    QObject::connect(school,SIGNAL(stworzPolaczeniezInputemdlaDodatkowychKolumn()),przekaznik,SLOT(wykonajPolaczeniezInputemdlaDodatkowychKolumn()));
    QObject::connect(school,SIGNAL(stworzPolaczeniezInputem()),przekaznik,SLOT(wykonajPolaczeniezInputem()));



    return a.exec();
}
