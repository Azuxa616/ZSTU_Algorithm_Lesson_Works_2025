#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;  // N为总钱数，m为物品个数
    
    vector<int> v(m);  // 物品价格
    vector<int> p(m);  // 物品重要度
    vector<long long> dp(N + 1, 0);  // dp数组，防止溢出使用long long
    
    // 输入每件物品的价格和重要度
    for(int i = 0; i < m; i++) {
        cin >> v[i] >> p[i];
    }
    
    // 0-1背包动态规划
    for(int i = 0; i < m; i++) {
        for(int j = N; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + (long long)v[i] * p[i]);
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}