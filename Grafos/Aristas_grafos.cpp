/*
EXPLORED = 2 (visitado pero no completado)
VISITED (visitado y completado)
TIPOS DE ARISTAS
1. Arista de arbol: la arista recorrida por DFS, es decir, una arista de un vertice con estado EXPLORED
a un vertice con estado UNVISITED
2. Arista inversa: una arista que es parte de un ciclo, es decir, una arista de un vertice con estado EXPLORED
a un vertice tambien EXPLORED. Hay que tener en cuenta que normalmente no consideramos que las aristas bidireccionales
tengan un "ciclo" (debemos recordar dfs_parent para distinguir esto)
3. Aristas adelante/cruzadas: de un vertice con estado EXPLORED a otro con estado VISITED.
*/

void graphCheck(int u){ //DFS para comprobar las propiedades de la arista

}