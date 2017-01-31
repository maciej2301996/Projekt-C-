#include "ustawienia.h"
#include "Game.h"

extern Game* game;
Ustawienia::Ustawienia()
{
}
void Ustawienia::widokUstawien()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Ustawienia"));
    QFont titleFont("Times New Roman",55);
    titleText->setFont(titleFont);
    int textxPos = 780;
    int textyPos = 270;
    titleText->setPos(textxPos,textyPos);
    game->scenaUstawien->addItem(titleText);

    jednomasztowiec = new QLabel("Ilość jednomasztowców");
    dwumasztowiec   = new QLabel("Ilość dwumasztowców");
    trojmasztowiec  = new QLabel("Ilość trójmasztowców");
    czteromasztowiec= new QLabel("Ilość czteromasztowców");

    jednomasztowiec1 = new QLineEdit();
    dwumasztowiec1   = new QLineEdit();
    trojmasztowiec1  = new QLineEdit();
    czteromasztowiec1= new QLineEdit();

    cofnij = new QPushButton("Wróć do menu");
    zastosuj  = new QPushButton("Zastosuj zmiany");

    jednomasztowiec->setFixedSize(120,40);
    dwumasztowiec->setFixedSize(120,40);
    trojmasztowiec->setFixedSize(120,40);
    czteromasztowiec->setFixedSize(120,40);

    jednomasztowiec->setGeometry(800,390,120,40);
    dwumasztowiec->setGeometry(800,450,120,40);
    trojmasztowiec->setGeometry(800,510,120,40);
    czteromasztowiec->setGeometry(800,570,120,40);


    jednomasztowiec1->setGeometry(970,390,120,40);
    dwumasztowiec1->setGeometry(970,450,120,40);
    trojmasztowiec1->setGeometry(970,510,120,40);
    czteromasztowiec1->setGeometry(970,570,120,40);

    cofnij->setGeometry(800,630,120,40);
    zastosuj->setGeometry(970,630,120,40);

    QObject::connect(cofnij,SIGNAL(clicked(bool)),game,SLOT(wrocDoMenu()));
    QObject::connect(zastosuj,SIGNAL(clicked(bool)),this,SLOT(Zastosuj()));

    QRegExp zakresQLineEdit("[1-4]{0,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    jednomasztowiec1->setValidator(validator);

    QRegExp zakres1QLineEdit("[0-3]{0,1}");
    QValidator *validator1 = new QRegExpValidator(zakres1QLineEdit,this);
    dwumasztowiec1->setValidator(validator1);

    QRegExp zakres2QLineEdit("[0-2]{0,1}");
    QValidator *validator2 = new QRegExpValidator(zakres2QLineEdit,this);
    trojmasztowiec1->setValidator(validator2);

    QRegExp zakres3QLineEdit("[0-1]{0,1}");
    QValidator *validator3 = new QRegExpValidator(zakres3QLineEdit,this);
    czteromasztowiec1->setValidator(validator3);

    game->scenaUstawien->addWidget(jednomasztowiec);
    game->scenaUstawien->addWidget(dwumasztowiec);
    game->scenaUstawien->addWidget(trojmasztowiec);
    game->scenaUstawien->addWidget(czteromasztowiec);
    game->scenaUstawien->addWidget(jednomasztowiec1);
    game->scenaUstawien->addWidget(dwumasztowiec1);
    game->scenaUstawien->addWidget(trojmasztowiec1);
    game->scenaUstawien->addWidget(czteromasztowiec1);
    game->scenaUstawien->addWidget(cofnij);
    game->scenaUstawien->addWidget(zastosuj);

}
void Ustawienia::Zastosuj()
{
   QString iloscjednomasztowcow = jednomasztowiec1->text();
   QString iloscdwumasztowcow   = dwumasztowiec1->text();
   QString ilosctrzymasztowcow  = trojmasztowiec1->text();
   QString iloscczteromasztowcow= czteromasztowiec1->text();

   if(iloscjednomasztowcow != "")
   {
       game->iloscJednomasztowcow = iloscjednomasztowcow.toInt() ;
   }

   if(iloscdwumasztowcow  != "")
   {
       game->iloscDwumasztowcow = iloscdwumasztowcow.toInt() ;
   }

   if(ilosctrzymasztowcow != "")
   {
       game->iloscTrojmasztowcow = ilosctrzymasztowcow.toInt()  ;
   }

   if(iloscczteromasztowcow != "")
   {
       game->iloscCzteromasztowcow = iloscczteromasztowcow.toInt()  ;
   }

   QMessageBox::information(this,"Zmian","Dokonano zmiany ilości okrętów");
}



