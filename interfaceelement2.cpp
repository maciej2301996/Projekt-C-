#include "interfaceelement2.h"
#include "school.h"

extern School* school ;

InterfaceElement2::InterfaceElement2(int x, int y, int IndeksKomorki, QString ID, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{   IDwTabeli = ID;

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
InterfaceElement2::InterfaceElement2(int x, int y, int IndeksKomorki, QString name, QString ID, QGraphicsItem *parent) :  QGraphicsRectItem(parent)
{   IDwTabeli = ID;

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
    int xPos = 8;
    int yPos = 3;
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

    int xPos = 7;
    int yPos = 3;
    text1->setPos(xPos,yPos);
    text1->setText(napis);
}
void InterfaceElement2::mousePressEvent(QGraphicsSceneMouseEvent *){

    emit  stworzPolaczenie();
    emit  create(unikatowaliczba);

}


