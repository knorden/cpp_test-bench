#ifndef BST_H
#define BST_H

class BSTNode {
 private:
  int data, height;
  BSTNode *left, *right;
  // compare and get the larger value of the two
  int _max(int a, int b) { return (a >= b) ? a : b; }

 public:
  // constructors:
  BSTNode() : left(nullptr), right(nullptr) {}
  BSTNode(int val) : data{val}, left{nullptr}, right{nullptr} {};

  // insert new node to tree:
  void insert(BSTNode*& root, int val) {
    if (!root)
      root = new BSTNode(val);
    else {
      if (val < root->data)
        insert(root->left, val);
      else if (val > root->data)
        insert(root->right, val);
      else
        return;
    }
  }
  // get the tree height
  int getHeight(BSTNode* root) {
    if (!root) return 0;
    return 1 + _max(getHeight(root->left), getHeight(root->right));
  }

  int isBalanced(BSTNode*& root, bool& isB) {
    if (!root || !isB) {
      return 0;
    }

    int lh = isBalanced(root->left, isB);
    int rh = isBalanced(root->right, isB);

    if (abs(lh - rh) > 1) isB = false;

    return _max(lh, rh) + 1;
  }
};

#endif