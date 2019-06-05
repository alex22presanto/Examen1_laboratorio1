#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Informes.h"
#include "Orquesta.h"
#define TEXT_SIZE 51


/** \brief Inicializa las primeras 6 posiciones del array
 *          musico
 * \param   array Musico Array de Musico
 * \return  Void
 *
 */

void harcodearMusico(Musico array[])
{
    int i;
    Musico x[6]=
    {
        {1,0,"musico1","Amus1",30,1,2},
        {2,0,"musico2","Amus2",20,2,5},
        {3,0,"musico3","Amus3",25,4,2},
        {4,0,"musico4","Amus4",27,4,1},
        {5,0,"musico5","Amus5",22,1,3},
        {6,0,"musico6","Amus6",35,3,4},
    };
    for(i=0;i<6;i++)
        array[i]=x[i];
}

/** \brief Inicializa las primeras 4 posicionse del array
 *          orquesta
 * \param   array Orquesta Array de Orquesta
 * \return  Void
 *
 */

void harcodearOrquesta(Orquesta array[])
{
    int i;
    Orquesta x[4]=
    {
        {1,0,"Orquesta1","lugarA",1},
        {2,0,"Orquesta2","lugarB",2},
        {3,0,"Orquesta3","lugarC",3},
        {4,0,"Orquesta4","lugarD",4},
    };
    for(i=0;i<4;i++)
        array[i]=x[i];
}

/** \brief Inicializa las primeras 5 posicionse del array
 *          instrumento
 * \param   array Instrumento Array de Instrumento
 * \return  Void
 *
 */

void harcodearInstrumento(Instrumento array[])
{
    int i;
    Instrumento x[5]=
    {
        {1,0,"instr1",1},
        {2,0,"instr2",2},
        {3,0,"instr3",2},
        {4,0,"instr4",3},
        {5,0,"instr5",4},
    };
    for(i=0;i<5;i++)
        array[i]=x[i];
}
/** \brief Imprime orquestas con mas de 5 musicos
 * \param arrayM Musico array de musicos
 * \param arrayO Orquesta array de orquesta
 * \param sizeM int tamaño del arrayM
 * \param sizeO int tamaño del arrayO
 * \return int return (-1) error arrayM = NULL, arrayO= NULL, sizeM<0 o sizeO<0 (0) si se realiza todo OK
 *
 */

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

/** \brief Imprime musicos con mas de 30 años
 * \param array Musico array de musicos
 * \param size int tamaño del array
 * \return int return (-1) error array = NULL o size<0 (0) si se realiza todo OK
 *
 */

