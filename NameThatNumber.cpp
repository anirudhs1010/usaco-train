// Source: https://usaco.guide/general/io
/*
ID: anirudh74
TASK: namenum
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
bool isT = false;
string b;
vector<string> ans;
map<string, int> names;
map<char, vector<char>> m;
void backtrack(int id, string v) {
	if (b.size() == v.size()) { 
		if (names.count(v))
			ans.push_back(v);
		return;
	}
	for (char c: m[b[id]]) {
		backtrack(id+1, v+c);
	}
}



int main() {
	freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
	string a;
	cin >> a;
	
	ifstream file("dict.txt");
    string line;
    if (file.is_open()) {
        // Read each line from the file and store it in the
        // 'line' variable.
        while (getline(file, line)) {
			names[line]++;
        }
        // Close the file stream once all lines have been
        // read.
        file.close();
	}
	
	
	m['2'] = {'A', 'B', 'C'};
	m['3'] = {'D', 'E', 'F'};
	m['4'] = {'G', 'H', 'I'};
	m['5'] = {'J', 'K', 'L'};
	m['6'] = {'M', 'N', 'O'};
	m['7'] = {'P', 'R', 'S'};
	m['8'] = {'T', 'U', 'V'};
	m['9'] = {'W', 'X', 'Y'};
	b = a;
	backtrack(0, "");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	if (ans.size() == 0)
		cout << "NONE" << endl;

	return 0;
	
	
}
