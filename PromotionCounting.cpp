// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
	unsigned long long a, b, c, d, e, f, g, h;
	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	cin >> g >> h;

	cout << (h-g) << endl;
	cout << (h-g) + (f-e) << endl;
	cout << (h-g) + (f-e) + (d-c) << endl;

}
