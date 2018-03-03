#include <stdio.h>

using namespace std;

#define MAX (int)10e3

int tree[MAX][MAX];
int n, m;

int read(int idx_x, int idx_y){
    int soma = 0, x = idx_x, y;
    while(x != 0){
        y = idx_y;
        while(y != 0){
            soma += tree[x][y];
            y -= y & (-y);
        }
        x -= x & (-x);
    }
    return soma;
}

void update(int idx_x, int idx_y, int value){
    int x = idx_x, y;
    while(x <= n){
        y = idx_y;
        while(y <= m){
            tree[x][y] += value;
            y += y & (-y);
        }
        x += x & (-x);
    }
}

int main(){
    int q, opc, x1, x2, y1, y2;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &x1);
            update(i, j, x1);
        }
    }
    while(q--){
        scanf("%d %d %d", &opc, &x1, &y1);
        if(opc == 1){
            scanf("%d %d", &x2, &y2);
            printf("%d\n", read(x2, y2) - read(x2, y1-1) - read(x1-1, y2) + read(x1-1, y1-1));
        }else{
            scanf("%d", &opc);
            update(x1, y1, opc);
        }
    }
    return 0;
}