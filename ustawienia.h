#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QValidator>
#include <QDebug>
#include <QMessageBox>

class Ustawienia: public QGraphicsView
{   Q_OBJECT
public:
    Ustawienia();

    QGraphicsScene* scenaUstawien ;

    QLabel* jednomasztowiec;
    QLabel* dwumasztowiec;
    QLabel* trojmasztowiec;
    QLabel* czteromasztowiec;

    QLineEdit* jednomasztowiec1;
    QLineEdit* dwumasztowiec1;
    QLineEdit* trojmasztowiec1;
    QLineEdit* czteromasztowiec1;

    QPushButton* cofnij ;
    QPushButton* zastosuj;

    void widokUstawien();
public slots:
    void Zastosuj();

};

#endif // USTAWIENIA_H
