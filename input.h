#ifndef INPUT_H
#define INPUT_H


#include <QLineEdit>
#include <QValidator>
#include <QDebug>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>


class Input : public QLineEdit
{
public:
    Input(int X,int Y,int Z,QString ID,QString nazwakolumny);
    ~Input();
    int X;
    int Y;
    int Value ;

    QString IDwTabeli;
    QString nazwaKolumny;
signals:
    void editingFinished();

public slots:
    void stworz();
};

#endif // INPUT_H
