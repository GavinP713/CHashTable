#include "Node.h"
#include "Student.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
 public:
  Node** table;
  int length;
  
  void insert(Student* student);
  void remove(Node* node);
  // returns node containing student
  // or NULL if student isnt in table
  Node* search(int id);
  int hashFunction(Student* student);

  void copy(Node** _table, int _length);

  // how many nodes are in the table
  int size();

  // move this to Node.h, not appropriate for this class
  // gets final node in linked list
  Node* getNode(int hashID);
  int linkLength(int hashID);
  HashTable(int size);
};

#endif
