#include "usunuzytkownik.h"
#include "school.h"
extern School* school;

UsunUzytkownik::UsunUzytkownik(QWidget*)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,400,300);
    setScene(scene2);
}

void UsunUzytkownik::interface()
{
    Imie        = new QLineEdit();
    Nazwisko    = new QLineEdit();
    Login       = new QLineEdit();
    Haslo       = new QLineEdit();
    Rola        = new QLineEdit();

    Dodaj       = new QPushButton("Dodaj");
    Anuluj      = new QPushButton("Anuluj");

    Imie1       = new QLabel("Imię użytkownika");
    Nazwisko1   = new QLabel("Nazwisko użytkownika");
    Login1     = new QLabel("Login użytkownika");
    Haslo1     = new QLabel("Haslo użytkownika");
    Rola1      = new QLabel("Rola użytkownika");

    Imie->setGeometry(180,70,100,20);
    Nazwisko->setGeometry(180,100,100,20);
    Login->setGeometry(180,130,100,20);
    Haslo->setGeometry(180,160,100,20);
    Rola->setGeometry(180,190,100,20);

    QRegExp zakresQLineEdit("[0-1]{0,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    Rola->setValidator(validator);

    Imie1->setGeometry(60,70,100,20);
    Nazwisko1->setGeometry(60,100,100,20);
    Login1->setGeometry(60,130,100,20);
    Haslo1->setGeometry(60,160,100,20);
    Rola1->setGeometry(60,190,100,20);

    Dodaj->setGeometry(130,230,50,25);
    Dodaj->setFixedSize(50,25);
    Anuluj->setGeometry(210,230,50,25);
    Anuluj->setFixedSize(50,25);

    Haslo->setEchoMode(QLineEdit::Password);

    this->scene2->addWidget(Imie) ;
    this->scene2->addWidget(Nazwisko);
    this->scene2->addWidget(Login);
    this->scene2->addWidget(Haslo);
    this->scene2->addWidget(Rola);

    this->scene2->addWidget(Imie1);
    this->scene2->addWidget(Nazwisko1);
    this->scene2->addWidget(Login1);
    this->scene2->addWidget(Haslo1);
    this->scene2->addWidget(Rola1);

    this->scene2->addWidget(Dodaj);
    this->scene2->addWidget(Anuluj);

    QObject::connect(Anuluj,SIGNAL(clicked(bool)),this,SLOT(zamknijokno()));
    QObject::connect(Dodaj,SIGNAL(clicked(bool)),this,SLOT(wprowadzdane()));
    QObject::connect(this,SIGNAL(sygnal()),school,SLOT(usunUzytkownik()));
}

void UsunUzytkownik::wprowadzdane()
{
    imie = Imie->text();
    nazwisko = Nazwisko->text();
    login = Login->text();
    haslo = Haslo->text();
    rola = Rola->text();

    if(Imie->text() != "" && Nazwisko->text() != "" && Rola->text().size() ==1 && Login->text() != "" && Haslo->text() != "")
    {

        emit sygnal();
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"Błąd","Wprowadzone dane są błędne. Pamiętaj,że wszystkie pola muszą być wypełnione");
    }
}

void UsunUzytkownik::zamknijokno()
{
    this->hide();
}
