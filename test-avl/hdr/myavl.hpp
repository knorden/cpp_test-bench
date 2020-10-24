#ifndef MYAVL_HPP
#define MYAVL_HPP
#include <initializer_list>

template <typename T>
class AvlNode {
 private:
  /****************************PRIVATE*****************************/
  T* data;
  AvlNode* left;
  AvlNode* right;
  int* height;

 public:
  /***************************PUBLIC API***************************/
  AvlNode(const T& dt)
      : data{new T{dt}}, left{nullptr}, right{nullptr}, height{new int{1}} {}
  ~AvlNode() {
    delete data;
    left = nullptr;
    right = nullptr;
    delete height;
  }

  T& getData() { return *this->data; }
  AvlNode*& getLeft() { return this->left; }
  AvlNode*& getRight() { return this->right; }
  int getHeight() { return *this->height; }

  AvlNode*& setLeft(AvlNode*& n) { return this->left = n; }
  AvlNode*& setRight(AvlNode*& n) { return this->right = n; }
  int setHeight(int h) { return *this->height = h; }
};

template <typename T>
class AVLT {
 private:
  /****************************PRIVATE*****************************/
  AvlNode<T>* _root;
  bool _isEmptyTree() { return (!_root) ? true : false; }
  void _destructFrom(AvlNode<T>*& r) {
    if (r) {
      _destructFrom(r->getLeft());
      _destructFrom(r->getRight());
      delete r;
    }
  }

  void _insert(AvlNode<T>*& r, const T& val) {
    // Add new data node like a regular BST:
    if (!r) {
      r = new AvlNode{val};
    } else {
      if (val < r->getData()) {
        _insert(r->getLeft(), val);
      } else if (val > r->getData()) {
        _insert(r->getRight(), val);
      }
    }

    // Update AVLT with correct rotations:
  }

  void _printIN(AvlNode<T>*& r, std::ostream& os) {
    if (!r) return;
    _printIN(r->getLeft(), os);
    os << "\t" << &r->getData() << ": " << r->getData() << '\n';
    _printIN(r->getRight(), os);
  }

 public:
  /***************************PUBLIC API***************************/
  AVLT() : _root{nullptr} {}
  AVLT(std::initializer_list<T>& list) : _root{nullptr} {
    for (auto i : list) {
      _insert(_root, i);
    }
  }
  ~AVLT() { _destructFrom(_root); }

  void insert(const T& val) { _insert(_root, val); }
  bool isEmptyTree() { return _isEmptyTree(); }

  std::ostream& printOrder_In(std::ostream& os = std::cout) {
    _printIN(_root, os);
    return os;
  }
};

#endif