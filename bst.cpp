#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
};

class BST {
private:
  Node* root;

public:
  BST() {
   root = nullptr;
  }
  bool isEmpty() const { return root == nullptr; };
  Node* getRoot() { return root; };
  void insert(int value);
  void insert(int value, Node* parent);
  bool find(int value);
  bool find(int value, Node* node);
  bool validate();
  bool validate(Node* node, int min, int max);
};

void BST::insert(int value) {
  Node* node = new Node { value, NULL, NULL };
  if (isEmpty()) root = node;
  insert(value, root);
}

void BST::insert(int value, Node* parent) {
  Node* node = new Node { value, NULL, NULL };
  if (value < parent->value && !parent->left) {
    parent->left = node;
  } else if (value > parent->value && !parent->right) {
    parent->right = node;
  } else if (value < parent->value && parent->left) {
    insert(value, parent->left);
  } else if (value > parent->value && parent->right) {
    insert(value, parent->right);
  }
}

bool BST::find(int value) {
  return find(value, root);
}

bool BST::find(int value, Node* node) {
  if (isEmpty()) { return false; };
  if (value == node->value) {
    return true;
  }
  if (value < node->value && node->left) {
    return find(value, node->left);
  } else if (value > node->value && node->right) {
    return find(value, node->right);
  } else {
    return false;
  }
}

bool BST::validate() {
  return validate(root, 0, 0);
}

bool BST::validate(Node* node, int min, int max) {
  if (isEmpty()) { return false; };
  if (max != 0 && node->value > max) {
    return false;
  }
  if (min != 0 && node->value < min) {
    return false;
  }
  if (node->left && !validate(node->left, min, node->value)) {
    return false;
  }
  if (node->right && !validate(node->right, node->value, max)) {
    return false;
  }
  return true;
}

int main() {

  BST* tree = new BST;
/*   tree->insert(20);
  tree->insert(10);
  tree->insert(30);
  tree->insert(50);
  tree->getRoot()->left->value = 100;
  cout << tree->getRoot()->value << endl;
  cout << tree->getRoot()->left->value << endl;
  cout << tree->getRoot()->right->value << endl;
  cout << tree->getRoot()->right->right->value << endl;
  cout << tree->find(50) << endl;
  cout << tree->validate() << endl; */

  return 0;
}