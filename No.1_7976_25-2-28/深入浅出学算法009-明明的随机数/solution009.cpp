#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for (int s: vec) {
        if(ans.empty() || s != ans.back()) {
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    for(int a: ans){
        cout<<a<<" ";
    }
    return 0;
}