#include <bits/stdc++.h>
#include "student.h"
#include <time.h>

using namespace std;

int Student::courseSize = 100;
int Student::size = 0;

class SisiSystem {
  private: 
    Student ** students;
    int maxStudentSize;

  public: 
    SisiSystem () {
      maxStudentSize = 1000;
      students = new Student * [maxStudentSize]();
    }

    void showStudentList () {
      system("clear");

      if (Student::size == 0) {
        cout << "No records" << endl;
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        cout << "\n";

        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ----------\n";
          students[i]->print();
          cout << endl;
        }
      }
      // ... after inserting the new student
      cin.ignore();
      cout << "Press ENTER to go back...";
      // discard leftover characters up to newline then wait for Enter
      string line;
      getline(cin, line);

    }

    void addStudentData () {
      string fname = "";
      string lname = "";
      int age = 0;
      char gender = 'M';
      string major = "";
      string id = "";

      cout << "First name: "; cin >> fname;
      cout << "Last name: "; cin >> lname;
      cout << "Age: "; cin >> age;
      cout << "Gender: "; cin >> gender;
      cout << "Major: "; cin >> major;
      cout << "ID: "; cin >> id;

      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          if (students[i]->getID() == id) {
            cout << "Student ID is duplicated";
            return;
          }
        } else {
          students[i] = new Student(
            fname, 
            lname, 
            age, 
            gender, 
            id, 
            major
          );
          break;
        }
      }

      printf("Successfully added. Press any key to go back.");
      cin.ignore();
      string line;
      getline(cin, line);
    }

    void deleteStudent() {
      system("clear");

      if (Student::size == 0) {
        cout << "No records" << endl;
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        cout << "\n";

        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ----------\n";
          students[i]->print();
          cout << endl;
        }
      }
      // ... after inserting the new student
      cin.ignore();
      cout << "Enter a student to remove: ";
      // discard leftover characters up to newline then wait for Enter
      string line;
      getline(cin, line);
      int delete_idx = stoi(line);

      if (students[delete_idx] == nullptr) {
        printf("Inapproperiate value.");
        return;
      }

      int i = 0;
      for(i = delete_idx; i < maxStudentSize; i++ ) {
        students[i] = students[i + 1];
      }
      printf("Deleted.\nPress any key to go back...");
      cin.ignore();
      getchar();
    }

    void editStudentRecord() {
      if (Student::size == 0) {
        cout << "No records" << endl;
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        cout << "\n";

        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ----------\n";
          students[i]->print();
          cout << endl;
        }
      }

      cout << "Enter student index to edit: ";
      cin.ignore();
      string str;
      getline(cin, str);
      int idx = stoi(str);

      system("clear");
      cout << "old data:\n";
      students[idx]->print();

      cout << "\nnew data:\n";

      // read new values with getline, keeping old if input is empty
      string tmp;

      string nfname = students[idx]->get_fname();
      cout << "fname [" << nfname << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) nfname = tmp;

      string nlname = students[idx]->get_lname();
      cout << "lname [" << nlname << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) nlname = tmp;

      char gender = students[idx]->get_gender();
      cout << "gender [" << gender << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) gender = tmp[0];

      int age = students[idx]->get_age();
      cout << "age [" << age << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) {
        try {
          age = stoi(tmp);
        } catch (...) {
          cout << "Invalid age input, keeping old value.\n";
        }
      }

      string nid = students[idx]->getID();
      cout << "ID [" << nid << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) nid = tmp;

      string nmajor = students[idx]->get_major();
      cout << "Major [" << nmajor << "]: ";
      getline(cin, tmp);
      if (!tmp.empty()) nmajor = tmp;

      students[idx] = new Student(
        nfname, 
        nlname, 
        age, 
        gender, 
        nid, 
        nmajor
      );

      cout << "saved changes.\n";
      cin.ignore();
      system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
    }

    void edit(Course ** courses, int n) {
      if (n == 0) {
          cout << "No courses\n";
          system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
          cout << "\n";
          return;
      }


      cout << "Enter course index to edit: ";
      cin.ignore();
      string str;
      getline(cin, str);
      int idx = 0;
      try {
          idx = stoi(str);
      } catch (...) {
          cout << "Invalid index input.\n";
          system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
          cout << "\n";
          return;
      }

      if (idx < 0 || idx >= n || courses[idx] == nullptr) {
          cout << "Index out of range or no course at this index.\n";
          system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
          cout << "\n";
          return;
      }

      system("clear");
      cout << "Old data:\n";
      courses[idx]->print();

      // Get old values for defaults
      string oldTitle = courses[idx]->get_title();
      string oldCode  = courses[idx]->get_code();
      int    oldCredit = courses[idx]->get_credit();
      float  oldGrade  = courses[idx]->get_grade();

      cout << "\nEnter new values (leave blank to keep old value):\n";

      cout << "Title [" << oldTitle << "]: ";
      string newTitle;
      getline(cin, newTitle);
      if (newTitle.empty()) newTitle = oldTitle;

      cout << "Code [" << oldCode << "]: ";
      string newCode;
      getline(cin, newCode);
      if (newCode.empty()) newCode = oldCode;

      cout << "Credit [" << oldCredit << "]: ";
      string sCredit;
      getline(cin, sCredit);
      int newCredit = oldCredit;
      if (!sCredit.empty()) {
          try {
              newCredit = stoi(sCredit);
          } catch (...) {
              cout << "Invalid credit input, keeping old value (" << oldCredit << ").\n";
              newCredit = oldCredit;
          }
      }

      cout << "Grade (GPA) [" << oldGrade << "]: ";
      string sGrade;
      getline(cin, sGrade);
      float newGrade = oldGrade;
      if (!sGrade.empty()) {
          try {
              newGrade = stof(sGrade);
          } catch (...) {
              cout << "Invalid grade input, keeping old value (" << oldGrade << ").\n";
              newGrade = oldGrade;
          }
      }

      delete courses[idx];
      courses[idx] = new Course(newTitle, newCode, newCredit, newGrade);

      cout << "Saved changes.\n";
      system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
      cout << "\n";
    }

    void listCourses () {
      if (students[0] == nullptr) {
        system("clear");
        cout << "No data found in students.\n";
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ";
          cout << students[i]->getID() << " " << students[i]->get_fname() << " " << students[i]->get_lname();
          cout << endl;
        }
      }

      cout << "Choose student to see their courses: ";
      cin.ignore();
      string input;
      getline(cin, input);
      int idx = stoi(input);
      Course ** s_courses = students[idx]->get_courses();


      if(s_courses[0] == nullptr) {
        cout << "No course found.\n";
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        return;
      }

      for (int i = 0; i < students[idx]->get_courseSize(); i++) {
        cout << "title: "; cout << s_courses[i]->get_title() << endl;
        cout << "code: "; cout << s_courses[i]->get_code() << endl;
        cout << "credit: "; cout << s_courses[i]->get_credit() << endl;
        cout << "grade: "; cout << s_courses[i]->get_grade() << endl;
      }

      getline(cin, input);
      int op = stoi(input);

      switch (op)
      {
      case 1:
        edit(s_courses, students[idx]->get_courseSize());
        break;
      
      default:
        return;
      }
    }

    void addCourses () {
      if (students[0] == nullptr) {
        cout << "No data found in students.\n";
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ";
          cout << students[i]->getID() << " " << students[i]->get_fname() << " " << students[i]->get_lname();
          cout << endl;
        }
      }

      cout << "Choose student to add courses to: ";
      cin.ignore();
      string input;
      getline(cin, input);
      int idx = stoi(input);
      
      Student * stud = students[idx];
      Course ** s_courses = students[idx]->get_courses();


      cout << "Enter course title: "; string title; cin >> title;
      cout << "Enter course code: "; string code; cin >> code;
      cout << "Enter credit hours: "; int credit = 0; cin >> credit;
      int course_size = stud->get_courseSize();
      cout << "Enter grade (0-4): "; float grade = 0; cin >> grade;

      for (int i = 0; i < course_size; i++) {
        if (s_courses[i] != nullptr) {
          if(s_courses[i]->get_code() != code){
            cout << "Code is duplicated.";
            return;
          }
        }

        s_courses[i] = new Course(title, code, credit, grade);
        break;
      }
    }

    void deleteCourses() {
      if (students[0] == nullptr) {
        system("clear");
        cout << "No data found in students.\n";
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        return;
      }

      cout << "------------Student List-------------\n";
      for (int i = 0; i < maxStudentSize; i++) {
        if (students[i] != nullptr) {
          cout << i << ". ";
          cout << students[i]->getID() << " " << students[i]->get_fname() << " " << students[i]->get_lname();
          cout << endl;
        }
      }

      cout << "Choose student to see their courses: ";
      cin.ignore();
      string input;
      getline(cin, input);
      int idx = stoi(input);
      Course ** s_courses = students[idx]->get_courses();


      if(s_courses[0] == nullptr) {
        cout << "No course found.\n";
        system("bash -c 'read -n1 -s -r -p \"Press any key to continue...\"'");
        return;
      }

      for (int i = 0; i < students[idx]->get_courseSize(); i++) {
        cout << "title: "; cout << s_courses[i]->get_title() << endl;
        cout << "code: "; cout << s_courses[i]->get_code() << endl;
        cout << "credit: "; cout << s_courses[i]->get_credit() << endl;
        cout << "grade: "; cout << s_courses[i]->get_grade() << endl;
      }

      cout << "\n\nEnter course index to delete: "; 
      cin.ignore();
      getline(cin, input);
      int c_idx = stoi(input);

      if(c_idx < 0 || students[idx]->get_courseSize() <= c_idx) {
        cout << "invalid input, try again: " << endl;
        getline(cin, input);
        c_idx = stoi(input);
      }

      int i=0;
      for (i = c_idx; i < students[idx]->get_courseSize(); i++) {
        s_courses[i] = s_courses[i + 1];
      }

      cout << "successfully deleted.";
    }

    void run () {
      Student * s1 = new Student("Naran", "Munkhbaatar", 18, 'M', "24b1num0255", "Software-Engineer");
      Student * s2 = new Student("Bat", "Buyankhuleg", 21, 'M', "21b1num1234", "Computer-Science");
      Student * s3 = new Student("Anu-Ujin", "Boldbaatar", 20, 'F', "22b1num5678", "Information-System");
      Student * s4 = new Student("Tseveensuren", "Gombodorj", 18, 'M', "24b1num1235", "Computer-Engineer");

      students[0] = s1;
      students[1] = s2;
      students[2] = s3;
      students[3] = s4;

      int opt;
      while (true) {
        system("clear");
        cout << "1. Show student list\n";
        cout << "2. Add student data\n";
        cout << "3. Delete a student record\n";
        cout << "4. Edit student record\n\n";

        cout << "5. list courses\n";
        cout << "6. Add courses\n";
        cout << "7. Delete courses\n";
        cout << "8. Edit coures\n";

        cout << "0. Exit program\n";
        cout << "Choose the option: "; 
        cin >> opt;

        switch (opt)
        {
          case 1: 
            system("clear");
            showStudentList();
            break;
          case 2:
            system("clear");
            addStudentData();
            break;
          case 3: 
            system("clear");
            deleteStudent();
            break;
          case 4:
            system("clear");
            editStudentRecord();
            break;

          case 5: 
            system("clear");
            listCourses();
            break;
          case 6:
            system("clear");
            addCourses();
            break;
          case 7: 
            system("clear");
            deleteStudent();
            break;
          case 8:
            system("clear");
            editStudentRecord();
            break;
          case 0:
            return;
        }
      }
    }
};

int main () {
  SisiSystem program; 
  program.run();

  return 0;
}

