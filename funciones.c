/**//* 41.764.906-CAMEJO,LucianoIvan-(03-2676) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#include<string.h>
#include<stdlib.h>
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(d)
        fprintf(fp,"%s %-*s %d%3d\n",((tFinal*)d)->dni,(int)sizeof(((tFinal*)d)->apYNom)-1,
                ((tFinal*)d)->apYNom,((tFinal*)d)->codMat,((tFinal*)d)->calif);
    else
        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");

}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    return strcmp(((tFinal*)d1)->dni,((tFinal*)d2)->dni);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    ((tFinal*)(*dest))->calif+=((tFinal*)orig)->calif;
    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
  int prom=(((tFinal*)d2)->calif/(float)cantCalif)+0.5;
  fprintf(fp,"   --- Rindio %d final(es) con un promedio de:%3d\n\n",cantCalif,prom);
}


/**//* para el TDA LISTA                                                  *//**/

tNodo* mayorOcurrencia(tLista*,int (*comparar)(const void*,const void*),int*);

tNodo* mayorOcurrencia(tLista* p,int (*comparar)(const void*,const void*),int* total)
{
    tNodo *anterior,
           *mayor,
           *mov;
    int contador,
        totalMayor=0,
        cant=(*total)/2,
        recorrido=0,
        comp;
    while(*p)
    {
        mov=(*p)->sig;
        contador=1;
        while(mov)
        {
            if(!comparar(mov->info,(*p)->info))
                contador++;
            mov=mov->sig;
        }
        if(totalMayor<contador)
        {
            totalMayor=contador;
            mayor=*p;
        }
        recorrido++;
        p=&(*p)->sig;
        if(recorrido<cant)                      ///a partir del if comparo que la cantidad de nodos verificados sea
        {                                       ///menor a la mitad del total de nodos.
            comp=0;                             ///En el segundo while, como tengo la posibilidad de acceder a los
            while(recorrido<cant && !comp)      ///nodos anteriores,comparo la clave del nodo actual con la de los nodos
            {                                   /// anteriores y de esa manera verifico que la clave actual todavia
                anterior=(*p)->ant;             ///no haya sido aparecido.Solo comparo hasta la mitad porque en el caso de
                while(anterior && (comp=comparar(anterior->info,(*p)->info)))///que una clave despues de la mitad todavia
                    anterior=anterior->ant;                                ///no haya aparecido me evito comparar con todos
                if(!comp)                                                  ///los nodos anteriores en vano.
                {
                    p=&(*p)->sig;
                    recorrido++;
                }
            }
        }
    }
    *total-=totalMayor;
    return mayor;
}


int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    int cont=0;
    if(!*p)
        return cont;
    if(fp)
        mostrar(NULL,fp);
    while((*p)->ant)
        p=&(*p)->ant;
    while(*p)
    {
        if(fp)
            mostrar((*p)->info,fp);
        cont++;
        p=&(*p)->sig;
    }
    return cont;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    int total=0;
    tNodo* act=*p,
            *mov,
            *mayor,
            *sig,
            *ant;
    if(!*p)
        return;
    while(*p)           ///estos dos primeros while son para contar la cantidad de nodos
    {                   ///porque lo voy a utilizar en mi funcion de mayorOcurrencia
        p=&(*p)->sig;
        total++;
    }
    p=&act;
    while((*p)->ant)
    {
        p=&(*p)->ant;
        total++;
    }
    act=*p;
    while(act)
    {
        mov=act;
        mayor=mayorOcurrencia(&act,comparar,&total);///esta funcion esta en la linea 55
        while(mov)
        {
            sig=mov->sig;
            if(!comparar(mayor->info,mov->info))
            {
                if(mov!=act)
                {
                    ant=mov->ant;
                    mov->ant=act->ant;
                    if(mov->ant)
                        mov->ant->sig=mov;
                    act->ant=mov;
                    mov->sig=act;
                    ant->sig=sig;
                    if(sig)
                        sig->ant=ant;
                }
                else
                    act=act->sig;
            }
            mov=sig;
        }
    }
}


int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                           const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    tNodo* act,*elim;
    int cont=0,cantCalif;
    if(!*p)
        return cont;
    while((*p)->ant)
        *p=(*p)->ant;
    while(*p)
    {
        act=*p;
        mostrar(NULL,fp);
        mostrar(act->info,fp);
        *p=(*p)->sig;
        cantCalif=1;
        while(*p && !comparar((*p)->info,act->info))
        {
            if(acumular)
                acumular(&act->info,&act->tamInfo,(*p)->info,(*p)->tamInfo);
            mostrar((*p)->info,fp);
            elim=*p;
            *p=(*p)->sig;
            free(elim->info);
            free(elim);
            cantCalif++;
        }
        mostrar2(act->info,cantCalif,fp);
        free(act->info);
        free(act);
        cont+=cantCalif;
    }
    return cont;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

