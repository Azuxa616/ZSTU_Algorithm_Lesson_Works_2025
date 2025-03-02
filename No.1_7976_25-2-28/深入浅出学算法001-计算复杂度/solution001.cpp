#include <iostream>
using namespace std;

int main() {
    int n,T;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>T;
        switch (T)
        {
        case 1:
            cout << "1"<<endl;
            break;
        case 2:
            cout << "n"<<endl;
            break;
        case 3:
            cout << "2^n"<<endl;
            break;
        case 4:
            cout << "n^2"<<endl;
            break;
        case 5:
            cout << "nlogn"<<endl;
            break;
    
        case 6:
            cout << "n^2"<<endl;
            break;    
        case 7:
            cout << "n^3"<<endl;
            break;
        }
    }
}