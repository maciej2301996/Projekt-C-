#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>


class Button : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public :
    //konstruktor
    Button(QString name,QGraphicsItem* parent = 0);

    //dekonstruktor
    ~Button();

    // metody
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
   void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
   void clicked();

private:
    QGraphicsTextItem* text;

};










#endif // BUTTON_H
