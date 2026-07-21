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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        if(root -> val == key){
            return helper(root);
        }
        TreeNode* node = root;
        while(root !=nullptr){
            if(root -> val < key){
                if(root ->right != nullptr && root -> right->val ==key){
                    root ->right = helper(root -> right);
                    break;
                }else{
                    root= root->right;
                }
            }else{
                if(root ->left !=nullptr && root ->left->val ==key){
                    root ->left = helper(root ->left);
                    break;
                }else{
                    root = root->left;
                }
            }
        }
        return node;
    }
private:
    TreeNode* helper(TreeNode* root){
        if(!root ->left){
            return root->right;
        }
        if(root -> right == nullptr){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* leftlastright = findlastright(root -> left);
        leftlastright ->right =root->right;
        return root->left;
    }  
    TreeNode* findlastright(TreeNode* root){
        while(root ->right!=nullptr){
            root = root ->right;
        }
        return root;
    }  
};