int muscio_lista_mas30(Musico array[],int size)
{
    int retorno=-1;
    int i;
    if (array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].edad>=30 && array[i].isEmpty == 0)
            {
                printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Imprime orquestas de un lugar ingresado por el usuario
 * \param array Orquesta array de orquesta
 * \param size int tamaño del array
 * \return int return (-1) error array = NULL o size<0 (0) si se realiza todo OK
 *
 */

int orquesta_lista_xLugar(Orquesta array[],int size)
{
    int retorno=-1;
    int posicion;
    char lugar[TEXT_SIZE];
    if (array!=NULL && size>0)
    {
        utn_getName("\nIngrese el lugar a buscar\n","\n No valido",1,TEXT_SIZE,3,&lugar);
        orquesta_buscarString(array,size,lugar,&posicion);
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
/** \brief busca en el campo .lugar de una orquesta un string ingresado por el usuario
 * \param array Orquesta array de orquesta
 * \param size int tamaño del array
 * \param valorBuscado char* string a buscar
 * \param indice int* poscion donde se encuentra el valorBuscado
 * \return int return (-1) error array = NULL, size<0, valorBuscado = NULL o indice =NULL (0) si se realiza todo OK
 *
 */
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 && valorBuscado!=NULL && indice != NULL)
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

/** \brief Imprime todos los musicos de una misma orquesta
 * \param array Musico array de musicos
 * \param size int tamaño del array
 * \param maxidO int tamaño maximo de id de orquesta
 * \return int return (-1) error array = NULL, size<0 o maxidO<0 (0) si se realiza todo OK
 *
 */
int musico_listar_xOrquesta(Musico array[],int size,int maxidO)
{
    int retorno=-1;
    int i;
    int id;
    if(array!=NULL && size>0 && maxidO>0)
    {
        utn_getSignedInt("ingrese el id","id no valido",1,sizeof(int),1,maxidO,3,&id);
        for(i=0;i<size;i++)
        {
            if(array[i].idOrquesta==id && array[i].isEmpty == 0)
            {
                 printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\nEdad: %d\n ID orquesta: %d\n ID instrumento: %d",
                   array[i].id,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
            }
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Imprime orquestas con mas musicos
 * \param arrayM Musico array de musicos
 * \param arrayO Orquesta array de orquesta
 * \param sizeM int tamaño del arrayM
 * \param sizeO int tamaño del arrayO
 * \return int return (-1) error arrayM = NULL, arrayO= NULL, sizeM<0 o sizeO<0 (0) si se realiza todo OK
 *
 */
int orquesta_lista_masMusicos(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO)
{
    int retorno=-1;
    int i=0;
    int posicion;
    int id=-1;
    int id2=-1;
    int contador1=0;
    int contador2=0;
    if(arrayM!=NULL && arrayO!=NULL && sizeM>0 && sizeO>0)
    {
        for(i=0;i<sizeM;i++)
        {
            if(id==arrayM[i].idOrquesta || i==0)
            {
                contador1++;
                if(id==-1)
                {
                    id = arrayM[i].idOrquesta;
                }
            }
            else
            {
                    if(contador1>contador2 || id2==-1)
                    {
                        contador2=contador1;
                        id2=id;
                    }
            id = arrayM[i].idOrquesta;
            contador1=0;
            }
            printf("asd  %d",id);
        }
        orquesta_buscarID(arrayO,sizeO,id2,&posicion);
        switch(arrayO[posicion].tipo)
        {
            case 1:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Sinfonica\n Cantidad de musicos: %d \n",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar,contador2);
                break;
            case 2:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Filarmonica\n Cantidad de musicos: %d \n",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar,contador2);
                break;
            case 3:
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: Camara\n Cantidad de musicos: %d \n",
                    posicion, arrayO[posicion].id,arrayO[posicion].nombre,arrayO[posicion].lugar,contador2);
        }
        retorno =0;
    }
    return retorno;
}

/** \brief promedio de musicos por orquesta
 * \param arrayM Musico array de musicos
 * \param arrayO Orquesta array de orquesta
 * \param sizeM int tamaño del arrayM
 * \param sizeO int tamaño del arrayO
 * \return int return (-1) error arrayM = NULL, arrayO= NULL, sizeM<0 o sizeO<0 (0) si se realiza todo OK
 *
 */
int musico_promedio_xOrquesta(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO)
{
    int retorno=-1;
    int i;
    int contadorM=0;
    int contadorO=0;
    float promedio;
    if(arrayM!=NULL && arrayO!=NULL && sizeM>0 && sizeO>0)
    {
        for(i=0;i<sizeM;i++)
        {
            if(arrayM[i].isEmpty!=1)
            {
                contadorM++;
                printf("%d",contadorM);
            }
        }
        for(i=0;i<sizeO;i++)
        {
            if(arrayO[i].isEmpty!=1)
            {
                contadorO++;
                printf("%d",contadorO);
            }
        }
        promedio=contadorM/contadorO;
        printf("\n El promedio de musicos por orquesta es: %d\n",promedio);
        retorno=0;
    }
    return retorno;
}

/** \brief Imprime musico que tengan istrumento de cuerda
 * \param arrayM Musico array de musicos
 * \param arrayI Instrumento array de instrumento
 * \param sizeM int tamaño del arrayM
 * \param sizeI int tamaño del arrayI
 * \return int return (-1) error arrayM = NULL, arrayI= NULL, sizeM<0 o sizeI<0 (0) si se realiza todo OK
 *
 */
int musico_listar_xIstrumento_cuerda(Musico arrayM[],Instrumento arrayI[],int sizeM, int sizeI)
{
    int retorno=-1;
    int i;
    int j;
    int posicion;
    if(arrayM!=NULL && arrayI!=NULL && sizeM>0 && sizeI>0)
    {
        for(i=0;i<sizeM;i++)
        {
            j=instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&posicion);
            if ( j!=0 )
            {
                retorno=-1;
                break;
            }
            if(arrayI[posicion].tipo == 1)
            {
                    printf("\n Nombre: %s\n Apelldio: %s\nEdad: %d\n Nombre del instrumento: %s\n Tipo instrumento: Cuerda\n",
                        arrayM[i].nombre,arrayM[i].apellido,arrayM[i].edad,arrayI[posicion].nombre);
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Imprime orquestas completa (minimo: 5 instrumentos de cuerda,3 de viento, 2 de percucion )
 * \param arrayM Musico array de musicos
 * \param arrayI Instrumento array de instrumento
 * \param arrayO Orquesta array de orquesta
 * \param sizeM int tamaño del arrayM
 * \param sizeI int tamaño del arrayI
 * \param sizeO int tamaño del arrayO
 * \return int return (-1) error arrayM = NULL, arrayI= NULL, arrayO= NULL, sizeM<0, sizeI<0 o sizeO<0 (0) si se realiza todo OK
 *
 */
int orquesta_listar_completa(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[],int sizeM,int sizeI, int sizeO)
{
    int retorno=-1;
    int i=0;
    int posicion;
    int idO;
    int contadorC;
    int contadorV;
    int contadorP;
    int j;
    if(arrayM!=NULL && arrayI!=NULL && arrayO!=NULL && sizeM>0 && sizeI>0 && sizeO>0)
    {
        idO= arrayM[i].idOrquesta;
        for(i=0;i<sizeM;i++)
        {
            if(arrayM[i].idOrquesta == idO)
            {
                j=instrumento_buscarID(arrayI,sizeI,arrayM[i].idInstrumento,&posicion);
                if ( j!=0 )
                {
                    retorno=-1;
                    break;
                }
                switch(arrayI[posicion].tipo)
                {
                case 1:
                    contadorC++;
                    break;
                case 2:
                case 3:
                    contadorV++;
                    break;
                case 4:
                    contadorP++;
                    break;
                }
            }
            else
            {
                if(contadorC >= 5 && contadorV >= 3 && contadorP >=2)
                {
                    j=orquesta_buscarID(arrayO,sizeO,idO,&posicion);
                    if ( j!=0 )
                    {
                        retorno=-1;
                        break;
                    }
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
                            break;
                    }
                    idO= arrayM[i].idOrquesta;
                    contadorC = 0;
                    contadorV = 0;
                    contadorP = 0;
                }
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief ordena musico por variable .idOrquesta
 * \param array Musico array de musicos
 * \param size int tamaño del array
 * \return int return (-1) error array = NULL o size<0 (0) si se realiza todo OK
 *
 */
int musico_ordenar_xIDorquesta(Musico array[],int size)
{
    int retorno=-1;
    int i, j;
    Musico bufferMusico;
    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferMusico=array[i];
            j = i - 1;
            while ((j >= 0) && bufferMusico.idOrquesta<=array[j].idOrquesta)
            {
                array[j + 1]=array[j];
                j--;
            }
            array[j + 1]=bufferMusico;
        }
        retorno=0;
    }
    return retorno;
}
