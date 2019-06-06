#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Insturmento.h"
#include "Musico.h"
#include "Orquesta.h"
#include "Informes.h"
#define QTY_TIPO_O 50
#define QTY_TIPO_I 20
#define QTY_TIPO_M 1000

int main()
{
    int opcion;
    int opcion2;
    int contadorIdOrquesta=4;
    int contadorIdInstrumento=5;
    int contadorIdMusico=6;
    int i;
    Orquesta arrayOrquesta[QTY_TIPO_O];
    Musico arrayMusico[QTY_TIPO_M];
    Instrumento arrayInstrumento[QTY_TIPO_I];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO_O);
    instrumento_Inicializar(arrayInstrumento,QTY_TIPO_I);
    musico_Inicializar(arrayMusico,QTY_TIPO_M);
    harcodearMusico(arrayMusico);
    harcodearInstrumento(arrayInstrumento);
    harcodearOrquesta(arrayOrquesta);
    do
    {
        utn_getUnsignedInt("\n\n1. Orquesta \n2. Instrumento \n3. Musico \n4. Informes \n5. Salir\n",
                      "\nValor no valido",1,sizeof(int),1,4,3,&opcion);
        switch(opcion)
        {
            case 1:
                utn_getUnsignedInt("\n\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquesta\n","\nValor no valido",1,sizeof(int),1,3,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        i=orquesta_alta(arrayOrquesta,QTY_TIPO_O,&contadorIdOrquesta);
                        break;
                    case 2:
                        i=orquesta_baja(arrayOrquesta,QTY_TIPO_O);
                        break;
                    case 3:
                        i=orquesta_listar(arrayOrquesta,QTY_TIPO_O);
                }
                break;
            case 2:
                utn_getUnsignedInt("1.Agregar instrumento\n2.Imprimir\n","\n valor no valido",1,sizeof(int),1,2,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        i=instrumento_alta(arrayInstrumento,QTY_TIPO_I,&contadorIdInstrumento);
                        break;
                    case 2:
                        i=instrumento_listar(arrayInstrumento,QTY_TIPO_I);
                        break;
                }
                break;
            case 3:
                 utn_getUnsignedInt("\n\n1.Agregar musico\n2.Modificar musico\n3.Eliminar musico\n4.Imprimir musico\n","\n Valor ingresado no valido",1,sizeof(int),1,3,3,&opcion2);
                switch(opcion2)
                {
                    case 1:
                        i=musico_alta(arrayMusico,arrayInstrumento,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_I,QTY_TIPO_O,&contadorIdMusico);
                        break;
                    case 2:
                        i=musico_modificar(arrayMusico,arrayInstrumento,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_I,QTY_TIPO_O);
                        break;
                    case 3:
                        i=musico_baja(arrayMusico,QTY_TIPO_M);
                        break;
                    case 4:
                        i=musico_listar(arrayMusico,QTY_TIPO_M);
                        break;
                }
                break;
            case 4:
               utn_getUnsignedInt("\n1. Orquestas con mas de 5 personas\n2. Musicos con mas de 30 años\n3. Oruqesta de un lugar\n4. Orquesta completa\n5. Musicos de una orquesta\n6. Orquesta con mas musicos\n7. Musicos por instrumento de cuerda\n8. Promedio de musicos por orquesta\n",
               "valor no valido",1,sizeof(int),1,8,3,&opcion2);
               switch(opcion2)
               {
                    case 1:
                        i=musico_ordenar_xIDorquesta(arrayMusico,QTY_TIPO_M);
                        i=orquesta_lista_mas5(arrayMusico,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_O);
                        break;
                    case 2:
                        i=muscio_lista_mas30(arrayMusico,QTY_TIPO_M);
                        break;
                    case 3:
                        i=orquesta_lista_xLugar(arrayOrquesta,QTY_TIPO_O);
                        break;
                    case 4:
                        i=musico_ordenar_xIDorquesta(arrayMusico,QTY_TIPO_M);
                        i=orquesta_listar_completa(arrayMusico,arrayInstrumento,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_I,QTY_TIPO_O);
                        break;
                    case 5:
                        i=musico_listar_xOrquesta(arrayMusico,QTY_TIPO_M,contadorIdOrquesta);
                        break;
                    case 6:
                        i=musico_ordenar_xIDorquesta(arrayMusico,QTY_TIPO_M);
                        i=orquesta_lista_masMusicos(arrayMusico,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_O);
                        break;
                    case 7:
                        i=musico_listar_xIstrumento_cuerda(arrayMusico,arrayInstrumento,QTY_TIPO_M,QTY_TIPO_I);
                        break;
                    case 8:
                        i=musico_promedio_xOrquesta(arrayMusico,arrayOrquesta,QTY_TIPO_M,QTY_TIPO_O);
                        break;
               }
        }
        if (i!=0)
        {
            printf("\nOcurrio un error intente nuevamente\n");
        }
    }while(opcion!=5);
    return 0;
}
