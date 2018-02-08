#include <stdio.h>
#include <queue>
#include <bitset>
#include <vector>

using namespace std;

typedef pair<int, int> pp;

#define MAX (int)10e6
#define INF (int)10e7

vector<pp> vertex_connect[MAX];
bitset<MAX> visit;
int dist[MAX];

int dijkstra(int source, int target){
  priority_queue<pp, vector<pp>, greater<pp> > pq;
  pq.push(make_pair(0, source));
  dist[source] = 0;
  while(!pq.empty()){
    pp top = pq.top(); pq.pop();
    if(top.second == target) return dist[top.second];
    visit.set(top.second);
    for(int i=0;  i<vertex_connect[top.second].size(); i++){
      pp vert = vertex_connect[top.second][i];
      if(!visit[vert.second]){
        if(dist[vert.second] > dist[top.second] + vert.first){
          dist[vert.second] = dist[top.second] + vert.first;
          pq.push(make_pair(dist[vert.second], vert.second));
        }
      }
    }
  }
}

void build(int tam){
  for(int i=1; i<=tam; i++) dist[i] = INF;
}

int main(){
  int edges, vert1, vert2, weight;
  scanf("%d", &edges);
  build(edges);
  while(edges--){
    scanf("%d %d %d", &vert1, &vert2, &weight);
    vertex_connect[vert1].push_back(make_pair(weight, vert2));
    vertex_connect[vert2].push_back(make_pair(weight, vert1)); // bidirectional
  }
  int source, target;
  scanf("%d %d", &source, &target);
  printf("%d\n", dijkstra(source, target));
  return 0;
}
