// Source: https://usaco.guide/general/io
/*
ID: anirudh74
TASK: friday
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
	int n;
	cin >> n;
	// jan 1 1900 is monday
	int day_counter = 1;
	int startday = 0;
	vector<int> days(7, 0);
	vector<int> month{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1900; i <= 1900+n-1; i++) { //year simulation
		for (int j = 0; j < 12; j++) {
			days[(startday+6)%7]++;
			if (j == 1 && ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)))
				startday = (startday+29) %7;
			else if (j == 1)
				startday = (startday+28)%7;
			else
				startday = (startday+month[j])%7;
		}
	}
	cout << days[days.size()-1] << " ";
	for (int i = 0; i < days.size()-2; i++) {
		cout << days[i] << " ";
	}
	cout << days[days.size()-2];
	cout << endl;
}
