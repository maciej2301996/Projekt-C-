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

    iloscJednomasztowcow = 0;
    iloscDwumasztowcow = 0 ;
    iloscTrojmasztowcow = 3;
    iloscCzteromasztowcow = 0;

    liczbaDoRozstawieniaJednomasztowcow = iloscJednomasztowcow;
    liczbaDoRozstawieniaDwumasztowcow = iloscDwumasztowcow;
    liczbaDoRozstawieniaTrojmasztowcow = iloscTrojmasztowcow ;
    liczbaDoRozstawieniaCzteromasztowcow = iloscCzteromasztowcow ;

    rodzajStatku = 0;
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
void Game::dodawanieStatkow()
{
    frame = new Okret();
    QObject::connect(frame,SIGNAL(Ruch()),this,SLOT(ruchStatku()));
    frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
    scene2->addWidget(frame);
}
void Game::rozstawianieStatkow()
{
  if(rodzajStatku == 0)
  {
    if(liczbaDoRozstawieniaJednomasztowcow != 0)
    {
        dodawanieStatkow();
        liczbaDoRozstawieniaJednomasztowcow -= 1;
    }
    else
    {
        rodzajStatku +=1;
    }
  }

  if(rodzajStatku == 1)
  {
    if(liczbaDoRozstawieniaDwumasztowcow != 0)
    {
        dodawanieStatkow();
        liczbaDoRozstawieniaDwumasztowcow -= 1;
    }
    else
    {
        rodzajStatku +=1;
    }
  }

  if(rodzajStatku == 2)
  {
    if(liczbaDoRozstawieniaTrojmasztowcow != 0)
    {
        dodawanieStatkow();
        liczbaDoRozstawieniaTrojmasztowcow -= 1;
    }
    else
    {
        rodzajStatku +=1;
    }
  }

  if(rodzajStatku == 3)
  {
    if(liczbaDoRozstawieniaCzteromasztowcow != 0)
    {
        dodawanieStatkow();
        liczbaDoRozstawieniaCzteromasztowcow -= 1;
    }
    else
    {
        rodzajStatku +=1;
    }
  }
}
void Game::start()
{
    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,1910,1000);
    setScene(scene2);


    for(int i = 0; i < 10 ;i++)
        for(int j  = 0; j < 10 ; j++)
          {
            int k =0;
            int p =1;
            PolePlanszy* gracz1 = new PolePlanszy(k);
            gracz1->setPos(100+40*j ,50+40*i);
            scene2->addItem(gracz1);
            PolaGracza1.append(gracz1);



            PolePlanszy* komputer = new PolePlanszy(p);
            komputer->setPos(100+40*j,500+40*i);
            scene2->addItem(komputer);
            PolaPrzeciwnika.append(komputer);

            tablicaRozstawieniaStatkowGracza1[j][i] = " ";
            tablicaRozstawieniaStatkowGracza2[j][i] = " ";

            tablicaStrzelaniaGracza1[j][i] = " ";
            tablicaStrzelaniaGracza2[j][i] = " ";

            //qDebug() << tablicaRozstawieniaStatkowGracza1[j][i] << j << i;
        }


    ramka = new Ramka();
    ramka->setPos(1000,80);
    scene2->addItem(ramka);

    QPushButton* przycisk = new QPushButton("Rozstaw statek");
    przycisk->setGeometry(1020,400,90,30);
    QObject::connect(przycisk,SIGNAL(clicked()),this,SLOT(sprawdzRuch()));
    scene2->addWidget(przycisk);

    rozstawianieStatkow();
}
void Game::ruchStatku(){
    if(frame->ruch == false){
        if(frame->xPos >= 100 && frame->xPos <500 && frame->yPos >= 50 && frame->yPos < 450){

            a = int(frame->xPos / 40);
            b = int(frame->yPos / 40);
            qDebug() << a << b;
            frame->setGeometry(40*a+20,40*b+10,frame->szerokosc,frame->wysokosc);
        }
    else{
            frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
        }
    }
}
void Game::sprawdzRuch()
{
    bool ustawWTablicy = false;
    for(int i = -1; i < ((frame->wysokosc/40)+2);i++)
        for(int j = -1; j < ((frame->szerokosc/40)+2);j++)
        {
           if(tablicaRozstawieniaStatkowGracza1[a+j][b+i] == " ")
           {
             qDebug() << "dziala1";
             ustawWTablicy = true ;
           }
           else
           {
               qDebug() << "dziala2";
             frame->setGeometry(1020,100,frame->szerokosc,frame->wysokosc);
             ustawWTablicy = false;
             i = ((frame->wysokosc/40)+2);
             j = ((frame->szerokosc/40)+2);
           }

        }
    if(ustawWTablicy == true)
    {
        for(int i = 0; i < ((frame->wysokosc/40));i++)
            for(int j = 0; j < ((frame->szerokosc/40));j++)
            {
                tablicaRozstawieniaStatkowGracza1[a+j][b+i] = "1";
            }
        rozstawianieStatkow();
    }
}



















