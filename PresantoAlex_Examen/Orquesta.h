#ifndef Orquesta_H_INCLUDED
#define Orquesta_H_INCLUDED
#define TEXT_SIZE 51

typedef struct
{
    int id;
    int isEmpty;
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;
}Orquesta;


#endif // Orquesta_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
int orquesta_baja(Orquesta array[], int sizeArray);
int orquesta_listar(Orquesta array[], int size);

