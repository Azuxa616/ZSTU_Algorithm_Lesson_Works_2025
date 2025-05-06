#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int V, m;
    cin >> V >> m;  // V为背包容量，m为物品种类数
    
    vector<int> dp(V + 1, 0);  // dp[i]表示容量为i时能获得的最大价值
    
    // 对每种物品进行处理
    for(int i = 0; i < m; i++) {
        int num, vol, val;
        cin >> num >> vol >> val;
        
        // 二进制优化：将num个物品拆分成1,2,4,...,2^k,rest个物品
        for(int k = 1; k <= num; k <<= 1) {
            num -= k;
            // 01背包逻辑
            for(int j = V; j >= k * vol; j--) {
                dp[j] = max(dp[j], dp[j - k * vol] + k * val);
            }
        }
        // 处理剩余的物品
        if(num > 0) {
            for(int j = V; j >= num * vol; j--) {
                dp[j] = max(dp[j], dp[j - num * vol] + num * val);
            }
        }
    }
    
    cout << dp[V] << endl;
    return 0;
}