#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        vector<int> tmp(1001, 0);
        iota(tmp.begin(), tmp.end(), 1);
        us = new unordered_set<int>(tmp.begin(), tmp.end());
    }
    
    int popSmallest() {
        auto minElement = min_element(us->begin(), us->end());
        int minValue = *minElement;
        us->erase(minElement);

        return minValue;
    }
    
    void addBack(int num) {
        if(us->find(num) == us->end())
            us->insert(num);
    }

private:
    unordered_set<int> *us;
};

int main() {
    SmallestInfiniteSet obj;
    cout<<obj.popSmallest()<<endl;
    cout<<obj.popSmallest();

    return 0;
}