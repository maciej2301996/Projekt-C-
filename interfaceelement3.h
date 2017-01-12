#ifndef INTERFACEELEMENT3_H
#define INTERFACEELEMENT3_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QFont>
#include <QDebug>


class InterfaceElement3 : public QObject,public QGraphicsRectItem
{   Q_OBJECT
public:
    InterfaceElement3(int x, int y, int liczba, QGraphicsItem* parent = 0);
    InterfaceElement3(int x, int y, QString name, QGraphicsItem* parent = 0);
    ~InterfaceElement3();

    QStringList a;

    QString b;
    QString nazwaKolumny;

    int unikatowaLiczba;
    int X;
    int Y;

    void uzupelnijDane(QString napis);
    void mousePressEvent(QGraphicsSceneMouseEvent *event = 0);
signals :
     void pisanie(int unikatowaLiczba);

private:
    QGraphicsSimpleTextItem* text;


};

#endif // INTERFACEELEMENT3_H
