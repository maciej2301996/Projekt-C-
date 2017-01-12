#include "usunprzedmiot.h"
#include "school.h"
extern School* school;

UsunPrzedmiot::UsunPrzedmiot(QWidget*)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,400,300);
    setScene(scene2);
}

void UsunPrzedmiot::interface()
{
    Przedmiot      = new QLineEdit();
    Klasa       = new QLineEdit();

    Dodaj       = new QPushButton("Usuń");
    Anuluj      = new QPushButton("Anuluj");


    Przedmiot1   = new QLabel("Przedmiot ucznia");
    Klasa1      = new QLabel("Klasa ucznia");

    Klasa->setGeometry(180,70,100,20);
    Przedmiot->setGeometry(180,100,100,20);


    QRegExp zakresQLineEdit("[1-9]{0,1}[a-z]{1,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    Klasa->setValidator(validator);

    Klasa1->setGeometry(80,70,100,20);
    Przedmiot1->setGeometry(80,100,100,20);


    Dodaj->setGeometry(130,130,50,25);
    Dodaj->setFixedSize(50,25);
    Anuluj->setGeometry(210,130,50,25);
    Anuluj->setFixedSize(50,25);

    this->scene2->addWidget(Przedmiot) ;
    this->scene2->addWidget(Klasa);

    this->scene2->addWidget(Przedmiot1);
    this->scene2->addWidget(Klasa1);

    this->scene2->addWidget(Dodaj);
    this->scene2->addWidget(Anuluj);

    QObject::connect(Anuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijokno()));
    QObject::connect(Dodaj,SIGNAL(clicked(bool)),this,SLOT(wprowadzdane()));
    QObject::connect(this,SIGNAL(sygnal()),school,SLOT(usunPrzedmiot()));
}

void UsunPrzedmiot::wprowadzdane()
{

}

void UsunPrzedmiot::zamknijokno()
{

}
