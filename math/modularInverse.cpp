#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modularInverse(ll a, ll m){
	ll m0 = m;
	ll y = 0, x = 1;

	if(m == 1) return 0;

	ll q, t;
	while(a > 1){
		q = a / m;
		t = m;

		m = a%m;
		a = t;
		t = y;

		y = x - q*y;
		x = t;
	}

	if(x < 0) x += m0;
	return x;
}

int main(){
	ll a, m;
	scanf("%lld%lld", &a, &m);
	printf("%lld\n", modularInverse(a, m));
	return 0;
}