#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct activity
{
    int start;
    int end;
};

int main()
{
    int n;
    cin >> n;
    int timeStack = 0;
    int count = 0;

    // 修改比较函数，按照结束时间排序
    auto cmp = [](activity a, activity b)
    {
        return a.end > b.end; // 按照结束时间升序排序
    };

    priority_queue<activity, vector<activity>, decltype(cmp)> activities(cmp);

    // 读入活动数据
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        activities.push({start, end});
    }

    // cout<<endl;
    // 贪心选择活动
    while (!activities.empty())
    {
        if (activities.top().start >= timeStack)
        {
            timeStack = activities.top().end;
            count++;
        }
    
        // cout<<activities.top().start<<" "<<activities.top().end<<endl;
        activities.pop();

    }

    cout << count;
    return 0;
}