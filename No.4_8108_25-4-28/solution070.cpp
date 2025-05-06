#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //设有1g、2g、3g、5g、10g、20g的砝码各若干枚
    vector<int> w = {1, 2, 3, 5, 10, 20}; //砝码的重量
    vector<int> v(6);//砝码的个数
    cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>v[5];
    
    int mx = 0;  // 初始化最大重量为0
    for(int i=0; i<6; i++){
        mx += w[i]*v[i]; //计算砝码的最大重量
    }
    
    vector<int> dp(mx + 1, 0); // dp[i]表示能否称出i克的重量
    dp[0] = 1;  // 0克是默认可以的（不使用砝码）
    
    // 对每种砝码
    for(int i=0; i<6; i++){
        // 对于当前重量的砝码，尝试使用0到v[i]个
        for(int k=1; k<=v[i]; k++){
            // 从大到小更新可能的重量，避免重复计算
            for(int j=mx; j>=w[i]; j--){
                if(dp[j-w[i]*k]){
                    dp[j] = 1;
                }
            }
        }
    }
    
    // 统计能称出的不同重量数（不包括0克）
    int total = 0;
    for(int i=1; i<=mx; i++){
        if(dp[i]) total++;
    }
    
    cout<<"Total="<<total<<endl;
    return 0;
}