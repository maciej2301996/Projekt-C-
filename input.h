#ifndef INPUT_H
#define INPUT_H


#include <QLineEdit>
#include <QValidator>
#include <QDebug>

class Input : public QLineEdit
{
public:
    Input();

signals:
    void wyslij();

public slots:
    void stworz();
};

#endif // INPUT_H
