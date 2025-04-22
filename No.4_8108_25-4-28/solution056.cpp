#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;


int main() {
    int n;
    cin >> n;
    int tower[40][40];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <=i; j++) {
            cin >> tower[i][j];
        }
    }
    int dp[40][40];
    dp[0][0] = tower[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + tower[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + tower[i][j]; 
            }else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tower[i][j];
            }
        } 
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout <<"max="<< ans << endl;
    return 0;
}