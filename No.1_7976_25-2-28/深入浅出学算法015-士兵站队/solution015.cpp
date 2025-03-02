#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x_coords(n);
    vector<int> y_coords(n);

    for (int i = 0; i < n; ++i) {
        cin >> x_coords[i] >> y_coords[i];
    }

    // 对y坐标进行排序，找到中位数
    sort(y_coords.begin(), y_coords.end());
    int y_target = y_coords[n / 2];

    // 对x坐标进行排序，确定队列的x坐标
    sort(x_coords.begin(), x_coords.end());
    for (int i = 0; i < n; ++i) {
        x_coords[i] -= i; // 调整x坐标，使其对应队列中的位置
    }
    sort(x_coords.begin(), x_coords.end());
    int x_target = x_coords[n / 2];

    // 计算总移动步数
    int total_steps = 0;
    for (int i = 0; i < n; ++i) {
        total_steps += abs(x_coords[i] - x_target) + abs(y_coords[i] - y_target);
    }

    cout << total_steps << endl;

    return 0;
}