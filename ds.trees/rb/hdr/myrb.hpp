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
  RbNode*& GetL() { return this->left; }
  RbNode*& GetR() { return this->right; }
  RbNode*& GetP() { return this->parent; }
  int GetColor() { return this->color; }
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
      _destructFrom(n->GetL());
      _destructFrom(n->GetR());
      delete n;
      return true;
    }
    // NOTE: More time/space efficient for large trees with loop?
    else
      return false;
  }

  void _rotateLeft(RbNode<T>*& n) {}
  void _rotateRight(RbNode<T>*& n) {}

  void _insertFrom(RbNode<T>*& n, T val) {
    if (!n) {
      n = new RbNode<T>{val};
      // if (n->GetP()->GetColor() == RED) {
      //   n->setBlack();
      // } else {
      //   n->setRed();
      // }
    } else {
      if (n->getData() > val) {
        _insertFrom(n->GetL(), val);
      } else if (n->getData() < val) {
        _insertFrom(n->GetR(), val);
      } else
        return;
    }
  }
  void _printIN(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    _printIN(n->GetL(), os);
    os << n->getData() << ' ';
    _printIN(n->GetR(), os);
  }

  void _printPRE(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    os << n->getData() << ' ';
    _printPRE(n->GetL(), os);
    _printPRE(n->GetR(), os);
  }

  void _printPOST(RbNode<T>*& n, std::ostream& os) {
    if (!n) return;
    _printPOST(n->GetL(), os);
    _printPOST(n->GetR(), os);
    os << n->getData() << ' ';
  }

  bool b_printIN(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      b_printIN(n->GetL(), os);
      os << n->getData() << ' ';
      b_printIN(n->GetR(), os);
      return true;
    }
  }

  bool b_printPRE(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      os << n->getData() << ' ';
      b_printPRE(n->GetL(), os);
      b_printPRE(n->GetR(), os);
      return true;
    }
  }

  bool b_printPOST(RbNode<T>*& n, std::ostream& os) {
    if (!n)
      return false;
    else {
      b_printPOST(n->GetL(), os);
      b_printPOST(n->GetR(), os);
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
      insert(i);
  }

  ~RbT() { _destructFrom(_Root); }

  // Operations on the tree:
  bool isEmptyTree() { return _isEmptyAt(_Root); }  // validate the tree?
  bool clearTree() { return _destructFrom(_Root); }

  void insert(T& val) {
    // immediately create node if _Root is empty:
    if (!_Root) {
      _Root = new RbNode<T>{val};
      _Root->setBlack();
    }
    // otherwise, start insertion from _Root:
    else
      _insertFrom(_Root, val);
  }
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