#include "interfaceelement3.h"

InterfaceElement3::InterfaceElement3(int x,int y,QString name, QGraphicsItem *parent):  QGraphicsRectItem(parent)
{
    X = x;
    Y = y;

    // rysowanie prostokąta
    setRect(0,0,26,240);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);


    nazwaKolumny = name;
    a = name.split(QRegExp("_"));
    unikatowaLiczba = a[0].toInt();
    b = a[1];


    // dodawanie napisu
    text = new QGraphicsSimpleTextItem(b,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = 8 ;
    int yPos = 220;
    text->setPos(xPos,yPos);
    text->setRotation(this->rotation()-90);


}
InterfaceElement3::~InterfaceElement3()
{

}
void InterfaceElement3::uzupelnijDane(QString napis)
{
    int xPos = 8;
    int yPos = 220;
    text->setPos(xPos,yPos);
    text->setRotation(this->rotation()-90);
    text->setText(napis);
}
void InterfaceElement3::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit pisanie(unikatowaLiczba);
}
InterfaceElement3::InterfaceElement3(int x, int y, int liczba, QGraphicsItem* parent): QGraphicsRectItem(parent)
{
    X = x;
    Y = y;
    b = " ";
    unikatowaLiczba = liczba;
    nazwaKolumny = QString::number(liczba);

    // rysowanie prostokąta
    setRect(0,0,26,240);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    text = new QGraphicsSimpleTextItem(b,this);
    QFont fieldFont1("Times New Roman",14);
    text->setFont(fieldFont1);
    int xPos = rect().width()  + 19- text->boundingRect().width()/2;
    int yPos = rect().height() - 55 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setRotation(this->rotation()-90);



}
