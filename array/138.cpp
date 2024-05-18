#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height)
{
    int n = static_cast<int>(height.size());
    int area = 0;
    int i = 0, j = n - 1;
    while (1)
    {
        if (i == j)
            break;

        area = max(area, (j - i) * min(height[i], height[j]));
        if(height[i] <= height[j])
            ++i;
        else
            --j;
    }

    return area;
}

int main()
{
    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", maxArea(h));
    return 0;
}