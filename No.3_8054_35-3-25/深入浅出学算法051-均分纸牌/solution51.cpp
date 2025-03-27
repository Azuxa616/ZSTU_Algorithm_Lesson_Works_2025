#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cards(n);
    int sum = 0;

    // 读入每堆纸牌的数量并计算总和
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
        sum += cards[i];
    }

    // 计算平均值
    int avg = sum / n;
    int moves = 0;

    // 从左到右遍历，将多余的牌移动到右边
    for (int i = 0; i < n - 1; i++)
    {
        if (cards[i] != avg)
        {
            // 计算需要移动的牌数
            int diff = cards[i] - avg;
            //例如diff=-3，就将-3张牌移动到下一堆
            // 将多余的牌移动到下一堆
            cards[i + 1] += diff;
            cards[i] = avg;
            moves++;
        }
    }

    cout << moves << endl;
    return 0;
}