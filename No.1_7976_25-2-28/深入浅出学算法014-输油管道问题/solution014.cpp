#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    vector<int> nums;
    int n,sum=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x>>y;
        nums.push_back(y);
    }
    sort(nums.begin(), nums.end());
    int m;
    if (n % 2 == 1) {
        m = nums[n / 2];
    } else {
        m = nums[n / 2 - 1];
    }
    for(int i=0;i<nums.size();i++){
        sum+=abs(nums[i]-m);
    }
    cout<<sum<<endl;
    return 0;
}