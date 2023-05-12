#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
class OrderedStream {
public:
    

    OrderedStream(int n) {
        stream.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
            stream[idKey] = value;
            int index = idKey;
            vs ans;

            if(idKey == 1) {
                ans.push_back(stream[idKey]);
                while(index + 1 < stream.size() && stream[++index] != "")
                    ans.push_back(stream[index]);
            }
            else {
                
            }

            return ans;
        }

    private:
        vs stream;
};


void print(vs temp) {
    if(temp.empty()) {
        cout<<"[]"<<endl;
        return;
    }

    for(auto item: temp)
        cout<<item<<" ";
    cout<<endl;
}


int main() {
    OrderedStream *os = new OrderedStream(9);
    auto aux = os->insert(9, "aaaaa");
    print(aux);
    aux = os->insert(7, "bbbbb");
    print(aux);
    aux = os->insert(6, "ccccc");
    print(aux);
    aux = os->insert(4,"oalee");
    print(aux);
    aux = os->insert(2,"bouhq");
    print(aux);
    aux = os->insert(1,"mnknb");
    print(aux);
    aux = os->insert(5,"qkxbj");
    print(aux);
    aux = os->insert(8,"iydkk");
    print(aux);
    aux = os->insert(3,"bbbbb");
    print(aux);
    
    return 0;
}


//[[9],[9,"nghbm"],[7,"hgeob"],[6,"mwlrz"],[4,"oalee"],[2,"bouhq"],[1,"mnknb"],[5,"qkxbj"],[8,"iydkk"]