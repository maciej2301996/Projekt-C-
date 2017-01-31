#include "Game.h"
#include "ustawienia.h"




extern Ustawienia* ustawienia ;

Game::Game(QWidget *)
{
    // ustawienia ekranu
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1910,1000);

    // ustawienia sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1910,1000);
    setScene(scene);

    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,1910,1000);

    scenaKoncowa = new QGraphicsScene();
    scenaKoncowa->setSceneRect(0,0,1910,1000);

    iloscJednomasztowcow = 1;
    iloscDwumasztowcow = 1;
    iloscTrojmasztowcow = 1;
    iloscCzteromasztowcow =1;

    wczytuje = false ;

    obrazekjednomasztowca  = "C:\\Users\\user\\Desktop\\IPP\\jednomasztowiec.png";
    obrazekdwumasztowca    = "C:\\Users\\user\\Desktop\\IPP\\dwumasztowiec.png";
    obrazektrojmasztowca   = "C:\\Users\\user\\Desktop\\IPP\\trojmasztowiec.png";
    obrazekczteromasztowca = "C:\\Users\\user\\Desktop\\IPP\\czteromasztowiec.png";

    obrazekjednomasztowcaobrocony = "C:\\Users\\user\\Desktop\\IPP\\jednomasztowiecpionowo.png";
    obrazekdwumasztowcaobrocony   = "C:\\Users\\user\\Desktop\\IPP\\dwumasztowiecpionowo.png";
    obrazektrojmasztowcaobrocony  = "C:\\Users\\user\\Desktop\\IPP\\trojmasztowiecpionowo.png";
    obrazekczteromasztowcaobrocony= "C:\\Users\\user\\Desktop\\IPP\\czteromasztowiecpionowo.png";

    rodzajStatku = 1;

    ktoryStatekObrocic = 0;

    rozstawionychStatkow = 0;

    fazaGry = 0;
    liczbaPunktow = 100 ;
    rozlacz = false ;
}
Game::~Game()
{

}
void Game::gamemenu()
{
    //tworzenie tytułu gry
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Statki"));
    QFont titleFont("Times New Roman",55);
    titleText->setFont(titleFont);
    int textxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int textyPos = this->height()/6;
    titleText->setPos(textxPos,textyPos);
    scene->addItem(titleText);


    // tworzenie przyciskow

    // przycisk gry
    Button* playButton = new Button(QString("Graj"));
    int button1xPos = this->width()/2 - playButton->boundingRect().width()/2;
    int button1yPos = this->height() * 2 /6;
    playButton->setPos(button1xPos,button1yPos);
    QObject::connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // przycisk opcji
    Button* optionButton = new Button(QString("Opcje"));
    int button3xPos = this->width()/2 - optionButton->boundingRect().width()/2;
    int button3yPos = this->height() * 2 /6 + 80;
    QObject::connect(optionButton,SIGNAL(clicked()),this,SLOT(ustawScene()));
    optionButton->setPos(button3xPos,button3yPos);
    scene->addItem(optionButton);

    // przycisk instrukcji
    Button* instructionButton = new Button(QString("Wczytaj"));
    int button2xPos = this->width()/2 - instructionButton->boundingRect().width()/2;
    int button2yPos = this->height() * 2 /6 + 160;
    QObject::connect(instructionButton,SIGNAL(clicked()),this,SLOT(wczytajZapis()));
    instructionButton->setPos(button2xPos,button2yPos);
    scene->addItem(instructionButton);

    // przycisk wyjscia
    Button* quitButton = new Button(QString("Wyjście"));
    int button4xPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int button4yPos = this->height() * 2 /6  + 240;
    QObject::connect(quitButton, SIGNAL (clicked()), qApp, SLOT (quit()));
    quitButton->setPos(button4xPos,button4yPos);
    scene->addItem(quitButton);
}
void Game::dodawanieStatkow(QString a)
{
    frame = new Okret(a);
    QObject::connect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
    frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
    scene2->addWidget(frame);
}
void Game::rozstawianieStatkow()
{

  if(rodzajStatku == 1)
  { ktoryStatekObrocic = 0;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaJednomasztowcow > 0)
    {
        dodawanieStatkow(obrazekjednomasztowca);
        liczbaDoRozstawieniaJednomasztowcow = liczbaDoRozstawieniaJednomasztowcow - 1;
        iloscStatkow = iloscStatkow -1 ;
    }
    else{

        rodzajStatku += 1;
    }
    qDebug() << liczbaDoRozstawieniaJednomasztowcow;

  }

  if(rodzajStatku == 2)
  { ktoryStatekObrocic = 1;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaDwumasztowcow != 0)
    {
        dodawanieStatkow(obrazekdwumasztowca);
        liczbaDoRozstawieniaDwumasztowcow = liczbaDoRozstawieniaDwumasztowcow - 1;
        iloscStatkow = iloscStatkow -1 ;
    }
    else{
        rodzajStatku +=1;
    }
    qDebug() << liczbaDoRozstawieniaDwumasztowcow;
  }

  if(rodzajStatku == 3)
  { ktoryStatekObrocic = 2;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaTrojmasztowcow != 0)
    {
        dodawanieStatkow(obrazektrojmasztowca);
        liczbaDoRozstawieniaTrojmasztowcow =liczbaDoRozstawieniaTrojmasztowcow - 1;
        iloscStatkow = iloscStatkow -1 ;
    }
    else
    {
        rodzajStatku +=1;
    }
  qDebug() << liczbaDoRozstawieniaTrojmasztowcow;
  }

  if(rodzajStatku == 4)
  { ktoryStatekObrocic = 3;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaCzteromasztowcow != 0)
    {
        dodawanieStatkow(obrazekczteromasztowca);
        liczbaDoRozstawieniaCzteromasztowcow =liczbaDoRozstawieniaCzteromasztowcow - 1;
        iloscStatkow = iloscStatkow -1 ;
    }
    else
    {
        rodzajStatku +=1;
    }
   qDebug() <<  liczbaDoRozstawieniaCzteromasztowcow;
  }

}
void Game::rozstawianieStatkowKomputera()
{
    int losowaOrientacja;
    for(int i = 0; i < iloscJednomasztowcow; i++)
    {
        sprawdzRuchKomputera(obrazekjednomasztowca,losowaOrientacja,1);
        losowaOrientacja = qrand() % 2;
    }

    for(int i = 0; i < iloscDwumasztowcow; i++)
    {
        sprawdzRuchKomputera(obrazekdwumasztowca,losowaOrientacja,2);
        losowaOrientacja = qrand() % 2;
    }
    for(int i = 0; i < iloscTrojmasztowcow; i++)
    {
        sprawdzRuchKomputera(obrazektrojmasztowca,losowaOrientacja,3);
        losowaOrientacja = qrand() % 2;
    }
    for(int i = 0; i < iloscCzteromasztowcow; i++)
    {
        sprawdzRuchKomputera(obrazekczteromasztowca,losowaOrientacja,4);
        losowaOrientacja = qrand() % 2;
    }
    plansza();
    fazaGry = 1 ;
}
void Game::sprawdzRuchKomputera(QString obrazek,int losowaOrientacja,int liczbaMasztow)
{
    int wysokosc ;
    int szerokosc;

    int losowaX = qrand() % 10 + 1 ;
    int losowaY = qrand() % 10 + 1 ;

    QPixmap pix(obrazek);

    bool ustawWTablicy = false;

    wysokosc = pix.height()/40;
    szerokosc = pix.width()/40;

    if(losowaOrientacja == 1)
    {

        wysokosc = pix.width()/40 ;
        szerokosc = pix.height()/40;
    }

    for(int i = -1; i < ((wysokosc)+1);i++)
        for(int j =-1; j < ((szerokosc)+1);j++)
        {
           if(tablicaRozstawieniaStatkowGracza2[losowaX+j][losowaY+i] == " ")
           {
             ustawWTablicy = true ;
           }
           else
           {

             ustawWTablicy = false;
             i = wysokosc+1;
             j = szerokosc +1;
           }

        }

    if((losowaX + szerokosc)-1 > 10 )
    {
       ustawWTablicy = false;
    }

    if((losowaY + wysokosc)-1 > 10 )
    {
       ustawWTablicy = false;
    }


    if(ustawWTablicy == true)
    {
        for(int i = 0; i < ((wysokosc));i++)
            for(int j = 0; j < ((szerokosc));j++)
            {
                tablicaRozstawieniaStatkowGracza2[losowaX+j][losowaY+i] = QString::number(liczbaMasztow) ;

            }
        rozstawionychStatkow += 1;
    }
    else
    {
        sprawdzRuchKomputera(obrazek,(qrand()%2),liczbaMasztow);
    }


}
void Game::strzelanieKomputera()
{
    if(fazaGry == 2)
    {
        int a = qrand() % 10 + 1;
        int b = qrand() % 10 + 1;

        if(tablicaRozstawieniaStatkowGracza1[a][b] == " " &&  tablicaStrzelaniaGracza2[a][b] == " " )
           {
            tablicaStrzelaniaGracza2[a][b] = '0' ;
            emit strzalKomputera(false,a,b);
            liczbaRuchowKomputera ++ ;
           }
        else if(tablicaStrzelaniaGracza2[a][b] == " ")
        {
            tablicaStrzelaniaGracza2[a][b] = tablicaRozstawieniaStatkowGracza1[a][b];
            liczbaPunktow = liczbaPunktow - 10 ;
            liczbaRuchowKomputera ++ ;
            sprawdzanieZatopienKomputera();
            rysowanieTabelki();
            czyKtosWygral2();
            emit strzalKomputera(true,a,b);
        }
        else
        {
            strzelanieKomputera();
        }

    }
}
void Game::czyKtosWygral1()
{
    bool wygrana = false;
    for(int i = 0; i < 11 ;i++)
        for(int j = 0; j < 11; j++)
        {
           if(tablicaRozstawieniaStatkowGracza2[j][i] == tablicaStrzelaniaGracza1[j][i]  || tablicaRozstawieniaStatkowGracza2[j][i] == " ")
           {
               wygrana = true ;
           }
           else
           {
               wygrana = false;
               j = 11;
               i = 11;
           }
        }

    if(wygrana == true)
    {   QFont titleFont("Times New Roman",55);

        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Wygrałeś"));
        titleText->setFont(titleFont);
        int textxPos = 780;
        int textyPos = 270;
        titleText->setPos(textxPos,textyPos);
        scenaKoncowa->addItem(titleText);

        liczbaPunktow = liczbaPunktow - liczbaRuchowGracza + liczbaRuchowKomputera ;

        QGraphicsTextItem* titleText1 = new QGraphicsTextItem(QString( "Twoj wynik to:"));
        titleText1->setFont(titleFont);
        int textxPos1 = 700;
        int textyPos1 = 360;
        titleText1->setPos(textxPos1,textyPos1);
        scenaKoncowa->addItem(titleText1);

        QGraphicsTextItem* titleText2 = new QGraphicsTextItem(QString( QString::number(liczbaPunktow) ));
        titleText2->setFont(titleFont);
        int textxPos2 = 850;
        int textyPos2 = 450;
        titleText2->setPos(textxPos2,textyPos2);
        scenaKoncowa->addItem(titleText2);

        QPushButton* wroc = new QPushButton("Powrót do menu");
        wroc->setGeometry(830,700,120,30);
        QObject::connect(wroc,SIGNAL(clicked()),this,SLOT(wrocDoMenu()));
        scenaKoncowa->addWidget(wroc);

        setScene(scenaKoncowa);
    }

}
void Game::czyKtosWygral2()
{
    bool wygrana = false;
    for(int i = 0; i < 11 ;i++)
       for(int j = 0; j < 11; j++)
       {
         if(tablicaRozstawieniaStatkowGracza1[j][i] == tablicaStrzelaniaGracza2[j][i] || tablicaRozstawieniaStatkowGracza1[j][i] == " ")
           {
              wygrana = true;
           }
         else
           {
              wygrana = false;
              j = 11;
              i = 11;
           }
       }
       if(wygrana == true)
            {
           QFont titleFont("Times New Roman",55);

                   QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Przegrałeś"));
                   titleText->setFont(titleFont);
                   int textxPos = 780;
                   int textyPos = 270;
                   titleText->setPos(textxPos,textyPos);
                   scenaKoncowa->addItem(titleText);

                   liczbaPunktow = liczbaPunktow - liczbaRuchowGracza + liczbaRuchowKomputera ;

                   QGraphicsTextItem* titleText1 = new QGraphicsTextItem(QString( "Twoj wynik to:"));
                   titleText1->setFont(titleFont);
                   int textxPos1 = 700;
                   int textyPos1 = 360;
                   titleText1->setPos(textxPos1,textyPos1);
                   scenaKoncowa->addItem(titleText1);

                   QGraphicsTextItem* titleText2 = new QGraphicsTextItem(QString( QString::number(liczbaPunktow) ));
                   titleText2->setFont(titleFont);
                   int textxPos2 = 850;
                   int textyPos2 = 450;
                   titleText2->setPos(textxPos2,textyPos2);
                   scenaKoncowa->addItem(titleText2);



                   QPushButton* wroc = new QPushButton("Powrót do menu");
                   wroc->setGeometry(850,700,120,30);
                   QObject::connect(wroc,SIGNAL(clicked()),this,SLOT(wrocDoMenu()));
                   scenaKoncowa->addWidget(wroc);

                   setScene(scenaKoncowa);
       }
}
void Game::ustawLiczbeStatkow()
{
    liczbaDoRozstawieniaJednomasztowcow = iloscJednomasztowcow;
    liczbaDoRozstawieniaDwumasztowcow = iloscDwumasztowcow;
    liczbaDoRozstawieniaTrojmasztowcow = iloscTrojmasztowcow ;
    liczbaDoRozstawieniaCzteromasztowcow = iloscCzteromasztowcow ;
    iloscStatkow = iloscJednomasztowcow + iloscDwumasztowcow + iloscTrojmasztowcow + iloscCzteromasztowcow ;

    liczbaJednoMasztowcowGracza = iloscJednomasztowcow;
    liczbaDwuMasztowcowGracza =iloscDwumasztowcow;
    liczbaTrzyMasztowcowGracza =iloscTrojmasztowcow;
    liczbaCzteroMasztowcowGracza=iloscCzteromasztowcow;

    liczbaJednoMasztowcowKomputera = iloscJednomasztowcow;
    liczbaDwuMasztowcowKomputera =iloscDwumasztowcow;
    liczbaTrzyMasztowcowKomputera=iloscTrojmasztowcow;
    liczbaCzteroMasztowcowKomputera =iloscCzteromasztowcow;
}
void Game::start()
{
    for(int i = 0; i < 100;i++)
    {   if(rozlacz == true)
        {
        QObject::disconnect(this,SIGNAL(strzalKomputera(bool,int,int)),PolaGracza1[0],SLOT(strzalKomputera(bool,int,int)));

        QObject::disconnect(PolaPrzeciwnika[0],SIGNAL(strzal(int,int,int,int)),this,SLOT(czyTrafiony(int,int,int,int)));
        QObject::disconnect(this,SIGNAL(poStrzale(bool,int,int)),PolaPrzeciwnika[0],SLOT(poStrzale(bool,int,int)));
        PolaGracza1.removeAt(0);
        PolaPrzeciwnika.removeAt(0);
        }
    }
    qDeleteAll(scene2->items());
    rozlacz = true;

    setScene(scene2);

    for(int i = 0; i < 10 ;i++)
        for(int j  = 0; j < 10 ; j++)
          {
            int k =0;
            int p =1;
            PolePlanszy* gracz1 = new PolePlanszy(k,j+1,i+1);
            gracz1->setPos(100+40*j ,50+40*i);
            scene2->addItem(gracz1);
            PolaGracza1.append(gracz1);



            PolePlanszy* komputer = new PolePlanszy(p,j+1,i+1);
            komputer->setPos(100+40*j,500+40*i);
            scene2->addItem(komputer);
            PolaPrzeciwnika.append(komputer);

          }

    for(int i = 0; i < 100;i++)
    {
        QObject::connect(this,SIGNAL(strzalKomputera(bool,int,int)),PolaGracza1[i],SLOT(strzalKomputera(bool,int,int)));

        QObject::connect(PolaPrzeciwnika[i],SIGNAL(strzal(int,int,int,int)),this,SLOT(czyTrafiony(int,int,int,int)));
        QObject::connect(this,SIGNAL(poStrzale(bool,int,int)),PolaPrzeciwnika[i],SLOT(poStrzale(bool,int,int)));
    }
    for(int i = 0; i < 11 ;i++)
        for(int j  = 0; j < 11 ; j++)
        {
            tablicaStrzelaniaGracza1[j][i] = " ";
            tablicaStrzelaniaGracza2[j][i] = " ";

            tablicaRozstawieniaStatkowGracza1[j][i] = " ";
            tablicaRozstawieniaStatkowGracza2[j][i] = " ";
        }

    ramka = new Ramka();
    ramka->setPos(1000,80);
    scene2->addItem(ramka);

    przycisk = new QPushButton("Rozstaw statek");
    przycisk->setGeometry(1000,300,90,30);
    QObject::connect(przycisk,SIGNAL(clicked()),this,SLOT(sprawdzRuch()));
    scene2->addWidget(przycisk);

    przycisk1= new QPushButton("Obróć statek");
    przycisk1->setGeometry(1120,300,90,30);
    QObject::connect(przycisk1,SIGNAL(clicked()),this,SLOT(obrocStatek()));
    scene2->addWidget(przycisk1);

    zapis = new QPushButton("Zapis gry");
    zapis->setGeometry(1000,350,90,30);
    QObject::connect(zapis,SIGNAL(clicked()),this,SLOT(zapiszGre()));
    scene2->addWidget(zapis);

    wrocDomenu = new QPushButton("Wróć do menu");
    wrocDomenu->setGeometry(1120,350,90,30);
    QObject::connect(wrocDomenu,SIGNAL(clicked(bool)),this,SLOT(wrocDoMenu()));
    scene2->addWidget(wrocDomenu);

    ustawLiczbeStatkow();
    rysowanieTabelki();
    rozstawianieStatkow();
}
void Game::ruchStatku(){
    {
        if(frame->xPos >= 100 && frame->xPos <485 && frame->yPos >= 50 && frame->yPos < 445){

            a = int((frame->xPos -5)/ 40);
            b = int((frame->yPos -5)/ 40);
            frame->setGeometry(40*a+20,40*b+10,frame->szerokosc,frame->wysokosc);
            a = a-1;
       }
    else{
            frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
        }
    }
}
void Game::sprawdzRuch()
{
    bool nieMaProblemu = true ;
    bool ustawWTablicy = false;

    if((460 - (40*a + 20)) < frame->szerokosc )
    {

        frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
        ustawWTablicy = false;
        nieMaProblemu = false;

    }

    if((450 - (40*b + 10)) < frame->wysokosc )
    {


        frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
        ustawWTablicy = false;
        nieMaProblemu = false;
    }



   if(nieMaProblemu == true)
   {
    for(int i = -1; i < ((frame->wysokosc/40)+1);i++)
        for(int j = -1; j < ((frame->szerokosc/40)+1);j++)
        {
           if(tablicaRozstawieniaStatkowGracza1[a+j][b+i] == " ")
           {
             ustawWTablicy = true ;
           }
           else
           {
             frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
             ustawWTablicy = false;
             i = ((frame->wysokosc/40)+2);
             j = ((frame->szerokosc/40)+2);
           }

        }
   }
    if(ustawWTablicy == true)
    {
        frame->statusRuchu = 1;
        for(int i = 0; i < ((frame->wysokosc/40));i++)
            for(int j = 0; j < ((frame->szerokosc/40));j++)
            {
                tablicaRozstawieniaStatkowGracza1[a+j][b+i] = QString::number(rodzajStatku);

            }
        if(liczbaDoRozstawieniaJednomasztowcow == 0 && liczbaDoRozstawieniaDwumasztowcow == 0 && liczbaDoRozstawieniaTrojmasztowcow ==0 && liczbaDoRozstawieniaCzteromasztowcow == 0)
        {
            qDebug() << "0 statkow";
            QObject::disconnect(przycisk,SIGNAL(clicked()),this,SLOT(sprawdzRuch()));
            rozstawianieStatkowKomputera();


        }
        else{
            rozstawianieStatkow();

        }
    }

}
void Game::obrocStatek()
{ if(frame->statusRuchu == 0)
   {
    if(ktoryStatekObrocic == 0)
    {
        QObject::disconnect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
        frame->~Okret();
        if(czyObrocony == false)
        {
        dodawanieStatkow(obrazekjednomasztowcaobrocony);
        czyObrocony = true;
        }
        else
        {
          czyObrocony = false ;
          dodawanieStatkow(obrazekjednomasztowca);
        }
    }
    if(ktoryStatekObrocic == 1)
    {
        QObject::disconnect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
        frame->~Okret();
        if(czyObrocony == false)
        {
        dodawanieStatkow(obrazekdwumasztowcaobrocony);
        czyObrocony = true;
        }
        else
        {
          czyObrocony = false ;
          dodawanieStatkow(obrazekdwumasztowca);
        }
    }
    if(ktoryStatekObrocic == 2)
    {
        QObject::disconnect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
        frame->~Okret();
        if(czyObrocony == false)
        {
        dodawanieStatkow(obrazektrojmasztowcaobrocony);
        czyObrocony = true;
        }
        else
        {
          czyObrocony = false ;
          dodawanieStatkow(obrazektrojmasztowca);
        }
    }
    if(ktoryStatekObrocic == 3)
    {
        QObject::disconnect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
        frame->~Okret();
        if(czyObrocony == false)
        {
        dodawanieStatkow(obrazekczteromasztowcaobrocony);
        czyObrocony = true;
        }
        else
        {
          czyObrocony = false ;
          dodawanieStatkow(obrazekczteromasztowca);
        }
    }
    }
}
void Game::czyTrafiony(int x, int y, int tablicaXpos, int tablicaYpos)
{
    int wspolrzednaX= (x - 99)/40 + 1;
    int wspolrzednaY= (y - 499)/40 + 1;



    if(tablicaRozstawieniaStatkowGracza2[wspolrzednaX][wspolrzednaY] == " ")
    {
        emit poStrzale(false,tablicaXpos,tablicaYpos);
        tablicaStrzelaniaGracza1[wspolrzednaX][wspolrzednaY] = '0' ;
        liczbaRuchowGracza ++ ;
    }
    else
    {
        emit poStrzale(true,tablicaXpos,tablicaYpos);
        tablicaStrzelaniaGracza1[wspolrzednaX][wspolrzednaY] = tablicaRozstawieniaStatkowGracza2[wspolrzednaX][wspolrzednaY];
        liczbaPunktow = liczbaPunktow + 10 ;
        liczbaRuchowGracza ++ ;
        sprawdzanieZatopien();
        rysowanieTabelki();
        czyKtosWygral1();
    }
}
void Game::ustawScene()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1910,1000);


    scenaUstawien = new QGraphicsScene();
    scenaUstawien->setSceneRect(0,0,1910,1000);
    setScene(scenaUstawien);


    ustawienia->widokUstawien();
}
void Game::wrocDoMenu()
{
    rodzajStatku = 1;
    setScene(scene);
}
void Game::zapiszGre()
{
    QFile plik("tablicaRozstawieniaStatkowGracza1.txt");
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream(&plik);
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            stream << tablicaRozstawieniaStatkowGracza1[j][i] << endl ;
        }
    plik.close();

    QFile plik1("tablicaRozstawieniaStatkowGracza2.txt");
    plik1.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream1(&plik1);
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            stream1 << tablicaRozstawieniaStatkowGracza2[j][i]  << endl ;
        }
    plik1.close();

    QFile plik2("tablicaStrzelaniaGracza1.txt");
    plik2.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream2(&plik2);
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            stream2 << tablicaStrzelaniaGracza1[j][i]  << endl ;
        }
    plik2.close();


    QFile plik3("tablicaStrzelaniaGracza2.txt");
    plik3.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream3(&plik3);
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            stream3 << tablicaStrzelaniaGracza2[j][i]  << endl ;
        }
    plik3.close();


    QFile plik4("pozostaleDane.txt");
    plik4.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream4(&plik4);
    {
     stream4 << iloscJednomasztowcow << endl ;
     stream4 << iloscDwumasztowcow << endl ;
     stream4 << iloscTrojmasztowcow << endl ;
     stream4 << iloscCzteromasztowcow << endl ;

     stream4 << liczbaDoRozstawieniaJednomasztowcow  << endl ;
     stream4 << liczbaDoRozstawieniaDwumasztowcow    << endl ;
     stream4 << liczbaDoRozstawieniaTrojmasztowcow   << endl ;
     stream4 << liczbaDoRozstawieniaCzteromasztowcow << endl ;

     stream4 << rodzajStatku << endl ;
     stream4 << fazaGry << endl;
    }
    plik4.close();


}
void Game::wczytajZapis()
{
    QFile plik("tablicaRozstawieniaStatkowGracza1.txt");
    plik.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents = plik.readAll().constData();;
    plik.close();
    QStringList a = contents.split(QRegExp("\n"));
    int k = 0;
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
           tablicaRozstawieniaStatkowGracza1[j][i]=a[k] ;
           k++;
        }

    QFile plik1("tablicaRozstawieniaStatkowGracza2.txt");
    plik1.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents1 = plik1.readAll().constData();;
    plik1.close();
    QStringList b = contents1.split(QRegExp("\n"));
    k = 0;
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            tablicaRozstawieniaStatkowGracza2[j][i]=b[k] ;
            k++;
        }

    QFile plik2("tablicaStrzelaniaGracza1.txt");
    plik2.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents2 = plik2.readAll().constData();;
    plik2.close();
    QStringList c = contents2.split(QRegExp("\n"));
    k = 0;
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
            tablicaStrzelaniaGracza1[j][i] = c[k];
            k++;
        }

    QFile plik3("tablicaStrzelaniaGracza2.txt");
    plik3.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents3 = plik3.readAll().constData();;
    plik3.close();
    QStringList d = contents3.split(QRegExp("\n"));
    k = 0;
    for(int i = 0; i < 11 ; i++)
        for(int j=0; j < 11; j++)
        {
            tablicaStrzelaniaGracza2[j][i] = d[k];
            qDebug() << d[k] << j << i ;
            k++;
        }

    QFile plik4("pozostaleDane.txt");
    plik4.open(QIODevice::ReadOnly | QIODevice::Truncate | QIODevice::Text);
    QString contents4 = plik4.readAll().constData();;
    plik4.close();
    QStringList e = contents4.split(QRegExp("\n"));
    {
        iloscJednomasztowcow = e[0].toInt() ;
        iloscDwumasztowcow   = e[1].toInt() ;
        iloscTrojmasztowcow  = e[2].toInt() ;
        iloscCzteromasztowcow= e[3].toInt() ;

        liczbaDoRozstawieniaJednomasztowcow = e[4].toInt() ;
        liczbaDoRozstawieniaDwumasztowcow   = e[5].toInt() ;
        liczbaDoRozstawieniaTrojmasztowcow  = e[6].toInt() ;
        liczbaDoRozstawieniaCzteromasztowcow= e[7].toInt() ;

        rodzajStatku = e[8].toInt() ;
        fazaGry = e[9].toInt();
    }
    startZWczytania();
}
void Game::plansza()
{
  QString a = "";
    for(int i = 0;i<11;i++){
        for(int j=0;j<11;j++)
        {
            a += tablicaStrzelaniaGracza2[j][i];
        }
    qDebug()<< a ;
    a ="";
    }
}
void Game::startZWczytania()
{
    for(int i = 0; i < 100;i++)
    {   if(rozlacz == true)
        {
        QObject::disconnect(this,SIGNAL(strzalKomputera(bool,int,int)),PolaGracza1[0],SLOT(strzalKomputera(bool,int,int)));

        QObject::disconnect(PolaPrzeciwnika[0],SIGNAL(strzal(int,int,int,int)),this,SLOT(czyTrafiony(int,int,int,int)));
        QObject::disconnect(this,SIGNAL(poStrzale(bool,int,int)),PolaPrzeciwnika[0],SLOT(poStrzale(bool,int,int)));
        PolaGracza1.removeAt(0);
        PolaPrzeciwnika.removeAt(0);
        }
    }
    qDeleteAll(scene2->items());
    rozlacz = true;

    setScene(scene2);

    for(int i = 0; i < 10 ;i++)
        for(int j  = 0; j < 10 ; j++)
          {
            int k =0;
            int p =1;
            PolePlanszy* gracz1 = new PolePlanszy(k,j+1,i+1);
            gracz1->setPos(100+40*j ,50+40*i);
            scene2->addItem(gracz1);
            PolaGracza1.append(gracz1);



            PolePlanszy* komputer = new PolePlanszy(p,j+1,i+1);
            komputer->setPos(100+40*j,500+40*i);
            scene2->addItem(komputer);
            PolaPrzeciwnika.append(komputer);

          }

    for(int i = 0; i < 100;i++)
    {
        QObject::connect(this,SIGNAL(strzalKomputera(bool,int,int)),PolaGracza1[i],SLOT(strzalKomputera(bool,int,int)));
        QObject::connect(PolaPrzeciwnika[i],SIGNAL(strzal(int,int,int,int)),this,SLOT(czyTrafiony(int,int,int,int)));
        QObject::connect(this,SIGNAL(poStrzale(bool,int,int)),PolaPrzeciwnika[i],SLOT(poStrzale(bool,int,int)));
    }


    ramka = new Ramka();
    ramka->setPos(1000,80);
    scene2->addItem(ramka);

    przycisk = new QPushButton("Rozstaw statek");
    przycisk->setGeometry(1000,300,90,30);
    QObject::connect(przycisk,SIGNAL(clicked()),this,SLOT(sprawdzRuch()));
    scene2->addWidget(przycisk);

    przycisk1= new QPushButton("Obróć statek");
    przycisk1->setGeometry(1120,300,90,30);
    QObject::connect(przycisk1,SIGNAL(clicked()),this,SLOT(obrocStatek()));
    scene2->addWidget(przycisk1);

    zapis = new QPushButton("Zapis gry");
    zapis->setGeometry(1000,350,90,30);
    QObject::connect(zapis,SIGNAL(clicked()),this,SLOT(zapiszGre()));
    scene2->addWidget(zapis);

    wrocDomenu = new QPushButton("Wróć do menu");
    wrocDomenu->setGeometry(1120,350,90,30);
    QObject::connect(wrocDomenu,SIGNAL(clicked(bool)),this,SLOT(wrocDoMenu()));
    scene2->addWidget(wrocDomenu);

    for(int i = 0; i < 11 ; i++)
        for(int j=0; j < 11; j++)
        {
           if(tablicaRozstawieniaStatkowGracza1[j][i] == "1")
           {
               frame = new Okret(obrazekjednomasztowca);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
           }

           if(tablicaRozstawieniaStatkowGracza1[j][i] == "2" && tablicaRozstawieniaStatkowGracza1[j-1][i] != "2" && tablicaRozstawieniaStatkowGracza1[j][i-1] != "2")
           {
              if(tablicaRozstawieniaStatkowGracza1[j+1][i] == "2")
              {
               frame = new Okret(obrazekdwumasztowca);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
              else
              {
               frame = new Okret(obrazekdwumasztowcaobrocony);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
           }
           if(tablicaRozstawieniaStatkowGracza1[j][i] == "3" && tablicaRozstawieniaStatkowGracza1[j-1][i] != "3" && tablicaRozstawieniaStatkowGracza1[j][i-1] != "3")
           {
              if(tablicaRozstawieniaStatkowGracza1[j+1][i] == "3")
              {
               frame = new Okret(obrazektrojmasztowca);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
              else
              {
               frame = new Okret(obrazektrojmasztowcaobrocony);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
           }
           if(tablicaRozstawieniaStatkowGracza1[j][i] == "4" && tablicaRozstawieniaStatkowGracza1[j-1][i] != "4" && tablicaRozstawieniaStatkowGracza1[j][i-1] != "4")
           {
              if(tablicaRozstawieniaStatkowGracza1[j+1][i] == "4")
              {
               frame = new Okret(obrazekczteromasztowca);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
              else
              {
               frame = new Okret(obrazekczteromasztowcaobrocony);
               frame->statusRuchu = 1;
               frame->setGeometry(100+40*(j-1) ,50+40*(i-1),frame->szerokosc,frame->wysokosc);
               scene2->addWidget(frame);
              }
           }
        }

    wczytuje = true ;
    for(int i = 0; i < 11 ; i++)
        for(int j=0; j < 11; j++)
        {
           if(tablicaStrzelaniaGracza1[j][i]== "0")
           {
               emit poStrzale(false,(j) ,(i));
           }
           else if(tablicaStrzelaniaGracza1[j][i]== " ")
           {

           }
           else {
               emit poStrzale(true,(j) ,(i));
           }
        }

    for(int i = 0; i < 11 ; i++)
        for(int j=0; j < 11; j++)
        {
           if(tablicaStrzelaniaGracza2[j][i]== "0")
           {   qDebug() << "dziala1" << j << i;
               emit strzalKomputera(false,(j),(i));
           }
           else if(tablicaStrzelaniaGracza2[j][i] == " ")
           {

           }
           else
           {
               qDebug() << j << i;
               emit strzalKomputera(true,j,i);
           }
        }
    wczytuje = false ;

    liczbaJednoMasztowcowGracza = iloscJednomasztowcow;
    liczbaDwuMasztowcowGracza =iloscDwumasztowcow;
    liczbaTrzyMasztowcowGracza =iloscTrojmasztowcow;
    liczbaCzteroMasztowcowGracza=iloscCzteromasztowcow;

    liczbaJednoMasztowcowKomputera = iloscJednomasztowcow;
    liczbaDwuMasztowcowKomputera =iloscDwumasztowcow;
    liczbaTrzyMasztowcowKomputera=iloscTrojmasztowcow;
    liczbaCzteroMasztowcowKomputera =iloscCzteromasztowcow;

    plansza();
    rozstawianieStatkow();
    rysowanieTabelki();

}
void Game::sprawdzanieZatopien()
{   int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for(int i = 0; i < 11 ; i ++)
        for(int j=0; j < 11; j++)
        {
           if(tablicaStrzelaniaGracza1[j][i]== "1")
           {
             a++ ;
              qDebug() << a;

           }
           if(tablicaStrzelaniaGracza1[j][i]== "2" && tablicaStrzelaniaGracza1[j-1][i] != "2" && tablicaStrzelaniaGracza1[j][i-1] != "2")
           {
               if(tablicaStrzelaniaGracza1[j+1][i] == "2" || tablicaStrzelaniaGracza1[j][i+1] == "2")
               {
                  b++ ;
                  qDebug() << b;
               }

           }
           if(tablicaStrzelaniaGracza1[j][i]== "3" && tablicaStrzelaniaGracza1[j-1][i] != "3" && tablicaStrzelaniaGracza1[j][i-1] != "3")
           {
               if((tablicaStrzelaniaGracza1[j+1][i]== "3" && tablicaStrzelaniaGracza1[j+2][i]== "3") || (tablicaStrzelaniaGracza1[j][i+1]== "3" && tablicaStrzelaniaGracza1[j][i+2]== "3") )
               {
                 c++;
                 qDebug() << c;
               }
           }
           if(tablicaStrzelaniaGracza1[j][i]== "4" && tablicaStrzelaniaGracza1[j-1][i] != "4" && tablicaStrzelaniaGracza1[j][i-1] != "4")
           {
               if((tablicaStrzelaniaGracza1[j+1][i]== "4" && tablicaStrzelaniaGracza1[j+2][i]== "4" && tablicaStrzelaniaGracza1[j+3][i]== "4") || (tablicaStrzelaniaGracza1[j][i+1]== "4" && tablicaStrzelaniaGracza1[j][i+2]== "4"&& tablicaStrzelaniaGracza1[j][i+3]== "4"))
               {
                   d++;
                   qDebug() << d ;
               }
           }


        }
    liczbaCzteroMasztowcowKomputera = iloscCzteromasztowcow - d;
    liczbaTrzyMasztowcowKomputera   = iloscTrojmasztowcow - c;
    liczbaDwuMasztowcowKomputera    = iloscDwumasztowcow - b;
    liczbaJednoMasztowcowKomputera  = iloscJednomasztowcow - a;
}
void Game::sprawdzanieZatopienKomputera()
{
    int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        for(int i = 0; i < 11 ; i ++)
            for(int j=0; j < 11; j++)
            {
               if(tablicaStrzelaniaGracza2[j][i]== "1")
               {
                 a++ ;


               }
               if(tablicaStrzelaniaGracza2[j][i]== "2" && tablicaStrzelaniaGracza2[j-1][i] != "2" && tablicaStrzelaniaGracza2[j][i-1] != "2")
               {
                   if(tablicaStrzelaniaGracza2[j+1][i] == "2" || tablicaStrzelaniaGracza2[j][i+1] == "2")
                   {
                      b++ ;

                   }

               }
               if(tablicaStrzelaniaGracza2[j][i]== "3" && tablicaStrzelaniaGracza2[j-1][i] != "3" && tablicaStrzelaniaGracza2[j][i-1] != "3")
               {
                   if((tablicaStrzelaniaGracza2[j+1][i]== "3" && tablicaStrzelaniaGracza2[j+2][i]== "3") || (tablicaStrzelaniaGracza2[j][i+1]== "3" && tablicaStrzelaniaGracza2[j][i+2]== "3") )
                   {
                     c++;

                   }
               }
               if(tablicaStrzelaniaGracza2[j][i]== "4" && tablicaStrzelaniaGracza2[j-1][i] != "4" && tablicaStrzelaniaGracza2[j][i-1] != "4")
               {
                   if((tablicaStrzelaniaGracza2[j+1][i]== "4" && tablicaStrzelaniaGracza2[j+2][i]== "4" && tablicaStrzelaniaGracza2[j+3][i]== "4") || (tablicaStrzelaniaGracza2[j][i+1]== "4" && tablicaStrzelaniaGracza2[j][i+2]== "4"&& tablicaStrzelaniaGracza2[j][i+3]== "4"))
                   {
                       d++;

                   }
               }


            }
    liczbaCzteroMasztowcowGracza = iloscCzteromasztowcow - d;
    liczbaTrzyMasztowcowGracza   = iloscTrojmasztowcow - c;
    liczbaDwuMasztowcowGracza    = iloscDwumasztowcow - b;
    liczbaJednoMasztowcowGracza  = iloscJednomasztowcow - a;
}
void Game::rysowanieTabelki()
{
    Ramka* rameczka = new Ramka() ;
    rameczka->setPos(1300,80);
    rameczka->iloscOkretow();
    scene2->addItem(rameczka);
}


















