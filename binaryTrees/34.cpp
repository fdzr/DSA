#include "../common/tree.h"

using namespace Tree;
typedef long long int ll;

long long kthLargestLevelSum(TreeNode* root, int k) {
    priority_queue<int> pq;
    queue<TreeNode*> q;
    ll sum = 0;

    q.push(root);
    q.push(nullptr);

    while (q.size() > 1) {
        auto node = q.front();
        q.pop();

        if (node != nullptr) {
            sum += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        } else {
            pq.push(sum);
            q.push(nullptr);
            sum = 0;
        }
    }

    pq.push(sum);

    if (pq.size() < k)
        return -1;

    ll answer;
    while (k-- > 0) {
        answer = pq.top();
        pq.pop();
    }

    return answer;
}

int main() {
    TreeNode *root = createNode(5);
    root->left = createNode(8);
    root->right = createNode(9);

    root->left->left = createNode(2);
    root->left->right = createNode(1);

    root->right->left = createNode(3);
    root->right->right = createNode(7);

    root->left->left->left = createNode(4);
    root->left->left->right = createNode(6);

    cout<<kthLargestLevelSum(root, 2) << "\n";

    root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);

    cout<< kthLargestLevelSum(root, 1);

    return 0;
}