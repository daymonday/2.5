/*2.5 Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas de
la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a la
derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.

Por cada reserva se debe solicitar la fila y número de butaca a reservar.

Cada vez que se realice una reserva se deberá actualizar el esquema que muestra las butacas.

Si la butaca seleccionada ya estaba ocupada se debe informar al usuario para que seleccione otra.
El proceso de reserva finaliza con una fila con un número negativo.

Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.
d. un listado con la cantidad de personas que se sentaron en los mismos números de butacas en
todo el cine ordenado de mayor a menor.*/

#include <stdio.h>
#include <stdlib.h>

#define FILAS 12
#define BUTACAS 9

int main()
{

    system("pause");
    return 0;
}

// Carga de menu
void cargaInicio(int m[FILAS][BUTACAS],int cantF,int cantB)
{
    int f,b;

    for(f=0; f<cantF; f++)

    {
        printf("\n");

        for(b=0; b<cantB; b++)
        {
            // esto solo funciona con carga secuencial
            if(b<4)
            {
                printf("%5d",8-2*b);
            }
            else if(b==4)
            {
                printf("%5d",1);
            }
            else
            {
                printf("%5d",2*b-7);
            }
        }

    }
}

// Ingreso del usuario
void cargaUsuario(int m[][BUTACAS],int cantF,int cantC)
{
    int filaButaca,columnaButaca,indiceButaca;

    printf("\n ************ SELECCION DE BUTACAS ************\n");

    printf("\n ¿Desea comprar una butaca? [-1 para finalizar, 1 a 12 para seleccionar]:\t");
    filaButaca=leeYvalidaIntFin(1,FILAS,-1);

    while(filaButaca>-1)
    {
        columnaButaca=leeYvalidaInt(1,BUTACAS);

        // en este caso, la busqueda va ser sobre el valor de columna ingresado para acceder al indice correcto

        indiceButaca=busquedaPos(m,columnaButaca,FILAS,BUTACAS);

        if(indiceButaca>-1)
        {
            printf("\n Butaca no disponible. Seleccione otra.\n");

        }
        else
        {
            m[filaButaca][indiceButaca]="R";
        }

        printf("\n ¿Desea comprar una butaca? [-1 o menos para finalizar, 1 a 12 para seleccionar]:\t");
        filaButaca=leeYvalidaIntFin(1,12,-1);
    }

    if(filaButaca<=-1)
    {
        printf("\n *********FIN DEL PROCESO DE SELECCION DE BUTACAS*************** \n");
    }

}

int busquedaPos(int m[][BUTACAS],int dato,int cantF,int cantC)
{
    int pos=-1,c,f;

    for(f=0; f<cantF; f++)
    {
        for(c=0; c<cantC; c++)

        {
            if(m[f][c]==dato)
                pos=m[f][c];
        }
    }
    return pos;
}
