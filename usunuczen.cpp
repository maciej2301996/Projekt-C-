#include "usunuczen.h"
#include "school.h"

extern School* school;

UsunUczen::UsunUczen(QWidget*)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,400,300);
    setScene(scene2);
}

UsunUczen::~UsunUczen()
{

}

void UsunUczen::interface()
{
    Imie        = new QLineEdit();
    Nazwisko    = new QLineEdit();
    Klasa       = new QLineEdit();

    Usun        = new QPushButton("Usun");
    Anuluj      = new QPushButton("Anuluj");

    Imie1       = new QLabel("Imię ucznia");
    Nazwisko1   = new QLabel("Nazwisko ucznia");
    Klasa1      = new QLabel("Klasa ucznia");

    Imie->setGeometry(180,70,100,20);
    Nazwisko->setGeometry(180,100,100,20);
    Klasa->setGeometry(180,130,100,20);

    Imie1->setGeometry(80,70,100,20);
    Nazwisko1->setGeometry(80,100,100,20);
    Klasa1->setGeometry(80,130,100,20);

    Usun->setGeometry(130,160,50,25);
    Usun->setFixedSize(50,25);
    Anuluj->setGeometry(210,160,50,25);
    Anuluj->setFixedSize(50,25);
    this->scene2->addWidget(Imie) ;
    this->scene2->addWidget(Nazwisko);
    this->scene2->addWidget(Klasa);

    this->scene2->addWidget(Imie1);
    this->scene2->addWidget(Nazwisko1);
    this->scene2->addWidget(Klasa1);

    this->scene2->addWidget(Usun);
    this->scene2->addWidget(Anuluj);

    QObject::connect(Anuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijokno()));
    QObject::connect(Usun,SIGNAL(clicked(bool)),this,SLOT(wprowadzdane()));
    QObject::connect(this,SIGNAL(sygnal()),school,SLOT(usunDane()));
}

void UsunUczen::wprowadzdane()
{
    imie = Imie->text();
    nazwisko = Nazwisko->text();
    klasa = Klasa->text();

    if(Imie->text() != "" && Nazwisko->text() != "" && Klasa->text().size() ==2)
    {

        emit sygnal();
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"Błąd","Wprowadzone dane są błędne. Pamiętaj,że wszystkie pola muszą być wypełnione. Pole Klasa musi się składać z 2 znaków. Pierwsza musi być cyfra a druga litera");
    }
}

void UsunUczen::zamknijokno()
{
    this->hide();
}
