#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int M, N; // M为背包容量，N为物品数量
    cin >> M >> N;
    
    vector<int> weights(N + 1);
    vector<int> values(N + 1);
    
    // 输1入每种物品的重量和价值
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // 创建dp数组，dp[j]表示容量为j的背包能获得的最大价值
    vector<int> dp(M + 1, 0);
    
    // 动态规划求解
    for (int i = 1; i <= N; i++) {
        for (int j = weights[i]; j <= M; j++) {
            // 对于完全背包问题，物品可以重复选择
            // 所以状态转移方程为：dp[j] = max(dp[j], dp[j - weights[i]] + values[i])
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    
    // 输出最大价值
    cout << "max=" << dp[M] << endl;
    
    return 0;
}

