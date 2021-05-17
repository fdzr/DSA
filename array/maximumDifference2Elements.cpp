/*Program to find the maximum difference between two elements
 * such as, the larger element appears after the smaller number.
 *
 * reference: https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
 *
 * */


#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;


void findMaximumDifferenceBetween2Elements(int arr[], int n){
    int index_max = distance(arr, max_element(arr, arr + n));
    int min = *min_element(arr, arr + index_max + 1);

    cout<<abs(min - arr[index_max]);
}


int main(){
    //int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int arr[] = {7, 9, 5, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    //cout<<distance(arr, max_element(arr, arr + n));
    findMaximumDifferenceBetween2Elements(arr, n);

    return 0;
}
