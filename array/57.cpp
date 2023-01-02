#include <bits/stdc++.h>

using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int cont = 0;
    for(int i = 0; i < startTime.size(); ++i)
        if(queryTime >= startTime[i] && queryTime <= endTime[i])
            cont++;
    
    return cont;
}

using vi = vector<int>;
int main() {
    vi startTime = {5};
    vi endTime = {5};
    int queryTime = 4;
    cout<<busyStudent(startTime, endTime, queryTime);


    return 0;
}