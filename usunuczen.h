#ifndef USUNUCZEN_H
#define USUNUCZEN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

class UsunUczen: public QGraphicsView
{   Q_OBJECT
public:
    UsunUczen(QWidget* parent=0);
    ~UsunUczen();


    QGraphicsScene* scene2;

    QLineEdit* Imie;
    QLineEdit* Nazwisko;
    QLineEdit* Klasa;

    QLabel* Imie1;
    QLabel* Nazwisko1;
    QLabel* Klasa1;

    QPushButton* Usun;
    QPushButton* Anuluj;

    QString imie;
    QString nazwisko;
    QString klasa;

    void interface();
signals:
    void sygnal();

public slots:
    void wprowadzdane();
    void zamknijokno();

private:
};

#endif // USUNUCZEN_H
