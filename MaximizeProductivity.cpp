#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    bool isMid = false;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        while (nums[mid] == target) {
            mid--;
            isMid = true;
        } 
        if (isMid)
            return mid+1;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;        
}

int main()
{
    unsigned long long N, Q;
    int v, s, a;
    cin >> N >> Q;
    
    vector<int> c;
    vector<int> t;
    vector<int> diff;
 
    for (unsigned long long i = 0; i < N; i++) {
        cin >> a;
        c.push_back(a);
    }
    for (unsigned long long i = 0; i < N; i++) {
        cin >> a;
        t.push_back(a);
        
        if (c[i] > t[i])
            diff.push_back(c[i]-t[i]);
    }
    sort(diff.begin(), diff.end()); //sort the farms by closing time
    //then binary search for the farm that satifies the limit

    for (unsigned long long i = 0; i < Q; i++) {
        cin >> v >> s;
        int count = 0;
        
        if (diff.size()-(searchInsert(diff, s+1)) >= v)
            cout << "YES" << endl;
        else
            cout <<"NO" << endl;
    }
    

    return 0;
}
