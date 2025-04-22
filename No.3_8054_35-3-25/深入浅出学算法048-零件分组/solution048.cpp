#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// 定义零件结构体
struct Part
{
    int length;
    int weight;
    bool used; // 标记是否已被分组
};

// 按照长度排序的比较函数
bool compareLength(const Part &a, const Part &b)
{
    return a.length < b.length;
}
// 按照重量排序的比较函数
bool compareWeight(const Part &a, const Part &b)
{
    return a.weight < b.weight;
}
// 算法主体
int cl(vector<Part> parts, int N)
{
    int groups = 0;
    int count = 0;
    
    // 贪心算法：每次选择未使用的零件，尽可能多地组成一组
    while (count < N)
    {
        groups++;
        int lastLength = -1, lastWeight = -1;

        // 尝试将未使用的零件加入当前组
        for (int i = 0; i < N; i++)
        {
            if (!parts[i].used)
            {
                if (lastLength == -1 ||
                    (parts[i].length >= lastLength && parts[i].weight >= lastWeight))
                {
                    parts[i].used = true;
                    lastLength = parts[i].length;
                    lastWeight = parts[i].weight;
                    count++;
                }
            }
        }
    }
    return groups;
}

int main()
{
    int N, res1, res2;
    cin >> N;

    vector<Part> parts(N);
    // 读入数据
    for (int i = 0; i < N; i++)
    {
        cin >> parts[i].length >> parts[i].weight;
        parts[i].used = false;
    }

    // 按长度排序
    sort(parts.begin(), parts.end(), compareLength);
    res1 = cl(parts, N);
    // 按重量排序
    sort(parts.begin(), parts.end(), compareWeight);
    res2 = cl(parts, N);
    // 取最小值输出
    cout << min(res1, res2) << endl;
    return 0;
}