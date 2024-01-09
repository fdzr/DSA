#include<bits/stdc++.h>

using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for(int i = 1; i <= n ; ++i)
            seats.push(i);
    }
    
    int reserve() {
        int minSeat = seats.top();
        seats.pop();

        return minSeat;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> seats;    
    
};

int main() {
    SeatManager obj(10);
    cout<<obj.reserve();
    

    return 0;
}