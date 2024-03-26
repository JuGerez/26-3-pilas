#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void ejercicios();
void muestraEjercicios();
void ejercicioClase19_3();
void ejercicioClase19_32();
void ejercicioClase20_3();
void ejercicioClase20_32();
void ejercicioClase25_3();
void ejercicioClase26_3();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void cargaPilaRandom(Pila*k);
void muestraPila(Pila k);
void pasaPila(Pila* k, Pila*l);
void ordenPila(Pila* k, Pila* l);
void insertarEnOrdenada (Pila* k, int dato);
void insertarOrdenando (Pila* k, Pila* l);
int sacarDatoMenor(Pila* k);
int cuentaElementosPila(Pila l);
int sumaElementosPila(Pila l);
int encuentraElemento(Pila k, int dato);
int ingresaDato();
int sumaTopeAnterior(Pila k);
int divideElementosPila (Pila l);


int main()
{
    srand(time(NULL));
    ejercicios();
        return 0;
}

void ejercicios()
{
    char opcion;

    do{
        system("cls");
        muestraEjercicios();

        opcion = getche();

    switch(opcion){
    case '1':
        ejercicioClase19_3();
        break;
    case '2':
        ejercicioClase19_32();
        break;
    case '3':
        ejercicioClase20_3();
        break;
    case '4':
        ejercicioClase20_32();
        break;
    case '5':
        ejercicioClase25_3();
        break;
    case '6':
        ejercicioClase26_3();
        break;
    case '7':
        ejercicio8();
        break;
    case '8':
        ejercicio9();
        break;
    case '9':
        ejercicio10();
        break;
    }
    system("pause");
    }while(opcion!=27);
}
void muestraEjercicios()
{
    system("color 3f");
    printf("Ingrese caso:\n\n\n");
    printf("\n 1 - Ejercicios 1ra Clase 19-3");
    printf("\n 2 - Ejercicios 2da Clase 19-3");
    printf("\n 3 - Ejercicios 3ra Clase 20-3");
    printf("\n 4 - Ejercicios 4ta Clase 20-3");
    printf("\n 5 - Ejercicios 5ta Clase 25-3");
    printf("\n 6 - Ejercicios 6ta Clase 26-3");
    printf("\n 7 - Ejercicio 8");
    printf("\n 8 - Ejercicio 9");
    printf("\n 9 - Ejercicio 10");

    printf("\n\n\n");
    printf("ESC para salir o cualquier tecla para continuar.\n");
}
void ejercicioClase19_3()
{
    Pila origen, destino;
    inicpila (&origen);
    inicpila (&destino);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int cantidad=cuentaElementosPila(origen);
    printf(" Cantidad elementos: %d \n", cantidad);

    int total=sumaElementosPila(origen);
    printf(" Suma elementos: %d \n", total);

    pasaPila(&origen, &destino);
    printf("Pila origen final:\n");
    muestraPila(origen);
    printf("Pila destino:\n");
    muestraPila(destino);
}

