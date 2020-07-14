/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"
class Figura
{
public:
    virtual double area()const=0;
    virtual ~Figura(){}///iba poner virtual ~Figura()=default pero creo que para versiones anteriores
};                      ///de codeblocks no compila





#endif // FIGURA_H_
