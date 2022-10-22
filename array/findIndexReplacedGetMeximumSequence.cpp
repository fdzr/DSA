#include <iostream>

using namespace std;

int getIndex(int arr[], int n){
    int len = -1;
    int last_index_0 = -1;
    int cont_1_current, cont_1_prev = 0;
    for(int i=0;i<n;++i){
        if(arr[i] == 0){
            if((cont_1_prev + cont_1_current + 1) > len){
                len = cont_1_prev + cont_1_current + 1;
                cont_1_prev = cont_1_current;
                cont_1_current = 0;
                last_index_0 = i;
            }
        }
        else{
            cont_1_current++;
        }


    }

    return last_index_0;

}

int main(){
    int arr[] = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<getIndex(arr, n);
    return 0;
}