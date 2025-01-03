#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
using ull = unsigned long long;

ull oddSum = 0;
ull evenSum = 0;

void findOddSum(ull start, ull end) {
    for(ull i = start; i <= end; ++i)
        if((i & 1) == 0)
            evenSum += i;
}

void findEvenSum(ull start, ull end) {
    for(ull i = start; i <= end; ++i)
        if((i & 1) == 1)
            oddSum += i;
}

int main() {
    ull start = 0;
    ull end = 1900000000;

    auto startTime = high_resolution_clock::now();

    thread t1(findOddSum, start, end);
    thread t2(findEvenSum, start, end);

    t1.join();
    t2.join();

    // findOddSum(start, end);
    // findEvenSum(start, end);

    auto duration = duration_cast<seconds>(high_resolution_clock::now() - startTime);

    cout<< "odd sum "<< oddSum <<"\n";
    cout<< "even sum "<< evenSum <<"\n";
    cout<< "elapsed time: "<< duration.count() << " seconds";

    return 0;
}