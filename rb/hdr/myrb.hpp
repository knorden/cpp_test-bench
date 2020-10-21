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
  RbNode(T dt)
      : data{new T{dt}}, left{nullptr}, right{nullptr}, parent{nullptr} {}
  ~RbNode() {
    delete data;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }

  T& getData() { return *this->data; }
  RbNode*& getLeft() { return this->left; }
  RbNode*& getRight() { return this->right; }
  RbNode*& getParent() { return this->parent; }
  Color getColor() { return this->color; }

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

  // destroy the branch starting from the supplied node:
  void _destructFrom(RbNode<T>*& r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
    }
  }

 public:
  /***************************PUBLIC API***************************/
  RbT() : _root{nullptr} {}
};

#endif