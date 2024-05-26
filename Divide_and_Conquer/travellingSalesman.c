
#include <stdio.h>
int tsp_g[10][10] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};
int visited[10], n, cost = 0;

/* creating a function to generate the shortest path */
void travellingsalesman(int c,int p){
   int k, adj_vertex = 999;
   int min = 999;
   
   /* marking the vertices visited in an assigned array */
   visited[c] = 1;
   
   /* displaying the shortest path */
   printf("%d ", c + 1);
   
   /* checking the minimum cost edge in the graph */
   for(k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (visited[k] == 0)) {
         if(tsp_g[c][k] < min) {
            min = tsp_g[c][k];
            adj_vertex = k;
         }
      }
   }
   if(min != 999) {
      cost = cost + min;
   }
   if(adj_vertex == 999) {
      adj_vertex = p;
      printf("%d", adj_vertex + 1);
      cost = cost + tsp_g[c][adj_vertex];
      return;
   }
   travellingsalesman(adj_vertex,p);
}

/* main function */
int main(){
   int i, j;
   n = 5;
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   printf("Shortest Path: ");
   travellingsalesman(1,1); // pass any source paramter.Both equal.
   printf("\nMinimum Cost: ");
   printf("%d\n", cost);
   return 0;
}