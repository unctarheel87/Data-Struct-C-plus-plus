#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

class LinkedList {
  private:
    Node* head;
    
  public:
    LinkedList() {
      head = nullptr;
    }
    Node* insertFirst(int value);
    int size();
    Node* getFirst() { return head; };
    Node* getLast();
    void clear() { head = nullptr; };
    void removeFirst() { head = head->next; };
    void removeLast();
};

Node* LinkedList::insertFirst(int value) {
  Node* node = new Node { value, head };
  head = node;
  return node;
}

int LinkedList::size() {
  int count = 0;
  Node* node = head;
  while(node) {
    count++;
    node = node->next;
  }
  return count;
}

Node* LinkedList::getLast() {
  if(!getFirst()) { return nullptr; };
  Node* node = head;
  while(node->next) {
    node = node->next;
  }
  return node;
}

void LinkedList::removeLast() {
  if(!getFirst()) { return; };
  if(!head->next) {
    head = nullptr;
    return;
  }
  Node* prevNode = nullptr;
  Node* node = head;
  while(node->next) {
    prevNode = node;
    node = node->next;
  }
  prevNode->next = nullptr;
}

int main() {
  LinkedList* list = new LinkedList;
/* 
  list->insertFirst(123);
  list->insertFirst(456);
  list->insertFirst(789);

  cout << list->size() << endl;
  cout << list->getFirst()->value << endl;
  cout << list->getLast()->value << endl; */

  return 0;
}