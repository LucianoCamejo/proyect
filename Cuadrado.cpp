/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#include"Cuadrado.h"
Cuadrado::Cuadrado(double lado1)
{
    if(lado1<=0)
        throw FiguraInvalidaException("Figura Invalida");
    this->lado=lado1;
}

double Cuadrado::area()const
{
    return this->lado*this->lado;
}


