#include "combobox.h"

combobox::combobox(QStringList name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{

    QComboBox* combo = new QComboBox();
    combo->addItems(name);
    combo->setGeometry(40,40,100,100);
}
