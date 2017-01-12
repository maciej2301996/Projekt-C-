#include "lista.h"

Lista::Lista(int X, int Y, int I, QSqlDatabase db)
{
    numer = I ;
    tables = db.tables();


    for(int i=0;i<tables.size();i++)
       {

        if("logowanie" != tables[i])
         {
           a = tables[i].split(QRegExp("_"));
           napis.append(a[numer]);
         }
        }
    napis.removeDuplicates();
    this->addItems(napis);
    setGeometry(X,Y,80,20);
}
Lista::~Lista()
{

}
