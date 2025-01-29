#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size) {
  table = new Node*[size];
}

void HashTable::insert(Student* student) {
  int hashID = hashFunction(student);

  // get final node in list
  Node* node = table[hashID];

  // space in list
  if (getLength(hashID) < 4) {
    Node* node = getNode(hashID);
    node = new Node(student);
  }
  // capacity exceeded, create new hashtable
  else {
    Node** newTable = new Node*[size()*2];
    newTable
  }
}

void HashTable::remove() {
  
}

void HashTable::search() {
  
}

int HashTable::hashFunction(Student* student) {
  return student->id % size();
}

void HashTable::copy(Node** copyTable) {
  // loop through the table we're copying from
  // calculate new position
  for (int i = 0; i < copyList->size(); i++) {
    if (copyTable[i] == NULL) continue;

    Student* student = copyTable[i]->student;
    table[hashFunction(student)] = student;
  }
}

int HashTable::size() {
  return sizeof(HashTable::table) / sizeof(HashTable::table[0]);
}

Node* HashTable::getNode(int hashID) {
  Node* node = table[hashID];

  // loop until the current node is null
  while (node != NULL) {
    node = node->next;
  }
  return node;
}

int HashTable::getLength(int hashID) {
  Node* node = table[hashID];
  int length = 0;
  
  while (node != NULL) {
    length++;
    node = node->next;
  }

  return length;
}
