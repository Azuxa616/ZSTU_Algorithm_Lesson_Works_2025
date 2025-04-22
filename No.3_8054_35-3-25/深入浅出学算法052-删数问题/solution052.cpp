#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

string removeKDigits(string num, int k)
{
    if (k >= num.length())
        return "0";

    string result = "";
    for (char c : num)
    {
        while (k > 0 && !result.empty() && result.back() > c)
        {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // 如果还需要删除数字，从末尾删除
    while (k > 0)
    {
        result.pop_back();
        k--;
    }

    // 删除前导零
    while (!result.empty() && result[0] == '0')
    {
        result.erase(0, 1);
    }

    return result.empty() ? "0" : result;
}

int main()
{
    string n;
    int s;
    cin >> n >> s;

    cout << removeKDigits(n, s) << endl;
    return 0;
}