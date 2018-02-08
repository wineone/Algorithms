#include <stdio.h>

using namespace std;

typedef long long int lld;

lld fast_exp(int base, int exp){
	if(!exp) return 1;
	else if(exp == 1) return base;
	else{
		if(exp%2){
			lld value = fast_exp(base, (exp-1)/2);
			return value * base;	
		}else{
			lld value = fast_exp(base, exp/2);
			return value * value;
		}
		
	}
}

int main(){
	int base, exp;
	scanf("%d %d", &base, &exp);
	printf("%lld\n", fast_exp(base, exp));
	return 0;
}