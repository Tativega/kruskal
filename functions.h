// INSERTS A NODE IN THE PRIORITY QUEUE
void insert(int u, int v, int cost, branch **node)
{
    if (*node == NULL) // if tree is still not pointing to anything it's empty, load the first node
    {
        *node = (branch *)malloc(sizeof(branch));
        (*node)->E.u = u;
        (*node)->E.v = v;
        (*node)->E.cost = cost;
        (*node)->next = NULL;
    }
    else
    { // the tree is not empty, I have to create a new node and place it according to its cost
        if (cost < (*node)->E.cost)
        {
            branch *new_node = (branch *)malloc(sizeof(branch));
            new_node->E.u = u;
            new_node->E.v = v;
            new_node->E.cost = cost;
            new_node->next = *node;
            *node = new_node;
        }
        else
        {
            insert(u, v, cost, &((*node)->next));
        }
    }
}

// INITIAL LOAD OF UNION-FIND SET
void initial(int name, int element, set_uf *C)
{
    C->names[element].set_name = name;
    C->names[element].next_element = -1;
    C->set_headers[name].count = 1;
    C->set_headers[name].first_element = element;
}

// RETURNS THE EDGE WITH THE LOWEST COST
edge *extract_min(branch **a)
{
    edge *head = &((*a)->E);
    *a = (*a)->next;

    return head;
}

// RETURNS THE NAME OF THE SET TO WHICH A NODE BELONGS
int find(int name, set_uf *set)
{
    return set->names[name].set_name;
}

// COMBINES TWO DISJOINT SETS
void combine(int A, int B, set_uf *C)
{
    int bigger_set = C->set_headers[A].count > C->set_headers[B].count ? A : B;
    int smaller_set = bigger_set == A ? B : A;

    int i = C->set_headers[smaller_set].first_element;
    while (C->names[i].next_element != -1)
    {
        C->names[i].set_name = bigger_set;
        i = C->names[i].next_element;
    }

    C->names[i].set_name = bigger_set;
    C->names[i].next_element = C->set_headers[bigger_set].first_element;
    C->set_headers[bigger_set].first_element = C->set_headers[smaller_set].first_element;
    C->set_headers[bigger_set].count += C->set_headers[smaller_set].count;
}

// PRINTS THE MINIMUM SPANNING TREE
void list(branch *tree)
{
    if (tree != NULL)
    {
        printf("Edge %i, %i. Cost %i\n", tree->E.u, tree->E.v, tree->E.cost);

        list(tree->next);
    }
}

// KRUSKAL'S ALGORITHM
void kruskal(branch *tree)
{
    set_uf set;
    branch *min_tree = NULL;
    edge *min;
    int n_comp = VERTICES;
    int comp_u, comp_v;

    for (int i = 0; i < VERTICES; i++)
    {
        initial(i, i, &set);
    }

    while (n_comp > 1)
    {
        min = extract_min(&tree);
        comp_u = find(min->u, &set);
        comp_v = find(min->v, &set);

        if (comp_u != comp_v)
        {
            combine(comp_u, comp_v, &set);
            insert(min->u, min->v, min->cost, &min_tree); // CHECK THIS
            n_comp -= 1;
        }
    }

    list(min_tree);

    freeQueue(min_tree);
}

// FREES THE MEMORY REQUESTED FOR THE PRIORITY QUEUE
void freeQueue(branch *head)
{
    branch *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}