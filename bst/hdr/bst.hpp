#ifndef BST_HPP
#define BST_HPP
#include <initializer_list>
#include <iostream>

template <typename T>
class BinNode {
 public:
  // FUNDAMENTAL NODE PROPERTIES:
  T data;
  int height;
  BinNode* left;
  BinNode* right;

  // CONSTRUCTORS & DESTRUCTOR:
  BinNode(T dt) : data{dt}, left{nullptr}, right{nullptr} {}
  BinNode(T dt, BinNode<T>* lt, BinNode<T>* rt) {
    this->data = dt;
    this->left = lt;
    this->right = rt;
  }
  ~BinNode() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
  }
  // bool operator>(BinNode<T> &right) { return (this->data > right.data); }
  // bool operator<(BinNode<T> &right) { return (this->data < right.data); }
  // bool operator==(BinNode<T> &right) {
  //   return !(this->data > right.data) && !(this->data < right.data);
  // }
};

template <typename T>
class BST {
 private:
  BinNode<T>* _root;

  // HIDDEN OPERATORS ON THE TREE:
  void _destructFrom(BinNode<T>* r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
    }
  }
  void _insert(BinNode<T>*& parent, const T& val) {
    if (!parent)
      parent = new BinNode<T>{val};
    else {
      if (val < parent->data)
        _insert(parent->left, val);
      else if (val > parent->data)
        _insert(parent->right, val);
      else
        return;
    }
    // if (root->data > val) {
    //   if (!root->left) {
    //     root->left = new BinNode<T>{val};
    //   } else {
    //     _insert(root->left, val);
    //   }
    // } else {
    //   if (!root->right) {
    //     root->right = new BinNode<T>{val};
    //   } else {
    //     _insert(root->right, val);
    //   }
    // }
  }
  void _printOrder_IN(BinNode<T>* parent, std::ostream& os) {
    if (!parent) return;
    _printOrder_IN(parent->left, os);
    os << parent->data << ' ';
    _printOrder_IN(parent->right, os);
  }

 public:
  // CONTRUCTORS AND DESTRUCTOR:
  BST() : _root{nullptr} {}
  BST(std::initializer_list<T> vals) : _root{nullptr} {
    for (auto val : vals) {
      _insert(_root, val);
    }
  }
  ~BST() { _destructFrom(this->_root); }

  // INTERFACES FOR OPERATIONS ON THE TREE:
  void insert(const T& val) {
    _insert(this->_root, val);
    // if (this->_root) {
    //   this->_insert(this->_root, val);
    // } else {
    //   this->_root = new BinNode<T>{val};
    // }
  }
  std::ostream& printOrder_IN(std::ostream& out = std::cout) {
    _printOrder_IN(this->_root, out);
    return out;
  }
};

#endif