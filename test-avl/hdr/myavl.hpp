#ifndef MYAVL_HPP
#define MYAVL_HPP

template <typename T>
class AvlNode {
 private:
  T* data;
  AvlNode* left;
  AvlNode* right;
  int* height;

 public:
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
  AVLT() : _root{nullptr} {}
  ~AVLT() { _destructFrom(_root); }

  bool isEmptyTree() { return _isEmptyTree(); }
};

#endif