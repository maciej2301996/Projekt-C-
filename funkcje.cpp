#include "funkcje.h"

extern School* school;

funkcje::funkcje()
{

}
void funkcje::sygnal()
{

    for (size_t i = 1, n = school->inputlist.size(); i < n; ++i)
    {
     QObject::connect(school->inputlist[i-1],SIGNAL(editingFinished()),school,SLOT(zbieranie()));
    }

}

void funkcje::polaczSchool()
{
    for (size_t i = 0, n = school->elementlist2.size(); i < n; ++i)
    {
     QObject::connect(school->elementlist2[i],SIGNAL(create(int)),school,SLOT(proba(int)));
    }
    QObject::connect(school->buttonZatwierdzZmiany,SIGNAL(clicked()),school,SLOT(zatwierdzzmiany()));
    QObject::connect(school->buttonDodajKolumne,SIGNAL(clicked()),school,SLOT(dodajKolumne()));
    QObject::connect(school->comboxKlasy,SIGNAL(activated(QString)),school,SLOT(zmienKlase(QString)));
    QObject::connect(school->comboxPrzedmioty,SIGNAL(activated(QString)),school,SLOT(zmienPrzedmiot(QString)));
}
void funkcje::wykonajPolaczeniezInputem()
{

    this->sygnal();
}
void funkcje::wykonajPolaczeniezInputemdlaDodatkowychKolumn()
{
    for (size_t i = 0, n = school->elementlist2.size(); i < n; ++i)
    {
        QObject::connect(school->elementlist2[i],SIGNAL(create(int)),school,SLOT(proba(int)));
    }

}


