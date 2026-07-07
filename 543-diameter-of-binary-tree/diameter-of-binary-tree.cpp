/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        height(root, diam);
        return diam;
    }

private:
    int height(TreeNode* root, int& diam){
        if(!root) {
            return 0;
        }
        int ln = height(root ->left,diam);
        int rn= height(root->right, diam);

        diam = max(diam, (ln+rn));
        return 1+max(ln,rn);

    }
};