#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Took 5 tries and needed hints and looked at solution
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n, b;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> b;
        v.push_back(b);
    }
    
    sort(v.begin(), v.end());

    vector<int> diff;
    int count = 0, counter = 0;
    vector<bool> cond(n, true);
    cond[0] = true;
    int prev = abs(v[0] - v[1]);
    for (int i = 1; i <= n-1; i++) {
        int curr = abs(v[i] - v[i+1]);
        cond[i] = (prev > curr);
        prev = curr;
    }
    //edge case for what if they are equal
    //the actual values do not matter what we care about instead is **direction**
    
    //for (int i = 0; i < n; i++) cout << cond[i] << ' ';
    
    int i = 0;
    while (i < n) {
        int lcount = 0, rcount = 0;
        while (i < n && cond[i]) {
            i++;
            lcount++;
        }
        while (i < n && !cond[i]) {
            i++;
            rcount++;
        }
        if (lcount > 1 && rcount> 1) //add 2 when we know we have to go all the way left and right (two-way)
            count += 2;
        else //since there's only one exception a neighboring cow will pass to it since we have a change in sequence from F->T so right<-left
            count++;
    }
 
    cout << count << endl;
   
    /*
    if (count == 0 && counter == 0)
        cout << 1 << endl;
    else
        cout << min(count, counter) << endl;
    
    int j = n-2;
    int counter = n-2;
    int count = 1;
    while (j > 0) {
        if (counter+2 <= j) {
            j-=2;
            counter=j;
            count++;
        }
        int diff1 = abs(v[j] - v[j+1]);
        int diff2 = abs(v[j] - v[j-1]);
        //want to iterate to the left
        if (diff2 <= diff1) {
            j--;  
        }
        else {
            j++;
        }
        counter--;
    }
    cout << count << endl;
    */
    //1 7 10 3 11
    //pass ball farthest to the left 
    return 0;
}
