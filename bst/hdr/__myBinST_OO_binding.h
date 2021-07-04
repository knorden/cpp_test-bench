/*
 * Binary Search Tree implementation
 *  - heavily lifted from https://gist.github.com/mgechev/5911348
 *  - though, very very hacked up since then
 *
 * Simple keys and basic operations BST
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  *  * Inorder, Preorder, Postorder printouts
 *  *  * Stubbed in level order printout
 * Aaron Crandall - 2017 - Heavy overhaul of tests & behaviors
 *  *  * Added BigFive (like we should!)
 *  *  * Added several public interfaces for tree features
 * Aaron Crandall - 2019 - Fixed -Wshadow errors
 *  *  * Identified a few badly done interface fixes
 * Andrew O'Fallon - 2020
 *  *  * Made changes for instructional purposes.
 * Karl Norden - 2020
 *  *  * Renamed all variables and functions for consistency.
 *  *  * Removed 'using namespace std' and its nightmarish behaviors.
 *
 */
#ifndef __MYBINST_OO_BINDING_H
#define __MYBINST_OO_BINDING_H

#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
 *  Template Datastructure for a single tree node.
 */
template <typename T>
class Node {
 public:
  T value;
  Node* l;
  Node* r;

  static int totalNodes;

  Node(T val) {
    this->value = val;
    this->l = nullptr;
    this->r = nullptr;
    ++totalNodes;
  }

  Node(T val, Node<T>* left, Node<T>* right) {
    this->value = val;
    this->l = left;
    this->r = right;
    ++totalNodes;
  }

  ~Node() {
    this->value = 0;
    this->l = nullptr;
    this->r = nullptr;
    --totalNodes;
  }

  void operator=(const Node<T>& rNode) {
    this->value = rNode.value;
    this->l = rNode.l;
    this->r = rNode.r;
  }
};

