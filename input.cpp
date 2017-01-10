#include "input.h"

#include "school.h"
extern School* school;
Input::Input(int X, int Y, int Z)
{
    // przygotowanie pola do pisania
    setGeometry(X,Y,26,26);
    setFixedSize(26,26);
    setMaxLength(2);

    // ustawienie zakresu mozliwego do wpisania
    QRegExp zakresQLineEdit("[1-6]{0,1}[-,+]{1,1}");
    QValidator *validator = new QRegExpValidator(zakresQLineEdit,this);
    Value = Z;
    setValidator(validator);

    setFocusPolicy(Qt::StrongFocus);


}
Input::~Input()
{
    QObject::disconnect(this,SIGNAL(editingFinished()),school,SLOT(zbieranie()));
}

