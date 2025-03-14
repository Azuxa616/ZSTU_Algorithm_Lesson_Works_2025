#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n,p;
    cin>>n>>p;
    cout<<(n*n+n-p*p+3*p)/2;    
}