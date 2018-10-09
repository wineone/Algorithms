#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> array = {-3, -4, -5, 6, -7 ,9, 2};

    int maiorAtual = 0;
    int maiorGlobal = array[0];
    for(auto a: array){
        maiorAtual += a;
        if(maiorAtual > maiorGlobal)
            maiorGlobal = maiorAtual;
        if(maiorAtual < 0)
            maiorAtual = 0;
    }


    cout << maiorGlobal << endl;

}
