#ifndef MYRB_HPP
#define MYRB_HPP

#include <initializer_list>
#include <iostream>

enum Paint { RED = 0, BLACK = 1 };

template <typename T>
class RbNode {
 private:
  /****************************PRIVATE*****************************/
  T* data;
  RbNode* left;
  RbNode* right;
  RbNode* parent;
  Paint color = BLACK;

 public:
  /***************************PUBLIC API***************************/
  // Constructor & Destructor:
  RbNode(const T& dt)
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
  int getColor() { return this->color; }
  // Setters:
  void setData(T dt) { this->data = new T{dt}; }
  RbNode*& setLeft(RbNode*& n) { return this->left = n; }
  RbNode*& setRight(RbNode*& n) { return this->right = n; }
  RbNode*& setParent(RbNode*& n) { return this->parent = n; }
  void setColor(Paint c) { this->color = c; }
  void setRed() { this->color = RED; }
  void setBlack() { this->color = BLACK; }
};

template <typename T>
class RbT {
 private:
  /*****************************PRIVATE****************************/
  RbNode<T>* _Root;

  // Check if Node is empty:
  bool _isEmptyAt(RbNode<T>*& n) { return (!n) ? true : false; }
  // Destruct SubTree with root at given node:
  bool _destructFrom(RbNode<T>*& n) {
    if (n) {
      _destructFrom(n->getLeft());
      _destructFrom(n->getRight());
      delete n;
      return true;
    }
    // NOTE: More time/space efficient for large trees with loop?
    else
      return false;
  }

  void _insert(RbNode<T>*& n, T val) {
    if (!n) {
      n = new RbNode<T>{val};
      n->setColor((n->getParent()->getColor() == RED) ? BLACK : RED);
    } else {
      if (n->getData() > val)
        _insert(n->getLeft(), val);
      else if (n->getData() < val)
        _insert(n->getRight(), val);
      else
        return;
    }
  }

  RbNode<T>*& _getGrandParent(RbNode<T>*& n) {
    return (n->getParent()->getParent());
  }

  RbNode<T>* _getSibling(RbNode<T>*& n) {
    RbNode<T>* p = n->getParent();
    if (!p) return nullptr;
    if (n == p->getLeft())
      return p->getRight();
    else
      return p->getLeft();
  }

  RbNode<T>*& _getUncle(RbNode<T>*& n) {
    RbNode<T>* p = n->getParent();
    return _getSibling(p);
  }

  void _rotateLeft(RbNode<T>*& n) {
    RbNode<T>* new_n = n->getRight();
    RbNode<T>* p = n->getParent();

    n->setRight(new_n->getLeft());
    new_n->setLeft(n);
    n->setParent(new_n);

    if (n->getRight()) (n->getRight())->setParent(n);

    if (!p) {
      if (n == p->getLeft())
        p->setLeft(new_n);
      else if (n == p->getRight())
        p->setRight(new_n);
    }
    new_n->setParent(p);
  }

  void _rotateRight(RbNode<T>*& n) {
    RbNode<T>* new_n = n->getLeft();
    RbNode<T>* p = n->getParent();

    n->setLeft(new_n->getRight());
    new_n->setRight(n);
    n->setParent(new_n);

    if (n->getLeft()) (n->getLeft())->setParent(n);

    if (!p) {
      if (n == p->getRight())
        p->setRight(new_n);
      else if (n == p->getRight())
        p->setLeft(new_n);
    }
    new_n->setParent(p);
  }

  RbNode<T>*& _insertNode(RbNode<T>*& root, RbNode<T>*& new_node) {
    // immediately create node if _Root is empty:
    _insertInternally(root, new_node);
    _repairInsert(new_node);

    root = new_node;
    while (root->getParent()) {
      root = root->getParent();
    }
    return root;
  }
  void _insertInternally(RbNode<T>*& root, RbNode<T>*& n) {
    if (!root) {
      if (n->getData() < root->getData()) {
        if (!root->getLeft()) {
          _insertInternally(root->getLeft(), n);
          return;
        } else
          root->setLeft(n);
      } else {
        if (!root->getRight()) {
          _insertInternally(root->getRight(), n);
          return;
        } else
          root->setRight(n);
      }
    }
    n->setParent(root);
    n->setLeft(nullptr);
    n->setRight(nullptr);
    n->setRed();
  }

