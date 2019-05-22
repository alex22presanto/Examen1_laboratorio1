#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Orquesta.h"
#include "Insturmento.h"
#include "Musico.h"

int orquesta_lista_mas5(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO);
int muscio_lista_mas30(Musico array[],int size);
int orquesta_lista_xLugar(Orquesta array[],int size);
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);
int musico_listar_xOrquesta(Musico array[],int size,int maxidO);
int orquesta_lista_masMusicos(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO);
int musico_promedio_xOrquesta(Musico arrayM[],Orquesta arrayO[],int sizeM, int sizeO);


#endif // INFORMES_H_INCLUDED
