#include <bits/stdc++.h>
#include "baseCourse.h"

using namespace std;

class Course {
  private: 
    string title;
    string code;
    int credit;
    float grade;
  public: 
    Course (
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

    virtual Course* createCourse () = 0;

    void print() {
      cout << "Title : " << this->title << endl;
      cout << "Code : " << this->code << endl;
      cout << "Credit : " << this->credit << endl;
      cout << "GPA: " << this->grade << endl;
    }

    string get_title() { return this->title; }
    string get_code() { return this->code; }
    int get_credit() { return this->credit; }
    float get_grade() { return this->grade; }

    friend class FundCourse;
};
