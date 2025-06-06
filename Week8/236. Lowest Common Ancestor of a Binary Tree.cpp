class Solution {

    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root || root == p || root == q) return root; //!root �Y root == nullptr
    
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);

            if (left && right) return root;
            else if(left) return left;
            else return right;
        }
    };
