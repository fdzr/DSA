#include <bits/stdc++.h>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> people(num_people, 0);
    int iteration = 0;

    while(candies > 0) {

        for(int i = 0; i < num_people; ++i) {
            if (candies <= 0)
                break;

            people[i] += min((num_people) * iteration + i + 1, candies);
            candies -= (num_people) * iteration + i + 1;

        }

        ++iteration;
    }

    return people;
}

int main() {
    int candies = 10, num_people = 3;
    for(const auto &elem: distributeCandies(candies, num_people))
        cout<<elem<<" ";

    return 0;
}