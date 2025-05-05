#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    // 奖品总数和拨款金额
    cin >> n >> m;
    vector<int> v(n); // 价格
    vector<int> w(n); // 价值
    vector<int> s(n); // 数量
    // 创建dp数组，dp[j]表示拨款为j时能获得的最大价值
    vector<int> dp(m + 1, 0);

    // 输入每种奖品的价格、价值和数量
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    // 多重背包问题
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            // 对于每种物品，尝试不同的购买数量
            for (int k = 1; k <= s[i] && k * v[i] <= j; k++)
            {
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }

    // 输出最大价值
    cout << dp[m] << endl;
    return 0;
}