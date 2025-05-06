#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, V; // N为面值数，V为目标面值
    cin >> N >> V;
    vector<int> w(N);     // 面值数组
    vector<long long> dp(V + 1, 0); // 使用long long防止溢出，注意大小为V+1

    // 输入面值
    for(int i = 0; i < N; i++){
        cin >> w[i];
    }

    dp[0] = 1; // 初始化，表示组成面值0有1种方案
    
    // 对每种面值
    for(int i = 0; i < N; i++){
        // 从小到大枚举金额
        for(int j = w[i]; j <= V; j++){
            dp[j] += dp[j - w[i]];
        }
    }

    cout << dp[V] << endl;
    return 0;
}