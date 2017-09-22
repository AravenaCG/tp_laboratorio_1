#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "persona.h"
#define MAX_INPUT_BUFFER 4096

/** \brief Pone el LF (salto de linea) en 0 para que termine con '/0'
 *
 * \param buffer donde se va a almacenar temporalmente hasta validar lo que se ingrese
 * \param limite cantidad de elementos
 * \param de donde se toma la informacion
 * \return buffer a validar de
 *
 */
void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}


/** \brief para una cierta cantidad de intentos se ejecuta el Mygets y se almacena en un buffer que se valida con valNombre
 *   si retorna -1 (error) se descuenta 1 intento y se continua con el ciclo si no tira error se copia en el destino
 *
 * \param destino puntero a donde se va a almacenar lo ingresado
 * \param  mensaje a mostrar ingresado por el usuario
 * \param mensajeError el mensaje a mostrar en caso de Error
 * \param intentos la cantidad de oportunidades para ingresar bien lo que se solicita
 * \param limite es la cantidad de elementos maxima
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarNombre(buffer) == -1)
            {
               printf(mensajeError);
                continue;
            }
             else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
}
    return retorno;
}

/** \brief valida que el nombre ingresado cumpla con los requisitos
 *
 * \param   buffer es el texto a validar
 * \param
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < 'a' || buffer[i] > 'z')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief para una cierta cantidad de intentos se ejecuta el Mygets y se almacena en un buffer que se valida con val_validarUnsignedInt
 *   si retorna -1 (error) se descuenta 1 intento y se continua con el ciclo si no tira error se copia en el destino
 *
 * \param destino puntero a donde se va a almacenar lo ingresado
 * \param  mensaje a mostrar ingresado por el usuario
 * \param mensajeError el mensaje a mostrar en caso de Error
 * \param intentos la cantidad de oportunidades para ingresar bien lo que se solicita
 * \param limite es la cantidad de elementos maxima
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief  valida el numero ingresado que se recibe por buffer
 *
 * \param   puntero a un buffer que es una cadena de caracteres que se somete a condiciones logicas para determinar como valido
 * \param
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief valida la edad entre 0 y 150
 *
 * \param   destino puntero a donde se almacenara lo validado
 * \param   edad_A_Validar es la edad que se analizara si cumple con los requisitos
 * \param   intentos es la cantidad de veces que se itera
 * \return  retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_validarEdad(int *destino, int edad_A_Validar, int intentos)
{

    int retorno;


    for (;intentos>0;intentos -- )
    {
        if (edad_A_Validar <0 || edad_A_Validar > 150)
        {
            printf("Edad No Valida");
            retorno = -1;
            continue;
        }
        else
        {
            *destino = edad_A_Validar;
            retorno = 0;
            break;
        }
    }
   return retorno;
}

/** \brief valida el dni segun parametros logicos de un valor minimo y maximo
 *
 * \param    destino puntero a donde se almacenara lo validado
 * \param    dni_A_Validar es la edad que se analizara si cumple con los requisitos
 * \param   intentos es la cantidad de veces que se itera
 * \return  retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int val_validarDni(int *destino, int dni_A_Validar, int intentos)
{
    int retorno;
    for (;intentos>0;intentos--)
    if (dni_A_Validar < 0 || dni_A_Validar > 50000000)//mayor a 50 millones en Argentina
        {
            retorno=-1;
            continue;
        }
        else
            {
                *destino= dni_A_Validar;
                retorno=0;
                break;

            }

    return retorno;

}
