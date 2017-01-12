#ifndef LISTA_H
#define LISTA_H

#include <QObject>
#include <QComboBox>
#include <QSqlDatabase>
#include <QDebug>


class Lista :  public QComboBox
{
public:
    Lista(int X,int Y,int I,QSqlDatabase db);
    ~Lista();


    int         numer;

    QSqlDatabase tablica;

    QStringList a;
    QStringList napis;
    QStringList tables;
signals:



private:

};

#endif // LISTA_H
