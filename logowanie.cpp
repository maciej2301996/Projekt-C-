#include "logowanie.h"
#include "school.h"

extern School* school;

Logowanie::Logowanie(QWidget*)
{
    nazwaPliku = "DaneSerwera.txt";
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);

    // ustawienia sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,400,300);


    scene1 = new QGraphicsScene();
    scene1->setSceneRect(0,0,400,300);

}
Logowanie::~Logowanie()
{

}
void Logowanie::polaczenie()
{

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName(ustawionaNazwaHosta);
    db.setDatabaseName(ustawionaNazwaBazyDaych);
    db.setUserName(ustawionaNazwaUzytkownika);
    db.setPassword(ustawioneHaslo);

    if(!db.open())
            qDebug() << "Nieudane polaczenie z baza danych";
    else
        {
            qDebug() << "Polaczenie z baza danych udało sie";
            setScene(scene);
            interface();

    }
}
void Logowanie::interface()
{
    Uzytkownik = new QLineEdit();
    Uzytkownik->setGeometry(180,100,100,20);

    Haslo = new QLineEdit();
    Haslo->setGeometry(180,130,100,20);
    Haslo->setEchoMode(QLineEdit::Password);

    opisUzytkownik = new QLabel("Login");
    opisUzytkownik->setGeometry(140,100,40,20);

    opisHaslo = new QLabel("Hasło");
    opisHaslo->setGeometry(140,130,40,20);

    Zaloguj = new QPushButton("Zaloguj");
    Zaloguj->setGeometry(195,160,50,25);
    Zaloguj->setFixedSize(50,25);

    scene->addWidget(Uzytkownik);
    scene->addWidget(Haslo);
    scene->addWidget(opisUzytkownik);
    scene->addWidget(opisHaslo);
    scene->addWidget(Zaloguj);

    QObject::connect(Zaloguj,SIGNAL(clicked()),this,SLOT(sprawdz()));

}
void Logowanie::interface2()
{
    NazwaHosta       = new QLineEdit();
    NazwaBazyDaych   = new QLineEdit();
    NazwaUzytkownika = new QLineEdit();
    Haslo1           = new QLineEdit();

    opisNazwaHosta       = new QLabel("Nazwa Hosta");
    opisNazwaBazyDaych   = new QLabel("Nazwa Bazy Daych");
    opisNazwaUzytkownika = new QLabel("Nazwa Uzytkownika");
    opisHaslo1           = new QLabel("Haslo");

    polacz = new QPushButton("Połącz");

    NazwaHosta->setGeometry(180,70,100,20);
    NazwaBazyDaych->setGeometry(180,100,100,20);
    NazwaUzytkownika->setGeometry(180,130,100,20);
    Haslo1->setGeometry(180,160,100,20);

    opisNazwaHosta->setGeometry(80,70,100,20);
    opisNazwaBazyDaych->setGeometry(80,100,100,20);
    opisNazwaUzytkownika->setGeometry(80,130,100,20);
    opisHaslo1->setGeometry(80,160,100,20);

    polacz->setGeometry(195,190,50,25);

    Haslo1->setEchoMode(QLineEdit::Password);

    scene1->addWidget(opisNazwaHosta);
    scene1->addWidget(opisNazwaBazyDaych);
    scene1->addWidget(opisNazwaUzytkownika);
    scene1->addWidget(opisHaslo1);

    scene1->addWidget(NazwaHosta);
    scene1->addWidget(NazwaBazyDaych);
    scene1->addWidget(NazwaUzytkownika);
    scene1->addWidget(Haslo1);

    scene1->addWidget(polacz);

    QObject::connect(polacz,SIGNAL(clicked()),this,SLOT(danebazy()));
}
void Logowanie::bazadaych()
{
    QFile plik(nazwaPliku);
    //plik.open(QIODevice::ReadOnly );
    if(plik.open(QIODevice::ReadOnly))
    {

        qDebug() << "Plik istnieje";
        wczytaj();
    }
    else
    {
        setScene(scene1);
        qDebug() << "Plik nie istnieje";
        interface2();
    }
    plik.close();
}
void Logowanie::wczytaj()
{


    QFile plik(nazwaPliku);
    plik.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents = plik.readAll().constData();;
    plik.close();
    QStringList a = contents.split(QRegExp("\n"));
    ustawionaNazwaHosta          = a[0];
    ustawionaNazwaBazyDaych      = a[1];
    ustawionaNazwaUzytkownika    = a[2];
    ustawioneHaslo               = a[3];

    polaczenie();
}
void Logowanie::sprawdz()
{
    QString uzytkownik;
    QString haslo;
    QSqlQuery polecenie;

    uzytkownik = this->Uzytkownik->text();
    haslo      = this->Haslo->text();

    if(!db.isOpen())
    {
        qDebug() << "nie otwarto";
    }

    if(polecenie.exec("SELECT * from Logowanie where Login='"+ uzytkownik +"' and Hasło='"+ haslo +"'"))
    {
        int licz = 0;
        while(polecenie.next())
        {
            licz++;
        }
            if(licz == 1)
            {
                int rola = polecenie.value(5).toInt();
                school->show();
                school->polaczenie(ustawionaNazwaHosta,ustawionaNazwaBazyDaych,ustawionaNazwaUzytkownika,ustawioneHaslo,rola);
                school->classwindow();

                this->hide();
            }
            else
            {
                QMessageBox::information(this,"Błąd","Błędny Login lub Hasło");

            }



    }

}
void Logowanie::danebazy()
{
    ustawionaNazwaHosta       = NazwaHosta->text() ;
    ustawionaNazwaBazyDaych   = NazwaBazyDaych->text();
    ustawionaNazwaUzytkownika = NazwaUzytkownika->text();
    ustawioneHaslo            = Haslo1->text();

    QFile plik(nazwaPliku);
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream(&plik);
    stream << ustawionaNazwaHosta << endl;
    stream << ustawionaNazwaBazyDaych << endl;
    stream << ustawionaNazwaUzytkownika << endl;
    stream << ustawioneHaslo << endl;
    plik.close();
    polaczenie();
}
