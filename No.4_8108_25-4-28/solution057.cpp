#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
struct node
{
    int val;
    int pre;
    int dp;
    node(int v, int p, int d = 1) : val(v), pre(p), dp(d) {}
};

int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);

    vector<node> dp_left;
    int val;
    while (iss >> val)
    {
        dp_left.push_back(node(val, -1));
    }

    int k = dp_left.size();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp_left[j].val < dp_left[i].val)
            {
                if (dp_left[j].dp + 1 > dp_left[i].dp)
                {
                    dp_left[i].dp = dp_left[j].dp + 1;
                    dp_left[i].pre = j;
                }
            }
        }
    }

    int mx = 0, mx_idx = 0;
    for (int i = 0; i < k; i++)
    {
        if (dp_left[i].dp > mx)
        {
            mx = dp_left[i].dp;
            mx_idx = i;
        }
    }

    cout << "max=" << mx << endl;
    vector<int> ans;
    int i = mx_idx;
    while (i != -1)
    {
        ans.push_back(dp_left[i].val);
        i = dp_left[i].pre;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}