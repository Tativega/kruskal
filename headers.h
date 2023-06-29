#define VERTICES 6

typedef struct _ARISTA
{
    int u;
    int v;
    int costo;
} arista;

typedef struct _RAMA
{
    arista A;
    struct _RAMA *sig;
} rama;

typedef struct _ENCABEZADO
{
    int cuenta;
    int primer_elemento;
} encabezado;

typedef struct _NOMBRE
{
    int nombre_conjunto;
    int siguiente_elemento;
} nombre;

typedef struct _CONJUNTO_CE
{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
} conjunto_CE;

void inicial(int, int, conjunto_CE *);
void combina(int, int, conjunto_CE *);
int encuentra(int, conjunto_CE *);
void kruskal(rama *);
void inserta(int, int, int, rama **);
arista *sacar_min(rama **);
void lista(rama *);

void freeQueue(rama *);