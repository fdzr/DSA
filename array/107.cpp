//
// Created by fzamora on 18-05-23.
//
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vi answer(A.size());
    vi C(A.size());
    int cont = 0;

    for(int i = 0; i < A.size(); ++i) {
        if(C[A[i] - 1] != 0)
            cont++;
        C[A[i] - 1]++;

        if(C[B[i] - 1] != 0)
            cont++;
        C[B[i] - 1]++;
        answer[i] = cont;
    }

    return answer;
}

int main() {
    vi A = {2,3,1};
    vi B = {3,1,2};

    for(auto elem: findThePrefixCommonArray(A, B))
        cout<<elem<<" ";
    return 0;
}