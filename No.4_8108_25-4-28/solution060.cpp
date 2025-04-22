#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

// 判断两条航道是否相交
bool ifCross(int s1, int n1, int s2, int n2) {
    // 如果一条航道的南岸坐标小于另一条的南岸坐标
    // 但北岸坐标大于另一条的北岸坐标，则两条航道相交
    return (s1 < s2 && n1 > n2) || (s1 > s2 && n1 < n2);
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> cities(n);
    
    // 输入南岸和北岸城市的坐标
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    
    // 按照南岸坐标排序
    sort(cities.begin(), cities.end());
    
    // dp[i]表示以第i个城市为结尾的最长不相交航道数
    vector<int> dp(n, 1);
    
    // 动态规划求解
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // 如果航道i和航道j不相交，则可以将航道i加入到以j结尾的序列中
            if (cities[j].second < cities[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // 找出最大值
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
    
    return 0;
}