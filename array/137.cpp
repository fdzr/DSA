#include <bits/stdc++.h>
//https://leetcode.com/problems/boats-to-save-people/description/ [881]
using namespace std;


int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end(), less<int>());
    int left = 0;
    int right = people.size() - 1;
    int sol = 0;

    while(left <= right) {
        int curr = people[right];
        if(curr + people[left] <= limit){
            ++sol;
            ++left;
            --right;
        }
        else {
            ++sol;
            --right;
        }
    }

    return sol;
}

int main() {
    vector<int> people{5, 1, 7, 4 ,2 ,4};
    cout<<numRescueBoats(people, 7);

    return 0;
}