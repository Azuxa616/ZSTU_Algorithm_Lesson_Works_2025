#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    // 计算以每个位置为结尾的最长上升子序列长度
    vector<int> dp_left(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (height[j] < height[i])
            {
                dp_left[i] = max(dp_left[i], dp_left[j] + 1);
            }
        }
    }

    // 计算以每个位置为开头的最长下降子序列长度
    vector<int> dp_right(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (height[j] < height[i])
            {
                dp_right[i] = max(dp_right[i], dp_right[j] + 1);
            }
        }
    }

    // 计算最长的合唱队形长度
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        // 注意这里要减1，因为当前位置被计算了两次
        max_length = max(max_length, dp_left[i] + dp_right[i] - 1);
    }

    // 需要出列的人数 = 总人数 - 最长合唱队形长度
    cout << n - max_length << endl;

    return 0;
}