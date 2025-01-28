#include "Node.h"
#include "Student.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
 public:
  Node* table[100];
  void insert(Student* student);
  void delete();
  void search();
  int hashFunction(Student* student);
  int size();
};

#endif
