#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    map<int,int> mp;
    vector<pair<int,int>> vec;
    int n,mx=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(map<int,int >::iterator it = mp.begin();it!=mp.end();it++){
        mx=max(mx,it->second);
        vec.push_back(make_pair(it->first,it->second));
    }
    for(pair<int,int> it:vec){
        if(it.second==mx){
            cout << it.first << "  " << it.second << endl;
        }
    }
}