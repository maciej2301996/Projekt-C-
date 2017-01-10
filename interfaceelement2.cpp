#include "interfaceelement2.h"
#include "school.h"

extern School* school ;

InterfaceElement2::InterfaceElement2(int x, int y,int IndeksKomorki,QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
    X=x;
    Y=y;
    unikatowaliczba = IndeksKomorki;

    text1 = new QGraphicsSimpleTextItem(" ",this);
    QFont fieldFont1("Times New Roman",14);
    text1->setFont(fieldFont1);


}
InterfaceElement2::InterfaceElement2(int x, int y,int IndeksKomorki, QString name, QGraphicsItem *parent) :  QGraphicsRectItem(parent)
{
    // rysowanie prostokąta
    setRect(0,0,26,26);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    // dodawanie napisu
    text1 = new QGraphicsSimpleTextItem(name,this);
    QFont fieldFont1("Times New Roman",14);
    text1->setFont(fieldFont1);
    int xPos = rect().width()/2 - text1->boundingRect().width()/2;
    int yPos = rect().height()/2 - text1->boundingRect().height()/2;
    text1->setPos(xPos,yPos);

    X=x;
    Y=y;
    unikatowaliczba = IndeksKomorki;


}
InterfaceElement2::~InterfaceElement2()
{

}
void InterfaceElement2::uzupelnijDane(QString napis)
{

    int xPos = rect().width()/2 - text1->boundingRect().width()/2;
    int yPos = rect().height()/2 - text1->boundingRect().height()/2;
    text1->setPos(xPos,yPos);
    text1->setText(napis);
}
void InterfaceElement2::mousePressEvent(QGraphicsSceneMouseEvent *){
    emit  stworzPolaczenie();
    emit  create(unikatowaliczba);

}


