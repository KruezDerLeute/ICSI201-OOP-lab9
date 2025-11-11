#include "course.h"

class FundCourse : public Course {
  public: 
    FundCourse (
      string title = "",
      string code = "", 
      int credit = 0, 
      float grade = 0
    ) {

    }

    Course * createCourse() {
      Course * temp = new FundCourse(
        title,
        code, 
        credit, 
        grade
      );
      return temp;
    }
};
