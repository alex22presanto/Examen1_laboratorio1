#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Musico.h"
#include "Insturmento.h"
#include "Orquesta.h"
#define TEXT_SIZE 51

/** \brief  inicializa la array en el campo .isEmpty en 1
*
* \param array Musico Array de musico
* \param size int tamaño de array
* \return int Return (-1) si array=NULL o size<0 (0) si Ok
*
*/
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

/** \brief buscar en el campo isEmpty de una array la primer posicion que se encuentre vacia(1)
 * \param array Musico Array de Musico
 * \param size int tamaño de array
 * \param posicion int* puntero a la posicion que se encontro vacia
 * \return int Return (-1) si array=NULL,posicion=NULL, size<0 o no se encuntra posicion  (0) si se encuentra posicion vacia
 *
 */
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

/** \brief busca el id(ingresado por el usuario) en una array de Musico
 * \param array Musico Array de musico
 * \param size int tamaño de array
 * \param valorBuscado int id a buscar
 * \param posicion int* puntero de la posicion encontrada
 * \return int Return (-1) si array=NULL, size<0 o no se encontro el id (0) si encontro el id
 *
 */
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion != NULL && valorBuscado>0)
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

 /** \brief Solicita los datos para completar la primer posicion vacia de un array
 * \param array Musico Array de musico
 * \param size int tamaño de array
 * \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
 * \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
 *
 */
int musico_alta(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[], int sizeM,int sizeI,int sizeO, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(arrayM!=NULL && sizeM>0 && arrayI!=NULL && sizeI>0 && arrayO!=NULL && sizeO>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(arrayM,sizeM,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayM[posicion].id=*contadorID;
            arrayM[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre\n: ","\nNombre no valido",1,TEXT_SIZE,3,arrayM[posicion].nombre);
            utn_getName("Ingrese el apellido\n: ","\nApelldio no valido",1,TEXT_SIZE,3,arrayM[posicion].apellido);
            utn_getUnsignedInt("\nIngrese la edad","\nEdad no valida",1,sizeof(int),1,100,3,&arrayM[posicion].edad);
            orquesta_listar(arrayO,sizeO);
            utn_getUnsignedInt("\n Ingrese el ID de la orquesta ","\nvalor no valido",1,sizeof(int),1,sizeO,1,&arrayM[posicion].idOrquesta);
            instrumento_listar(arrayI,sizeI);
            utn_getUnsignedInt("\nIngrese el ID del Instrumento","\nvalor no valido",1,sizeof(int),1,sizeI,1,&arrayM[posicion].idInstrumento);
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   posicion, arrayM[posicion].id,arrayM[posicion].nombre,arrayM[posicion].apellido,arrayM[posicion].edad,arrayM[posicion].idOrquesta,arrayM[posicion].idInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array Musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
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

/** \brief Busca un elemento por ID y modifica el campo que el ususario seleccione
* \param array Muscio Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[],int sizeM,int sizeI,int sizeO)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(arrayM!=NULL && sizeM>0 && arrayI!=NULL && sizeI>0 && arrayO!=NULL && sizeO>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nID no valido",1,sizeof(int),1,sizeM,1,&id);
        if(musico_buscarID(arrayM,sizeM,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   posicion, arrayM[posicion].id,arrayM[posicion].nombre,arrayM[posicion].apellido,arrayM[posicion].edad,arrayM[posicion].idOrquesta,arrayM[posicion].idInstrumento);
                utn_getUnsignedInt("\n\n Que desa modificar?\n1- Nombre \n2- Apellido \n3- Edad \n4- Orquesta \n5- Instrumnto\n6-Salir","\nValor ingresado no valido",1,sizeof(int),1,6,3,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("Ingrese el nombre\n: ","\nNombre no valido",1,TEXT_SIZE,3,arrayM[posicion].nombre);
                        break;
                    case 2:
                        utn_getName("Ingrese el apellido\n: ","\nApelldio no valido",1,TEXT_SIZE,3,arrayM[posicion].apellido);
                        break;
                    case 3:
                        utn_getUnsignedInt("\nIngrese la edad","\nEdad no valida",1,sizeof(int),1,100,3,&arrayM[posicion].edad);
                        break;
                    case 4:
                        orquesta_listar(arrayO,sizeO);
                        utn_getUnsignedInt("\n Ingrese el ID de la orquesta ","\nvalor no valido",1,sizeof(int),1,sizeO,1,&arrayM[posicion].idOrquesta);
                        break;
                    case 5:
                        instrumento_listar(arrayI,sizeI);
                        utn_getUnsignedInt("\nIngrese el ID del Instrumento","\nvalor no valido",1,sizeof(int),1,sizeI,1,&arrayM[posicion].idInstrumento);
                        break;
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief imprime todos los elementos de una array de musico
 * \param array Musico Array de musico
 * \param size int tamaño de array
 * \return int Return (-1) si array=NULL o size<0 (0) si Ok
 *
 */

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
                 printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
        }
        retorno=0;
    }
    return retorno;
}




