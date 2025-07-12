#include "../../common/tree.h"

using namespace Tree;

void findKthSmallestNumber(TreeNode<int> *root, int &k, int &sum) {
    if (root == nullptr) return;

    findKthSmallestNumber(root->left, k, sum);
    if (k-- > 0) {
        sum += root->val;
    }
    findKthSmallestNumber(root->right, k, sum);
}

int main() {
    TreeNode<int> *root = createNode(8);
    root->left = createNode(7);
    root->left->left = createNode(2);
    root->right = createNode(10);
    root->right->left = createNode(9);
    root->right->right = createNode(13);

    int sum = 0;
    int k = 3;
    findKthSmallestNumber(root, k, sum);
    cout << "sum of elements that are smaller than or equal to kth smallest number: "
         << sum << "\n";

    return 0;
}