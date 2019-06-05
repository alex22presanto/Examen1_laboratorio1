#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Insturmento.h"
#define TEXT_SIZE 51

/** \brief  inicializa la array en el campo .isEmpty en 1
*
* \param array Instrumento Array de Instrumento
* \param size int tamaño de array
* \return int Return (-1) si array=NULL o size<0 (0) si Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)
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
 * \param array Instrumento Array de Instrumento
 * \param size int tamaño de array
 * \param posicion int* puntero a la posicion que se encontro vacia
 * \return int Return (-1) si array=NULL,posicion=NULL o size<0  (0) si Ok
 *
 */
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

 /** \brief Solicita los datos para completar la primer posicion vacia de un array
 * \param array Instrumento Array de Instrumento
 * \param size int tamaño de array
 * \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
 * \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
 *
 */
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
            switch(array[posicion].tipo)
            {
                case 1:
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Cuerda",
                        posicion, array[posicion].id,array[posicion].nombre);
                    break;
                case 2:
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-madera",
                        posicion, array[posicion].id,array[posicion].nombre);
                    break;
                case 3:
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Viento-metal ",
                        posicion, array[posicion].id,array[posicion].nombre);
                    break;
                case 4:
                    printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Tipo: Percusion",
                        posicion, array[posicion].id,array[posicion].nombre);
                    break;
            }
            retorno=0;
        }
    }
    return retorno;
}
/** \brief imprime todos los elementos de una array de instrumentos
 * \param array Instrumento Array of Instrumento
 * \param size int tamaño de array
 * \return int Return (-1) si array=NULL o size<0 (0) si Ok
 *
 */

int instrumento_listar(Instrumento array[], int size)
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
                        printf("\n ID: %d\n Nombre: %s\n Tipo: Cuerda",
                            array[i].id,array[i].nombre);
                        break;
                    case 2:
                        printf("\n ID: %d\n Nombre: %s\n Tipo: Viento-madera",
                            array[i].id,array[i].nombre);
                        break;
                    case 3:
                        printf("\n ID: %d\n Nombre: %s\n Tipo: Viento-metal ",
                            array[i].id,array[i].nombre);
                        break;
                    case 4:
                        printf("\n ID: %d\n Nombre: %s\n Tipo: Percusion",
                            array[i].id,array[i].nombre);
                        break;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
/** \brief busca el id(ingresado por el usuario) en una array de instrumento
 * \param array Instrumento Array of Instrumento
 * \param size int tamaño de array
 * \param valorBuscado int id a buscar
 * \param posicion int* puntero de la posicion encontrada
 * \return int Return (-1) si array=NULL, size<0 o no se encontro el id (0) si encontro el id
 *
 */

int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)
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

