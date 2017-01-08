#ifndef SCHOOL_H
#define SCHOOL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QString>

#include "interfaceelement1.h"
#include "interfaceelement2.h"
#include "interfaceelement3.h"
#include "input.h"

class School : public QGraphicsView
{ Q_OBJECT

public :
    // konstruktor

    School(QWidget* parent=0);

    // dekonstruktor

    ~School();

    // metody

    void polaczenie();
    void classwindow();
    //atrybuty

    QGraphicsScene* scene;
    QSqlDatabase db;
    QList<InterfaceElement1*> elementlist1;
    QList<InterfaceElement3*> elementlist3;
    QList<InterfaceElement2*> elementlist2;
    QList<Input*>             inputlist;


signals:

public slots:
    void proba();


private:





};

#endif // SCHOOL_H;

