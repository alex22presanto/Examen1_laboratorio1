#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Orquesta.h"
#define TEXT_SIZE 51



int orquesta_Inicializar(Orquesta array[], int size)
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


int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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


int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
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


int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].id=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre de la orquesta\n: ","\nNombre no valido ",1,TEXT_SIZE,3,array[posicion].nombre);
            utn_getTexto("Ingrese el lugar\n: ","\nLugar no valido",1,TEXT_SIZE,3,array[posicion].lugar);
            utn_getUnsignedInt("\nIngrese el tipo de orquesta: \n1.Sinfonica\n2.Filarmonica\n3.Camara","\nvalor ingresado no valido",1,sizeof(int),1,3,3,&array[posicion].tipo);
            if(array[posicion].tipo==1)
            {
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                   posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
            }else if(array[posicion].tipo==2)
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                   posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
            }
            else
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                   posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
            }
            retorno=0;
        }
    }
    return retorno;
}


int orquesta_baja(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        i=orquesta_listar(array,sizeArray);
        if(i==0)
        {
            utn_getUnsignedInt("\nIngrese el ID ","\nValor ingresado no valido",1,sizeof(int),1,sizeArray,1,&id);
            if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                array[posicion].isEmpty=1;
                array[posicion].id=0;
                array[posicion].tipo=0;
                strcpy(array[posicion].nombre,"");
                strcpy(array[posicion].lugar,"");
                retorno=0;
            }
        }
    }
    return retorno;
}


int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                if(array[i].tipo==1)
                {
                    printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                    array[i].id,array[i].nombre,array[i].lugar);
                }
                else if(array[i].tipo==2)
                {
                    printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                    array[i].id,array[i].nombre,array[i].lugar);
                }
                else
                {
                    printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                    array[i].id,array[i].nombre,array[i].lugar);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

