#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int cont = 0;
    int numberNoMatch = 0;

    list<int> bocaditos(sandwiches.begin(), sandwiches.end());
    list<int> estudiantes(students.begin(), students.end());

    while(true) {
        if(bocaditos.front() == estudiantes.front()) {
            bocaditos.pop_front();
            estudiantes.pop_front();
            numberNoMatch = 0;
        } else {
            int temp = estudiantes.front();
            estudiantes.pop_front();
            estudiantes.push_back(temp);

            numberNoMatch++;
        }

        if(numberNoMatch == estudiantes.size() || estudiantes.empty())
            break;

    }


    return estudiantes.size();
}

int main() {
    ios_base::sync_with_stdio(false);


    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    
    printf("%d", countStudents(students, sandwiches));


    return 0;
}