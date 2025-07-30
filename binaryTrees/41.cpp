#include "../common/tree.h"

using namespace Tree;

string solution(TreeNode<int> *root) {
    if (root == nullptr) {
        return "";
    }

    string leftSolution = solution(root->left);
    string rightSolution = solution(root->right);

    if (leftSolution == "" && rightSolution == "")
        return string{static_cast<char>(root->val + 97)};

    if (leftSolution != "" && rightSolution == "") {
        return leftSolution + string{static_cast<char>(root->val + 97)};
    }

    if (rightSolution != "" && leftSolution == "") {
        return rightSolution + string{static_cast<char>(root->val + 97)};
    }

    string solutionRight, solutionLeft, finalSolution;
    solutionRight = rightSolution + string{static_cast<char>(root->val + 97)};
    solutionLeft = leftSolution + string{static_cast<char>(root->val + 97)};

    if (leftSolution > rightSolution) {
        if (solutionRight < solutionLeft)
            finalSolution = solutionRight;
        else
            finalSolution = solutionLeft;

    } else {
        if (solutionLeft < solutionRight)
            finalSolution = solutionLeft;
        else {
            finalSolution = solutionRight;
        }
    }

    return finalSolution;
}

string smallestFromLeaf(TreeNode<int> *root) {
    return solution(root);
}

int main() {
    TreeNode<int> *root = createNode(2);
    root->left = createNode(2);
    root->right = createNode(1);

    root->left->right = createNode(1);
    root->left->right->left = createNode(0);

    root->right->left = createNode(0);

    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(0);
    root->right->right = createNode(2);

    cout << smallestFromLeaf(root);

    return 0;
}