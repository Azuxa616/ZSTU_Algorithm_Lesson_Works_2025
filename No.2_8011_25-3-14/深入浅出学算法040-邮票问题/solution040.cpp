#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxConsecutiveDenominations(int m, int n, vector<int>& denominations) {
    // 计算最大可能的面额
    int maxDenomination = *max_element(denominations.begin(), denominations.end());
    int maxPossible = n * maxDenomination;

    // 初始化 dp 数组
    vector<int> dp(maxPossible + 1, INT_MAX);
    dp[0] = 0; // 组成面额 0 需要 0 张邮票

    int maxConsecutive = 0;

    // 动态规划填充 dp 数组
    for (int i = 1; i <= maxPossible; ++i) {
        for (int d : denominations) {
            if (i >= d && dp[i - d] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
        // 如果当前面额需要的邮票数超过 n，则停止
        if (dp[i] > n) {
            break;
        }
        maxConsecutive = i;
    }

    return maxConsecutive;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> denominations(m);
    for (int i = 0; i < m; ++i) {
        cin >> denominations[i];
    }

    int result = maxConsecutiveDenominations(m, n, denominations);
    cout << result << endl;

    return 0;
}