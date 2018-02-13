#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX (int)10e6

int array_value[MAX];

void merge(int ini, int med, int fin){
  int idx_1 = ini, idx_2 = med + 1; // Range for sorting
  int tam = fin - ini + 1, idx_vet_aux = 0; // Variables for the vetor auxiliar
  int *array_aux; array_aux = (int*)malloc(tam * sizeof(int)); // Allocate memory for sorting in range
  while(idx_1 <= med && idx_2 <= fin){
    if(array_value[idx_1] <= array_value[idx_2]){
      array_aux[idx_vet_aux] = array_value[idx_1];
      idx_1 ++;
    }else{
      array_aux[idx_vet_aux] = array_value[idx_2];
      idx_2 ++;
    }
    idx_vet_aux ++;
  }
  while(idx_1 <= med){
    array_aux[idx_vet_aux] = array_value[idx_1];
    idx_vet_aux ++;
    idx_1 ++;
  }
  while(idx_2 <= fin){
    array_aux[idx_vet_aux] = array_value[idx_2];
    idx_vet_aux ++;
    idx_2 ++;
  }
  // Add ordered elements in array original
  for(int idx = ini; idx <= fin; idx++){
    array_value[idx] = array_aux[idx - ini];
  }
  free(array_aux);
}

void merge_sort(int ini, int fin){
  if(ini < fin){
    int med = ((ini + fin)/2);
    merge_sort(ini, med);
    merge_sort(med + 1, fin);
    merge(ini, med, fin);
  }
}

void list_array(int tam){
  for(int i=0; i<tam; i++){
    printf("%d ", array_value[i]);
  }
  printf("\n");
}

int main(){
  int n_number;
  scanf("%d", &n_number);
  for(int i=0; i<n_number; i++) scanf("%d", &array_value[i]);
  merge_sort(0, n_number-1); //Sorting Algorithm
  list_array(n_number); //Show the elements's array
  return 0;
}
