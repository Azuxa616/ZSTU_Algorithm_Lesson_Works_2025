#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int V, N, T;
    cin >> V >> N >> T;

    vector<int> w(N);
    vector<int> c(N);
    vector<int> p(N);
    vector<int> dp(V + 1, 0);
    vector<vector<int>> groups(T + 1); // 存储每个组的物品索引

    // 输入数据
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> c[i] >> p[i];
        groups[p[i]].push_back(i); // 将物品添加到对应的组
    }

    // 对每个组进行处理
    for (int g = 1; g <= T; g++)
    {
        // 需要从后向前遍历背包容量，避免重复选择
        for (int j = V; j >= 0; j--)
        {
            // 尝试当前组的每个物品
            for (int idx : groups[g])
            {
                if (j >= w[idx])
                {
                    dp[j] = max(dp[j], dp[j - w[idx]] + c[idx]);
                }
            }
        }
    }

    cout << dp[V] << endl;
    return 0;
}