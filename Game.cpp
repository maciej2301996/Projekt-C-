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
void Game::start()
{
    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,1910,1000);
    setScene(scene2);


    for(int i = 0; i < 10 ;i++)
        for(int j  = 0; j < 10 ; j++)
          {
            PolePlanszy* gracz1 = new PolePlanszy();
            gracz1->setPos(100+40*j ,50+40*i);
            scene2->addItem(gracz1);
            PolaGracza1.append(gracz1);


            PolePlanszy* komputer = new PolePlanszy();
            komputer->setPos(100+40*j,500+40*i);
            scene2->addItem(komputer);
            PolaPrzeciwnika.append(komputer);
          }

    // wstawianie obrazka

    QPixmap pix("C:\\Users\\user\\Desktop\\dwumasztowiec.png");
    QLabel *frame = new QLabel();
    frame->setGeometry(100,50,80,40);
    frame->setPixmap(pix);
    scene2->addWidget(frame);








}





















