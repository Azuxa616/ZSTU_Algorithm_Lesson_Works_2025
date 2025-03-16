#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 实现高精度加法
 * @param a 第一个加数，以字符串形式表示
 * @param b 第二个加数，以字符串形式表示
 * @return 两个数相加的结果，以字符串形式表示
 */
string gjd(string a,string b){ // 高精加现场
    string ans;
    int la[1000]={0},lb[1000]={0};
    int lena=a.length(),lenb=b.length();
    // 依次将字符串中的字符转换为 int 型，方便后续计算
    for(int i=0;i<lena;i++)la[lena-1-i]=a[i]-'0';
    for(int i=0;i<lenb;i++)lb[lenb-1-i]=b[i]-'0';
    int max1=max(lena,lenb); // 寻找两个字符串长度的最大值
    // 进行加法运算并处理进位
    for(int i=0;i<max1;i++)la[i]+=lb[i],la[i+1]+=la[i]/10,la[i]%=10;
    // 判断最高位是否有进位
    if(la[max1])max1++;
    // 将结果转换为字符串形式
    for(int i=max1-1;i>=0;i--)ans+=la[i]+'0';
    return ans;
}

// 预处理前两位，用于动态规划
string a[1001]={"0","1","1"};
int n,m;

int main(){
    cin>>n>>m;
    int ans=m-n+1;
    // 从第 3 项开始，依次计算每一项的值
    for(int i=3;i<=ans;i++){
        a[i]=gjd(a[i-1],a[i-2]); // 进行高精加
    }
    cout<<a[ans];
    return 0;
}