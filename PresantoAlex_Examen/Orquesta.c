#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Orquesta.h"
#define TEXT_SIZE 51


/** \brief  inicializa la array en el campo .isEmpty en 1
*
* \param array Orquesta Array de Orquesta
* \param size int tamaño de array
* \return int Return (-1) si array=NULL o size<0 (0) si Ok
*
*/
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

/** \brief buscar en el campo isEmpty de una array la primer posicion que se encuentre vacia(1)
 * \param array Orquesta Array de orquesta
 * \param size int tamaño de array
 * \param posicion int* puntero a la posicion que se encontro vacia
 * \return int Return (-1) si array=NULL,posicion=NULL, size<0 o no se encuntra posicion  (0) si se encuentra posicion vacia
 *
 */
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

/** \brief busca el id(ingresado por el usuario) en una array de Orquesta
 * \param array Orquesta Array de orquesta
 * \param size int tamaño de array
 * \param valorBuscado int id a buscar
 * \param posicion int* puntero de la posicion encontrada
 * \return int Return (-1) si array=NULL, size<0 o no se encontro el id (0) si encontro el id
 *
 */
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
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
 * \param array Orquesta Array de orquesta
 * \param size int tamaño de array
 * \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
 * \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
 *
 */
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
                    break;
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array Orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
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

/** \brief imprime todos los elementos de una array de orquesta
 * \param array Orquesta Array de orquesta
 * \param size int tamaño de array
 * \return int Return (-1) si array=NULL o size<0 (0) si Ok
 *
 */

int orquesta_listar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty!=1)
            {
                switch(array[i].tipo)
                {
                    case 1:
                        printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica",
                            array[i].id,array[i].nombre,array[i].lugar);
                        break;
                    case 2:
                        printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica",
                            array[i].id,array[i].nombre,array[i].lugar);
                        break;
                    case 3:
                        printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara",
                            array[i].id,array[i].nombre,array[i].lugar);
                        break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

