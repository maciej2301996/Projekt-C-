#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

class Logowanie : public QGraphicsView
{   Q_OBJECT
public:
    // konstruktor

    Logowanie(QWidget* parent=0);

    // dekonstruktor

    ~Logowanie();

    //atrybuty


    QGraphicsScene* scene;
    QGraphicsScene* scene1;

    QSqlDatabase db;

    QLineEdit* Uzytkownik;
    QLineEdit* Haslo;
    QLineEdit* NazwaHosta;
    QLineEdit* NazwaBazyDaych;
    QLineEdit* NazwaUzytkownika;
    QLineEdit* Haslo1;

    QLabel* opisUzytkownik;
    QLabel* opisHaslo;
    QLabel* opisNazwaHosta;
    QLabel* opisNazwaBazyDaych;
    QLabel* opisNazwaUzytkownika;
    QLabel* opisHaslo1;

    QString ustawionaNazwaHosta;
    QString ustawionaNazwaBazyDaych;
    QString ustawionaNazwaUzytkownika;
    QString ustawioneHaslo;
    QString nazwaPliku;

    QPushButton* Zaloguj;
    QPushButton* polacz;
    // metody
    void polaczenie();
    void interface();
    void interface2();
    void bazadaych();
    void wczytaj();
signals:

public slots:
    void sprawdz();
    void danebazy();
 private:
};

#endif // LOGOWANIE_H
