#include <bits/stdc++.h>

using namespace std;

bool checkIfExist(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2)
            {
                return true;
            }
        }
    }

    return false;
}

using vi = vector<int>;
int main()
{
    vi arr{3,1,7,11};
    cout<<boolalpha<<checkIfExist(arr);
    

    return 0;
}