#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        historial.push_back(homepage);
        index = 0;
        in = false;
    }
    
    void visit(string url) {
        if (in) {
            historial.erase(historial.begin() + index + 1);
        }
            
        historial.push_back(url);
        index = (in)? index: index + 1;
        
    }
    
    string back(int steps) {
        in = true;
        index = (steps > index)? 0: index - steps;

        return historial[index];
    }
    
    string forward(int steps) {
        in = true;
        int n = historial.size();
        index = (steps + index > n - 1)? n - 1: index + steps;

        return historial[index];
    }

private:
    vector<string> historial;
    int index;
    bool in;
};

int main() {
    BrowserHistory *obj = new BrowserHistory("esgriv.com");
    obj->visit("cgrt.com");
    cout<<obj->back(9)<<endl;
    obj->visit("kttzxgh.com");
    cout<<obj->forward(7)<<endl;
    obj->visit("crqje.com");
    obj->visit("iybch.com");
    cout<<obj->forward(5)<<endl;
    obj->visit("uun.com");
    cout<<obj->back(10)<<endl;
    obj->visit("hci.com");
    obj->visit("whula.com");
    cout<<obj->forward(10)<<endl;

    return 0;
}