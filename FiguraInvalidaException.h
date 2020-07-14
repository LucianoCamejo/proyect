/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_
class FiguraInvalidaException  /// no desarrollé en FiguraInvalidaException.cpp
{                              ///porque el archivo no vino incluido en el proyecto
private:                       ///no quise agregar nada que no haya venido en el proyecto
    const char* mensaje;
public:
    FiguraInvalidaException(const char* mens)
    {
        this->mensaje=mens;
    }
    const char* what()
    {
        return this->mensaje;
    }
};







#endif // FIGURAINVALIDAEXCEPTION_H_