void ejercicioClase19_32()
{
    Pila origen;
    inicpila (&origen);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int flag=encuentraElemento(origen, 33);
    if(flag == 1){
        printf("El elemento esta presente.\n");
    } else {
        printf("El elemento no esta presente.\n");
    }

}
void ejercicioClase20_3()
{
    int existe;
    Pila origen;
    inicpila(&origen);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int dato=ingresaDato();
    existe == encuentraElemento(origen, dato);
    if(existe){
           printf("El elemento no esta presente.\n");
    } else {
        printf("El elemento esta presente.\n");
    }

}
void ejercicioClase20_32()
{
    printf("\nCodigo ASCII de caracteres:\n");
    for(int i = 0; i <257; i++){
        printf("\n Codigo: %d - %c", i, i);
    }
}
void ejercicioClase25_3()
{
    Pila origen, ordenada;
    inicpila(&origen);
    inicpila(&ordenada);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int menor=sacarDatoMenor(&origen);
    printf("El menor es %d.\n", menor);

    ordenPila(&origen, &ordenada);
    printf("\nPila ordenada:\n");
    muestraPila(ordenada);

}
void ejercicioClase26_3()
{
    Pila origen, ordenada;
    inicpila(&origen);
    inicpila(&ordenada);

    cargaPilaRandom(&origen);

    //    ordenPila(&origen, &ordenada);
    //    printf("\nPila ordenada:\n");
    //    muestraPila(ordenada);
    //
    //    insertarEnOrdenada(&ordenada, 8);
    //    printf("\nPila con el dato ingresado\n");
    //    muestraPila(ordenada);

    insertarOrdenando(&origen, &ordenada);
    printf("\nPila con el dato ingresado\n");
    muestraPila(ordenada);
}
void ejercicio8()
{
    Pila origen;
    inicpila(&origen);

    cargaPilaRandom(&origen);
    muestraPila(origen);
    int suma=sumaTopeAnterior(origen);
    printf("\n La suma de el tope y el anterior es %d:\n", suma);

}
void ejercicio9()
{
    Pila origen;
    inicpila (&origen);

    cargaPilaRandom(&origen);

    int total=sumaElementosPila(origen);
    printf(" Suma elementos: %d \n", total);

    int cantidad=cuentaElementosPila(origen);
    printf(" La cantidad de elementos son: %d \n", cantidad);

    int promedio = total / cantidad;
    printf(" El promedio es: %d \n", promedio);
}
void ejercicio10()
{
   Pila origen, aux;
   inicpila(&origen);
   inicpila(&aux);
   int numero;
   char opcion;

   while(opcion != 27)
    {   printf("Ingresa un numero de un solo digito:\n");
        scanf("%d", numero);
        if(numero < 10){
        apilar(&origen, numero);
        } else{
        apilar(&aux, numero);
        }
        system("cls");
    }
}
void cargaPilaRandom(Pila* k)
{
    int numero;

    for (int i = 1; i < 50; i++)
    {
        numero = rand()%100+1;
        apilar(k, numero);
    }
}
void muestraPila(Pila k)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    while(!pilavacia(&k))
    {   apilar(&aux, desapilar(&k));
    }

    while(!pilavacia(&aux))
    {
        printf("%d | ",tope(&aux));
        apilar(&aux2, desapilar(&aux));
    }
}
void pasaPila(Pila*k, Pila*l)
{
    while(!pilavacia(k))
    {
        apilar(l, desapilar(k));
    }
}
void ordenPila(Pila*k, Pila* l)
{
    while(!pilavacia(k)){
        apilar(l, sacarDatoMenor(k));
            }
}
void insertarEnOrdenada(Pila* k, int dato)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(k)&& dato < tope(k)){
        apilar(&aux, desapilar(k));
    }

    apilar(k, dato);
    pasaPila(&aux, k);

}
void insertarOrdenando (Pila* k, Pila* l)
{
    while(!pilavacia(k)){
        insertarEnOrdenada(l, desapilar(k));
        }
}
int sacarDatoMenor(Pila* k)
{
     int dato;
    Pila aux, menor;
    inicpila (&aux);
    inicpila(&menor);

    if (!pilavacia(k)){
        dato = desapilar(k);
        }

    while(!pilavacia(k)){
        if (tope(k) < dato){
            apilar(&aux, dato);
            dato = desapilar(k);
        } else {
            apilar(&aux, desapilar(k));
            }
        }
    pasaPila(&aux, k);
    return dato;
}

int cuentaElementosPila(Pila l)
{
    int contador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        apilar(&aux, desapilar(&l));
        contador++;
    }
    return contador;
}

int sumaElementosPila(Pila l)
{
    int acumulador = 0;
    int topepila;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        topepila = tope(&l);
        acumulador = acumulador + topepila;// acumulador = acumulador + tope(&l);
        apilar(&aux, desapilar(&l));
    }
    return acumulador;
}

int encuentraElemento(Pila k, int dato)
{
    int flag = 0;
    Pila aux;
    inicpila (&aux);

    while(!pilavacia(&k) && flag == 0)
    {
        if(tope(&k) == dato)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(&k));
        return flag;
    }
}
int ingresaDato()
{
    int dato;
    printf("\n Ingrese el dato a buscar: \n");
    scanf("%d", &dato);

    return dato;
}
int sumaTopeAnterior(Pila k)
{
    Pila aux;
    inicpila(&aux);
    int acumulador = 0;

    for(int i = 0; i < 1; i++){
        apilar(&aux, desapilar(&k));
        acumulador = tope(&k) + tope(&aux);
    }

    return acumulador;
}
