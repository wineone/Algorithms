#include <bits/stdc++.h>

using namespace std;

struct trie{
	map<char, trie> node;
	bool end_point;

	trie(): end_point(false) {}

	void add(const string &s, int i = 0){
		if(i == s.size())
			end_point = true;
		else
			node[s[i]].add(s, i+1);
	}

	bool check(const string &s, int i = 0){
		if(i == s.size())
			return true;
		else{
			if(node.count(s[i]))
				node[s[i]].check(s, i+1);
			else
				return false;
		}
	}
};

trie my_trie;
int n, m;
string in;

int main(){
	scanf("%d %d", &n, &m);
	while(n--){
		cin >> in;
		my_trie.add(in);
	}
	while(m--){
		cin >> in;
		if(my_trie.check(in)) printf("Yes\n");
		else printf("No\n");
	}
}