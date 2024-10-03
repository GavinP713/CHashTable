#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int cssize = 20;

struct Student {
  char firstname[cssize];
  char lastname[cssize];
  int id;
  float gpa;
};

void addStudent(vector<Student*> &students, char input[cssize]) {
  Student* student = new Student();
  
  cout << "enter student details" << endl;

  // prompt user and add in data
  cout << "first name: "; cin >> input; strcpy(student-> firstname, input);
  cout << "last name: "; cin >> input; strcpy(student-> lastname, input);
  cout << "id: "; cin >> input; student-> id = atoi(input);
  cout << "gpa: "; cin >> input; student-> gpa = atof(input);

  cout << "student added" << endl;
  
  // assign to vector
  students.push_back(student);
}

void removeStudent(vector<Student*> &students, char input[cssize]) {
  cin >> input;
  int targetid = atoi(input);

  for (int i = 0; i < students.size(); i++) {
    Student* student = students[i];
    
    if (student -> id == targetid) {
      cout << "removing student" << endl;
      students.erase(students.begin() + i);
      return;
    }
  }

  cout << "student of id " << targetid << " could not be found!" << endl;
}

int main() {
  vector<Student*> students;

  // program controls
  char input[cssize];
  
  while (true) {
    cout << "awaiting input. type \"help\" for a list of commands." << endl;
    cin >> input;
    
    if (strcmp(input, "add") == 0) {
      addStudent(students, input);
    }
    else if (strcmp(input, "remove") == 0) {
      removeStudent(students, input);
    }
    else if (strcmp(input, "print") == 0) {

    }
    else if (input == "help") {

    }
    else if (input == "quit") {

    }
  }
  
  return 0;
}
