#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int func(int n,int* dp){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    int i=3;
    while(i<=n){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        i++;
    }
    return dp[n];
    
}

int main() {
    int n;
    int dp [1000]={1,1,2};
    cin >> n;
    cout << func(n,dp) << endl;
    return 0;
}