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
void postorder(TreeNode* root,vector<int>&r){
    if(root==NULL){
        return;
    }
     postorder(root->left,r);
     postorder(root->right,r);
     r.push_back(root->val);
}


    vector<int> postorderTraversal(TreeNode* root) {

      vector<int>r;
    postorder(root,r);
    return r;
        
    }
};