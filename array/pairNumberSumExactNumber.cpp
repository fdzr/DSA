#include <iostream>

using namespace std;

int pairsSumInRotatedArray(int arr[], int n, int x){
    /*
     *Function to count all pairs of number to sum x
     * n length of the array
     * */

    int i;
    for(i=1; i < n; ++i)
        if(arr[i-1] > arr[i])
            break;

    int h = (i-1) % n;
    int l = i;
    int cont = 0;

    while(l != h){
        cout<<l<<" "<<h<<endl;
        if(arr[h] + arr[l] == x){
            cont++;

            if(l == (h - 1 + n) % n)
                return cont;
            
            l = (l + 1) % n;
            h = (n + h - 1) % n;
        }

        else if (arr[l] + arr[h] < x)
            l = (l + 1) % n;

        else
            h = (n + h - 1) % n;

    }

    return cont;


}


int main(){

    int arr[] = {11,15,6,7,9,10};
    int cont = pairsSumInRotatedArray(arr, 6, 16);
        cout<<cont;

    return 0;
}
