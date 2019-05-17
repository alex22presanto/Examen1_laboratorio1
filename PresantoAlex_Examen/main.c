#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Insturmento.h"
#include "Musico.h"
#include "Orquesta.h"
#define QTY_TIPO_O 50
#define QTY_TIPO_I 20
#define QTY_TIPO_M 1000

int main()
{
    int opcion;
    int opcion2;
    int contadorIdOrquesta=0;
    int contadorIdInstrumento=0;
    int contadorIdMusico=0;
    Orquesta arrayOrquesta[QTY_TIPO_O];
    Musico arrayMusico[QTY_TIPO_M];
    Instrumento arrayInstrumento[QTY_TIPO_I];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO_O);
    instrumento_Inicializar(arrayInstrumento,QTY_TIPO_I);
    musico_Inicializar(arrayMusico,QTY_TIPO_M);
    do
    {
        utn_getUnsignedInt("\n\n1. Orquesta \n2. Instrumento \n3. Musico \n4. Salir \n",
                      "\nValor no valido",1,sizeof(int),1,4,3,&opcion);
        switch(opcion)
        {
            case 1:
                utn_getUnsignedInt("\n\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquesta","\nValor no valido",1,sizeof(int),1,3,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        orquesta_alta(arrayOrquesta,QTY_TIPO_O,&contadorIdOrquesta);
                        break;
                    case 2:
                        orquesta_baja(arrayOrquesta,QTY_TIPO_O);
                        break;
                    case 3:
                        orquesta_listar(arrayOrquesta,QTY_TIPO_O);
                }
                break;
            case 2:
                utn_getUnsignedInt("1.Agregar instrumento\n2.Imprimir","\n valor no valido",1,sizeof(int),1,2,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        instrumento_alta(arrayInstrumento,QTY_TIPO_I,&contadorIdInstrumento);
                        break;
                    case 2:
                        instrumento_listar(arrayInstrumento,QTY_TIPO_I);
                        break;
                }
                break;
            case 3:
                 utn_getUnsignedInt("\n\n1.Agregar musico\n2.Modificar musico\n3.Eliminar musico\n4.Imprimir orquesta","\n Valor ingresado no valido",1,sizeof(int),1,3,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        musico_alta(arrayMusico,QTY_TIPO_M,&contadorIdMusico);
                        break;
                    case 2:
                        musico_modificar(arrayMusico,QTY_TIPO_M);
                        break;
                    case 3:
                        musico_baja(arrayMusico,QTY_TIPO_M);
                        break;
                    case 4:
                        musico_listar(arrayMusico,QTY_TIPO_M);
                        break;
                }
                break;
        }
    }
    while(opcion!=4);
    return 0;
}
