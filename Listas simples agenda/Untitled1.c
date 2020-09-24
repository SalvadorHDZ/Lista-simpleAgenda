/**
 * Estructuras de Datos II
 * Ejercicio:   Listas simples
 * Fecha:       13/03/2020
 */


/**  Bibliotecas **/
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int info;           // Dato que se almacenara en el nodo
    struct nodo *sig;   // Apuntador al siguiente nodo
}TNodo;


/* Prototipos de la funcion */
void insertaInicio(TNodo **lista, int info);
void imprimeLista(TNodo *lista);
void eliminaInicio(TNodo **lista);
void eliminaFinal(TNodo **lista);


int main()
{
    TNodo *lista = NULL; // Inicializacion de la lista

    insertaInicio(&lista, 2);
    insertaInicio(&lista,4);
    insertaInicio(&lista,200);
    insertaInicio(&lista,3);

    imprimeLista(lista);

    return 0;
}

/**
 * Funcion creaNodo(int info)
 * @info:   Dato tipo int que se le asigna al nodo
 * return:  Nuevo nodo creado
 *
 * Se crea un nodo asginando un valor y su apuntador en NUL
 */
TNodo *creaNodo(int info)
{
    TNodo *aux=(TNodo*)malloc(sizeof(TNodo)); // Reserva de memoria
    aux->info = info;
    aux->sig  = NULL;
    return(aux);
}


/**
 * Funcion insertaInicio(TNodo **lista, int info)
 * @lista:  Apuntador a la Cabeza de la lista
 * info:    Dato a insertar en el nodo
 */

void insertaInicio(TNodo **lista, int info)
{
    TNodo *aux = creaNodo(info);
    aux->sig = *lista;
    *lista = aux;
}

/**
 * Funcion imprimeLista(TNodo *lista)
 * @lista:  Cabeza de la lista
 *
 * Se recorre toda la lista de nodos y se muestra en pantalla el contenido
 */
void imprimeLista(TNodo *lista)
{
    TNodo *aux = lista; // Se crea un apuntador auxiliar que apunta al inicio de la lista

    while(aux!=NULL) // tambien se puede expresar como while(aux)
    {
        printf("[%d] ", aux->info);
        aux = aux->sig;
    }
}

/**
 * Funcion eliminaInicio(TNodo **lista)
 * @lista:  Apuntador a la cabeza de la lista
 *
 * Si la lista contiene nodos, se elimina el primer nodo
 * haciendo que La Cabeza de la lista apunte al siguiente nodo
 */
void eliminaInicio(TNodo **lista)
{
    if(*lista) // Si lista no esta vacia
    {
        TNodo *aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}
/**
 * Funcion eliminaFinal(TNodo **lista)
 * @lista:  Apuntador a la cabeza de la lista
 */
void eliminaFinal(TNodo **lista)
{
    TNodo *aux1, *aux2;
    aux1 = *lista;
    if(*lista)
    {
        while(aux1->sig != NULL)
        {
            aux2 = aux1;
            aux1 = aux1->sig;
        }
        if(aux1 == *lista)
        {
            *lista = NULL;

        }
        free(aux1);
        aux2->sig = NULL;


    }
}
