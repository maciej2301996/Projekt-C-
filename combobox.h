#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QGraphicsRectItem>
#include <QStringList>
#include <QComboBox>

class combobox : public QObject,public QGraphicsRectItem
{
public:
    combobox(QStringList name,QGraphicsItem* parent=0);


};

#endif // COMBOBOX_H
