#include <bits/stdc++.h>

using namespace std;

#define max 100007

vector<int> tree[max];
int sub_size[max];

vector<int> centroid_tree[max];
int centroid_parent[max];
bitset<max> is_centroid;

int dfs(int u, int p){
    sub_size[u] = 1;
    for(auto v: tree[u]){
        if(!is_centroid[v] && v != p){
            sub_size[u] += dfs(v, u);
        }
    }
    return sub_size[u];
}

int get_centroid(int u, int p, int tree_size){
    int heavy_child = -1;
    is_centroid[u] = true;
    for(auto v: tree[u]){
        if(v != p && !is_centroid[v]){
            if((sub_size[v] << 1) > tree_size) is_centroid[u] = false;
            if(heavy_child == -1 || sub_size[v] > sub_size[heavy_child]) heavy_child = v;
        }
    }
    if(is_centroid[u]) return u;
    else return get_centroid(heavy_child, u, tree_size);
}

int decompose_tree(int root){
    int centroid = get_centroid(root, root, dfs(root, root));
    for(auto v: tree[centroid]){
        if(!is_centroid[v]){
            int sub_centroid = decompose_tree(v);
            centroid_tree[v].push_back(centroid);
            centroid_tree[centroid].push_back(v);
            centroid_parent[sub_centroid] = centroid;
        }
    }
    return centroid;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(centroid_parent, -1, sizeof(centroid_parent));
    int root = decompose_tree(0);
    for(int i=0; i<n; i++){
        printf("%d ", 1 + centroid_parent[i]);
    }
    return 0;
}