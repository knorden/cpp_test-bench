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
  AvlNode*& GetL() { return this->left; }
  AvlNode*& GetR() { return this->right; }
  int get_Hyt() { return *this->height; }

  AvlNode*& setLeft(AvlNode*& n) { return this->left = n; }
  AvlNode*& setRight(AvlNode*& n) { return this->right = n; }
  int set_Hyt(int h) { return *this->height = h; }
};

template <typename T>
class AVLT {
 private:
  /****************************PRIVATE*****************************/
  AvlNode<T>* _root;
  bool _isEmptyTree() { return (!_root) ? true : false; }
  void _destructFrom(AvlNode<T>*& r) {
    if (r) {
      _destructFrom(r->GetL());
      _destructFrom(r->GetR());
      delete r;
    }
  }

  static const int ALLOW_IMBALANCE = 1;

  void _rotateWithLeftChild(AvlNode<T>*& root) {
    // First, Rotate:
    AvlNode<T>* new_root = root->GetL();
    root->setLeft(new_root->GetR());
    new_root->setRight(root);
    // SET HEIGHT:
    root->set_Hyt(
        [&]() { return std::max(Hyt(root->GetL()), Hyt(root->GetR())) + 1; }());
    new_root->set_Hyt([&]() {
      return std::max(Hyt(new_root->GetL()), root->get_Hyt()) + 1;
    }());
    root = new_root;
  }
  void _doubleWithLeftChild(AvlNode<T>*& off) {
    _rotateWithLeftChild(off->GetL());
    _rotateWithLeftChild(off);
  }

  void _rotateWithRightChild(AvlNode<T>*& root) {
    // First, Rotate:
    AvlNode<T>* new_root = root->GetR();
    root->setRight(new_root->GetL());
    new_root->setLeft(root);
    // Set Height:
    root->set_Hyt(
        [&]() { return std::max(Hyt(root->GetR()), Hyt(root->GetL())) + 1; }());
    new_root->set_Hyt([&]() {
      return std::max(Hyt(new_root->GetR()), root->get_Hyt()) + 1;
    }());
    root = new_root;
  }

  void _doubleWithRightChild(AvlNode<T>*& off) {
    _rotateWithRightChild(off->GetR());
    _rotateWithRightChild(off);
  }

  // BALANCE:
  void _balance(AvlNode<T>*& st) {
    if (!st) return;

    if (Hyt(st->GetL()) - Hyt(st->GetR()) > ALLOW_IMBALANCE) {
      if (Hyt(st->GetL()->GetL()) >= Hyt(st->GetL()->GetR())) {
        _rotateWithLeftChild(st);
      } else {
        _doubleWithLeftChild(st);
      }
    } else if (Hyt(st->GetR()) - Hyt(st->GetL()) > ALLOW_IMBALANCE) {
      if (Hyt(st->GetR()->GetR()) >= Hyt(st->GetR()->GetL())) {
        _rotateWithRightChild(st);
      } else {
        _doubleWithRightChild(st);
      }
    }

    st->set_Hyt(
        [&]() { return std::max(Hyt(st->GetL()), Hyt(st->GetR())) + 1; }());
  }
  void _insert(AvlNode<T>*& r, const T& val) {
    // Add new data node like a regular BST:
    if (!r) {
      r = new AvlNode{val};
    } else {
      if (val < r->getData()) {
        _insert(r->GetL(), val);
      } else if (val > r->getData()) {
        _insert(r->GetR(), val);
      }
    }

    // Update AVLT with correct rotations:
    _balance(r);
  }

  void _printIN(AvlNode<T>*& r, std::ostream& os) {
    if (!r) return;
    _printIN(r->GetL(), os);
    os << "\t" << &r->getData() << ": " << r->getData() << '\n';
    _printIN(r->GetR(), os);
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

  int Hyt(AvlNode<T>*& n) { return n == nullptr ? -1 : n->get_Hyt(); }
  std::ostream& printOrder_In(std::ostream& os = std::cout) {
    _printIN(_root, os);
    return os;
  }
};

#endif