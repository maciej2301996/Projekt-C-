#include "school.h"
#include "funkcje.h"
#include <QApplication>

School* school;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    school = new School();
    funkcje* przekaznik = new funkcje();

    QObject::connect(school,SIGNAL(zmianaStanu()),przekaznik,SLOT(polaczSchool()));

    school->show();
    school->polaczenie();
    school->classwindow();



    QObject::connect(school,SIGNAL(stworzPolaczeniezInputemdlaDodatkowychKolumn()),przekaznik,SLOT(wykonajPolaczeniezInputemdlaDodatkowychKolumn()));
    QObject::connect(school,SIGNAL(stworzPolaczeniezInputem()),przekaznik,SLOT(wykonajPolaczeniezInputem()));



    return a.exec();
}
