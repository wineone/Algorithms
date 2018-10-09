#include <cstdio>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

vector<int> v[10005];
vector<pair<bool, bool> > vq(10005,make_pair(false,false));// first -> visitado / second -> queue


bool cicle(int no){
	vq[no].first = true;
	vq[no].second = true;

	for(auto r: v[no]){
		if(!vq[r].first)
			if(cicle(r)) return true;
		if(vq[r].second) return true;
	}

	vq[no].second = false;
	return false;
}

int main(){
	int vezes;
	scanf("%d",&vezes);

	for(int i = 0; i < vezes; i++){

		int liga, verti;
		scanf("%d %d",&verti,&liga);

		for(int j = 0; j < liga; j++){
			int v1, v2;
			scanf("%d %d",&v1,&v2);
			v[v1].push_back(v2);
		}

		bool aux = false;

		for(int j = 0; j < verti; j++){
			if(!vq[j].first){ 
				if(cicle(j)){
					aux = true;
					break;
				}
			}
		}

		if(aux) printf("SIM\n");
		else printf("NAO\n");

		for(int j = 1; j <= verti; j++){
			v[j].clear();
			vq[j].first = false;
			vq[j].second = false;
		}

	}

	return 0;
}
