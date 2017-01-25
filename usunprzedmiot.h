#ifndef USUNPRZEDMIOT_H
#define USUNPRZEDMIOT_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QValidator>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

class UsunPrzedmiot :public QGraphicsView
{   Q_OBJECT
public:
    UsunPrzedmiot(QWidget* parent=0);

    QGraphicsScene* scene2;

    QLineEdit* Klasa;
    QLineEdit* Przedmiot;


    QLabel* Klasa1;
    QLabel* Przedmiot1;

    QPushButton* Dodaj;
    QPushButton* Anuluj;

    QString klasa;
    QString przedmiot;



    void interface();
signals:
    void sygnal();

public slots:
    void wprowadzdane();
    void zamknijokno();
};


#endif // USUNPRZEDMIOT_H
