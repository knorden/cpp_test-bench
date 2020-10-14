#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>

template <typename T> class AvlNode {
private:
public:
  T data;
  AvlNode *predecessor;
  AvlNode *left;
  AvlNode *right;

  AvlNode(const T &dt)
      : data{dt}, predecessor{nullptr}, left{nullptr}, right{nullptr} {}
  ~AvlNode() {
    predecessor = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T> class AVL {
private:
  AvlNode<T> *_root;
  void _destructFrom(AvlNode<T> *r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
    }
  }

public:
  AVL() : _root{nullptr} {}
  ~AVL() { _destructFrom(this->_root); }
};

#endif