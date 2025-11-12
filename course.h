#include <bits/stdc++.h>

#ifndef course
#define course

using namespace std;

class Course
{
private:
  string title;
  string code;
  int credit;
  float grade;

public:
  Course(
    string title = "",
    string code = "",
    int credit = 0,
    float grade = 0
  ) {
    this->code = code;
    this->title = title;
    this->credit = credit;
    this->grade = grade;
  }

  virtual Course *createCourse(string title = "", string code = "", int credit = 0, float grade = 0) = 0;
  virtual void print() = 0;

  string get_title() { return this->title; }
  string get_code() { return this->code; }
  int get_credit() { return this->credit; }
  float get_grade() { return this->grade; }

  friend class FundCourse;
  friend class RequiredCourse;
  friend class ElectiveCourse;
};



class RequiredCourse : public Course {
  public:
    RequiredCourse(
      string title = "",
      string code = "",
      int credit = 0,
      float grade = 0
    ) {
      this->title = title;
      this->code = code;
      this->credit = credit;
      this->grade = grade;
    }
  
    Course *createCourse(string title = "", string code = "", int credit = 0, float grade = 0) {
      Course * newCourse =  new RequiredCourse(
        title, code, credit, grade
      );
      return newCourse;
    }

  void print() {
    cout << "Title   : " << this->title << endl;
    cout << "Code    : " << this->code << endl;
    cout << "Credit  : " << this->credit << endl;
    cout << "Grade   : " << this->grade << endl;
  }
};



class FundCourse : public Course
{
public:
  FundCourse(
    string title = "",
    string code = "",
    int credit = 0,
    float grade = 0
  ) { 
    this->title = title;
    this->code = code;
    this->credit = credit;
    this->grade = grade;
  }

  void print() {
    cout << "Title   : " << this->title << endl;
    cout << "Code    : " << this->code << endl;
    cout << "Credit  : " << this->credit << endl;
    cout << "Grade   : " << this->grade << endl;
  }

  Course *createCourse(string title = "", string code = "", int credit = 0, float grade = 0) {
    Course *temp = new FundCourse(title, code, credit, grade);
    return temp;
  }
};



class ElectiveCourse : public Course{
  public: 
    ElectiveCourse (
      string title,
      string code,
      int credit,
      float grade
    ) {
      this->title = title;
      this->code = code;
      this->credit = credit;
      this->grade = grade;
    }

  void print() {
    cout << "Title   : " << this->title << endl;
    cout << "Code    : " << this->code << endl;
    cout << "Credit  : " << this->credit << endl;
    cout << "Grade   : " << this->grade << endl;
  }

  Course * createCourse (string title = "", string code = "", int credit = 0, float grade = 0) {
    Course * newCourse = new ElectiveCourse(title, code, credit, grade);
    return newCourse;
  }
};

#endif
