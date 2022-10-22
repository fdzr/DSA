#include <iostream>
#include <unordered_set>

using namespace std;


void checkArray(int arr[], int n){
    int sum = 0;
    unordered_set<int> us;
    us.insert(0);
    int cont = 1;

    for(int i = 0; i < n; ++i){
        sum += arr[i];
        
        if(us.find(sum) != us.end())
            cout<<(cont++)<<"founded"<<endl;

        else
            us.insert(sum);
    }
}


int main(){
    int arr[] = { 4, 2, -3, -1, 0, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);

    checkArray(arr, n);

    return 0;
}
