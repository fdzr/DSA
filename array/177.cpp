#include <bits/stdc++.h>

using namespace std;

int numberOfChild(int n, int k) {
    int sec = 0;
    int noChild = 0;
    bool forward = true, backward = false;

    while(sec < k) {
        ++sec;

        if(forward) {
            ++noChild;
            if (noChild == n - 1) {
                forward = false;
                backward = true;
            }
        }
        else if(backward){
            --noChild;
            if (noChild == 0) {
                forward = true;
                backward = false;
            }
        }
        
    }

    return noChild;
}


int main() {
    int n = 4, k = 2;
    cout<<numberOfChild(n, k);

    return 0;
}