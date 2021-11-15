#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;


//assuming that the subarray always exists
void findSubarray(int arr[], int n){
    unordered_map<int, int> um;
    int ending_index = -1;
    int len = INT_MIN;
    int sum = 0;

    for(int i=0; i < n; ++i) {
        sum += arr[i];
        if(um.find(sum) != um.end() && i - um[sum] > len){
            len = i - um[sum];
            ending_index = i;
        }
        else
            um.insert(make_pair(sum, i));
    }

    cout<<"["<<ending_index - len + 1<<", "<<ending_index<<"]";

}

int main(){
    int arr[] = { 0, 0, 1, 0, 1, 0, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    replace_if(arr, arr + n, [](int elem){return elem == 0;}, -1);
    
    findSubarray(arr, n);

    return 0;
}