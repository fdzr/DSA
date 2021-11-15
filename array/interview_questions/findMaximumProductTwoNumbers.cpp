#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {-10, -3, 5, 6, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int first_min = INT_MAX, second_min = INT_MAX;
    int first_max = INT_MIN, second_max = INT_MIN;

    for(int i=0; i<n ; ++i){
        if (arr[i] > first_max) {second_max = first_max; first_max = arr[i];}
        if (arr[i] > second_max && arr[i] < first_max) second_max = arr[i];
        if (arr[i] < first_min) {second_min = first_min; first_min = arr[i];}
        if (arr[i] < second_min && arr[i] > first_min) second_min = arr[i];
    }
    
    if(first_max * second_max < first_min * second_min)
        cout<<first_max * second_max;
    else
        cout<<first_min * second_min;

    return 0;
}