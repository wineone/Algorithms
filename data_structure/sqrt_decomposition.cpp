#include <bits/stdc++.h>

using namespace std;

#define max 107
#define sqrt_max 11

int block[sqrt_max];
int values[max];
int n, q, groups;

int query(int l, int r){
    int sum = 0;
    for(int i=l; i<=r;){
        if(i%groups==0 && i+groups-1 <= r){
            sum += block[i/groups];
            i += groups;
        }
        else sum += values[i++];
    }
    return sum;
}

int main(){
    int x, y;
    scanf("%d%d", &n, &q);
    groups = sqrt(n);
    for(int i=0; i<n; i++){
        scanf("%d", &values[i]);
        block[i/groups] += values[i];
    }
    while(q--){
        scanf("%d%d", &x, &y);
        printf("%d\n", query(--x, --y));
    }
    return 0;
}