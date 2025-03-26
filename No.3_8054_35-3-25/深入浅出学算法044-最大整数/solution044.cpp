#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <iomanip>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}
int main() {
    int n;
    cin >> n;
    string res;
    vector<string> nums;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(to_string(x));
    }
    sort(nums.begin(),nums.end(),cmp);
    for(int i = 0; i < n; i++) {
        res+=nums[i];
    }
    cout << res << endl;
}