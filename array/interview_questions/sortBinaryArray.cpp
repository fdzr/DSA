#include <iostream>

using namespace std;


void sort(int arr[], int n){
    int j = n - 1, i = 0;

    while(i < j){
        if(arr[i] == 0){
            i++;
            continue;
        }
        if(arr[j] == 1){
            j--;
            continue;
        }

        swap(arr[i++], arr[j--]);
    }
}


int main(void)
{
    int A[] = { 1, 0, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(A)/sizeof(A[0]);

    sort(A, n);

    // print the rearranged array
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
