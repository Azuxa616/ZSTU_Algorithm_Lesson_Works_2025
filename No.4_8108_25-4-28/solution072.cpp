#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T,M;
    cin >> T >> M;
    vector<int> t(M),v(M);
    for (int i = 0; i < M; i++) {
        cin >> t[i] >> v[i];
    }
    vector<int> dp(T + 1, 0);
    for (int i = 0; i < M; i++) {
        for (int j = T; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
    cout << dp[T] << endl;
}