#include <stdio.h>
#include <vector>
#include <bitset>

using namespace std;

#define MAX (int)10e6

vector<int> lst_adj[MAX];
bitset<MAX> visit;
int source, target;


bool dfs(int no){
	visit.set(no);
	for(int i=0; i<lst_adj[no].size(); i++){
		if(!visit[lst_adj[no][i]]) dfs(lst_adj[no][i]);
	}
}

int main(){
	int edges, vert1, vert2;
	scanf("%d", &edges);
	while(edges--){
		scanf("%d %d", &vert1, &vert2);
		lst_adj[vert1].push_back(vert2);
		lst_adj[vert2].push_back(vert1); // bidirectional
	}
	scanf("%d %d", &source, &target);
	dfs(source);
	if(visit[target]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
