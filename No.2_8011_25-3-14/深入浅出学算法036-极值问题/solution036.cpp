#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
 
int main() {
    long long int k;
    cin >> k;
    long long int a = 1, b = 1;
    
    // 生成斐波那契数列直到超过k
    while (true) {
        int c = a + b;
        if (c > k) break;
        a = b;
        b = c;
    }
    
    cout << "m=" << a << "\n" 
         << "n=" << b << endl;
    return 0;
}