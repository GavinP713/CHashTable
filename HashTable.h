#include "Node.h"
#include "Student.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
 public:
  Node** table;
  
  void insert(Student* student);
  void remove();
  void search();
  int hashFunction(Student* student);

  void copy(Node* _table);
  
  int size(); // include linked lists?

  // move this to Node.h, not appropriate for this class
  Node* getNode(int hashID);
  int getLength(int hashID);
  
  HashTable(int size);
};

#endif
