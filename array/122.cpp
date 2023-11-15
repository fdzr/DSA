#include <bits/stdc++.h>

using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    vector<string> ans;
    int indexTarget = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i == target[indexTarget])
        {
            ans.push_back("Push");
            ++indexTarget;
            if (indexTarget == target.size())
                break;
        }
        else
        {
            ans.push_back("Push");
            ans.push_back("Pop");
        }
    }

    return ans;

}

int main()
{
    vector<int> target = {1, 3};
    int n = 4;

    for(auto str: buildArray(target, n))
        cout<<str<<" ";

    return 0;
}