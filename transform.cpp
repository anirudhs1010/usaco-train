/*
ID: anirudh74
LANG: C++
TASK: transform
*/

#include <bits/stdc++.h>
using namespace std;
long unsigned int N;
void rotate(vector<vector<char>>& matrix) {
        for (long unsigned int i = 0; i < N; i++) {
            for (long unsigned int j = 0; j < N; j++) {
                if (j < i) {
                    char temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
                
            }
        }

        for (long unsigned int i = 0; i < N; i++) {
            for (long unsigned int j = 0; j < N/2; j++) {
                char temp = matrix[i][N-j-1];
                matrix[i][N-j-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
}

void horiz(vector<vector<char>>& matrix) {
	for (long unsigned int i = 0; i < N; i++) {
            for (long unsigned int j = 0; j < N/2; j++) {
                char temp = matrix[i][N-j-1];
                matrix[i][N-j-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }

}

int main() {
	freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
	cin >> N;
	char a;
	vector<vector<char>> v;
	vector<char> b;
	for (long unsigned int i = 0; i < N; i++) {
		for (long unsigned int j = 0; j < N; j++) {
			cin >> a;
			b.push_back(a);
		}
		v.push_back(b);
		b.clear();
	}

	vector<vector<char>> res;
	b.clear();
	for (long unsigned int i = 0; i < N; i++) {
		for (long unsigned int j = 0; j < N; j++) {
			cin >> a;
			b.push_back(a);
		}
		res.push_back(b);
		b.clear();
	}
	int ans = INT_MAX;
	if (res == v) { //no change
		ans = min(ans, 6);
	}
	
	vector<vector<char>> f = v;
	rotate(v);
	if (res == v) { //90 deg
		ans = min(ans, 1);
	
	}
	
	horiz(f);
	if (f == res) { //horiz first
		ans = min(ans, 4);

	}
	rotate(f);
	if (res == f) { //combo
		ans = min(ans, 5);

	}
	rotate(v);
	rotate(f);
	if (res == v) { //180 deg
		ans = min(ans, 2);
	}
	else if (res == f) { //combo
		ans = min(ans, 5);
	}

	rotate(v);
	rotate(f);
	if (res == v) { //270 deg
		ans = min(ans, 3);
	}
	else if (res == f) { //combo
		ans = min(ans, 5);
	}

	//none are valid

	ans = min(ans, 7);
	cout << ans << endl;

	return 0;

}
