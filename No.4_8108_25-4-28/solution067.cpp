#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int m, n;  // m: 需要的氧气量, n: 需要的氮气量
    cin >> m >> n;
    
    int k;  // 气缸数量
    cin >> k;
    
    vector<int> oxygen(k);    // 每个气缸的氧气量
    vector<int> nitrogen(k);  // 每个气缸的氮气量
    vector<int> weight(k);    // 每个气缸的重量
    
    // 输入每个气缸的数据
    for(int i = 0; i < k; i++) {
        cin >> oxygen[i] >> nitrogen[i] >> weight[i];
    }
    
    // dp[i][j]表示满足i升氧气和j升氮气需求的最小重量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;  // 初始状态
    
    // 对每个气缸
    for(int t = 0; t < k; t++) {
        // 从大到小枚举氧气需求量
        for(int i = m; i >= 0; i--) {
            // 从大到小枚举氮气需求量
            for(int j = n; j >= 0; j--) {
                // 计算选择当前气缸后能满足的需求量
                int newi = min(m, i + oxygen[t]);
                int newj = min(n, j + nitrogen[t]);
                // 更新最小重量
                if(dp[i][j] != INF) {
                    dp[newi][newj] = min(dp[newi][newj], dp[i][j] + weight[t]);
                }
            }
        }
    }
    
    cout << dp[m][n] << endl;
    return 0;
}