#include <iostream>
#include <vector>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void allPaths(Node* root, vector<string> &vc, string cad="") {
    if (!root)
        return;

    cad += to_string(root->key) + "->";

    if (!root->left && !root->right) {
        cad.pop_back();
        cad.pop_back();
        vc.push_back(cad);
    }
        

    allPaths(root->left, vc, cad);
    allPaths(root->right, vc, cad);


}


int main() {
    Node *root = createNode(1);
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    

    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    vector<string> vc;
    string cad = "";
    allPaths(root, vc, cad);

    for(auto a: vc)
        cout<<a<<endl;


    return 0;
}