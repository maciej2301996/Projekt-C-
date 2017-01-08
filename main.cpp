#include "school.h"
#include <QApplication>

School* school;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    school = new School();
    school->show();
    school->polaczenie();
    school->classwindow();

    QObject::connect(school->elementlist2[0],SIGNAL(create()),school,SLOT(proba()));


    return a.exec();
}
