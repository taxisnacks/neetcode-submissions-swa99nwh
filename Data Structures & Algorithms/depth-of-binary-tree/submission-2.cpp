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
private:
    int currentDepth = 0;
    int maximumDepth = 0;
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        currentDepth++;
        if (currentDepth > maximumDepth){
            maximumDepth = currentDepth;
        }
        if (root->left != nullptr){
            maxDepth(root->left);
        }
        if (root->right != nullptr){
            maxDepth(root->right);
        }
        currentDepth--;
        return maximumDepth;
    }
};