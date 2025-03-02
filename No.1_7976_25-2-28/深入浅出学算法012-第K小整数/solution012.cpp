#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        cout << nums[x-1] << endl;
    }
    return 0;
}