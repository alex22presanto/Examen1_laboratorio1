#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Informes.h"
#include "Orquesta.h"
#define TEXT_SIZE 51

int orquesta_lista_mas5(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO)
{
    int contador=0;
    int retorno=-1;
    int buffer;
    int i;
    int posicion;
    if(arrayM!=NULL && arrayO!=NULL && sizeM>0 && sizeO>0)
    {
        buffer= arrayM[0].idOrquesta;
        for(i=1;i<sizeM;i++)
        {
            if(arrayM[i].idOrquesta==buffer && contador<=5)
            {
                contador++;
            }
            else
            {
                contador=0;
                buffer=arrayM[i].idOrquesta;
            }
            if(contador==5)
            {
                orquesta_buscarID(arrayO,sizeO,arrayM[i].idOrquesta,&posicion);
                switch(arrayO[posicion].tipo)
                {
                    case 1:
                        printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                            posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
                        break;
                    case 2:
                        printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                            posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
                        break;
                    case 3:
                        printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                            posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int muscio_lista_mas30(Musico array[],int size)
{
    int retorno=-1;
    int i;
    if (array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].edad>=30)
            {
                printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}

int orquesta_lista_xLugar(Orquesta array[],int size)
{
    int retorno=-1;
    int posicion;
    char lugar[TEXT_SIZE];
    if (array!=NULL && size>0)
    {
        utn_getName("\nIngrese el lugar a buscar\n","\n No valido",1,TEXT_SIZE,3,&lugar);
        orquesta_buscarString(array,size,lugar,posicion);
        switch(array[posicion].tipo)
        {
            case 1:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                    posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
                break;
            case 2:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                    posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
                break;
            case 3:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                    posicion, array[posicion].id,array[posicion].nombre,array[posicion].lugar);
        }
        retorno=0;
    }
    return retorno;
}

int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lugar,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int musico_listar_xOrquesta(Musico array[],int size,int maxidO)
{
    int retorno=-1;
    int i;
    int id;
    if(array!=NULL && size>0)
    {
        utn_getUnsignedInt("\nIngrese el id de la orquesta\n","\nId no valido\n",1,sizeof(int),1,int maxidO,3,id);
        for(i=0;i<size,i++)
        {
            if(array[i].idOrquesta==id)
            {
                 printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}

int orquesta_lista_masMusicos(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO)
{
    int retorno=-1;
    int i=0;
    int posicion;
    int id=-1;
    int id2;
    int contador1=0;
    int contador2=0;
    if(arrayM!=NULL && arrayO!=NULL && sizeM>0 && sizeO>0)
    {
        for(i=0;i<sizeM;i++)
        {
            if(id==arrayM[i].idOrquesta || i==0)
            {
                contador1++;
                if(i==0)
                {
                    id = arrayM[i].idOrquesta;
                }
            }
            else
            {
                    if(contador1>caontador2)
                    {
                        contador2==1
                        id2=id;
                    }
            id = arrayM[i].idOrquesta;
            contador1=0;
            }
        }
        orquesta_buscarID(arrayO,sizeO,id2,&posicion);
        switch(array[posicion].tipo)
        {
            case 1:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
                break;
            case 2:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
                break;
            case 3:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar);
        }
        retorno =0;
    }
    return retorno;
}

int musico_promedio_xOrquesta(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO)
{
    int retorno=-1;
    int i;
    int contadorM=0;
    int contadorO=0;
    int promedio;
    if(arrayM!=NULL && arrayO!=NULL && sizeM>0 && sizeO>0)
    {
        for(i=0;i<sizeM;i++)
        {
            if(arrayM[i].isEmpty!=1)
            {
                contadorM++;
            }
        }
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty!=1)
            {
                contadorO++;
            }
        }
        promedio=contadorM/contadorO;
        printf("\n El promedio de musicos por orquesta es: %d\n",promedio);
        retorno=0;
    }
    return retorno;
}
