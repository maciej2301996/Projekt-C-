#include "okret.h"

Okret::Okret()
{
    QPixmap pix("C:\\Users\\user\\Desktop\\dwumasztowiec.png");
    wysokosc = pix.height();
    szerokosc = pix.width();
    //setGeometry(100,50,80,40);
    setPixmap(pix);
    statusRuchu  =  0;
    ruch = false;

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
          qDebug() << xPos << yPos;
       }
   }



}
void Okret::mouseReleaseEvent(QMouseEvent *)
{
   ruch = false;
   emit Ruch();
}
