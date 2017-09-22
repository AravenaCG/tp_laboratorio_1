#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"
#include "persona.h"
#define LIMITE_CARGA_PERSONAS 10

int main()
{

    char bufferInt[40];
    char bufferDni[40];
    int  dni_A_Eliminar;
    int  menores18,entre19y35,mayores35;

    EPersona arrayLista[LIMITE_CARGA_PERSONAS];
    persona_InitLista(arrayLista,LIMITE_CARGA_PERSONAS);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n","error",2,40);
        switch(atoi(bufferInt))
      {
            case 1:
                persona_AgregarPersona(arrayLista,persona_obtenerEspacioLibre(arrayLista, LIMITE_CARGA_PERSONAS),LIMITE_CARGA_PERSONAS);
                break;

            case 2:
                val_getUnsignedInt(bufferDni,"\nIngrese el Dni a Eliminar:\n","\nError!:No Valido!\n",3,40);
                dni_A_Eliminar=atoi(bufferDni);
                persona_Borrar(arrayLista,dni_A_Eliminar,LIMITE_CARGA_PERSONAS);
                break;

            case 3:
                 persona_ordenarXnombre(arrayLista,LIMITE_CARGA_PERSONAS);
                 persona_PrintPersonas(arrayLista,LIMITE_CARGA_PERSONAS);
                break;

            case 4:
                 persona_ContarbyEdad(arrayLista, &menores18,&entre19y35,&mayores35,LIMITE_CARGA_PERSONAS);
                 persona_graficoBarras(menores18, entre19y35, mayores35);
                break;

            case 5:
                break;
        }
    }while(atoi(bufferInt) != 5);

    return 0;
}
