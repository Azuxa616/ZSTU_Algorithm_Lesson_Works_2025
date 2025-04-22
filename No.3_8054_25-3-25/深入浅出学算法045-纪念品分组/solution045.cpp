#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x); 
    }
    sort(nums.begin(), nums.end());
    
    int left = 0, right = nums.size() - 1;
    int count = 0;
    
    while(left <= right) {
        if(nums[left] + nums[right] <= w) {
            left++;
            right--;
        } else {
            right--;
        }
        count++;
    }
    
    cout << count << endl;
    return 0;
}