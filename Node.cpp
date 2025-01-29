#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(Student* _student) {
  student = _student;
}

Node* Node::last() {
  Node* node = this;

  while (node->next != NULL) {
    node = node->next;
  }
  return node;
}

int Node::length() {
  return 1;
}
