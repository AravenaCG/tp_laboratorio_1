#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
float ingresarPrimerOperando();
float ingresarSegundoOperando();



int main()
{
system("cls");


char seguir='s';
int opcion=0;
float a;
float b;
float resultadoDivision;
int resultadoFactorial;

    do{
        printf("1- Ingresar 1er operando (A=%.2f)\n",a);
        printf("2- Ingresar 2do operando (B=%.2f)\n",b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
               a=ingresarPrimerOperando();

                break;
            case 2:
              b=ingresarSegundoOperando();

               break;
            case 3:
                printf("El resultado de la suma es: %.2f  \n " , sumar(a,b));
                break;
            case 4:
                 printf("El resultado de la resta es: %.2f  \n " , restar(a,b));
                break;
            case 5:
              dividir(a,b, &resultadoDivision);
                if (dividir(a,b, &resultadoDivision)== -1)
                 {
                     printf("no se puede dividir por 0 \n");
                 }
                    else
                    {
                        printf("El resultado de la division es: %.2f  \n " , resultadoDivision);
                    }

                break;
            case 6:
                 printf("El resultado de la multiplicacion es: %.2f  \n " , multiplicar(a,b));
                break;
            case 7:
              if (   factorial(a, &resultadoFactorial) == -1 )
              {
                  printf("el numero no es valido!");
              }
                 else
                 {
                        printf("El resultado del factorial (de la parte entera) es: %d  \n " , resultadoFactorial);
                 }

                break;
            case 8:
                 printf("El resultado de la suma es: %.2f  \n " , sumar(a,b));

                 printf("El resultado de la resta es: %.2f  \n " , restar(a,b));

                dividir(a,b, &resultadoDivision);
                if (dividir(a,b, &resultadoDivision)== -1)
                 {
                     printf("no se puede dividir por 0 \n");
                 }
                    else
                    {
                        printf("El resultado de la division es: %.2f  \n " , resultadoDivision);
                    }


                 printf("El resultado de la multiplicacion es: %.2f  \n " , multiplicar(a,b));

                 //printf("El resultado del factorial (de la parte entera) es: %d  \n " , factorial(a));

            case 9:
                seguir = 'n';
                break;
        }

    printf("desea continuar? s/n  \n");
    fflush(stdin);
    scanf("%c",&seguir);


}while(seguir =='s');

return 0;
}


/** \brief permite al usuario ingresar el primer operando
 *
 * \param   x es la variable donde se almacena el numero ingresado
 * \param
 * \return x el numero ingresado por el usuario
 *
 */

float ingresarPrimerOperando()
{
float x;

                printf("\nIngrese 1er operando: \n ");
                scanf("%f",&x);
                printf("______________________________________\n");

               return x;
}

/** \brief permite ingresar el segundo numero por el usuario
 *
 * \param y variable donde se almacena el numero
 * \param
 * \return el numero ingresado por el usuario
 *
 */

float ingresarSegundoOperando()
{
    float y;


        printf("\nIngrese el 2do operando: \n ");
        scanf("%f",&y);
        printf("______________________________________\n");


    return y;
}
