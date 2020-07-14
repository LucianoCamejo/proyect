/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#include "Triangulo.h"
Triangulo::Triangulo(double lado1,double altura1)
{
    if(lado1<=0 || altura1<=0)
        throw FiguraInvalidaException("Figura Invalida");
    this->lado=lado1;
    this->altura=altura1;
}

double Triangulo::area()const
{
    return this->lado*this->altura/2;
}
