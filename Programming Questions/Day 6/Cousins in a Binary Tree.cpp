/*In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.*/


class Solution {
public:
    bool areChildren(TreeNode* node, int x, int y) {
        // If x is the left child and y is the right child
        if(node->left && node->left->val == x && node->right && node->right->val == y) {
            return true;
        }
        // if y is the left child and x is the right child
        if(node->left && node->left->val == y && node->right && node->right->val == x) {
            return true;
        }
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) {
            return false;
        }
        // Level order traversal
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            bool foundX = false;
            bool foundY = false;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                // Check if current node is the parent of both x and y
                // If true, we return false from one level above x & y
                if(areChildren(node, x, y)) {
                    return false;
                }
                if(node->val == x) {
                    foundX = true;
                }
                if(node->val == y) {
                    foundY = true;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(foundX && foundY) {
                // found both x and y at the same level
                return true;
            } else if(foundX || foundY) {
                // found either x or y on this level, thus they are not on same level
                return false;
            }
        }
        return false;
    }
};