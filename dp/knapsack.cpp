#include <stdio.h>

using namespace std;

#define MAX (int)10e6

int knapsack[MAX];
int weight_limit, max_value;

// repeat itens
void add_itens_repeat(int value, int weight){
  for(int i=0; i<= weight_limit; i++){
    if(knapsack[i]){
      if(i + weight <= weight_limit){
        knapsack[i + weight] = value + knapsack[i];
        if(knapsack[i + weight] > max_value) max_value = knapsack[i + weight];
      }
    }
  }
}

// no repeat itens
void add_itens_no_repeat(int value, int weight){
  for(int i=weight_limit; i >= 0; i--){
    if(i - weight <= weight_limit && knapsack[i - weight]){
        knapsack[i] = value + knapsack[i - weight];
        if(knapsack[i] > max_value) max_value = knapsack[i];
    }
  }
}

void build(){  knapsack[0] = 1;  }

int main(){
  build();
  int number, value, weight;
  scanf("%d %d", &number, &weight_limit);
  while(number--){
    scanf("%d %d", &value, &weight);
    //add_itens_repeat(value, weight);    // repeat itens
    add_itens_no_repeat(value, weight); // no repeat itens
  }
  printf("%d\n", max_value - 1);
  return 0;
}
