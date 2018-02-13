#include <stdio.h>

using namespace std;

int mdc(int a, int b){
  if(b == 0) return a;
  else return mdc(b, a%b);
}

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", mdc(a, b));
  return 0;
}
