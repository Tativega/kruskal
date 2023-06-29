void inserta(int u, int v, int costo, rama **nodo)
{
    if (*nodo == NULL) // si arbol todavia no apunta a nada esta vacio, cargo el primer nodo
    {
        *nodo = (rama *)malloc(sizeof(rama));
        (*nodo)->A.u = u;
        (*nodo)->A.v = v;
        (*nodo)->A.costo = costo;
        (*nodo)->sig = NULL; // es el ultimo elemento de la lista
    }
    else
    { // el arbol no esta vacio, tengo que crear un nodo nuevo

        // ahora queda determinar donde pongo el nodo ya que tienen que estar ordenados por costo
        if (costo < (*nodo)->A.costo)
        { // el primer elemento siempre va a ser el mas chico
            rama *nuevo_nodo = (rama *)malloc(sizeof(rama));
            nuevo_nodo->A.u = u;
            nuevo_nodo->A.v = v;
            nuevo_nodo->A.costo = costo;
            nuevo_nodo->sig = *nodo;
            *nodo = nuevo_nodo; // el primer elemento pasa a ser nuevo_nodo
        }
        else
        {
            inserta(u, v, costo, &((*nodo)->sig));
        }
    }
}

void inicial(int nombre, int elemento, conjunto_CE *C)
{
    C->nombres[elemento].nombre_conjunto = nombre;
    C->nombres[elemento].siguiente_elemento = -1;
    C->encabezamientos_conjunto[nombre].cuenta = 1;
    C->encabezamientos_conjunto[nombre].primer_elemento = elemento;
}

arista *sacar_min(rama **a)
{
    arista *head = &((*a)->A);
    *a = (*a)->sig;

    return head;
}

int encuentra(int nombre, conjunto_CE *conjunto)
{
    return conjunto->nombres[nombre].nombre_conjunto;
}

void combina(int A, int B, conjunto_CE *C)
{
    int bigger_set = C->encabezamientos_conjunto[A].cuenta > C->encabezamientos_conjunto[B].cuenta ? A : B;
    int smaller_set = bigger_set == A ? B : A;

    int i = C->encabezamientos_conjunto[smaller_set].primer_elemento;
    while (C->nombres[i].siguiente_elemento != -1)
    {
        C->nombres[i].nombre_conjunto = bigger_set;
        i = C->nombres[i].siguiente_elemento;
    }

    C->nombres[i].nombre_conjunto = bigger_set;
    C->nombres[i].siguiente_elemento = C->encabezamientos_conjunto[bigger_set].primer_elemento;
    C->encabezamientos_conjunto[bigger_set].primer_elemento = C->encabezamientos_conjunto[smaller_set].primer_elemento;
    C->encabezamientos_conjunto[bigger_set].cuenta += C->encabezamientos_conjunto[smaller_set].cuenta;
}

void lista(rama *arbol)
{
    if (arbol != NULL)
    {

        printf("Arista %i, %i. Costo %i\n", arbol->A.u, arbol->A.v, arbol->A.costo);

        lista(arbol->sig);
    }
}

void kruskal(rama *arbol)
{
    conjunto_CE conjunto;
    rama *arbol_min = NULL;
    arista *min;
    int n_comp = VERTICES;
    int comp_u, comp_v;

    for (int i = 0; i < VERTICES; i++)
    {

        inicial(i, i, &conjunto);
    }

    while (n_comp > 1)
    {
        min = sacar_min(&arbol);
        comp_u = encuentra(min->u, &conjunto);
        comp_v = encuentra(min->v, &conjunto);

        if (comp_u != comp_v)
        {
            combina(comp_u, comp_v, &conjunto);
            inserta(min->u, min->v, min->costo, &arbol_min); // VER ESTO
            n_comp -= 1;
        }
    }

    lista(arbol_min);

    freeQueue(arbol_min);
}

void freeQueue(rama *head)
{
    rama *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->sig;
        free(temp);
    }
}