#ifndef AVL_HPP
#define AVL_HPP
#include <initializer_list>
#include <iostream>

template <typename T>
class AvlNode {
 private:
 public:
  T* data;
  AvlNode* parent;
  AvlNode* left;
  AvlNode* right;
  int* height;

  explicit AvlNode(const T& dt)
      : parent{nullptr}, left{nullptr}, right{nullptr} {
    data = new T{dt};
    height = new int{1};
  }
  ~AvlNode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    delete data;
    delete height;
  }
};

template <typename T>
class AVL {
 private:
  /*********************************PRIVATE*********************************/
  AvlNode<T>* _root;

  // HIDDEN OPERATORS ON THE TREE:
  bool _destructFrom(AvlNode<T>* r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
      return true;
    } else
      return false;  // might need flag suppression once tested.
  }

  bool _insert(AvlNode<T>*& r, const T& val) {
    if (!r) {
      r = new AvlNode{val};
      return true;
    } else {
      if (val < *r->data)
        _insert(r->left, val);
      else if (val > *r->data)
        _insert(r->right, val);
      return false;  // will need flag suppression once tested.
    }
  }

  void _printIN(AvlNode<T>*& r, std::ostream& os) {
    if (!r) return;
    _printIN(r->left, os);
    os << "\t" << r->data << ": " << *r->data << '\n';
    _printIN(r->right, os);
  }

 public:
  /*********************************PUBLIC*********************************/
  // CONSTRUCTORS & DESTRUCTOR:
  AVL() : _root{nullptr} {}
  AVL(std::initializer_list<T>& list) : _root{nullptr} {
    for (auto i : list)
      _insert(_root, i);
  }
  ~AVL() { _destructFrom(this->_root); }

  // INTERFACE FOR OPERTIONS ON THE TREE:
  void insert(const T& val) { _insert(_root, val); }

  std::ostream& printOrder_In(std::ostream& os = std::cout) {
    _printIN(_root, os);
    return os;
  };
};

#endif