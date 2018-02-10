#include <stdio.h>

using namespace std;

typedef long long int lld;

#define MAX (int)10e6

lld fib[MAX];

lld fibonacci(int idx){
	if(fib[idx]) return fib[idx];
	else if(idx == 0 || idx == 1) return 1;
	else return fib[idx] = fibonacci(idx-1) + fibonacci(idx-2);
}

int main(){
	int idx;
	scanf("%d", &idx);
	printf("%lld\n", fibonacci(idx));
	return 0;
}