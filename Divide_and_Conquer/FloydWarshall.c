#include<stdio.h>
#define INF 9999
#define v 4
void FloydWarshall(int graph[][v]){
    int i,j,k;
    for(k=0;k<v;k++){
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                if(i!=j&&(graph[i][k]+graph[k][j]<graph[i][j])){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
}
void printGraph(int graph[][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(graph[i][j]==INF){
                printf("INF ");
            } else
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int graph[v][v]={{0,5,INF,10},
                     {INF,0,3,INF},
                     {INF,INF,0,1},
                     {INF,INF,INF,0}};
    FloydWarshall(graph);
    printGraph(graph);
    return 0;
}