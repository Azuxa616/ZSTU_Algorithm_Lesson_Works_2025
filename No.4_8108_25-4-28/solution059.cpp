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
    int graph[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; 
        }
    }
    int weightList[200];
    for (int i = 0; i < n; i++) {
        cin >> weightList[i];
    }
    while(true){
        int s,d;
        cin >> s >> d;
        if(s==0 && d==0) break;
        graph[s-1][d-1] = 1; // 只记录有无路径，权重由地窖本身决定
    }
    
    // 初始化dp数组
    int dp[200]; 
    for (int i = 0; i < n; i++) {
        dp[i] = weightList[i]; // 初始值为地窖自身的地雷数
    }
    
    // 记录前驱节点，用于回溯路径
    int prev[200]; 
    for (int i = 0; i < n; i++) {
        prev[i] = -1;
    }
    
    // 记录最大值及其位置
    int maxMines = 0;
    int maxPos = 0;
    
    // 动态规划求最长路径
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[j][i] != 0) {
                if (dp[j] + weightList[i] > dp[i]) {
                    dp[i] = dp[j] + weightList[i];
                    prev[i] = j;
                }
            }
        }
        // 更新最大值
        if (dp[i] > maxMines) {
            maxMines = dp[i];
            maxPos = i;
        }
    }
    
    // 回溯并输出路径
    vector<int> path;
    int curr = maxPos;
    while (curr != -1) {
        path.push_back(curr + 1); // 转换为1-based索引
        curr = prev[curr];
    }
    
    // 反转路径（从起点到终点）
    reverse(path.begin(), path.end());
    
    // 输出路径，用-连接
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << "-";
        }
    }
    cout << endl;
    
    // 输出最大地雷数
    cout << maxMines << endl;
    
    return 0;
}