# kruskal

1. **RESERVO ESPACIO EN MEMORIA PARA LA MATRIZ DE ADYACENCIA**

- (**) malloc sizeof(int*)* VERTICES (filas)
- (*) malloc sizeof(int) * VERTICES (columnas, dentro de un for)

2. **CARGA DE PESOS DE ARISTAS**
- bucle anidado.
- i = 0;
- j = i + 1;

3. **RECORRO LA MATRIZ Y LLAMO A LA FUNCION ***INSERTA*** EN CADA ELEMENTO**
inserta genera la cola de prioridad (lista enlazada) donde cada nodo tiene:

arista.u
arista.v
arista.costo
puntero al nodo siguiente

- rama *arbol = *NULL*;
- funcion **INSERTA(i, j, matriz[i][j], &arbol)**:
(i, j) es una arista
matriz[i][j] es el COSTO de la arista (i, j);

4. **LLAMADA FUNCION KRUSKAL**
- recorro los V y llamo a la funcion **INICIAL(v, v, CONJUNTO_CE)** para inicializar el CONJUNTO_CE
- CONJUNTO_CE tiene:
- - arreglo NOMBRE [{nombre, siguiente}, ..., {nombre, siguiente}]
- - arreglo ENCABEZADO [{cuenta, primer_elem},..., {cuenta, primer_elem}]

- en la inicializacion, nombre es el vertice y siguiente es 0.
- cuenta es 1 y primer elemento es el vertice

- llamo a la funcion **SACAR_MIN(**nodo)**
- - sacar min recibe la direccion de la lista enlazada (el primer elemento)
- - si no es NULL, retorna la arista y despues hace que el valor nodo sea igual a nodo.siguiente

- **SACAR_MIN()** retorno una arista A
- llamo a la funcion **ENCUENTRA()** con el valor de A.u y A.v para saber a que componente pertenece cada vertice de la arista
- - comp_u = encuentra(A.u)
- - comp_v = encuentra(A.v)
- si comp_u != comp_v quiere decir que pertenecen a conjuntos diferentes y puedo agregarla al arbol T
- llamar a la funcion **COMBINA()** para actualizar el CONJUNTO_CE
- llamar a la funcion **INSERTA()** para agregar esa arista al arbol solucion (es otra lista enlazada) (es necesario??)

- por ultimo se llama a la funcion **LISTA()** que se va a llamar recursivamente sobre la lista enlazada, listando la arista y su costo.

5. liberar los bloques de memoria que se hayan pedido con malloc


