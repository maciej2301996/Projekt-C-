#include "school.h"
#include <QApplication>

School* school;

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    school = new School();
    school->show();
    Connect();
    school->drawTabel();

    AddData();
    SelectData();


    return a.exec();
}
