#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;


void kSmallestPair(vector<int> A, vector<int> B, int K){
        
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    priority_queue<pii, vector<pii >, greater<pii > > pq;

    set<pi> my_set; 

    pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));

    my_set.insert(make_pair(0, 0));

    for(int c=0; c < K; ++c){
        auto temp = pq.top();       
        pq.pop();
        
        int i = temp.second.first;
        int j = temp.second.second;

        cout<<"("<<A[i]<<","<<B[j]<<")"<<endl;

        if(i + 1 < A.size()){
            int sum = A[i+1] + B[j];
            auto temp1 = make_pair(i + 1, j);
            if(my_set.find(temp1) == my_set.end()){
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
        if(j + 1 < B.size()){
            int sum = A[i] + B[j + 1];
            auto temp1 = make_pair(i, j + 1);
            if(my_set.find(temp1) == my_set.end()){
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
    }
}


int main(){
    vector<int> A = {1, 7, 11};
    vector<int> B = {2, 4, 6};

    kSmallestPair(A, B, 3);

    return 0;
}
