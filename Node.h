#include "Student.h"

#ifndef NODE_H
#define NODE_H

class Node {
public:
  Student* student;
  Node* next;
  Node* last();
  int length();
  Node(Student* _student);
};

#endif
