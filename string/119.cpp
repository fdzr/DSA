#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2) {
    int size_a = num1.size() - 1, size_b = num2.size() - 1;
    int acc = 0;
    int num_a = 0, num_b = 0;
    list<int> ans;

    while (size_a >= 0 || size_b >= 0) {
        if (size_a >= 0) {
            num_a = num1[size_a] - '0';
        }
        if (size_b >= 0) {
            num_b = num2[size_b] - '0';
        }

        int sum = num_a + num_b + acc;
        acc = sum / 10;
        int res = sum % 10;

        ans.push_front(res);

        --size_a, --size_b;
        num_a = 0, num_b = 0;
    }

    if(acc != 0)
        ans.push_front(acc);

    string finalAnswer = "";
    for_each(ans.begin(), ans.end(), [&finalAnswer](int elem){
        finalAnswer.push_back(elem + '0');
    });

    return finalAnswer;

}

int main () {
    string num1 = "456", num2= "77";
    cout<<addStrings(num1, num2);


    return 0;
}