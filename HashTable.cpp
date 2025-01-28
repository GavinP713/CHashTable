#include "HashTable.h"

void HashTable::insert(Student* student) {
  int hashID = hashFunction(student);

  // make cleaner?
  if (table[hashID] != NULL) {
    table[hashID] = new Node(student);
  }
  else {
    
  }
}

int HashTable::hashFunction(Student* student) {
  return student->id % HashTable::size();
}

int HashTable::size() {
  return sizeof(HashTable::table) / sizeof(HashTable::table[0]);
}
