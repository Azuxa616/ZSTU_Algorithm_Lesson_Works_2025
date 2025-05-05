#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int V, N; // V为背包容量，N为物品数量
    cin >> V >> N;

    vector<int> w(N); // 重量
    vector<int> c(N); // 价值
    vector<int> p(N); // 可购买的数量上限，0表示无限
    vector<int> dp(V + 1, 0);

    // 输入数据
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> c[i] >> p[i];
    }

    // 对每个物品处理
    for (int i = 0; i < N; i++)
    {
        if (p[i] == 0)
        { // 完全背包
            for (int j = w[i]; j <= V; j++)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
        else if (p[i] == 1)
        { // 01背包
            for (int j = V; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
        else
        { // 多重背包
            for (int j = V; j >= w[i]; j--)
            {
                for (int k = 1; k <= p[i] && k * w[i] <= j; k++)
                {
                    dp[j] = max(dp[j], dp[j - k * w[i]] + k * c[i]);
                }
            }
        }
    }

    cout << dp[V] << endl;
    return 0;
}