#ifndef SCHOOL_H
#define SCHOOL_H

#include <QMainWindow>

#include "addfunction.h"


namespace Ui {
class School;
}

class School : public QMainWindow
{
    Q_OBJECT

public:
    explicit School(QWidget *parent = 0);
    ~School();

private:
    Ui::School *ui;
};

#endif // SCHOOL_H
