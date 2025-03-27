#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;



struct dish{
    int fat;    
    int kind;
    bool eaten;
};
bool cmp(dish a,dish b){
    return a.fat>b.fat;
}
int main()
{
    int n,m,k;
    map<int,int> kind_count;
    cin>>n>>m>>k;
    vector<dish> dishes(n);
    
    int count=0;
    int sumFat=0;

    for(int i=0;i<k;i++){
        cin>>kind_count[i+1];
    }
    for(int i=0;i<n;i++){
        cin>>dishes[i].fat>>dishes[i].kind;
        dishes[i].eaten=false;
    }
    sort(dishes.begin(),dishes.end(),cmp);
    for(auto &dish:dishes){
            if(dish.eaten==false&&kind_count[dish.kind]>0&&count<m){
                dish.eaten=true;
                kind_count[dish.kind]--;
                count++;
                sumFat+=dish.fat;
                // cout<<"eat"<<dish.fat<<" "<<dish.kind<<"=>"<<sumFat<<endl;
            }
        }
    cout<<sumFat<<endl;
}