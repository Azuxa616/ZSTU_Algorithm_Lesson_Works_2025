#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int func(int n){
    if(n==1||n==2){
        return n;
    }
    return func(n-1)+func(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}