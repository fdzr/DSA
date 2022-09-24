#include <iostream>

#include "stack.h"

using namespace std;

int main() {
    Stack st;
    try{
        st.top();
    } catch(char const*) {
        cout<<"entro"<<endl;
    }
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    st.pop();
    st.print();
    

    return 0;
}