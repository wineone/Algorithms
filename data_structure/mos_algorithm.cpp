#include <bits/stdc++.h>

using namespace std;

#define max 107

typedef struct query{
    int id;
    int left, right;
    int x;
}query;

int values[max], freq[max], answer[max];
query qry[max];
int n, q, groups;

bool compare(query a, query b){
    if(a.left/groups < b.left/groups) return true;
    else if(a.left/groups == b.left/groups){
        if(a.right < b.right) return true;
        else return false;
    }else return false;
}

void add(int x){
    freq[values[--x]]++;
}

void remove(int x){
    freq[values[--x]]--;
}

void mos(){
    int L = 1, R = 0;
    int l, r;
    for(int i=0; i<q; i++){
        l = qry[i].left;
        r = qry[i].right;
        while(r > R){
            R++;
            add(R);
        }
        while(r < R){
            remove(R);
            R--;
        }
        while(l > L){
            remove(L);
            L++;
        }
        while(l < L){
            L--;
            add(L);
        }
        answer[qry[i].id] = freq[qry[i].x];
    }
}

int main(){
    int x, y, z;
    scanf("%d%d", &n, &q);
    groups = sqrt(n);
    for(int i=0; i<n; i++) scanf("%d", &values[i]);
    for(int i=0; i<q; i++){
        scanf("%d%d%d", &x, &y, &z);
        qry[i].id = i;
        qry[i].left = x;
        qry[i].right = y;
        qry[i].x = z;
    }
    sort(qry, qry+q, compare);
    mos();
    for(int i=0; i<q; i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}