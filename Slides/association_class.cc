#include <iostream>

using namespace std;

class Student;

class Department
{
  private:
    string name_p;

  public:
    Department(const string& dName)
        : name_p(dName) {
      cout << "Department::ctor\n";
    }

    string dName() const {
      return name_p;
    }

    ~Department() {
      cout << "Department::dtor\n";
    }

};

class Student {
  private:
    string name_p;

  public:
    Student(const string& sName)
        : name_p(sName) {
      cout<<"Student::ctor\n";
    }

    string sName()const {
      return name_p;
    }
    
    ~Student() {
      cout<<"Student::dtor\n";
    }
};


class Course {
  private:
    Student * std_p;
    Department * dept_p;
    string courseName_p;

    static unsigned int index;
    static Course *courseList[4];

  public:  
    Course(string crseName, Student* student, Department* dept):
      courseName_p(crseName), std_p(student), dept_p(dept) {
      cout<<"Course:ctor\n";

      if (index < 4) {        
        //insert this Course in courseList
        courseList[index] = this;
        ++index;
      } else {
        cout<<"Cannot accomodate any more Course\n";
      }
    };

    ~Course() { 
      cout<<"Course:dtor\n";
    };

    static string findStudent(const string& crseName, const string& deptName) {
      for(int i=0; i<index; i++) {
        if ( (courseList[i]->getCourseName() == crseName) && 
             (courseList[i]->getDeptName() == deptName) ) {
          return(courseList[i]->getStdName());
        }
      }
    }

    string getStdName()const {
      return(std_p->sName());
    }
    string getDeptName() const {
      return(dept_p->dName());
    }
    string getCourseName()const {
      return(courseName_p);
    }
}; 

// static
unsigned int Course::index = 0;

// static
Course* Course::courseList[4] = {0,0,0,0};

int main() {
  int i;

  cout << "\nExample of Association class...\n";
  cout << "-----------------------------------\n\n";

  cout << "We have got 4 students ...\n";
  Student *studentNames[4] = {
              new Student("Meera"),
              new Student("Moina"),
              new Student("Teena"),
              new Student("Mridula")
            };

  cout<<"\n";

  cout<<"We have got 2 Departments...\n";
  Department *departNames[2] = {
              new Department("Mathemetics"),
              new Department("ComputerSceince")
            };
  
  cout<<"\n";

  cout<<"Here class Course Associates Student and Department, with a Course name ...\n";
  Course course1("DataStructure", studentNames[0], departNames[1]);
  Course course2("Maths", studentNames[3], departNames[0]);
  Course course3("Geometry", studentNames[2], departNames[0]);
  Course course4("CA", studentNames[1], departNames[1]);

  cout<<"\n";

  cout<<"Finding a Student using Course and Department...\n";
  cout<<"Student who has taken Maths Course in Mathemetics Department is:"<<
        Course::findStudent("Maths", "Mathemetics")<<endl;
  
  cout<<"\n";

  cout<<"Deletion of objects...\n\n";

  for(i=0; i<4; ++i) {
    delete studentNames[i];
  }

  cout<<"\n";

  for(i=0; i<2; ++i) {
    delete departNames[i];
  }

  cout<<"\n";

  return 0;
}

// output:
// ------

// Example of Association class...
// -----------------------------------

// We have got 4 students ...
// Student::ctor
// Student::ctor
// Student::ctor
// Student::ctor

// We have got 2 Departments...
// Department::ctor
// Department::ctor

// Here class Course Associates Student and Department, with a Course name ...
// Course:ctor
// Course:ctor
// Course:ctor
// Course:ctor

// Finding a Student using Course and Department...
// Student who has taken Maths Course in Mathemetics Department is:Mridula

// Deletion of objects...

// Student::dtor
// Student::dtor
// Student::dtor
// Student::dtor

// Department::dtor
// Department::dtor

// Course:dtor
// Course:dtor
// Course:dtor
// Course:dtor