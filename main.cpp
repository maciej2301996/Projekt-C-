#include "school.h"
#include <QApplication>

School* school;

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    school = new School();
    school->show();
    school->connect();

    //QObject::connect(school->combo,SIGNAL(currentIndexChanged(QString)),school->nazwa,SLOT(school->drawTabel(QString)));

    school->drawTabel();
    school->addCombos();




    return a.exec();
}
