#include <stdio.h>

using namespace std;

typedef long long int lld;

#define MAX (int)10e6

lld fact[MAX];

lld factorial(lld number){
	if(fact[number]) return fact[number];
	else if(number == 1 || number == 0) return 1;
	else return fact[number] = factorial(number-1) * number;
}

int main(){
	lld number;
	scanf("%lld", &number);
	printf("%lld\n", factorial(number));
	return 0;
}