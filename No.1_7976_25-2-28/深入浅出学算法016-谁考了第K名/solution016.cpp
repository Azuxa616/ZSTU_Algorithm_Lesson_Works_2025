#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    map<float,int>mp;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int num;
        float sco;
        cin >> num>>sco;
        mp[sco]=num;
    }
    map<float,int>::iterator it=mp.end();
    for(int i=0;i<k;i++){
        it--;
    }
    cout<<it->second<<" "<<it->first<<endl;
}