  void _repairInsert(RbNode<T>*& n) {
    if (!n->getParent()) {
      // case1
      _insCase1(n);
    } else if (n->getParent()->getColor() == BLACK) {
      // case2
      _insCase2(n);
    } else if (_getUncle(n) && _getUncle(n)->getColor() == RED) {
      // case 3
      _insCase3(n);
    } else {
      // case 4
      _insCase4(n);
    }
  }

  void _insCase1(RbNode<T>*& n) { n->setBlack(); }
  void _insCase2(RbNode<T>*& n) { return; }
  void _insCase3(RbNode<T>*& n) {
    n->getParent()->setColor(BLACK);
    _getUncle(n)->set(BLACK);
    _getGrandParent(n)->setColor(RED);
    _repairInsert(_getGrandParent(n));
  }
  void _insCase4(RbNode<T>*& n) {
    RbNode<T>* p = n->getParent();
    RbNode<T>* g = p->getParent();

    if (n == p->getRight() && p == g->getLeft()) {
      _rotateLeft(p);
      n = n->getLeft();
    } else if (n == p->getLeft() && p == g->getRight()) {
      _rotateRight(p);
      n = n->getRight();
    }
    _insCase4_CONTINUE(n);
  }
  void _insCase4_CONTINUE(RbNode<T>*& n) {
    RbNode<T>* p = n->getParent();
    RbNode<T>* g = p->getParent();

    if (n == p->getLeft())
      _rotateRight(g);
    else
      _rotateLeft(g);
    p->setColor(BLACK);
    g->setColor(RED);
  }

  void _printIN(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    _printIN(n->getLeft(), os);
    os << n->getData() << ' ';
    _printIN(n->getRight(), os);
  }
  void _printPRE(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    os << n->getData() << ' ';
    _printPRE(n->getLeft(), os);
    _printPRE(n->getRight(), os);
  }
  void _printPOST(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    _printPOST(n->getLeft(), os);
    _printPOST(n->getRight(), os);
    os << n->getData() << ' ';
  }
  bool b_printIN(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      b_printIN(n->getLeft(), os);
      os << n->getData() << ' ';
      b_printIN(n->getRight(), os);
      return true;
    }
  }
  bool b_printPRE(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      os << n->getData() << ' ';
      b_printPRE(n->getLeft(), os);
      b_printPRE(n->getRight(), os);
      return true;
    }
  }
  bool b_printPOST(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      b_printPOST(n->getLeft(), os);
      b_printPOST(n->getRight(), os);
      os << n->getData() << ' ';
      return true;
    }
  }

 public:
  /***************************PUBLIC API***************************/
  // Constructor & Destructor:
  RbT() : _Root{nullptr} {}
  RbT(std::initializer_list<T>& list) {
    _Root = nullptr;
    for (auto i : list)
      _insert(_Root, i);
  }

  ~RbT() { _destructFrom(_Root); }

  // Operations on the tree:
  bool isEmptyTree() { return _isEmptyAt(_Root); }  // validate the tree?
  bool clearTree() { return _destructFrom(_Root); }
  RbNode<T>*& insertNode(RbNode<T>*& n) { _insertNode(n); }
  RbNode<T>*& insertValue(T*& val) { _insertNode(new RbNode<T>{val}); }
  void print_InOrder(std::ostream& os = std::cout) { _printIN(_Root, os); }
  void print_PreOrder(std::ostream& os = std::cout) { _printPRE(_Root, os); }
  void print_PostOrder(std::ostream& os = std::cout) { _printPOST(_Root, os); }

  bool bprint_InOrder(std::ostream& os = std::cout) {
    return b_printIN(_Root, os);
  }
  bool bprint_PreOrder(std::ostream& os = std::cout) {
    return b_printPRE(_Root, os);
  }
  bool bprint_PostOrder(std::ostream& os = std::cout) {
    return b_printPOST(_Root, os);
  }
};

#endif