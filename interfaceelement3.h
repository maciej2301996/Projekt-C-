#ifndef INTERFACEELEMENT3_H
#define INTERFACEELEMENT3_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

class InterfaceElement3 : public QObject,public QGraphicsRectItem
{   Q_OBJECT
public:
    InterfaceElement3(QGraphicsItem* parent = 0);
    InterfaceElement3(QString name,QGraphicsItem* parent = 0);

private:
    QGraphicsTextItem* text;
};

#endif // INTERFACEELEMENT3_H
