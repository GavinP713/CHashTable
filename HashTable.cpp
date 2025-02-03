#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int _length) {
  table = new Node*[-length];
  length = _length;
}

void HashTable::insert(Student* student) {
  int hashID = hashFunction(student);

  // get final node in list
  Node* node = table[hashID];

  // space in list
  if (linkLength(hashID) < 4) {
    Node* node = getNode(hashID); // gets last node in list
    node = new Node(student); 
  }
  // capacity exceeded, create new hashtable
  else {
    Node** oldTable = table;
    Node** newTable = new Node*[length*2];
    table = newTable;
    length = length*2;
    
    copy(oldTable, length/2);
  }
}

void HashTable::remove(Node* node) {
  for (int i = 0; i < length; i++) {
    Node* current = table[i];
    if (current == NULL) continue;
    else if (current == node) {
      table[i] = current->next;
      delete(node);
      return;
    }
   
    while (current->next != node || current->next != NULL) {
      current = current->next;
    }
    
    if (current->next == node) {
      current->next = current->next->next;
      delete(node);
      return;
    }
  }
}

Node* HashTable::search(int id) {
  // search table
  for (int i = 0; i < length; i++) {
    Node* node = table[i];
    
    // get each node in linked list until either a NULL node is found or the student we're looking for
    while (node->student->id != id || node != NULL) {
      node = node->next;
    }
    
    // list did or didnt contain the student
    if (node->student->id == id) return node;
    else return NULL;
  }

  return NULL;
}

int HashTable::hashFunction(Student* student) {
  return student->id % size();
}

void HashTable::copy(Node** _table, int _length) {
  // loop through the table we're copying from
  // calculate new position for students
  for (int i = 0; i < _length; i++) {
    if (_table[i] != NULL) {
      Student* _student = _table[i]->student;
      table[hashFunction(_student)]->student = _student;
    }
  }
}
 
int HashTable::size() {
  int size = 0;
  
  for (int i = 0; i < length; i++) {
    size += linkLength(i);
  }
       
  return size;
}

Node* HashTable::getNode(int hashID) {
  Node* node = table[hashID];

  // loop until the current node is null
  while (node != NULL) {
    node = node->next;
  }
  return node;
}

int HashTable::linkLength(int hashID) {
  Node* node = table[hashID];
  int length = 0;
  
  while (node != NULL) {
    length++;
    node = node->next;
  }

  return length;
}
