/*
ID: anirudh74
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//needed a lot of handholding
//FUCK THIS PROBLEM
//I knew the approach but implementation ASS

int countBeads(const string& necklace) {
    int N = necklace.length();
    // Double the necklace to handle the circular nature
    string doubleNecklace = necklace + necklace;
    int maxBeads = 0;
    
    for (int b = 0; b < N; b++) {
        char leftB = 'w';
        int l = 0; //number of left characters
        int i = b; //counter for our position
        while (l < N) {
            char currentBed = doubleNecklace[i]; //take most recent
            if (leftB == 'w' && currentBed != 'w')
                leftB = currentBed; //store it if its a color and start
            if (leftB != 'w' && currentBed != 'w' && leftB != currentBed)
                break; //otherwise a difference has been made from the intial color
            l++;
            i--;
            if (i < 0)
                i = doubleNecklace.size()-1;    
        }
        
        int r = 0; //number of right characters
        char rightC = 'w';
        i = b + 1; //counter for position and same logic
        while (r < N-l && i < doubleNecklace.size()) {
            char currentBe = doubleNecklace[i];
            if (rightC== 'w' && currentBe != 'w')
                rightC = currentBe;
            if (rightC != 'w' && currentBe != 'w' && rightC != currentBe)
                break;
            r++;
            i++;
        }
        maxBeads = max(maxBeads, l+r);
    }
    return min(maxBeads, N);
    // Cannot collect more beads than N
}

int main() {
   
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int N;
    string necklace;
    
	cin >> N;
    cin >> necklace;
    
    int result = countBeads(necklace);
    cout << result << endl;
    
    return 0;
}
