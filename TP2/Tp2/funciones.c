#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"
#include "persona.h"

/** \brief Inicializa la lista
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param limite es la cantidad de elementos del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int persona_InitLista(EPersona*  arrayLista, int limite)
{
    int retorno = -1;
    int i;

    if(arrayLista != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
           arrayLista[i].estado = INDICE_LIBRE;
           retorno=0;
        }

    }

    return retorno;
}



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int persona_obtenerEspacioLibre(EPersona*  arrayLista,int limite)
{

    int retorno = -1;
    int i;
    if(arrayLista != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(arrayLista[i].estado == INDICE_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;

}

/** \brief Agrega persona a la lista
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  limite cantidad de elementos en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

 int persona_AgregarPersona (EPersona* arrayLista, int index, int limite)
{

    int retorno = -1;
    char bNombre[51];
    char bufferDni[10];
    char bufferEdad[4];
    int nuevaEdad, edad_a_Validar;
    int nuevoDni,dni_a_Validar;

    if(arrayLista != NULL && index >= 0 && index <limite)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?\n","\nError:\n",3,51)==0)
        {

                        strncpy(arrayLista[index].nombre,bNombre,51);
                        arrayLista[index].estado = INDICE_OCUPADO;
                        val_getUnsignedInt(bufferEdad, "\ningrese Edad:\n","\nNo Valida\n",3,4);
                        edad_a_Validar = atoi(bufferEdad);
                        val_validarEdad(&nuevaEdad, edad_a_Validar,3);
                        arrayLista[index].edad = nuevaEdad;
                        val_getUnsignedInt(bufferDni,"\nIngrese el Dni: \n", "\n DNI no valido\n",3,10);
                        dni_a_Validar = atoi(bufferDni);
                        val_validarDni(&nuevoDni,dni_a_Validar,3);
                        arrayLista[index].dni = nuevoDni;


                        retorno=0;
                    }
            }
    return retorno;
}

/** \brief imprime la estructura
 *
 * \param arrayLista es el array
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int persona_PrintPersonas(EPersona* arrayLista, int limite)
{
    int retorno = -1;
    int i;
    if(arrayLista != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(arrayLista[i].estado == INDICE_OCUPADO)
            {
                printf("\n-\nNombre:%s\n\nEdad:%d\n\nDNI:%d\n\n ",arrayLista[i].nombre,arrayLista[i].edad,arrayLista[i].dni);
            }
        }

    }
    return retorno;
}

/** \brief pone el estado del elemento en libre para "borrarlo"
 *
 * \param arrayLista es el array que recibe
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int persona_Borrar(EPersona* arrayLista, int dni,int limite)
{
    int retorno = -1;
    int i = 0;

    if(arrayLista != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(arrayLista[i].estado == INDICE_OCUPADO && arrayLista[i].dni == dni)
            {
              arrayLista[i].estado = INDICE_LIBRE;
              printf("\nPersona Eliminada!!!\n");
              retorno=0;
            }
        }

    }



  return retorno;
}


/** \brief cuenta la cantidad de personas para distintos segmentos segun la edad de las mismas
 *
 * \param arrayLista es el array a recorrer
 * \param contador18 puntero a donde se va a almacenar el contador para menores de 18 años
 * \param contador19a35 puntero a donde se va a almacenar el contador para mayores de 19 años y menores de 35
 * \param contador35 puntero a donde se va a almacenar el contador para mayores de 35 años
 * \param limite es la cantidad de elementos a recorrer del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int persona_ContarbyEdad(EPersona* arrayLista, int *contador18, int *contador19a35, int *contador35, int limite)
{
    int retorno = -1;
    int i = 0;
    *contador18 = 0;
    *contador19a35=0;
    *contador35=0;
   if(arrayLista != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(arrayLista[i].estado == INDICE_OCUPADO && arrayLista[i].edad <18)
            {
                *contador18= *contador18 + 1;
                retorno=0;
            }
            if(arrayLista[i].estado == INDICE_OCUPADO && arrayLista[i].edad >=19 && arrayLista[i].edad <35)
            {
                *contador19a35=*contador19a35 +1;
                retorno=0;
            }
            if(arrayLista[i].estado == INDICE_OCUPADO && arrayLista[i].edad >35)
            {
                *contador35=*contador35+1;
            }

        }

    }

return retorno;
}

/** \brief grafica segun la cantidad de personas por segmento de edad
 *
 * \param cont18 menores de 18
 * \param cont19a35 segmento de 19 a 35 años
 * \param cont35 mayores de 35 años
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */


void persona_graficoBarras(int cont18,int cont19a35,int cont35)
{
    int i;

    int flag=0;
    int mayor;



    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {
        if(cont19a35 >= cont18 && cont19a35 >= cont35)
        {
            mayor = cont19a35;
        }
        else
        {
            mayor = cont35;
        }
    }

    printf("\n\n--+------------------\n");
    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i <= cont18)
        {
            printf("*");
        }

        if(i <= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }

        printf("\n");
    }
    printf("--+------------------\n");

    printf("  |<18\t19-35\t>35\n");
    printf("   %d\t%d\t%d\n\n", cont18, cont19a35, cont35);

}



/** \brief compara los elementos en .nombre del array segun el indice y  reordena alfabeticamente
 *
 * \param arrayLista es el array que contiene los elementos a ordenar
 * \param limite es la cantidad de elementos que contiene ese array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

void persona_ordenarXnombre(EPersona* arrayLista,int limite)
{
    char aux[20];
    int auxEdad;
    int auxDNI;
    int i,j;
    for( i=0; i<limite-1; i++)
    {
        for(j = i+1; j<limite; j++)
        {
            if(arrayLista[i].estado == INDICE_OCUPADO && arrayLista[j].estado == INDICE_OCUPADO)
            {
                if(strcmp(arrayLista[i].nombre,arrayLista[j].nombre)>0)
                {
                    strcpy(aux,arrayLista[i].nombre);
                    strcpy(arrayLista[i].nombre,arrayLista[j].nombre);
                    strcpy(arrayLista[j].nombre,aux);

                    auxEdad = arrayLista[i].edad;
                    arrayLista[i].edad = arrayLista[j].edad;
                    arrayLista[j].edad= auxEdad;

                    auxDNI = arrayLista[i].dni;
                    arrayLista[i].dni=arrayLista[j].dni;
                    arrayLista[j].dni=auxDNI;
                }
            }
        }

    }


}


