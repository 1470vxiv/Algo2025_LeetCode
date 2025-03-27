#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    private:
        unordered_map<int,int> inorderMap; //紀錄inorder之 value->index

        TreeNode* buildTreePrivate(vector<int>& preorder, int& preorderIndex, int left, int right){
            if (left > right) return nullptr; // Base case, 終止條件

            int rootVal = preorder[preorderIndex];
            TreeNode* root = new TreeNode(rootVal);
            preorderIndex++;
            int inorderIndex = inorderMap[rootVal];

            //Divide and Conquer
            root->left = buildTreePrivate(preorder, preorderIndex, left, inorderIndex - 1);
            root->right = buildTreePrivate(preorder, preorderIndex, inorderIndex + 1, right);

            return root;

        }

    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int sz = preorder.size();
            
            for(int i=0; i<sz; i++) inorderMap[inorder[i]] = i;

            int preorderIndex = 0;
            return buildTreePrivate(preorder, preorderIndex, 0, sz-1);
        }
    };

