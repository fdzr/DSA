#include <bits/stdc++.h>

using namespace std;

void findMissingNumber_naive(int arr[], int n){
    int number = 0;
    bool flag = false;

    for(int i=0; i < n; ++i){
        if(arr[i] != number){
            flag = true;
            cout<<"The smallest missing number is: "<<number<<endl;
            break;
        }
        number++;
    }
}

int findFirstMissing(int array[],
                    int start, int end)
{
    if (start > end)
        return end + 1;
 
    if (start != array[start])
        return start;
 
    int mid = (start + end) / 2;
 
    // Left half has all elements
    // from 0 to mid
    if (array[mid] == mid)
        return findFirstMissing(array,
                            mid+1, end);
 
    return findFirstMissing(array, start, mid);
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    findMissingNumber_naive(arr, n);

    int number = findFirstMissing(arr, 0, n-1);
    cout<<"The missing number is: "<<number;
    return 0;
}

