#include <iostream>
using namespace std;

int main() {
    int n,a,b,c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        c=a%b;
        while(c!=0){
            a=b;
            b=c;
            c=a%b;
        }
        cout << b << endl;
    }
}