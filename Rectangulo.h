/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include"Figura.h"
class Rectangulo: public Figura
{
private:
    double ancho,
           alto;
public:
    Rectangulo(double=1,double=1);
    double area()const;

};

#endif // RECTANGULO_H_
