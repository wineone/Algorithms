
//maior subsequencia comum
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int lcs(const string &a,const string &b){
	int lens1 = a.size(), lens2 = b.size();

	int matriz[lens1 + 2][lens2 + 2] = {0};// +2 para compensar um bug da liguagem o certo era +1, mas não muda nada

	for(int i = 1; i <= lens1; i++){
		for(int j = 1; j <= lens2; j++){
			if(a[i-1] == b[j-1])
				matriz[i][j] = matriz[i-1][j-1] + 1;
			else
				matriz[i][j] = max(matriz[i-1][j],matriz[i][j-1]);
		}
	}

	for(int i = 0; i <= lens1; i++){
		for(int j = 0; j <= lens2; j++){
			printf("%d ",matriz[i][j]);
			if(j == lens2) putchar('\n');
		}
	}

	return matriz[lens1][lens2];

}

int main(){
	string s1("MATH"), s2("MAdsdsdTdsdsH");
	printf("length: %d\n",lcs(s1,s2));
	return 0;
}
