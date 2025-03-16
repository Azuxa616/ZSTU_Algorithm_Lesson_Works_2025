#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int partitionNumber(int n, int k) {
    // 初始化 dp 数组
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1; // 初始条件

    // 动态规划填充 dp 数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (1LL * j * dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    int result = partitionNumber(n, k);
    cout << result << endl;

    return 0;
}