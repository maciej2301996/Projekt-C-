#ifndef INPUT3_H
#define INPUT3_H

#include <QLineEdit>


class Input3 : public QLineEdit
{
public:
    Input3(int X,int Y,int value);

    ~Input3();

    int Value;
private :

};

#endif // INPUT3_H
