#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int m, n; // m为背包容量，n为物品数量
    cin >> m >> n;
    
    vector<int> weights(n+1, 0); // 物品重量
    vector<int> values(n+1, 0);  // 物品价值
    
    // 输入每个物品的重量和价值
    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // 创建dp数组，dp[i][j]表示前i个物品放入容量为j的背包的最大价值
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // 动态规划求解
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (weights[i] > j) {
                // 当前物品重量大于背包容量，不能放入
                dp[i][j] = dp[i-1][j];
            } else {
                // 可以选择放入或不放入，取最大值
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
        }
    }
    
    // 输出最大价值
    cout << dp[n][m] << endl;
    
    return 0;
}