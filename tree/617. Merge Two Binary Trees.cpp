/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }

    TreeNode* merge(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;

        TreeNode* sum = new TreeNode(root1->val + root2->val);

        sum->left = merge(root1->left, root2->left);
        sum->right = merge(root1->right, root2->right);

        return sum;
    }
};