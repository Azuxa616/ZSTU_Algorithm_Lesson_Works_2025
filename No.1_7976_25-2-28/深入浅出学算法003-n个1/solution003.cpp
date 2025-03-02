#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n,k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int remainder=1;
        int count =1;
        while(1){
            remainder=(remainder*10)%(9*k);
            if(remainder==1){
                cout<<count<<endl;
                break;
            }
            count++;
            if(count>100000){
                break;
            }
        }
    }
    return 0;
}