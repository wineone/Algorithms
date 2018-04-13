#include <stdio.h>

using namespace std;

#define MAX 100

int lg[MAX];

void log_b2(){
    lg[0] = 0; lg[1] = 0;
    for(int i=2; i<MAX; i++) lg[i] = lg[i/2] + 1;
}

int main(){
    log_b2();

    int x;
    scanf("%d", &x);
    printf("%d\n", lg[x]);
    return 0;
}