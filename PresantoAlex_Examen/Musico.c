#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Musico.h"
#include "Insturmento.h"
#include "Orquesta.h"
#define TEXT_SIZE 51


int musico_Inicializar(Musico array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int musico_buscarEmpty(Musico array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int musico_alta(Musico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre\n: ","\nNombre no valido",1,TEXT_SIZE,3,array[posicion].nombre);
            utn_getName("Ingrese el apellido\n: ","\nApelldio no valido",1,TEXT_SIZE,3,array[posicion].apellido);
            utn_getUnsignedInt("\nIngrese la edad","\nEdad no valida",1,sizeof(int),1,100,3,&array[posicion].edad);
            orquesta_listar()
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idInstrumento);
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idOrquesta);
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}
