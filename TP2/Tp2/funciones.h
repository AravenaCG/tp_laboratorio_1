#include "persona.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




#endif // FUNCIONES_H_INCLUDED



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int persona_obtenerEspacioLibre(EPersona*  arrayLista, int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int persona_buscarPorDni(EPersona*   arrayLista, int dni);

int persona_InitLista(EPersona*  arrayLista,int limite);

int persona_AgregarPersona (EPersona* arrayLista, int index, int limite);

int persona_PrintPersonas(EPersona* arrayLista, int limite);

int persona_Borrar(EPersona* arrayLista, int dni,int limite);

int persona_Ordenar_Comparando_Nombre(EPersona* arrayLista, char* nombre_A_Comparar, int limite);

int persona_ContarbyEdad(EPersona* arrayLista, int *, int *, int *, int limite);

void persona_graficoBarras(int cont18,int cont19a35,int cont35);

void persona_ordenarXnombre(EPersona* arrayLista,int limite);

