#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int graph[12][12];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    // 初始化dp数组为无穷大
    int dp[12];
    for (int i = 0; i < n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0; // 起点为1号城市(索引0)
    
    // 记录前驱节点，用于回溯路径
    int prev[12];
    for (int i = 0; i < n; i++) {
        prev[i] = -1;
    }
    
    // 动态规划求最短路径
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (graph[j][i] != 0 && dp[j] != INT_MAX) {
                if (dp[j] + graph[j][i] < dp[i]) {
                    dp[i] = dp[j] + graph[j][i];
                    prev[i] = j;
                }
            }
        }
    }
    
    // 输出最短路径值
    cout << "minlong=" << dp[n-1] << endl;
    
    // 回溯并输出路径
    vector<int> path;
    int curr = n - 1;
    while (curr != -1) {
        path.push_back(curr + 1); // 转换为1-based索引
        curr = prev[curr];
    }
    
    // 反转路径（从起点到终点）
    reverse(path.begin(), path.end());
    
    // 输出路径
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}