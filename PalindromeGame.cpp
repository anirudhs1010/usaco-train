// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int main() {
	unsigned long long n;
	string a;
	cin >> n;
	for (unsigned long long i = 0; i < n; i++) {
		cin >> a;
		if (a[a.size()-1] == '0')
			cout << 'E' << endl;
		else
			cout << 'B' << endl;
	}
	
}
