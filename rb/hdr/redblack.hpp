#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <initializer_list>
#include <iostream>

/* COLORING FOR THE TREE */
enum COLOR { RED = 0, BLACK = 1 };

/* Red-Black Node Template */
template <typename T>
class RbNode {
 private:
 public:
  /* NODE FUNDAMENTALS: */
  T data;
  RbNode* parent;
  RbNode* left;
  RbNode* right;
  enum COLOR isColor;

  /* Constructor and Destructor: */
  RbNode(T dt) : data{dt}, left{nullptr}, right{nullptr} {}
  ~RbNode() {
    left = nullptr;
    right = nullptr;
    // delete &data;
  }
};

/* RB Tree Template */
template <typename T>
class RBT {
 private:
  /* TREE FUNDAMENTALS: */
  RbNode<T>* _root;

  /* HIDDEN OPERATORS ON THE TREE NODES: */
  /* Get the parent node: */
  RbNode<T>*& _getParent(RbNode<T>*& n) {
    return (n == nullptr) ? nullptr : n->parent;
  }
  /* Get the Grand-parent node: */
  RbNode<T>*& _getGrandParent(RbNode<T>*& n) {
    return _getParent(_getParent(n));
  }
  /* Get this node's siblings: */
  RbNode<T>*& _getSibling(RbNode<T>*& n) {
    RbNode<T>* p = _getParent(n);

    if (!p) return nullptr;
    if (n == p->left)
      return p->right;
    else
      return p->left;
  }
  /* Get the siblings of this node's parent: */
  RbNode<T>*& _getUncle(RbNode<T>*& n) {
    RbNode<T>* p = _getParent(n);
    return _getSibling(p);
  }

  /* TREE BALANCING: */
  void _rotateLeft(RbNode<T>*& n) {
    RbNode<T>* new_n = n->right;
    RbNode<T>* p = _getParent(n);
    static_assert(!new_n);

    n->right = new_n->left;
    new_n->left = n;
    n->parent = new_n;

    if (n->right) n->right->parent = n;

    if (!p) {
      if (n == p->left)
        p->left = new_n;
      else if (n == p->right)
        p->right = new_n;
    }

    new_n->parent = p;
  }

  void _rotateRight(RbNode<T>*& n) {
    RbNode<T>* new_n = n->left;
    RbNode<T>* p = _getParent(n);
    static_assert(!new_n);

    n->left = new_n->right;
    new_n->right = n;
    n->parent = new_n;

    if (n->left) n->left->parent = n;

    if (!p) {
      if (n == p->right)
        p->right = new_n;
      else if (n == p->left)
        p->left = new_n;
    }

    new_n->parent = p;
  }

  /* Destruct a tree/branch from the passed node */
  void _destructFrom(RbNode<T>*& r) {
    if (r) {
      _destructFrom(r->left);
      _destructFrom(r->right);
      delete r;
    }
  }
  /* Insert a node */
  void _insert(RbNode<T>*& n, T val) {
    if (!n) {
      n = new RbNode<T>{val};
      n->color = (n->parent->color == RED) ? BLACK : RED;
    } else {
      if (n->data > val)
        _insert(n->left, val);
      else if (n->data < val)
        _insert(n->right, val);
      else
        return;
    }
  }
  /* Print out elements In-Order */
  void _printIN(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    _printIN(n->left, os);
    os << n->data << ' ';
    _printIN(n->right, os);
  }

 public:
  // CONSTRUCTORS & DESTRUCTOR:
  RBT() : _root{nullptr} { _root->color = BLACK; }
  ~RBT() { _destructFrom(this->_root); }

  // PUBLIC INTERFACE FOR OPERATIONS ON THE TREE:
  /* Insert a new node: */
  void insert(T val) { _insert(this->_root, val); }
  /* Print the tree In-Order: */
  std::ostream& printInOrder(std::ostream& os = std::cout) {
    _printIN(this->_root, os);
    return os;
  }
};

#endif