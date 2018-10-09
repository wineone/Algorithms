//subset sum
#include <cstdio>
#define tamv 6
#define proc 9

using namespace std;

int main(){
	int p[] = {1,2,4,5,1,2};
	bool matriz[tamv + 1][proc + 1] = {0};

	for(int i = 0; i <= tamv; i++) matriz[i][0] = true;

	for(int i = 1; i <= proc; i++){
		for(int j = 1; j <= tamv; j++){
			bool s = matriz[j-1][i];
			if(!s && p[j - 1] <= i) s = matriz[j - 1][i - p[j - 1]];
			matriz[j][i] = s;
		}
	}
	printf("  ");
	for(int i = 0; i <= proc; i++){
		printf("%d ",i);
	}
	for(int i = 0; i <= tamv; i++){
		for(int j = 0; j <= proc; j++){
			if(!j%proc){
				putchar('\n');
				if(i == 0) printf("0 ");
				else printf("%d ",p[i-1]);
			}
			printf("%d ",matriz[i][j]);
		}
	}putchar('\n');

	return 0;
}
