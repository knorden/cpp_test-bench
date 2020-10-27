#ifndef MYAVL_HPP
#define MYAVL_HPP

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

  // Getters:
  T& getData() { return *this->data; }
  AvlNode*& getLeft() { return this->left; }
  AvlNode*& getRight() { return this->right; }
  int getHeight() { return *this->height; }
  // Setters:
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

 public:
  /***************************PUBLIC API***************************/
  AVLT() : _root{nullptr} {}
  ~AVLT() { _destructFrom(_root); }
  bool isEmptryTree() { return _isEmptyTree(); }
};

#endif