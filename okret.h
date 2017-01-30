#ifndef OKRET_H
#define OKRET_H

#include <QLabel>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsItem>

#include <QDebug>

class Okret :  public QLabel
{
    Q_OBJECT
public:
    Okret(QString a);

    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


    int xPos;
    int yPos;

    int wysokosc;
    int szerokosc;

    bool ruch;
    QPoint offset;

    int statusRuchu ;
signals:
    void Ruch();
};

#endif // OKRET_H
