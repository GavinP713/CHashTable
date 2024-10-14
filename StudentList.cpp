#include <iostream>
#include <iomanip>
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

// returns index in students array
int find(vector<Student*> &students, int id) {
  // check list for student of id
  for (int i = 0; i < students.size(); i++) {
    Student* student = students[i];

    // return the student if it matches the id
    if (student -> id == id) {
      return i;
    }
  }
  
  // if the student wasnt found, throw error
  cout << "student of id " << id << " could not be found!" << endl;
  return -1;
}

void addStudent(vector<Student*> &students, char input[cssize]) {
  Student* student = new Student();
  
  cout << "enter student details" << endl;

  // prompt user and add in data
  cout << "first name: "; cin >> input; strcpy(student-> firstname, input);
  cout << "last name: ";  cin >> input; strcpy(student-> lastname, input);
  cout << "id: ";         cin >> input; student-> id = atoi(input);
  cout << "gpa: ";        cin >> input; student-> gpa = atof(input);

  cout << "student added" << endl;
  
  // assign to vector
  students.push_back(student);
}

void removeStudent(vector<Student*> &students, char input[cssize]) {
  // prompt user for id of student to remove
  cout << "id: "; cin >> input;

  // convert to number
  int id = atoi(input);

  // find the student
  int index = find(students, id);
  
  // remove the student associated with id
  if (index != -1) {
    students.erase(students.begin() + index);
    cout << "removing student" << endl;
  }
}

// print info of one student
void printStudent(vector<Student*> &students, int id, bool userset) {
  int _id = id;

  // user inputed id overrides reference
  if (userset == true) {
    // prompt for id
    char input[cssize];
    cout << "id: "; cin >> input;

    // override id to new
    _id = atoi(input);
  }

  // print the student
  Student* student = students[find(students, _id)];
  cout << "id: "          << student -> id << endl;
  cout << "- firstname: " << student -> firstname << endl;
  cout << "- lastname: "  << student -> lastname << endl;
  cout << "- gpa: "       << setprecision(2) << fixed << student -> gpa << endl;
}

// print all students
void printAll(vector<Student*> &students) {
  for (int i = 0; i < students.size(); i++) {
    Student* student = students[i];
    printStudent(students, student -> id, false);
  }
}

void help() {
  cout << "\"add\": register a student into the system" << endl;
  cout << "\"remove\": remove a student from the system" << endl;
  cout << "\"print\": print info of a registered student" << endl;
  cout << "\"printall\": display list of registered students" << endl;
  cout << "\"quit\": exit the program" << endl;
  cout << "\"help\": display a list of commands" << endl;
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
      printStudent(students, 0, true);
    }
    else if (strcmp(input, "printall") == 0) {
      printAll(students);
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