// Initialize the static class variable for counting nodes to zero
template <typename T>
int Node<T>::totalNodes = 0;

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BinST {
 protected:
  Node<T>* _root;
  bool _debug = false;

  /* Clone a passed in tree, returns pointer to new tree */
  Node<T>* h_cloneTree(Node<T>* node) {
    if (!node)
      return nullptr;
    else
      return new Node<T>(node->value, h_cloneTree(node->l),
                         h_cloneTree(node->r));
  }

  void h_destroyBranch(Node<T>* b) {
    if (b) {
      h_destroyBranch(b->l);
      h_destroyBranch(b->r);
      delete b;
    }
  }

  void h_addNode(Node<T>* root, T val) {
    if (root->value > val) {
      if (!root->l) {
        root->l = new Node<T>(val);
      } else {
        h_addNode(root->l, val);
      }
    }

    else {
      if (!root->r) {
        root->r = new Node<T>(val);
      } else {
        h_addNode(root->r, val);
      }
    }
  }

  void h_printOrder_IN(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    h_printOrder_IN(root->l, output);
    output << root->value << ' ';
    h_printOrder_IN(root->r, output);
  }

  void h_printOrder_POST(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    h_printOrder_POST(root->l, output);
    h_printOrder_POST(root->r, output);
    output << root->val << ' ';
  }

  void h_printOrder_PRE(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    output << root->val << ' ';
    h_printOrder_PRE(root->l, output);
    h_printOrder_PRE(root->r, output);
  }

  void h_printOrder_LEVEL(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
      int num_nodes = static_cast<int>(q.size());
      while (num_nodes > 0) {
        Node<T>* nPtr = q.front();
        output << nPtr->value << ' ';
        q.pop();
        if (nPtr->l) {
          q.push(nPtr->l);
        }
        if (nPtr->r) {
          q.push(nPtr->r);
        }
        --num_nodes;
      }
      output << std::endl;
    }
  }

  int h_countNodes(Node<T>* root) {
    int n = 0;
    (!root) ? n = 0
            : n = 1 + h_countNodes(root->l) + h_countNodes(root->r);
    return n;
  }

  int h_getHeight(Node<T>* root) {
    int h = 0;
    (!root) ? h = -1
            : h = 1 + std::max(h_getHeight(root->l),
                               h_getHeight(root->r));
    return h;
  }

  void h_printLongestPath(Node<T>* root) {
    if (!root)
      return;
    std::cout << root->value << ' ';
    if (h_getHeight(root->l) > h_getHeight(root->r)) {
      h_printLongestPath(root->l);
    } else {
      h_printLongestPath(root->r);
    }
  }

  bool h_deleteValue(Node<T>* predecessor, Node<T>* current, T val) {
    if (!current)
      return false;
    if (current->value == val) {
      if (!(current->l) || !(current->r)) {
        Node<T>* temp = current->l;
        if (current->r)
          temp = current->r;

        if (predecessor) {
          (predecessor->l == current) ? temp : predecessor->r = temp;
        } else
          this->_root = temp;
      }

      else {
        Node<T>* valid = current->r;
        while (valid->l)
          valid = valid->l;

        T tempVal = current->value;
        current->value = valid->value;
        valid->value = tempVal;
        return h_deleteValue(current, current->r, tempVal);
      }
      delete current;
      return true;
    }
    return h_deleteValue(current, current->l, val) ||
           h_deleteValue(current, current->r, val);
  }

  bool h_checkIf_val_exists(Node<T>* root, T val) {
    bool isVal = false;
    (!root) ? isVal = false
            : (root->value == val)
                  ? isVal = true
                  : (root->value > val)
                        ? isVal = (h_checkIf_val_exists(root->l, val))
                        : isVal = (h_checkIf_val_exists(root->r, val));
    return isVal;
  }

 public:
  BinST() : _root(nullptr) {}  //

  BinST(std::initializer_list<T> vals) : _root(nullptr) {
    for (auto val : vals) {
      this->addNode(val);
    }
  }

  ~BinST() {
    if (this->_debug)
      h_destroyBranch(this->_root);
  }

  BinST(const BinST& another) : _root(nullptr) {
    if (this->_debug)
      std::cout << "[_debug] Invoked:\"Copy Constructor\"" << std::endl;
    this->_root = h_cloneTree(another._root);
  }

  BinST(BinST&& another) : _root(nullptr) {
    if (this->_debug)
      std::cout << "[_debug] Invoked:\"Move Constructor\"" << std::endl;
    this->_root = another._root;
    another._root = nullptr;
  }

  BinST& operator=(BinST& another) {
    if (this->_debug)
      std::cout << "[_debug] Invoked:\"Copy Assignment\"" << std::endl;
    this->_root = h_cloneTree(another._root);
    return *this;
  }

  BinST& operator=(BinST&& another) {
    if (this->_debug)
      std::cout << "[_debug] Invoked:\"Move Assignment\"" << std::endl;
    this->_root = another._root;
    another._root = nullptr;
    return *this;
  }

  void destroyBranch() {
    if (this->_root)
      this->h_destroyBranch(this->_root);
    this->_root = nullptr;
  }

  void addNode(T val) {
    if (this->_root)
      this->h_addNode(this->_root, val);
    else
      this->_root = new Node<T>(val);
  }

  bool empty() { return (this->root == nullptr); }

  void print(std::ostream& output = std::cout) {
    h_printOrder_IN(this->_root, output);
  }

  void print_PostOrder(std::ostream& output = std::cout) {
    h_printOrder_POST(this->_root, output);
  }

  void print_PreOrder(std::ostream& output = std::cout) {
    h_printOrder_PRE(this->_root, output);
  }

  void print_LevelOrder(std::ostream& output = std::cout) {
    h_printOrder_LEVEL(this->_root, output);
  }

  int size() { return h_countNodes(); }

  int count_Nodes() { return h_countNodes(this->_root); }

  int getHeight() { return h_getHeight(this->_root); }

  void printLongestPath() { h_printLongestPath(this->_root); }

  bool deleteValue(T val) {
    return this->h_deleteValue(nullptr, this->_root, val);
  }

  bool foundInTree(T val) {
    return h_checkIf_val_exists(this->_root, val);
  }

  void debug_on() { this->_debug = true; }

  void debug_off() { this->_debug = false; }
};

#endif