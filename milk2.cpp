// Source: https://usaco.guide/general/io
/*
ID: anirudh74
TASK: milk2
LANG: C++                 
*/
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];
            if (prev[1] >= curr[0]) {
                int start = min(prev[0], curr[0]);
                int end = max(prev[1], curr[1]);
                prev[0] = start;
                prev[1] = end;
            }
            else {
                ans.push_back(prev);
                prev = curr;
            }
        }
        ans.push_back(prev);
        return ans;
}
	
int main() {
	freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
	vector<vector<int>> inp;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> c;
		cin >> a;
		c.push_back(a);
		cin >> b;
		c.push_back(b);
		inp.push_back(c);
	}
	int mdiff = 0, ms = 0;
	vector<vector<int>> res = merge(inp);
	for (int i = 0; i < res.size(); i++) {
		vector<int> curr = res[i];
		int diff = curr[1] - curr[0];
		mdiff = max(mdiff, diff);
	}

	for (int i = 0; i < res.size()-1; i++) {
		vector<int> curr = res[i];
		vector<int> n = res[i+1];
		int diff = n[0] - curr[1];
		ms = max(ms, diff);
	}
	cout << mdiff << " " << ms << endl;
}
