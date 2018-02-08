#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > ppp;

#define MAX (int)10e6

int parent[MAX];
vector <ppp> vertex_connects;
int weight_total;

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
  int edges, vert1, vert2, weight;
  scanf("%d", &edges);
  build(edges);
  while(edges--){
    scanf("%d %d %d", &vert1, &vert2, &weight);
    vertex_connects.push_back(make_pair(weight, make_pair(vert1, vert2)));
  }
  sort(vertex_connects.begin(), vertex_connects.end());
  for(int i=0; i<vertex_connects.size(); i++){
    weight = vertex_connects[i].first;
    vert1 = vertex_connects[i].second.first;
    vert2 = vertex_connects[i].second.second;
    if(find(vert1) != find(vert2)){
      join(vert1, vert2);
      weight_total += weight;
    }
  }
  printf("%d\n", weight_total);
  return 0;
}
