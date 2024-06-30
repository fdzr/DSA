#include <bits/stdc++.h>

using namespace std;

string removeTrailingZeros(string num)
{
    num.erase(
        find_if(num.rbegin(), num.rend(), [](char ch){
            return ch != '0';
        }).base(),
        num.end());

    return num;
}

int main()
{
    cout<<removeTrailingZeros("51230100");

    return 0;
}