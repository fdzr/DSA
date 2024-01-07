#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        vector<int> tmp(1001, 0);
        iota(tmp.begin(), tmp.end(), 1);
        s.insert(tmp.begin(), tmp.end());
    }
    
    int popSmallest() {
        int minValue = *s.begin();
        s.erase(s.begin());
        return minValue;
    }
    
    void addBack(int num) {
        s.insert(num);
    }

private:
    set<int> s;
};

int main() {
    SmallestInfiniteSet obj;
    cout<<obj.popSmallest()<<endl;
    cout<<obj.popSmallest();

    return 0;
}