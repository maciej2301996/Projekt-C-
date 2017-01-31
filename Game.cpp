#include "Game.h"

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

    iloscJednomasztowcow = 4;
    iloscDwumasztowcow = 3;
    iloscTrojmasztowcow = 2;
    iloscCzteromasztowcow =1;



    obrazekjednomasztowca  = "C:\\Users\\user\\Desktop\\IPP\\jednomasztowiec.png";
    obrazekdwumasztowca    = "C:\\Users\\user\\Desktop\\IPP\\dwumasztowiec.png";
    obrazektrojmasztowca   = "C:\\Users\\user\\Desktop\\IPP\\trojmasztowiec.png";
    obrazekczteromasztowca = "C:\\Users\\user\\Desktop\\IPP\\czteromasztowiec.png";

    obrazekjednomasztowcaobrocony = "C:\\Users\\user\\Desktop\\IPP\\jednomasztowiecpionowo.png";
    obrazekdwumasztowcaobrocony   = "C:\\Users\\user\\Desktop\\IPP\\dwumasztowiecpionowo.png";
    obrazektrojmasztowcaobrocony  = "C:\\Users\\user\\Desktop\\IPP\\trojmasztowiecpionowo.png";
    obrazekczteromasztowcaobrocony= "C:\\Users\\user\\Desktop\\IPP\\czteromasztowiecpionowo.png";

    rodzajStatku = 0;

    ktoryStatekObrocic = 0;

    rozstawionychStatkow = 0;

    fazaGry = 0;
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
    optionButton->setPos(button3xPos,button3yPos);
    scene->addItem(optionButton);

    // przycisk instrukcji
    Button* instructionButton = new Button(QString("Instrukcja"));
    int button2xPos = this->width()/2 - instructionButton->boundingRect().width()/2;
    int button2yPos = this->height() * 2 /6 + 160;
    instructionButton->setPos(button2xPos,button2yPos);
    scene->addItem(instructionButton);

    // przycisk wyjscia
    Button* quitButton = new Button(QString("Wyjście"));
    int button4xPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int button4yPos = this->height() * 2 /6  + 240;
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
  if(rodzajStatku == 0)
  { ktoryStatekObrocic = 0;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaJednomasztowcow > 0)
    {
        dodawanieStatkow(obrazekjednomasztowca);
        liczbaDoRozstawieniaJednomasztowcow = liczbaDoRozstawieniaJednomasztowcow - 1;
    }
    else{

        rodzajStatku += 1;
    }


  }

  if(rodzajStatku == 1)
  { ktoryStatekObrocic = 1;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaDwumasztowcow != 0)
    {
        dodawanieStatkow(obrazekdwumasztowca);
        liczbaDoRozstawieniaDwumasztowcow = liczbaDoRozstawieniaDwumasztowcow - 1;
    }
    else{
        rodzajStatku +=1;
    }
  }

  if(rodzajStatku == 2)
  { ktoryStatekObrocic = 2;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaTrojmasztowcow != 0)
    {
        dodawanieStatkow(obrazektrojmasztowca);
        liczbaDoRozstawieniaTrojmasztowcow =liczbaDoRozstawieniaTrojmasztowcow - 1;
    }
    else
    {
        rodzajStatku +=1;
    }
  }

  if(rodzajStatku == 3)
  { ktoryStatekObrocic = 3;
    czyObrocony = false ;
    if(liczbaDoRozstawieniaCzteromasztowcow != 0)
    {
        dodawanieStatkow(obrazekczteromasztowca);
        liczbaDoRozstawieniaCzteromasztowcow =liczbaDoRozstawieniaCzteromasztowcow - 1;
    }
    else
    {
        rodzajStatku +=1;
    }
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
        qDebug() << a << b ;
        if(tablicaRozstawieniaStatkowGracza1[a][b] == " " &&  tablicaStrzelaniaGracza2[a][b] == " " )
           {
            tablicaStrzelaniaGracza2[a][b] = '0' ;
            emit strzalKomputera(false,a,b);
           }
        else if(tablicaStrzelaniaGracza2[a][b] == " ")
        {
            tablicaStrzelaniaGracza2[a][b] = tablicaRozstawieniaStatkowGracza1[a][b];
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
    {
        setScene(scene);
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
                setScene(scene);
            }
}
void Game::start()
{
    liczbaDoRozstawieniaJednomasztowcow = iloscJednomasztowcow;
    liczbaDoRozstawieniaDwumasztowcow = iloscDwumasztowcow;
    liczbaDoRozstawieniaTrojmasztowcow = iloscTrojmasztowcow ;
    liczbaDoRozstawieniaCzteromasztowcow = iloscCzteromasztowcow ;


    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,1910,1000);
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

    rozstawianieStatkow();
}
void Game::ruchStatku(){
    if(frame->ruch == false){
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
                tablicaRozstawieniaStatkowGracza1[a+j][b+i] = "1";

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
    }
    else
    {
        emit poStrzale(true,tablicaXpos,tablicaYpos);
        tablicaStrzelaniaGracza1[wspolrzednaX][wspolrzednaY] = tablicaRozstawieniaStatkowGracza2[wspolrzednaX][wspolrzednaY];
        czyKtosWygral1();
    }
}
void Game::plansza()
{
  QString a = "";
    for(int i = 0;i<11;i++){
        for(int j=0;j<11;j++)
        {
            a += tablicaRozstawieniaStatkowGracza2[j][i];
        }
    qDebug()<< a ;
    a ="";
    }
}

















