#include <stdio.h>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

typedef long long int lld;

#define MAX (int)10e5

bitset<MAX> eh_primo;
vector<lld> primos;
lld quant = 0;

lld crivo(){
  int limit = (int)sqrt(MAX);

  for(lld i=2; i <= limit; i++){
    if(!eh_primo[i]){
      for(lld j= i * i; j < MAX; j += i){
        eh_primo[j] = true;
      }
      primos.push_back(i);
      printf("%lld\n", i);
      quant ++;
    }
  }
  return quant;
}

int main(){
  printf("%lld\n", crivo());
  return 0;
}
