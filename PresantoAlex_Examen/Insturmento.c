#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Insturmento.h"
#define TEXT_SIZE 51


int instrumento_Inicializar(Instrumento array[], int size)                                    /
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

int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
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


int instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].id=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre del instrumento\n: ","\nnombre no valido",1,TEXT_SIZE,3,array[posicion].nombre);
            utn_getUnsignedInt("\nIngrese el tipo de instrumento:\n\n1.Cuerda \n2.Viento-madera\n3.Viento.metal\n4.Percusion","\nValor ingresado no valido",1,sizeof(int),1,4,3,&array[posicion].tipo);
            if(array[posicion].tipo==1)
            {
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Cuerda",
                    posicion, array[posicion].id,array[posicion].nombre);
            }else if(array[posicion].tipo==2)
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-madera",
                    posicion, array[posicion].id,array[posicion].nombre);
            }else if(array[posicion].tipo==3)
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-metal ",
                    posicion, array[posicion].id,array[posicion].nombre);
            }
            else
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Percusion",
                    posicion, array[posicion].id,array[posicion].nombre);
            }
            retorno=0;
        }
    }
    return retorno;
}

int instrumento_listar(Instrumento array[], int size)
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
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Cuerda",
                        array[i].id,array[i].nombre);
                }else if(array[i].tipo==2)
                {
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-madera",
                        array[i].id,array[i].nombre);
                }else if(array[i].tipo==3)
                {
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-metal ",
                        array[i].id,array[i].nombre);
                }
                else
                {
                    printf("\n ID: %d\n Nombre: %s\n Tipo: Percusion",
                        array[i].id,array[i].nombre);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}


