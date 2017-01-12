#include "input3.h"

Input3::Input3(int X, int Y, int value)
{

    Value = value;
    // przygotowanie pola do pisania
    QLineEdit::setGeometry(X,Y,26,240);
    QLineEdit::setFixedSize(26,240);


}

Input3::~Input3()
{

}
