#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#define TEXT_SIZE 51
#include "Orquesta.h"
#include "Insturmento.h"

typedef struct
{
    int id;
    int isEmpty;
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;




int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_baja(Musico array[], int size);
int musico_alta(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[], int sizeM,int sizeI,int sizeO, int* contadorID);
int musico_modificar(Musico arrayM[],Instrumento arrayI[],Orquesta arrayO[],int sizeM,int sizeI,int sizeO);
int musico_listar(Musico array[], int size);

#endif // MUSICO_H_INCLUDED
