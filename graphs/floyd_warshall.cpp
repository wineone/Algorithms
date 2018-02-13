#include <stdio.h>

using namespace std;

#define MAX (int)10e3
#define INF (int)10e8

int dist[MAX][MAX];

int min(int a, int b){
  if(a < b) return a;
  else return b;
}

void floyd_warshall(int tam){
  for(int k=1; k<=tam; k++){
    for(int i=1; i<=tam; i++){
      for(int j=1; j<=tam; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

void build(int tam){
  for(int i=1; i<=tam; i++) for(int j=1; j<=tam; j++) dist[i][j] = INF;
}

int main(){
  int n_vert, edges, vert1, vert2, weight;
  scanf("%d %d", &n_vert, &edges);
  build(n_vert);
  while(edges--){
    scanf("%d %d %d", &vert1, &vert2, &weight);
    dist[vert1][vert2] = weight;
    dist[vert2][vert1] = weight; //bidirectional
  }
  floyd_warshall(n_vert);
  int source, target;
  scanf("%d %d", &source, &target);
  printf("%d\n", dist[source][target]);
  return 0;
}
