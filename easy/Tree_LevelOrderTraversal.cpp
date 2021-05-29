// Level Order
// Problem Description

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



// Problem Constraints
// 1 <= number of nodes <= 105



// Input Format
// First and only argument is root node of the binary tree, A.



// Output Format
// Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



// Example Input
// Input 1:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Input 2:

//    1
//   / \
//  6   2
//     /
//    3


// Example Output
// Output 1:

//  [
//    [3],
//    [9, 20],
//    [15, 7]
//  ]
// Output 2:

//  [ 
//    [1]
//    [6, 2]
//    [3]
//  ]


// Example Explanation
// Explanation 1:

//  Return the 2D array. Each row denotes the traversal of each level.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A==NULL){
        vector<int> res={};
        ans.push_back(res);
        return ans;
    }
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int s=q.size();
        vector<int> res;
        for(int i=0;i<s;i++){
            TreeNode* temp = q.front();
            res.push_back(temp->val);
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        ans.push_back(res);
    }
    return ans;
}