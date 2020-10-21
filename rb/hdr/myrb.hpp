#ifndef MYRB_HPP
#define MYRB_HPP

#include <iostream>

enum Color { RED = 0, BLACK = 1 };

template <typename T>
class RbNode {
 private:
  /****************************PRIVATE*****************************/
  T* data;
  RbNode* left;
  RbNode* right;
  RbNode* parent;
  Color color = BLACK;

 public:
  /***************************PUBLIC API***************************/
  // Constructor & Destructor:
  RbNode(T dt)
      : data{new T{dt}}, left{nullptr}, right{nullptr}, parent{nullptr} {}
  ~RbNode() {
    delete data;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }
  // Getters:
  T& getData() { return *this->data; }
  RbNode*& getLeft() { return this->left; }
  RbNode*& getRight() { return this->right; }
  RbNode*& getParent() { return this->parent; }
  Color getColor() { return this->color; }
  // Setters:
  void setData(T dt) { this->data = new T{dt}; }
  RbNode*& setLeft(RbNode*& n) { return this->left = n; }
  RbNode*& setRight(RbNode*& n) { return this->right = n; }
  RbNode*& setParent(RbNode*& n) { return this->parent = n; }
  void setColor(Color c) { this->color = c; }
};

template <typename T>
class RbT {
 private:
  /*****************************PRIVATE****************************/
  RbNode<T>* _root;

  // Destruct the subtree, starting from the supplied node:
  // NOTE: Might be more time/space efficient if use a loop for large trees:
  bool _isEmptyTree() { return (!_root) ? true : false; }
  void _destructFrom(RbNode<T>*& r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
    }
  }

  void _rotateLeft(RbNode<T>*& n) {}
  void _rotateRight(RbNode<T>*& n) {}

  void _insert(RbNode<T>*& n, T val) {
    if (!n) {
      n = new RbNode<T>{val};
      if (n->getParent()->getColor() == RED) {
        n->setColor(BLACK);
      } else {
        n->setColor(RED);
      }
    } else {
      if (n->getData() > val) {
        _insert(n->getLeft(), val);
      } else if (n->getData() < val) {
        _insert(n->getRight(), val);
      } else
        return;
    }
  }

 public:
  /***************************PUBLIC API***************************/
  // Constructor & Destructor:
  RbT() : _root{nullptr} {}
  ~RbT() { _destructFrom(_root); }

  // Operations on the tree:
  bool isEmptyTree() { return _isEmptyTree(); }
};

#endif