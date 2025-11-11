#include <bits/stdc++.h>

using namespace std;

class Person {
  private: 
    string fname;
    string lname;
    int age;
    char gender;
  public:
    Person (string fname = "",
            string lname = "", 
            int age = 0, 
            char gender = ' '
          ) 
    {
      this->age = age;
      this->fname = fname;
      this->lname = lname;
      this->gender = gender;
    }
  
    string get_fname() { return this->fname; }
    string get_lname() { return this->lname; }
    int get_age() { return this->age; }
    char get_gender () { return this->gender; }

  friend class Student;
};
