#include <bits/stdc++.h>

using namespace std;

constexpr int intervale = 12;

double angleClock(int hour, int minutes) {
    double minutesAngle = minutes * 6;
    hour = (hour == 12) ? 0 : hour;
    double hoursAngle = hour * 30 + static_cast<double>((minutes / 12.0) * 6);

    return min(abs(minutesAngle - hoursAngle), 360 - abs(minutesAngle - hoursAngle));
}

int main() {
    int h = 9;
    int m = 7;

    printf("%f", angleClock(h, m));

    return 0;
}