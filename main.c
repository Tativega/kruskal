#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"
#include "functions.h"

int main()
{
    int COSTOS[VERTICES][VERTICES] = {
        {0, 3, 7, 6, 1, 2},
        {3, 0, 5, 4, 8, 9},
        {7, 5, 0, 2, 6, 0},
        {6, 4, 2, 0, 7, 3},
        {1, 8, 6, 7, 0, 5},
        {2, 9, 0, 3, 5, 0}};

    // int COSTOS[VERTICES][VERTICES]; // tengo q guardarlo en memoria dinamica? por que?
    rama *arbol = NULL;

    // carga matriz con pesos
    // for (int i = 0; i < VERTICES; i++)
    // {
    //     for (int j = i + 1; j < VERTICES; j++)
    //     {
    //         printf("Ingrese el costo entre los vertices %i y %i\n", i, j);
    //         scanf("%i", &COSTOS[i][j]);
    //     }
    // }

    // RECORRE LA MATRIZ PARA GENERAR LA COLA DE PRIORIDAD

    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = i + 1; j < VERTICES; j++)
        {
            int costo = COSTOS[i][j];

            if (costo > 0)
            {
                inserta(i, j, costo, &arbol);
            }
        }
    }

    // ------------------ KRUSKAL -------------------------

    kruskal(arbol);

    //------------liberar memoria cola prioridad
    freeQueue(arbol);

    return 0;
}