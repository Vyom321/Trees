#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL),right(NULL){}

};
class Solution{
    public:
    pair<int,TreeNode*> dfs(TreeNode* root){
        if(!root){
            return(-1,nullptr);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left.first == right.first){
            return{left.first+1,root};
        }else if (left.first>right.first)
        {
            return{left.first+1,left.second};
        }else{
            return{right.first+1 , right.second};
        }
    
        
    }
    TreeNode* lcaDeepestleaves(TreeNode*root){
        return dfs(root).second;
    }
};
