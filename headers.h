#define VERTICES 6

typedef struct _EDGE
{
    int u;
    int v;
    int cost;
} edge;

typedef struct _BRANCH
{
    edge E;
    struct _BRANCH *next;
} branch;

typedef struct _HEADER
{
    int count;
    int first_element;
} header;

typedef struct _NAME
{
    int set_name;
    int next_element;
} name;

typedef struct _SET_UF
{
    name names[VERTICES];
    header set_headers[VERTICES];
} set_uf;

void initial(int, int, set_uf *);
void combine(int, int, set_uf *);
int find(int, set_uf *);
void kruskal(branch *);
void insert(int, int, int, branch **);
edge *extract_min(branch **);
void list(branch *);

void freeQueue(branch *);
