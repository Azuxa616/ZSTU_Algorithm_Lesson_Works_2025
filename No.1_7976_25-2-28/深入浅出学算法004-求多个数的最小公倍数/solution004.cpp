#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1.计算两个数的LCM：
    
// 其中，GCD 用欧几里得算法计算。

// 2.扩展到多个数：
// 逐个用前两个数的 LCM 与下一个数计算新的 LCM，直到处理完所有数


// 计算两个数的最大公约数（GCD）
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// 计算两个数的最小公倍数（LCM）
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  
}

// 计算多个数的LCM
int findLcm(vector<int>& nums) {
    if (nums.empty()) return 0;
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = lcm(result, nums[i]);
    }
    return result;
}


int main() {
    int T,k;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n,input;
        vector<int> vec;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        cout << findLcm(vec) << endl;
    }
    return 0;
}