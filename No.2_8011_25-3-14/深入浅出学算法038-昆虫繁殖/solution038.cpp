#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    // 存储每个月的成虫数量
    vector<long long> adults(z + 2, 0);
    // 存储每个月新产生的卵的数量
    vector<long long> eggs(z + 2, 0);

    // 第一个月有一对成虫
    adults[1] = 1;
    eggs[1]=0;
    eggs[0]=0;
    for (int i = 1; i <= z; ++i) {
        // 过了i个月，成虫开始产卵
        if (i >= x) {
            eggs[i+1] = adults[i+1-x] * y;
        }
        // 卵过两个月长成成虫
        adults[i + 1] = adults[i] + eggs[i-1];
    }

    // 输出过z个月后的成虫数量
    // for( int i= 1; i<=z; i++){
    //     cout<<eggs[i]<<" "<<adults[i]<<endl;
    // }
    cout << adults[z + 1] << endl;

}