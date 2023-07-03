#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"
#include "functions.h"

int main()
{
    // TEST MATRIX
    // int COSTS[VERTICES][VERTICES] = {
    //     {0, 3, 7, 6, 1, 2},
    //     {3, 0, 5, 4, 8, 9},
    //     {7, 5, 0, 2, 6, 0},
    //     {6, 4, 2, 0, 7, 3},
    //     {1, 8, 6, 7, 0, 5},
    //     {2, 9, 0, 3, 5, 0}};

    int COSTS[VERTICES][VERTICES] = {0};
    branch *tree = NULL;

    // loads adjacency matrix with weights
    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = i + 1; j < VERTICES; j++)
        {
            printf("Enter the cost between vertices %i and %i\n", i, j);
            scanf("%i", &COSTS[i][j]);
        }
    }

    // TRAVERSES THE MATRIX TO GENERATE THE PRIORITY QUEUE
    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = i + 1; j < VERTICES; j++)
        {
            int cost = COSTS[i][j];

            if (cost > 0)
            {
                insert(i, j, cost, &tree);
            }
        }
    }

    kruskal(tree);

    // free priority queue memory
    freeQueue(tree);

    return 0;
}
