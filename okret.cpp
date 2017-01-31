#include "okret.h"

Okret::Okret(QString a)
{

    setStyleSheet("background:transparent");
    QPixmap pix(a);

    wysokosc = pix.height();
    szerokosc = pix.width();
    setPixmap(pix);
    statusRuchu  =  0;
    xPos = 0;
    yPos = 0;

}

Okret::~Okret()
{

}
void Okret::mousePressEvent(QMouseEvent *ev)
{
     offset = ev->pos();

}
void Okret::mouseMoveEvent(QMouseEvent *event)
{
   if(statusRuchu == 0){
    if(event->buttons() & Qt::LeftButton)
       {
          this->move(QLabel::mapToParent(event->pos() - offset));
          xPos = this->pos().x();
          yPos = this->pos().y();
       }
   }



}
void Okret::mouseReleaseEvent(QMouseEvent *)
{

   emit Ruch();
}
