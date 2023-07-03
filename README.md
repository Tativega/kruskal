# kruskal

## Kruskal's algorithm for the final programming exam.

1. **ALLOCATE SPACE IN MEMORY FOR THE ADJACENCY MATRIX**

- (**) malloc sizeof(int*)* VERTICES (rows)
- (*) malloc sizeof(int) * VERTICES (columns, within a for loop)

2. **LOAD EDGE WEIGHTS**
- nested loop.
- i = 0;
- j = i + 1;

3. **GO THROUGH THE MATRIX AND CALL THE ***INSERT*** FUNCTION FOR EACH ELEMENT**
Insert generates the priority queue (linked list) where each node has:
edge.u
edge.v
edge.cost
pointer to the next node

- branch *tree = *NULL*;
- **INSERT(i, j, matrix[i][j], &tree)** function:
(i, j) is an edge
matrix[i][j] is the COST of the edge (i, j);

4. **KRUSKAL FUNCTION CALL**
- Go through the Vs and call the **INITIAL(v, v, SET_CE)** function to initialize the SET_UF
- SET_UF has:
- - NAME array [{name, next}, ..., {name, next}]
- - HEADER array [{count, first_elem},..., {count, first_elem}]

- in initialization, name is the vertex and next is 0.
- count is 1 and first element is the vertex

- I call the function **EXTRACT_MIN(**node)**
- - extract_min receives the address of the linked list (the first element)
- - if it is not NULL, it returns the edge and then makes the node value equal to node.next

- **EXTRACT_MIN()** returns an edge A
- Call the **FIND()** function with the value of A.u and A.v to know which component each vertex of the edge belongs to
- - comp_u = find(A.u)
- - comp_v = find(A.v)
- if comp_u != comp_v it means that they belong to different sets and it can be added to the tree T
- call the **COMBINE()** function to update the SET_UF
- call the **INSERT()** function to add that edge to the solution tree (it's another linked list)

- finally, call the **LIST()** function that is going to be called recursively over the linked list, listing the edge and its cost.

5. Free the memory blocks that have been requested with malloc.


