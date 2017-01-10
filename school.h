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
#include "przyciskclasswindow.h"
#include "lista.h"


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
    QList<QGraphicsProxyWidget*> inputlist1;

    PrzyciskClassWindow*      buttonZatwierdzZmiany;
    PrzyciskClassWindow*      buttonDodajKolumne;

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



    QString klasa         ;
    QString przedmiot     ;

    // metody

    void polaczenie();
    void classwindow();
    void tworzenieElementuPierwszego(QString i);
    void tworzenieElementuDrugiego(QString i);
    void tworzenieElementuDrugiegoiTrzeciego(QString i);
    void tworzenieElementuPierwszegoiTrzeciego(QString i);

    QString sklej();
    QString sklej1();

signals:
    void stworzPolaczeniezInputem();
    void stworzPolaczeniezInputemdlaDodatkowychKolumn();
    void zmianaStanu();
public slots:

    void proba(int value);
    void zbieranie();
    void zatwierdzzmiany();
    void dodajKolumne();
    void zmienKlase(QString value);
    void zmienPrzedmiot(QString value);

private:




};

#endif // SCHOOL_H;

