#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int> tree[MAX];
vector< pair<int, int> > euler_circuit;
bitset<MAX> visit;
bool euleriano;
int n, m, cont_visit;

void fleury_algorithm(int no){
    if(!euleriano) return;

    for(int i=0; i<tree[no].size(); i++){
        int v = tree[no][i];
        if(tree[v].size() > 1){
            printf("{%d %d}\n", no, v);
            euler_circuit.push_back(make_pair(no, v));
            tree[no].erase(tree[no].begin() + i);
            for(int k=0; k<tree[v].size(); k++){
                if(tree[v][k] == no){
                    tree[v].erase(tree[v].begin() + k);
                    break;
                }
            }
            
            fleury_algorithm(v);
            break;
        }
    }

    if(tree[no].size() == 1){
        euler_circuit.push_back(make_pair(no, tree[no][0]));
        tree[no].erase(tree[no].begin());
        tree[tree[no][0]].erase(tree[tree[no][0]].begin());
        fleury_algorithm(tree[no][0]);
    }
}

void dfs_fleury(int u, int p){
    cont_visit ++;
    visit[u] = true;
    if(tree[u].size() % 2) euleriano = false;

    for(int i=0; i<tree[u].size(); i++){
        if(!visit[tree[u][i]]){
            dfs_fleury(tree[u][i], u);
        }
    }
}

bool fleury(){
    euleriano = true;
    dfs_fleury(1, 1);

    if(!euleriano || cont_visit != n) return false;

    fleury_algorithm(1);
    return true;
}

void path_euler(){
    for(int i=0; i<euler_circuit.size(); i++){
        int first = euler_circuit[i].first;
        int second = euler_circuit[i].second;
        printf("{%d, %d} ", first, second);
    }
    printf("\n");
}

int main(){
    int x, y;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    if(fleury()) {
        printf("Yes\n");
        path_euler();
    }else printf("No\n");
    return 0;
}