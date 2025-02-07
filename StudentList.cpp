#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "HashTable.h"
using namespace std;

const int cssize = 128;

void addStudent(HashTable* &table, char input[cssize]);
void removeStudent(HashTable* &table, char input[cssize]);
void printStudent(HashTable* &table, int id, bool userset);
void help();

Student* randomStudent();

int main() {
  // both the class and the array of nodes within the class have the same name, i would change it but lazy
  HashTable* table = new HashTable(100);

  // program controls
  char input[cssize];
  
  while (true) {
    cout << "awaiting input. type \"help\" for a list of commands." << endl;
    cin >> input;
    
    if (strcmp(input, "add") == 0) {
      addStudent(table, input);
    }
    else if (strcmp(input, "remove") == 0) {
      removeStudent(table, input);
    }
    else if (strcmp(input, "print") == 0) {
      printStudent(table, 0, true);
    }
    else if (strcmp(input, "help") == 0) {
      help();
    }
    else if (strcmp(input, "quit") == 0) {
      cout << "end program" << endl;
      return 0;
    }
    else {
      cout << "unkown command" << endl;
    }
  }

  cout << "loop ended" << endl;
  return 0;
}

Student* randomStudents() {
  vector<Student*> students;
  Student* student;

  ifstream file("Students.txt");
  
  // loop through students file
  char line[128];
  int var = 0;
  while (file >> line)) {
    // new student
    if (line[0] == ' ') {
      vector.push_back(student);

      student = new Student();
      var = 0;
    }
    // assign values to student
    else {
      if (var == 0) line >> student->id;
      else if (var == 1) strcpy(student->firstname, line);
      else if (var == 2) strcpy(student->lastname, line);
      else if (var == 3) line >> student->gpa;
    }
  }

  return rand(0, vector.size());
}

void addStudent(HashTable* &table, char input[cssize]) {
  Student* student = new Student();
  
  cout << "enter student details" << endl;
  
  // prompt user and add in data
  cout << "first name: "; cin >> input; strcpy(student->firstname, input);
  cout << "last name: ";  cin >> input; strcpy(student->lastname, input);
  cout << "id: ";         cin >> student->id;
  //student->id = atoi(input);
  cout << "gpa: ";        cin >> student->gpa;
  //student->gpa = atof(input);
  
  // insert to hash table
  table->insert(student);
  
  
  cout << "student added" << endl;
}

void removeStudent(HashTable* &table, char input[cssize]) {
  // prompt user for id of student to remove
  cout << "id: "; cin >> input;

  // convert to number
  int id = atoi(input);

  // find the student node
  Node* node = table->search(id);
  
  // remove the student associated with id
  if (node != NULL && node->student != NULL) {
    //students.erase(students.begin() + index);
    table->remove(node);
    cout << "student removed" << endl;
  }
  else {
    cout << "student not found!" << endl;
  }
}

// print info of one student
void printStudent(HashTable* &table, int id, bool userset) {
  int _id = id;

  // user inputed id overrides reference
  if (userset == true) {
    // prompt for id
    char input[cssize];

    // override id to new
    _id = atoi(input);
  }

  // get the student
  Node* node = table->search(_id);

  // print info
  if (node != NULL) {
    Student* student = node->student;
    cout << "id: "          << student -> id << endl;
    cout << "- firstname: " << student -> firstname << endl;
    cout << "- lastname: "  << student -> lastname << endl;
    cout << "- gpa: "       << setprecision(2) << fixed << student -> gpa << endl;
  }
  else {
    cout << "student not found!" << endl;
  }
}

void help() {
  cout << "\"add\": register a student into the system" << endl;
  cout << "\"remove\": remove a student from the system" << endl;
  cout << "\"print\": print info of a registered student" << endl;
  cout << "\"quit\": exit the program" << endl;
  cout << "\"help\": display a list of commands" << endl;
}
