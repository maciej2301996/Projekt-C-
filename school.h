#ifndef SCHOOL_H
#define SCHOOL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsItem>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QKeyEvent>

#include "interfaceelement1.h"
#include "interfaceelement2.h"
#include "interfaceelement3.h"
#include "input.h"
#include "input3.h"
#include "przyciskclasswindow.h"
#include "lista.h"
#include "dodajuczen.h"
#include "dodajprzedmiot.h"
#include "dodajuzytkownik.h"
#include "usunuczen.h"
#include "usunprzedmiot.h"
#include "usunuzytkownik.h"


class School : public QGraphicsView
{ Q_OBJECT

public :
    // konstruktor

    School(QWidget* parent=0);

    // dekonstruktor

    ~School();

    //atrybuty
    QGraphicsScene* scene;

    QSqlDatabase db;

    QList<InterfaceElement1*>    elementlist1;
    QList<InterfaceElement3*>    elementlist3;
    QList<InterfaceElement2*>    elementlist2;
    QList<Input*>                inputlist;
    QList<Input3*>               inputlistelement3;
    QList<QGraphicsProxyWidget*> inputlist1;
    QList<QGraphicsProxyWidget*> inputlistelement31;

    PrzyciskClassWindow*      buttonZatwierdzZmiany;
    PrzyciskClassWindow*      buttonDodajKolumne;

    QPushButton*    dodajucznia;
    QPushButton*    dodajkonto;
    QPushButton*    dodajprzedmiot;
    QPushButton*    usunucznia;
    QPushButton*    usunkonto;
    QPushButton*    usunprzedmiot;


    Lista* comboxPrzedmioty;
    Lista* comboxKlasy;

    int X ;
    int Y ;
    int XElementInterface1;
    int YElementInterface1;
    int XElementInterface2;
    int YElementInterface2;
    int XElementInterface3;
    int YElementInterface3;
    int XElementInterface23;
    int IndeksKomorki     ;
    int LicznikWierszy    ;
    int LicznikOcenPojedynczegoUcznia;
    int NumerKolumnyPobieranej;
    int IndeksKolumny     ;
    int rola              ;

    QString klasa         ;
    QString przedmiot     ;
    QString nazwaBazy     ;
    // metody

    void polaczenie(QString a, QString b, QString c, QString d, int i);
    void classwindow();
    void tworzenieElementuPierwszego(QString i);
    void tworzenieElementuDrugiego(QString i);
    void tworzenieElementuDrugiegoPustego(QString i);
    void tworzenieElementuPierwszegoiTrzeciego(QString i);
    void tworzenieElementuTrzeciego();
    void dodawanieOcenTabela(int i);
    void dodawanieNazwKolumnTabela(int i);
    void tworzeniePaneluAdministratora();

    QString sklej();
    QString sklej1();

signals:
    void stworzPolaczeniezInputem();
    void stworzPolaczeniezInputemdlaDodatkowychKolumn();
    void zmianaStanu();
public slots:

    void tworzenieInputElement2(int value);
    void tworzenieInputElement3(int value);
    void zatwierdzzmiany();
    void dodajKolumne();
    void zmienKlase(QString value);
    void zmienPrzedmiot(QString value);

    void DodajUcznia();
    void UsunUcznia();
    void DodajKonto();
    void UsunKonto();
    void DodajPrzedmiot();
    void UsunPrzedmiot();

    void wprowadzDane();
    void usunDane();
    void dodajUzytkownik();
    void usunUzytkownik();
    void dodajPrzedmiot();
    void usunPrzedmiot();
private:




};

#endif // SCHOOL_H;

