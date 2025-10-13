#include "../common/tree.h"

using namespace Tree;

void solve(TreeNode<int>* root, vector<vector<int>>& answer, int cont, vector<int> aux,
           int k) {
    if (root == nullptr) return;

    cont += root->val;
    aux.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr && cont == k) {
        answer.push_back(aux);
        return;
    }

    solve(root->left, answer, cont, aux, k);
    solve(root->right, answer, cont, aux, k);
}

vector<vector<int>> pathSum(TreeNode<int>* root, int targetSum) {
    int cont = 0;
    vector<vector<int>> answer;
    vector<int> temp;

    solve(root, answer, cont, temp, targetSum);

    return answer;
}

int main() {
    TreeNode<int>* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);

    root->left->left = createNode(11);

    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);

    root->right->left = createNode(13);
    root->right->right = createNode(4);

    root->right->right->left = createNode(5);
    root->right->right->right = createNode(1);

    auto res = pathSum(root, 22);

    for (const auto& v : res) {
        for (const auto& e : v) {
            cout << e << " ";
        }

        cout << "\n";
    }

    return 0;
}