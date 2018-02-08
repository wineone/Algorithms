#include <stdio.h>

using namespace std;

#define MAX (int)10e6

int parent[MAX];

int find(int a){
  if(parent[a] == a) return a;
  else return parent[a] = find(parent[a]);
}

void join(int a, int b){
  int prtA = find(a);
  int prtB = find(b);
  if(prtA == prtB) return;
  parent[prtA] = prtB;
}

void build(int tam){
  for(int i=1; i<=tam; i++) parent[i] = i;
}

int main(){
  int edges, vert1, vert2;
  scanf("%d", &edges);
  build(edges);
  while(edges--){
    scanf("%d %d", &vert1, &vert2);
    join(vert1, vert2);
  }
  int source, target;
  scanf("%d %d", &source, &target);
  if(find(source) == find(target)) printf("YES\n");
  else printf("NO\n");
  return 0;
}
