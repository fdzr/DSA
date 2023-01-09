#include <bits/stdc++.h>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

namespace ARRAY {
    
    ostream& operator <<(ostream& out, vector<int> &v) {
    out<<"["<<v[0];
    for(int i=1;i<v.size();++i)
        out<<","<<v[i];

    out<<"]";
    return out;
}


};

#endif