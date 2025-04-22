#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;
int main() {
    map<int,int> mp;
    vector<int> nums,res,wt;
    float aveTime = 0;
    int sumTime = 0,waitTime=0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
        mp[i+1]=x;
    }
    sort(nums.begin(),nums.end());
    map<int,int>::iterator it;
    for(int i : nums) {
        for(it = mp.begin(); it != mp.end(); ++it) {
            if(it->second == i) {
                res.push_back(it->first);
                waitTime += it->second;
                wt.push_back(waitTime);
                mp.erase(it);
                break;
            }
        }
        
    }
    for (int i:wt) {
        sumTime += i;
    }
    for(int i:res) {
        cout << i << " ";
    }
    cout << endl;
    aveTime = sumTime / (float)n;
    cout << fixed << setprecision(2) << aveTime << endl;
    return 0;
}