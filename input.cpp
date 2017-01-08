#include "input.h"

Input::Input()
{
    // przygotowanie pola do pisania
    setGeometry(180,180,26,26);
    setFixedSize(26,26);
    setMaxLength(2);

    // ustawienie zakresu mozliwego do wpisania
    QRegExp zakresQLineEdit("[1-6]{0,1}[-,+]{1,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    validator->Acceptable;
    setValidator(validator);
    qDebug()<< "dziala";
    // school->scene->addWidget(linia);
}
