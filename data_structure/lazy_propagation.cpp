#include <stdio.h>

using namespace std;

#define MAX (int)10e6

int tree[MAX * 4], lazy[MAX * 4], values[MAX];

void lazyprop(int id){
    if(lazy[id] != 0){
        lazy[id*2] = lazy[id];
        lazy[id*2+1] = lazy[id];
        lazy[id] = 0;
    }
}

int read(int id, int l, int r, int x, int y){
    if(l > y || r < x){
        if(lazy[id] != 0) tree[id] = lazy[id] * ((r-l) +1);
        return 0;
    }else{
        if(l >= x && r <= y){
            return tree[id];
        }else{
            int mid = (l+r)/2;
            lazyprop(id);
            int q1 = read(id*2, l, mid, x, y);
            int q2 = read(id*2+1, mid+1, r, x, y);
            tree[id] = tree[id*2] + tree[id*2+1];
            return q1 + q2;
        }
    }
}

void update(int id, int l, int r, int x, int y, int value){
    if(l > y || r < x){
        if(lazy[id] != 0) tree[id] = lazy[id] * ((r-l) +1);
        return;
    }else if(l >= x && r <= y){
        lazy[id] = value;
        tree[id] = value * ((r-l) + 1);
    }else{
        int mid = (l+r)/2;
        lazyprop(id);
        update(id*2, l, mid, x, y, value);
        update(id*2+1, mid+1, r, x, y, value);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

void build(int id, int l, int r){
    if(l == r) tree[id] = values[l];
    else{
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

int main(){
    int n, q, opc, x, y;
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%d", &values[i]);
    build(1, 1, n);
    while(q--){
        scanf("%d %d %d", &opc, &x, &y);
        if(opc == 1){ //read
            printf("%d\n", read(1, 1, n, x, y));
        }else{ //update
            scanf("%d", &opc);
            update(1, 1, n, x, y, opc);
        }
    }
    return 0;
}