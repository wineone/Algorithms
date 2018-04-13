#include <stdio.h>

using namespace std;

#define MAX 100
#define LOG_B2_MAX 7

int sp[LOG_B2_MAX][MAX], lg[MAX], val[MAX];

void log_b2(){
    for(int i=2; i<MAX; i++) lg[i] = lg[i/2] + 1;
}

int max(int a, int b){ if(a>b) return a; else return b; }

void build(int n){
    for(int i=0; i<n; i++) sp[0][i] = val[i];
    for(int j=1; j <= lg[n]; j++){
        for(int i=0; i + (1<<j) <= n; i++){
            sp[j][i] = max(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);
        }
    }
}

int query(int l, int r){
    int k = lg[r-l+1];
    return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

int main(){
    log_b2();
    int n, q, x, y;
    scanf("%d%d", &n, &q);
    for(int i=0; i<n; i++) scanf("%d", &val[i]);
    build(n);
    while(q--){
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x-1, y-1));
    }
    return 0;
}