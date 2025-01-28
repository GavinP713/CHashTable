#include "Student.h"

#ifndef NODE_H
#define NODE_H

class Node {
public:
  Student* student;
  Node* next;
  Node(Student* student);
};

#endif
