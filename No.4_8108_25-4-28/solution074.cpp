#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;  // M为总时间，N为题目种类数
    cin >> M >> N;
    
    
    vector<int> points(N);  // 每种题目的分数
    vector<int> minutes(N); // 每种题目的耗时
    vector<long long> dp(M + 1, 0);  // dp[i]表示在i分钟内能获得的最大分数
    
    // 输入每种题目的分数和耗时
    for(int i = 0; i < N; i++) {
        cin >> points[i] >> minutes[i];
        
    
    }
    
    // 完全背包动态规划
    for(int i = 0; i < N; i++) {
        // 正向遍历时间，因为每种题目可以选择多次
        for(int j = minutes[i]; j <= M; j++) {
            dp[j] = max(dp[j], dp[j - minutes[i]] + points[i]);
        }
    }
    
    cout << dp[M] << endl;
    return 0;
}