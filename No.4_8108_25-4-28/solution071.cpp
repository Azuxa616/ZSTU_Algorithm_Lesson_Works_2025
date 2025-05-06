#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int V, N;
    cin >> V >> N;
    vector<int> w(N);  // 物品体积数组
    vector<bool> dp(V + 1, false);  // dp[i]表示体积i是否可以被选择的物品组合填满
    
    // 输入每个物品的体积
    for(int i = 0; i < N; i++) {
        cin >> w[i];
    }
    
    dp[0] = true;  // 初始状态：空箱子是可达的
    
    // 对每个物品
    for(int i = 0; i < N; i++) {
        // 从大到小考虑所有可能的体积
        for(int j = V; j >= w[i]; j--) {
            // 如果当前体积j减去物品体积后的状态是可达的，那么当前体积也是可达的
            if(dp[j - w[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // 从大到小找第一个可达的体积
    for(int j = V; j >= 0; j--) {
        if(dp[j]) {
            cout << V - j << endl;  // 输出剩余空间
            break;
        }
    }
    
    return 0;
}