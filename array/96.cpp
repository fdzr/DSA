#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vi leftPivot, rightPivot;
    int cont = 0;

    for(auto elem: nums) {
        if(elem < pivot)
            leftPivot.push_back(elem);
        else if(elem > pivot)
            rightPivot.push_back(elem);
        else
            cont++;
    }

    while(cont--)
        leftPivot.push_back(pivot);

    leftPivot.insert(leftPivot.end(), rightPivot.begin(), rightPivot.end());
    return leftPivot;
}

int main() {
    vi nums = {4,3,2};
    int pivot = 4;

    for(auto elem: pivotArray(nums, pivot))
        cout<<elem<<" ";


    return 0;
}