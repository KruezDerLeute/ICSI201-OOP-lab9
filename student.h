#include "person.h"
#include "course.h"

using namespace std;

class Student : public Person {
  private: 
    string studentID;
    string major;
    Course **courses;
    static int courseSize;

  public: 
    static int size;            
    
    Student (string fname = "",
      string lname = "", 
      int age = 0, 
      char gender = ' ',
      string studentID = "",
      string major = ""
    ) {
      size++;
      Person::fname = fname;
      Person::lname = lname;
      Person::age = age;
      Person::gender = gender;

      this->studentID = studentID;
      this->major = major;

      courseSize = 100;

      courses = new Course * [courseSize]();
    }

    void print() {
      cout << "First name : " << this->fname << endl;
      cout << "Last name  : " << this->lname << endl;
      cout << "Gender     : " << this->gender << endl;
      cout << "Age        : " << this->age << endl; 
      cout << "Major      : " << this->major << endl;
    }

    string getID () { return studentID; }
    string get_major() { return this->major; }
    Course ** get_courses() { return this->courses; }
    int get_courseSize() { return this->courseSize; }
    int get_maxCourseSize() { return this->courseSize; }

    void set_courseSize (int i) {
      courseSize = i;
    }

    ~Student() {
      size--;
      for (int i = 0; i < courseSize; i++) {
        if (courses[i] != nullptr) {
          delete this->courses[i];
        }
      }
    }

    friend void editStudentRecord();

};
