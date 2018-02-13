#include <stdio.h>

using namespace std;

#define MAX (int)10e6

int array_value[MAX];

void list_array(int tam){
  for(int i=0; i<tam; i++){
    printf("%d ", array_value[i]);
  }
  printf("\n");
}

void quick_sort(int iniVet, int finVet){
  int ini = iniVet, fin = finVet;
  int pivo = array_value[(ini + fin)/2];
  while(ini <= fin){
    while(array_value[ini] < pivo) ini ++;
    while(array_value[fin] > pivo) fin --;
    if(ini <= fin){
      int aux = array_value[ini];
      array_value[ini] = array_value[fin];
      array_value[fin] = aux;
      ini ++;
      fin --;
    }
  }
  if(iniVet < fin) quick_sort(iniVet, fin);
  if(ini < finVet) quick_sort(ini, finVet);
}

int main(){
  int n_number;
  scanf("%d", &n_number);
  for(int i=0; i<n_number; i++) scanf("%d", &array_value[i]);
  quick_sort(0, n_number-1);
  list_array(n_number);
  return 0;
}
