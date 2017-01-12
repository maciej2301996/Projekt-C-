#ifndef DODAJUZYTKOWNIK_H
#define DODAJUZYTKOWNIK_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QValidator>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

class DodajUzytkownik : public QGraphicsView
{   Q_OBJECT
public:
    DodajUzytkownik(QWidget* parent=0);
    ~DodajUzytkownik();

    QGraphicsScene* scene2;

    QLineEdit* Imie;
    QLineEdit* Nazwisko;
    QLineEdit* Login;
    QLineEdit* Haslo;
    QLineEdit* Rola;

    QLabel* Imie1;
    QLabel* Nazwisko1;
    QLabel* Login1;
    QLabel* Haslo1;
    QLabel* Rola1;

    QPushButton* Dodaj;
    QPushButton* Anuluj;

    QString imie;
    QString nazwisko;
    QString login;
    QString haslo;
    QString rola;


    void interface();
signals:
    void sygnal();

public slots:
    void wprowadzdane();
    void zamknijokno();
};

#endif // DODAJUZYTKOWNIK_H
