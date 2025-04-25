#include "../common/tree.h"

using namespace Tree;

pair<optional<int>, int> solution(TreeNode* root, int& cont) {
    if (root == nullptr) {
        return {nullopt, 0};
    }

    pair<optional<int>, int> solLeft = solution(root->left, cont);
    pair<optional<int>, int> solRight = solution(root->right, cont);

    pair<optional<int>, int> solution;

    if (solLeft.first == nullopt && solRight.first == nullopt) {
        solution.first = root->val;
        solution.second = 0;
        cont = max(cont, solution.second);
    } else if (solLeft.first == nullopt || solRight.first == nullopt) {
        if (solLeft.first != nullopt) {
            int newCont = solLeft.second + (solLeft.first == root->val);
            solution.first = root->val;
            solution.second = newCont;
            cont = max(cont, newCont);
        } else {
            int newCont = solRight.second + (solRight.first == root->val);
            solution.first = root->val;
            solution.second = newCont;
            cont = max(cont, newCont);
        }
    } else {
        if(solLeft.first != root->val && solRight.first != root->val) {
            solution.first = root->val;
            solution.second = 0;
        } else if (solLeft.first != root->val || solRight.first != root->val) {
            if(solLeft.first == root->val) {
                int newCont = solLeft.second + 1;
                solution.first = root->val;
                solution.second = newCont;
            } else {
                int newCont = solRight.second + 1;
                solution.first = root->val;
                solution.second = newCont;
            }

            cont = max(cont, solution.second);
        } else {
            solution.first = root->val;
            solution.second = solLeft.second + solRight.second + 2;
            cont = max(cont, solution.second);
        }
    }

    return solution;
}

int longestUnivaluePath(TreeNode* root) {
    int cont = 0;
    solution(root, cont);
    return cont;
}

int main() {
    TreeNode *root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(1);
    root->right->right = createNode(1);

    cout<< longestUnivaluePath(root);

    return 0;
}