#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    while(pq.size()!=1){
        int temp=pq.top();
        pq.pop();
        temp+=pq.top();
        pq.pop();
        pq.push(temp/k);
    }
    cout<<pq.top();
}