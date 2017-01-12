#include "dodajuczen.h"
#include "school.h"

extern School* school;

DodajUczen::DodajUczen(QWidget* )
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,400,300);
    setScene(scene2);
}

DodajUczen::~DodajUczen()
{

}

void DodajUczen::interface()
{
    Imie        = new QLineEdit();
    Nazwisko    = new QLineEdit();
    Klasa       = new QLineEdit();

    Dodaj       = new QPushButton("Dodaj");
    Anuluj      = new QPushButton("Anuluj");

    Imie1       = new QLabel("Imię ucznia");
    Nazwisko1   = new QLabel("Nazwisko ucznia");
    Klasa1      = new QLabel("Klasa ucznia");

    Imie->setGeometry(180,70,100,20);
    Nazwisko->setGeometry(180,100,100,20);
    Klasa->setGeometry(180,130,100,20);

    QRegExp zakresQLineEdit("[1-9]{0,1}[a-z]{1,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    Klasa->setValidator(validator);

    Imie1->setGeometry(80,70,100,20);
    Nazwisko1->setGeometry(80,100,100,20);
    Klasa1->setGeometry(80,130,100,20);

    Dodaj->setGeometry(130,160,50,25);
    Dodaj->setFixedSize(50,25);
    Anuluj->setGeometry(210,160,50,25);
    Anuluj->setFixedSize(50,25);

    this->scene2->addWidget(Imie) ;
    this->scene2->addWidget(Nazwisko);
    this->scene2->addWidget(Klasa);

    this->scene2->addWidget(Imie1);
    this->scene2->addWidget(Nazwisko1);
    this->scene2->addWidget(Klasa1);

    this->scene2->addWidget(Dodaj);
    this->scene2->addWidget(Anuluj);

    QObject::connect(Anuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijokno()));
    QObject::connect(Dodaj,SIGNAL(clicked(bool)),this,SLOT(wprowadzdane()));
    QObject::connect(this,SIGNAL(sygnal()),school,SLOT(wprowadzDane()));
}

void DodajUczen::wprowadzdane()
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

void DodajUczen::zamknijokno()
{
   this->hide();
}
