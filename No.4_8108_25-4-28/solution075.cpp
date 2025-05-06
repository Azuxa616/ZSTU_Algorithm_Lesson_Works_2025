
/*
答案错误 AC:50%
*/




#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 方向数组：上、下、左、右
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// 计算从起点(0,0)到指定位置(x,y)的最短距离
int getMinDistance(int x, int y) {
    return x + y;  // 因为只能上下左右移动，所以最短距离就是横纵坐标之和
}

int main() {
    int N, M, TI, A;
    cin >> N >> M >> TI >> A;
    
    // 读取桃子数量矩阵
    vector<vector<int>> peach(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> peach[i][j];
        }
    }
    
    // 读取每棵树可以摘的次数
    vector<vector<int>> K(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> K[i][j];
        }
    }
    
    long long maxPeaches = 0;
    
    // 对每个位置进行尝试
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(peach[i][j] == 0 || K[i][j] == 0) continue;
            
            // 计算到这个位置的往返距离
            int distance = 2 * getMinDistance(i + 1, j + 1);  // +1因为坐标从(1,1)开始
            
            // 如果单次往返超过时间或体力限制，跳过
            if(distance > TI || distance > A) continue;
            
            // 计算在时间和体力限制下最多能往返多少次
            int maxTrips = min(K[i][j], min(TI / distance, A / distance));
            
            // 更新最大桃子数量
            maxPeaches = max(maxPeaches, (long long)maxTrips * peach[i][j]);
        }
    }
    
    cout << maxPeaches << endl;
    return 0;
}