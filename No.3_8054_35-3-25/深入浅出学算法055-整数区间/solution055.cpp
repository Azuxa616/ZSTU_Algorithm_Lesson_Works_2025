#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct container{
    int start;
    int end;
    bool isVisited;
};

bool cmp(container a,container b){
    return a.end-a.start>b.end-b.start;
}

int main()
{
    int n;
    cin>>n;
    int res=0;
    vector<container> containers(n);
    for(int i=0;i<n;i++){
        cin>>containers[i].start>>containers[i].end;
        containers[i].isVisited=false;
    }
    sort(containers.begin(),containers.end(),cmp);
    int N=0;
    // for(int i=0;i<containers.size();i++){
    //     cout<<containers[i].start<<" "<<containers[i].end<<endl;
    // }
    while (N<containers.size())
    {
        int left=-1,right=10000;
        for(int i=0;i<containers.size();i++){
            if(!containers[i].isVisited){
                if(containers[i].start>right||containers[i].end<left){
                    continue;
                }else{
                
                    if(containers[i].start>left){
                        left=containers[i].start;
                        containers[i].isVisited=true;
                    }
                    if(containers[i].end<right){
                        right=containers[i].end;
                        containers[i].isVisited=true;
                    }
                    // cout<<"NOW:"<<left<<" "<<right<<endl;
                    N++;
                }
            }
        }
        res++;
    }
    cout<<res<<endl;
}