#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define LG_MAX 100

typedef struct qry{
    int left, right, id, number_lca;
    bool lca_include;
}qry;

int freq[MAX], freq_peso[MAX];
qry query[MAX];
int answer[MAX];

int parent[LG_MAX][MAX];
int level[MAX];

vector<int> euler;
pair<int, int> inter[MAX];

vector<int> tree[MAX];
int pesos[MAX];
int n, q, g, res, lg;

//Dfs
void dfs(int u, int p){
    inter[u].first = euler.size();
    euler.push_back(u);
    for(auto v: tree[u]){
        if(v != p){
            level[v] = level[u] + 1;
            parent[0][v] = u;
            dfs(v, u);
        }
    }
    inter[u].second = euler.size();
    euler.push_back(u);
}

//Lca
void build(){
    for(int i=1; i<=lg; i++){
        for(int j=1; j<=n; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int lca(int u, int v){
    if(level[u] < level[v]) return lca(v, u);
    for(int i=lg; i>=0; i--){
        if(level[u] - (1<<i) >= level[v]){
            u = parent[i][u];
        }
    }
    if(u == v) return u;
    for(int i=lg; i>=0; i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

//Mos
void operation(int i){
    if(!freq[euler[i]]){
        if(freq_peso[pesos[euler[i]]] == 0) res ++;
        freq_peso[pesos[euler[i]]] ++;
        freq[euler[i]] = true;
    }else{
        if(freq_peso[pesos[euler[i]]] == 1) res --;
        freq_peso[pesos[euler[i]]] --;
        freq[euler[i]] = false;
    }
}

void mos(){
    int L = 0, R = -1;
    int l, r;
    for(int i=0; i<q; i++){
        l = query[i].left;
        r = query[i].right;

        while(r > R) operation(++R);
        while(r < R) operation(R--);

        while(l > L) operation(L++);
        while(l < L) operation(--L);

        if(query[i].lca_include && !pesos[query[i].number_lca])
            answer[query[i].id] = res + 1;
        else
            answer[query[i].id] = res;        
    }
}

//Sort
bool compare(qry a, qry b){
    if(a.left/g < b.left/g) return true;
    else if(a.left/g == b.left/g){
        if(a.right < b.right) return true;
        else return false;
    }
    else return false;
}

//Build query
void type_path(int i, int u, int v){
    int lca_number = lca(u, v);
    if(lca_number == u || lca_number == v){
        query[i].left = min(inter[u].first, inter[v].first);
        query[i].right = max(inter[u].first, inter[v].first);
        query[i].lca_include = false;
    }else{
        query[i].left = min(inter[u].second, inter[v].second);
        query[i].right = max(inter[u].first, inter[v].first);
        query[i].lca_include = true;
        query[i].number_lca = lca_number;
    }
}

int main(){
    int x, y;
    scanf("%d%d", &n, &q);
    g = sqrt(n<<1);
    for(int i=0; (1<<i) <= n; i++) lg++;

    for(int i=1; i<=n; i++) scanf("%d", &pesos[i]);
    for(int i=1; i<n; i++){
        scanf("%d%d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    } 
    dfs(1,1); build();
    for(int i=0; i<q; i++){
        scanf("%d%d", &x, &y);
        query[i].id = i;
        type_path(i, x, y);
    }
    sort(query, query+q, compare); mos();
    for(int i=0; i<q; i++) printf("%d\n", answer[i]);
    return 0;
}