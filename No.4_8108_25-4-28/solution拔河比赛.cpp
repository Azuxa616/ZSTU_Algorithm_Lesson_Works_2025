/*
时间超限 AC:60%
*/

#include <iostream>
#include <vector>
#include <numeric>  // 用于accumulate
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    
    
    vector<int> weights(n);
    // 读取每个人的体重
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    // 计算总重量
    int total = accumulate(weights.begin(), weights.end(), 0);
    int target = total / 2;  // 理想的每组重量
    
    // dp[i]表示是否可以组成重量i
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // 空集的重量为0是可行的
    
    // 记录能达到的最大重量
    int maxWeight = 0;
    
    // 动态规划过程
    for(int weight : weights) {
        for(int j = target; j >= weight; j--) {
            if(dp[j - weight]) {
                dp[j] = true;
                maxWeight = max(maxWeight, j);
            }
        }
    }
    
    // 计算两组的重量
    int group1 = maxWeight;
    int group2 = total - group1;
    
    // 确保较小的数在前面
    if(group1 > group2) {
        swap(group1, group2);
    }
    
    cout << group1 << " " << group2 << endl;
    
    return 0;
}

