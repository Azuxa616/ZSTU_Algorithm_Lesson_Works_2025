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
    vector<int> rates(n);
    for (int i = 0; i < n; i++) {
        cin >> rates[i];
    }
    
    double money = 100.0f;  // 初始资金
    bool holdMark = false; // 是否持有马克
    
    for (int i = 0; i < n - 1; i++) {
        if (!holdMark && rates[i] > rates[i+1]) {
            // 汇率将上升，买入马克
            money = money * rates[i] / 100.0f;
            holdMark = true;
        }
        else if (holdMark && rates[i] < rates[i+1]) {
            // 汇率将下降，卖出马克
            money = money * 100.0f / rates[i];
            holdMark = false;
        }
        cout<<"day"<<i+1<<":"<<money<<endl;
    }
    
    // 最后一天必须换成美元
    if (holdMark) {
        money = money * 100.0f / rates[n-1];
    }
    
    cout << fixed << setprecision(2) << money;
    return 0;
}