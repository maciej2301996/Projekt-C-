#ifndef POLEPLANSZY_H
#define POLEPLANSZY_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QDebug>

class PolePlanszy : public QObject , public QGraphicsRectItem{
    Q_OBJECT
public:

   // konstruktor
        PolePlanszy(int k,int j,int i);

        int tablicaXpos ;
        int tablicaYpos ;

        void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);

        QPointF offset;

        bool nieWcisnieta ;
public slots:
      void poStrzale(bool a,int j, int i);
      void strzalKomputera(bool a,int j, int i);
signals:
      void strzal(int x,int y,int j,int i) ;

private:
      int statusPola ;
};

#endif // POLEPLANSZY_H
