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
#include <QVariant>

#include "addfunction.h"
#include "interface1.h"
#include "interface2.h"
#include "interface3.h"


class School : public QGraphicsView{
    Q_OBJECT
public:
    // konstruktor
    School(QWidget* parent=0);


    // dekonsturktor
    ~School();

    // metody
    void drawTabel();
    void addCombos();
    void connect();

    // attrybuty
    QGraphicsScene* scene;
    QSqlDatabase db;
    QComboBox* combo;
    QComboBox* combo1;
    QString nazwa;
public slots:
    //void QComboBox::currentIndexChanged(const QString);

};

#endif // SCHOOL_H
