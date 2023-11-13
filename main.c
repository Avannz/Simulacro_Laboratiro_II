#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct
{
    char nombreYapellido [30];
    int edad;
    int dni;
} personaje;

typedef struct
{
    personaje dato;
    struct nodoLista* anterior;
    struct nodoLista* siguiente;
} nodoLista;

typedef struct
{
    char nombreEspecie[20]; //vampiro, hombre lobo, hada, medium, cambia formas, humano
    int rankPeligrosidad; //1 el más peligroso, 6 el menos peligroso
    float promedioEdad; // 0
    nodoLista* personajes; //lista de personajes que pertencen a esta especie
} especie;

int main()
{
    printf("Hello world!\n");
    return 0;
}


nodoLista* iniciar_nodo()
{

    return NULL;
}

nodoLista* crear_nodo(personaje dato)
{

    nodoLista*  aux = (nodoLista*)malloc(sizeof(nodoLista));

    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

nodoLista* agregar_principio(nodoLista* lista, nodoLista* nuevoNodo)
{

    nuevoNodo->siguiente = lista;

    if(!lista)
    {

        lista->anterior = nuevoNodo;
    }

    return nuevoNodo;
}

void mostrar_lista(nodoLista* lista)
{

    if(lista)
    {

        printf("\nNombre: %s", lista->dato.nombreYapellido);
        printf("\nEdad: %i", lista->dato.edad);
        printf("\nDni: %i", lista->dato.dni);

        mostrar_lista(lista->siguiente);
    }
}

int buscar_posicion(especie arreglo[], int dimension, char nuevaEspecie)
{

    int pos = -1;
    int i = 0;

    while(i < dimension && pos == -1)
    {

        if(strcmp(arreglo[i].nombreEspecie, nuevaEspecie) == 0)
        {

            pos = i;
        }

        i++;
    }

    return pos;
}

int buscar_rango(especie arreglo[], int dimension, int rango)
{

    int flag = 0;
    int i = 0;

    while(i < dimension && flag == 0)
    {

        if(strcmp(arreglo[i].rango, rango) == 0)
        {

            flag = 1;
        }

        i++;
    }

    return flag;
}

int verificar_rango(especie arreglo, int rango, int validos)
{

    int flag = 0;
    int i = 0;

    while(i < validos && flag == 0)
    {

        if(strcmp(arreglo[i].rankPeligrosidad, rango) == 0)
        {

            flag = 1;
        }

        i++;
    }

    return flag
}


int agregar_especie(especie arreglo[], int validos, char nuevaEspecie)
{
    int flag = 0;

    strcpyarreglo[validos].nombreEspecie, nuevaEspecie);

    printf("Ingresa el rango de peligrosidad: ");
    fflush(stdin);
    scanf("%i", &arreglo[validos].rankPeligrosidad);

    arreglo[validos].promedioEdad = 0;

    validos++;



    return validos;
}

int agregar_contenido(especie arreglo[], int dimension, int validos)
{

    int i = 0;
    char especie;
    char letra = 's';
    int flag = 0;
    int rango;

    personaje aux;

    printf("Ingresa una especie: ");
    fflush(stdin);
    gets(&nuevo);

    int pos = buscar_posicion(arreglo, 6, nuevo);

    while(flag != 1)
    {

    printf("Ingresa un rango a la especie: ");
    fflush(stdin);
    scanf("%i", &rango);

    flag = buscar_rango(arreglo,6, rango);

    printf("Rango en uso!");
    }

        if(pos == -1)
        {

            validos = agregar_especie(arreglo, validos, nuevo);
            pos = validos-1;
        }

        while(letra == 's')
        {

            printf("Ingresale un nombre: ");
            fflush(stdin);
            gets(&aux.nombreYapellido);

            printf("Ingresa la edad del personaje: ");
            fflush(stdin);
            scanf8("%i", &aux.edad);

            printf("Ingresa el DNI: ");
            fflush(stdin);
            scanf("%i", &aux.dni);

            nodoLista* nuevoNodo = crear_nodo(aux);

            arreglo[pos].personajes = agregar_principio(arreglo[pos].personajes, nuevoNodo);

            printf("Ingresa 's' para seguir agregando personajes a esta especie: ");
            fflush(stdin);
            scanf("%c", &letra);
        }

    return validos;
}
