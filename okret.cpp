#include "okret.h"

Okret::Okret(QString a)
{
    QPixmap pix(a);
    wysokosc = pix.height();
    szerokosc = pix.width();
    setPixmap(pix);
    statusRuchu  =  0;
    ruch = false;

}

Okret::~Okret()
{

}
void Okret::mousePressEvent(QMouseEvent *ev)
{
     offset = ev->pos();
     ruch = true;
}
void Okret::mouseMoveEvent(QMouseEvent *event)
{
   if(statusRuchu == 0){
    if(event->buttons() & Qt::LeftButton)
       {
          this->move(QLabel::mapToParent(event->pos() - offset));
          xPos = this->pos().x();
          yPos = this->pos().y();
        //  qDebug() << xPos << yPos;
       }
   }



}
void Okret::mouseReleaseEvent(QMouseEvent *)
{
   ruch = false;
   emit Ruch();
}
