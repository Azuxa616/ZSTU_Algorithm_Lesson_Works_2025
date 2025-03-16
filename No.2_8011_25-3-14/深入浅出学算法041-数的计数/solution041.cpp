#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    // 修改 dp 数组大小为 1001，因为 n 最大为 1000
    int dp[1001] = {0};
    // 初始化 dp[0] 和 dp[1] 为 1
    dp[0] = dp[1] = 1;

    // 动态规划计算 dp 数组
    for (int i = 2; i <= n; i++) {
        dp[i] = 1; // 不添加任何数的情况
        for (int j = 1; j <= i / 2; j++) {
            dp[i] += dp[j];
        }
    }
    cout<<dp[n]<<endl;
}