#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cost =0 ;
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
        cost+=temp;
        pq.push(temp);
    }
    cout<<cost;
}