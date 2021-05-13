#include<iostream>
#include<queue>

using namespace std;

int kMinimumProduct(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > qp;

    for(int i=0; i < n; ++i)
        qp.push(arr[i]);

    int count = 0, ans = 1;

    while(qp.empty() == false && count < k){
        count++;
        ans *= qp.top();
        qp.pop();
    }

    return ans;
}

int main(){
    int arr[] = {198, 76, 544, 123, 154, 675};
    int k = 2;
    int n = sizeof(arr)/ sizeof(arr[0]);
    long long int res = kMinimumProduct(arr, n, k);
    cout<<"Minimun produc is "<< res;


    return 0;
}
