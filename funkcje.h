#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "school.h"


class funkcje : public QObject
{   Q_OBJECT
public:
    funkcje();

void sygnal();  // tworzy polaczenie

public slots :
    void polaczSchool();
    void wykonajPolaczeniezInputem();
    void wykonajPolaczeniezInputemdlaDodatkowychKolumn();
};
#endif // FUNCKJE_H
