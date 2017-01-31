#include "okret.h"

Okret::Okret(QString a)
{
    setAutoFillBackground(false);
    //setStyleSheet();
    QPixmap pix(a);
    pix.fill(Qt::transparent);
    wysokosc = pix.height();
    szerokosc = pix.width();
    setPixmap(pix);
    statusRuchu  =  0;
    ruch = false;


   // QImage image(a);
    //QPainter p;
   //p.begin(&image);
    //p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
   // p.fillRect(image.rect(), QColor(0, 0, 0, 50));
   // p.end();
   // setPixmap(QPixmap::fromImage(image));
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
       }
   }



}
void Okret::mouseReleaseEvent(QMouseEvent *)
{
   ruch = false;
   emit Ruch();
}
