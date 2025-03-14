#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int dp[50];
    cin >> n;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=3 ;i<=n;i++){
        dp[i] =dp[i-1]+dp[i-2];
    }
    cout << dp[n-1] << endl;
    return 0;
}