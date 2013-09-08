/**
Definition for binary tree
 * struct TreeNode {
 *  int val;
 *  TreeNode *left;
 *  TreeNode *right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/
class Solution {
    public:
            int sumNumbers(TreeNode *root, int number){
                        if(root == NULL) return 0;
                                if(root->left == NULL && root->right==NULL){
                                                return number * 10 + root->val;
                                                        }
                                        number = number * 10 + root->val;
                                                return sumNumbers(root->left, number)+sumNumbers(root->right,number);
                                                    }
                int sumNumbers(TreeNode *root) {
                            return sumNumbers(root,0);
                                }
};
