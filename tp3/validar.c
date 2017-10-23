#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validar.h"
#define MAX_INPUT_BUFFER 4096

/** \brief Pone el LF (salto de linea) en 0 para que termine con '/0'
 *
 * \param buffer donde se va a almacenar temporalmente hasta validar lo que se ingrese
 * \param limite cantidad de elementos
 * \param de donde se toma la informacion
 * \return
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


/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/** \brief valida si la cadena de caracteres es flotante
 *
 * \param    cantidadPuntos es un contador, verifica que contenga solo 1 punto pero al menos 1.
 * \param    dni_A_Validar es la edad que se analizara si cumple con los requisitos
 * \return  retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */


int esNumericoFlotante(char str[])
{
   int i=0;
   int retorno = -1;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
       {
           retorno= -1;
       i++;


       }
   }
   return retorno;
}

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 0 si es n�merico y -1 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   int retorno=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
        {
           retorno=-1;
        }
       i++;
   }
   return retorno;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo ' ' y letras y -1 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   int retorno=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
        retorno=-1;

       }
      i++;
   }
   return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene letras y n�meros, y -1 si no
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   int retorno=0;
   while(str[i] != '\0')
   {
       if(str[i] < 'a' || str[i] > 'z')
       {
           if (str[i] < 'A' || str[i] > 'Z')
           {
               if(str[i] < '0' || str[i] > '9')
               {
                    retorno = -1;
               }
           }
       }


       i++;
   }

   return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo n�meros y -
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo numeros y un guion. -1 si no funciona. -2 si no tiene numeros
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int retorno=-1;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
        {
        retorno=-2;

        }

       if(str[i] == '-')
       {
        contadorGuiones++;
        i++;
       }
   }
   if(contadorGuiones==1)
   {// debe tener un guion
        retorno=0;
   }
    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return  0 si el texto contiene solo letras . -1 si no es asi.
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    int retorno=-1;
    printf(mensaje);
    myFgets(aux,256,stdin);
    if(esSoloLetras(aux) == 0)
    {
        strcpy(input,aux);
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 0 si el texto contiene solo n�meros .-1 error
 */
int getStringNumeros(char mensaje[],char input[])
{
    int retorno=-1;
    char aux[256];
    printf(mensaje);
    myFgets(aux,256,stdin);

    if(esNumerico(aux)==0)
    {
        strcpy(input,aux);
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 0 si el texto contiene solo n�meros .-1 error
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    int retorno=-1;
    printf(mensaje);

    myFgets(aux,256,stdin);
    if(esNumericoFlotante(aux)==0)
    {
        strcpy(input,aux);
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Detiene la ejecucion y muestra un mensaje
 * \param message Mensaje
 * \return -
 *
 */
void pause(char message[])
{
    getChar(message);
    clean_stdin();
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar[50];
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); //UNIX
    fgets(auxiliar,50,stdin);
    return auxiliar[50];
}

/** \brief para una cierta cantidad de intentos se ejecuta el Mygets y se almacena en un buffer que se valida con esAlfanumerico()
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

int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(esAlfaNumerico(buffer) == -1)
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

/** \brief para una cierta cantidad de intentos se ejecuta el Mygets y se almacena en un buffer que se valida con esDireccion()
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

int val_getAlfaNumerico_Espacio(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(esAlfaNumerico_Espacio(buffer) != 0)
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

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros (permite espacios)
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene letras y n�meros, y -1 si no
 *
 */
int esAlfaNumerico_Espacio(char str[])
{
   int i=0;
   int retorno=-1;
   while(str[i] != '\0')
   {
        if((str[i] >= 'a' || str[i] <= 'z')|| (str[i] >= 'A' || str[i] <= 'Z')|| (str[i] >= '0' || str[i] <= '9')||(str[i]== 32))
        {
                    retorno = 0;

        }

    i++;
   }


    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo n�meros y '.'
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo numeros y letras y un punto. -1 si no funciona. -2 si tiene mas de un punto
 *
 */
int esNombreArchivo(char str[])
{
   int i=0;
   int retorno=-1;
   int contadorPuntos=0;


   while(str[i] != '\0')
   {
       if((str[i] == '.') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z'))
        {
        retorno=0;
        }

       if(str[i] == '.')
       {
        contadorPuntos++;
       }
       i++;
   }

   if(contadorPuntos>1)
   {
        retorno=-2;
   }

    return retorno;
}



/** \brief para una cierta cantidad de intentos se ejecuta el Mygets y se almacena en un buffer que se valida con esNombreArchivo()
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

int val_getNombreArchivo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(esNombreArchivo(buffer) != 0)
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
