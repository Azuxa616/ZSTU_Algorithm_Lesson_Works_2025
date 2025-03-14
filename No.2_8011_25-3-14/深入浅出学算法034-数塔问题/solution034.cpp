#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int list[10][10];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> list[i][j];
        }
    }
    int dp[10][10];
    dp[0][0]=list[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]+list[i][j];
            }else if(j==i){
                dp[i][j]=dp[i-1][j-1]+list[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+list[i][j];
            }
        }
    }
    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(dp[n-1][i],mx);
    }
    cout << mx << endl;
    return 0;
}