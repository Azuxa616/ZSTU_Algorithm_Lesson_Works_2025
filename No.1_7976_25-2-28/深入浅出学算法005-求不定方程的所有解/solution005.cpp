#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 算法思路
// 1.条件筛选：若c < a + b，则方程无解，直接输出"No"[2][3][4]。
// 2.范围优化：当c ≥ a + b时，x的最大可能值为(c - b)/a（向下取整），从而减少遍历次数[2][3]。
// 3.遍历验证：对每个x的候选值，计算剩余值rem = c - a*x，若rem能被b整除且结果y ≥ 1，则为有效解[2][3][4]。


// 1.多组输入处理：通过外层循环处理T组测试用例。
// 2.解的存在性判断：当c < a + b时，直接排除无解情况。
// 3.高效遍历：通过数学推导缩小x的范围，避免双重循环，时间复杂度优化至O((c - b)/a)。
// 4.解的验证：利用取模运算验证y是否为整数，并保证y的正整数性质。
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int a,b,c,count=0;
        cin >> a >> b >> c;

        if(c<a+b){
            cout<<"No\n";
            continue;
        }
        int max_x =(c-b)/a;
        for(int x=1;x<=max_x;x++){
            int rem=c-a*x;
            if(rem%b==0){
                int y=rem/b;
                cout<<x<<" "<<y<<endl;
                count++;
            }
        }
        if(count==0){
            cout<<"No\n";
        }
    }
    return 0;
}