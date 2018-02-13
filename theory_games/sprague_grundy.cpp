#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (int)10e6

int xor_games;
int lst_grundy[MAX];
vector<int> lst_floor;

bool binary_search(vector<int> grundys, int key){
  int ini = 0, fin = grundys.size() - 1, med;
  while(ini <= fin){
    med = (ini + fin) / 2;
    if(grundys[med] > key) fin = med - 1;
    else if(grundys[med] < key) ini = med + 1;
    else return true;
  }
  return false;
}

int mex(vector<int> grundys){
  sort(grundys.begin(), grundys.end());
  for(int i=0; i<= MAX; i++){
    if(!binary_search(grundys, i)) return i;
  }
}

int grundy(int x){
  if(lst_grundy[x] != -1) return lst_grundy[x];
  else{
    vector<int> grundys;
    for(int i=0; i<lst_floor.size(); i++){
      int value = x - lst_floor[i];
      if(value >= 0) grundys.push_back(grundy(value));
    }
    return lst_grundy[x] = mex(grundys);
  }
}

void build(int tam){
  for(int i=1; i<=tam; i++) lst_grundy[i] = -1;
  lst_grundy[0] = 0;
}

int main(){
  int games, q_floor, value;
  build(50);
  scanf("%d %d", &games, &q_floor);
  while(q_floor--){
    scanf("%d", &value);
    lst_floor.push_back(value);
  }
  while(games--){
    scanf("%d", &value);
    xor_games = xor_games ^ grundy(value);
  }
  if(xor_games) printf("FIRST\n");
  else printf("SECOND\n");
  return 0;
}
