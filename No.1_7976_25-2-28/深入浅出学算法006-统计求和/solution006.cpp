#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isInclude(int n,int huge){
    string str=to_string(huge);
    for(int i=0;i<str.size();i++){
        if(str[i]==to_string(n)[0]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int n,sum=0,count=0;
        cin >> n;
        for(int i=1000;i<=9999;i++){
            if(isInclude(n,i)&&i%n!=0){
                count++;
                sum+=i;
            }
        }
        cout<<count<<" "<<sum<<endl;
    }
    return 0;
}