#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int answer = 0;
    bool flag = true;

    for(int i = 0; i < citations.size(); ++i) {
        if(citations[i] > 0) {
            if(citations[i] >= i + 1 && flag)
                answer += 1;
            else
                flag = false;
        }
    }

    return answer;
}

int main() {
    vi citations = {25,8,5,4,4};
    cout<<hIndex(citations);

    return 0;
}