/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676)*//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include"Figura.h"
class Triangulo: public Figura
{
private:
    double lado,
           altura;
public:
    Triangulo(double=1, double=1);
    double area()const;

};







#endif // TRIANGULO_H_
