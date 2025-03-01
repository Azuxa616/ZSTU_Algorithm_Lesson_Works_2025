#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        int n,y;
        bool flag=false;
        double x;
        cin >> n;

        for(int y=1;y<=10000;y++){
            //消除x
            if((int)sqrt(n*y*y+1)*(int)sqrt(n*y*y+1)==n*y*y+1){
                cout<<y<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"No"<<endl;
    }
    return 0;
}