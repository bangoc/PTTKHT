#include <iostream>

using namespace std;

class Employee {
  private:
    string myName_p;

  public:
    Employee(const string& name)
        : myName_p(name) {
      cout<<"Employee::ctor\n";
    }    

    string disp() {
      return myName_p;
    }

    ~Employee() {
      cout<<"Employee:dtor\n\n";
    }
};

class Company {
  private:
    string name;
    Employee *myEmp_p;

  public:
    Company(const string& compName, Employee* emp) {
      cout<<"Company::ctor\n";
      name = compName;
      myEmp_p = emp;
    }

    ~Company() {
      cout<<"Company:dtor\n\n";
      myEmp_p = NULL;
    }
};


int main() {
  cout<<"\nExample of Aggregation Relationship \n";
  cout<<"-----------------------------------------\n\n";
  {
    cout<<"Here, an Employee-Keerti works for Company-MS \n";
    Employee emp("Keerti");
  
    {
      Company comp("MS", &emp);
    } // here Company object will be deleted, whereas Employee object is still there

    cout<<"At this point Company gets deleted...\n";
    cout<<"\nBut Employee-"<<emp.disp();
    cout<<" is still there\n";
    
  } //here Employee object will be deleted

  return 0;
}

// output:
// -------

// Example of Aggregation Relationship 
// -----------------------------------------

// Here, an Employee-Keerti works for Company-MS 
// Employee::ctor
// Company::ctor
// Company:dtor

// At this point Company gets deleted...

// But Employee-Keerti is still there
// Employee:dtor