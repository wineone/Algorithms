#include <stdio.h>

using namespace std;

#define MAX 107

int tree[MAX];
int values[MAX], n;


int read(int idx){
    int sum = 0;
    while(idx != 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int idx, int value){
    while(idx < MAX){
        tree[idx] += value;
        idx += (idx)&(-idx);
    }
}

int main(){
    int k, opc, x, y;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &values[i]);
        update(i, values[i]);
    }
    while(k--){
        scanf("%d %d %d", &opc, &x, &y);
        if(opc == 1){   //Read
            printf("%d\n", read(y) - read(x-1));
        }else{          //Update
            update(x, y);
        }
    }
    return 0;
}