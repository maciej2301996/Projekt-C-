#ifndef DODAJUCZEN_H
#define DODAJUCZEN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QValidator>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

class DodajUczen : public QGraphicsView
{   Q_OBJECT
public:
    DodajUczen(QWidget* parent=0);
    ~DodajUczen();


    QGraphicsScene* scene2;

    QLineEdit* Imie;
    QLineEdit* Nazwisko;
    QLineEdit* Klasa;

    QLabel* Imie1;
    QLabel* Nazwisko1;
    QLabel* Klasa1;

    QPushButton* Dodaj;
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


#endif // DODAJUCZEN_H
