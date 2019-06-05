#ifndef INSTURMENTO_H_INCLUDED
#define INSTURMENTO_H_INCLUDED
#define TEXT_SIZE 51

typedef struct
{
    int id;
    int isEmpty;
    char nombre[TEXT_SIZE];
    int tipo;
}Instrumento;


#endif // INSTURMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_listar(Instrumento array[], int size);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);


