#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

#define MAX (int)10e6

vector<int> lst_adj[MAX];
bitset<MAX> visit;
int dist[MAX];

int bfs(int source, int target){
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	while(!q.empty()){
		int vert = q.front(); q.pop();
		visit.set(vert);
		if(vert == target) return dist[vert];
		for(int i=0; i<lst_adj[vert].size(); i++){
			int vert_connect = lst_adj[vert][i];
			if(!visit[vert_connect]){
				q.push(vert_connect);
				dist[vert_connect] = dist[vert] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int edges, source, target, vert1, vert2;
	scanf("%d", &edges);
	while(edges--){
		scanf("%d %d", &vert1, &vert2);
		lst_adj[vert1].push_back(vert2);
		lst_adj[vert2].push_back(vert1); // bidirectional
	}
	scanf("%d %d", &source, &target);
	printf("%d\n", bfs(source, target));
	return 0;
}
