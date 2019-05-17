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


int musico_alta(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[], int sizeM,int sizeI,int sizeO, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(arrayM,size,&posicion)==-1)                          //
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre\n: ","\nNombre no valido",1,TEXT_SIZE,3,arrayM[posicion].nombre);
            utn_getName("Ingrese el apellido\n: ","\nApelldio no valido",1,TEXT_SIZE,3,arrayM[posicion].apellido);
            utn_getUnsignedInt("\nIngrese la edad","\nEdad no valida",1,sizeof(int),1,100,3,&arrayM[posicion].edad);
            orquesta_listar(arrayO,sizeO);
            utn_getUnsignedInt("\ingrese el ID de la orquesta ","\nvalor no valido",1,sizeof(int),1,sizeO,1,&arrayM[posicion].idOrquesta);
            instrumento_listar(arrayI,sizeI);
            utn_getUnsignedInt("\nIngrese el ID del Instrumento","\nvalor no valido",1,sizeof(int),1,sizeI,1,&arrayM[posicion].idInstrumento);
            printf("\n Posicion: %d\n ID: %d\ Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   posicion, arrayM[posicion].id,arrayM[posicion].nombre,arrayM[posicion].apellido,arrayM[posicion].edad,arrayM[posicion].idOrquesta,arrayM[posicion].idInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nIngrese el ID ","\nID no valido",1,sizeof(int),1,sizeArray,3,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].id=0;
            array[posicion].edad=0;
            array[posicion].idInstrumento=0;
            array[posicion].idOrquesta=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}


int musico_listar(Musico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                 printf("\n ID: %d\ Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
        }
        retorno=0;
    }
    return retorno;
}




