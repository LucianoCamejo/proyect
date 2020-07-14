/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#ifndef CUADRADO_H_
#define CUADRADO_H_
#include"Figura.h"
class Cuadrado: public Figura
{
private:
    double lado;
public:
    Cuadrado(double=1);
    double area()const;

};







#endif // CUADRADO_H_
