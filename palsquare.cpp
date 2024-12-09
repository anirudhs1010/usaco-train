// Source: https://usaco.guide/general/io
/*
ID: anirudh74
TASK: palsquare
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

bool isPal(string s) {
	int j = s.size() - 1;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[j])
			return false;
		j--;
	}
	return true;
}

string convBase(int n, int b) {
	string s;
	while (n > 0) {
		int rem = n % b;
		if (rem < 10)
			s += (rem + '0');  // Convert to a character for digits 0-9
		else
			s += (rem - 10 + 'A');  // Convert to a character for letters A-Z (for bases > 10)
		n /= b;
	}
	reverse(s.begin(), s.end());  // Reverse the string to get the correct representation
	return s;
}

int main() {
	int b;
	
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	cin >> b;
	for (int i = 1; i <= 300; i++) {
		string n = convBase(i, b);  // Convert number to the base
		string square = convBase(i * i, b);  // Convert square to the base
		if (isPal(square)) {
			cout << n << " " << square << endl;
		}
	}
	return 0;
}
