#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#define max 100

typedef pair<int, int> pp;

vector<int> graph[max], sub_tree;
map<int, pp> interval;
int n;

void dfs(int u, int p){
    sub_tree.push_back(u);
    interval[u].first = sub_tree.size();
    for(auto v: graph[u]){
        if(v != p) dfs(v, u);
    }
    sub_tree.push_back(u);
    interval[u].second = sub_tree.size();
}

int main(){
    int x, y;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,1);
    for(int i=0; i<(n<<1); i++){
        printf("%d ", sub_tree[i]);
    }
    printf("\n");
    for(int i=1; i<=n; i++){
        printf("%d:[%d, %d]\n", i, interval[i].first, interval[i].second);
    }
}