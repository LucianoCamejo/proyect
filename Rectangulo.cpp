/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#include "Rectangulo.h"


Rectangulo::Rectangulo(double ancho1,double alto1)
{
    if(ancho1<=0 || alto1<=0)
        throw FiguraInvalidaException("Figura Invalida");
    this->ancho=ancho1;
    this->alto=alto1;
}

double Rectangulo::area()const
{
    return this->ancho*this->alto;
}
