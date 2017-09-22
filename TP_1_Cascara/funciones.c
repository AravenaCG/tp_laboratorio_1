#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



/** \brief  suma 2 numeros que ingresa el usuario
 *
 * \param   X es el primer operando
 * \param   Y es el segundo operando
 * \return  auxSuma es el resultado de la suma
 *
 */

float sumar(float x, float y)
{
     float auxSuma;

    auxSuma= x+ y;

    return auxSuma;
 }

/** \brief  Resta 2 numeros que ingresa el usuario
 *
 * \param   X es el primer operando
 * \param   Y es el segundo operando
 * \return  auxResta es el resultado de la resta
 *
 */
float restar(float x, float y)
{
    float auxResta;
    auxResta= x-y;
    return auxResta;
}

/** \brief  multiplica 2 numeros que ingresa el usuario
 *
 * \param   X es el primer operando
 * \param   Y es el segundo operando
 * \return  auxMultiplica es el producto
 *
 */

float multiplicar(float x, float y)
{
    float auxMultiplica;
    auxMultiplica= x*y;
    return auxMultiplica;
}

/** \brief valida y divide los numeros recibidos
 * \param x es el primer operando
 *
 * \param y es el segundo operando
 *
 * \param auxDivision es donde se almacena el resultado de la division
 *
 * \param
 * \return retorno = -1 (para indicar que el numero es invalido), retorno = 0 (para indicar que la funcion se completo correctamente)
 *
 */

float dividir(float x, float y, float* resultDivision)
{
    float retorno = 0;
    float auxDivision;

    if (y == 0)
    {
        retorno= -1;
    }
        else
        {

        auxDivision = x/y;
        *resultDivision = auxDivision;
        }

return retorno;
}
/** \brief  Realiza el factorial del primer operando que ingresa el usuario
 *
 * \param   x es el primer operando
 * \param   aux toma la parte entera del numero
 * \param   fac es el calculo del factorial
 * \param   resultFactorial es el puntero que recibe a donde se va a dejar la direccion que apunta al valor del resultado del factorial
 *
 *\return   retorno = -1 (el numero es negativo) ,
 *\return   retorno = 0 cuando la funcion se completo sin errores
 *
 */

int factorial(float x, int* resultFactorial)
{
int i,retorno;
int fac= 1;
int aux;

aux= (int) x;

    if (aux < 0 )
    {
        retorno=-1;

    }
        else
        {


            for (i=1; i<= aux ; i++)
            {
            fac= fac*i;
            retorno=0;
            }
    *resultFactorial =fac;

        }
return retorno;

}




