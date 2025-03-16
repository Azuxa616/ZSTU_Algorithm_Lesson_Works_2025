#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int mod = 12345;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(2));
    dp[1][0] = 8; // 一位数中没有3的情况（1-9排除3）
    dp[1][1] = 1;  // 一位数中有1个3
    
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i-1][0] * 9 + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][1] * 9 + dp[i-1][0]) % mod;
    }
    
    cout << dp[n][0] % mod;
    return 0;
}