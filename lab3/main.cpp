#include <iostream>
#include <string> 
using namespace std;
class Employee {
protected:
  string name;
  string post;
  int exp;
  int salary;

public:
  Employee(string userName = "", string userPost = "", int userExp = 0, int userSalary = 0) : name(userName), post(userPost), exp(userExp), salary(userSalary) {}
  Employee(const Employee &p) : name(p.name), post(p.post), exp(p.exp), salary(p.salary) {}
  ~Employee(){};
  void setName(const string& userName) { name = userName; }
  void setPost(const string& userPost) { post = userPost; }
  void setExp(int userExp) { exp = userExp; }
  void setSalary(int userSalary) { salary = userSalary; }

  string getName() const { return name; }
  string getPost() const { return post; }
  int getExp() const { return exp; }
  int getSalary() const { return salary; }

  virtual void print() const 
  {
      cout << "Name: " << name << endl
           << "Post: " << post << endl
           << "Experience: " << exp << endl
           << "Salary: " << salary << endl;
  }
  
};

class Worker : public Employee {
public:
  using Employee::Employee;
  
  void setSpeciality(int spec) {
    speciality = spec;
  };
  void print() const override {
	Employee::print();
	cout << "Spec: " << speciality << endl;
  }
  
private:
  int speciality; 
};

class Engineer : public Employee {
public:
  using Employee::Employee;

  void setCategory(int cat) {
    category = cat;
  };
  void setProjectsCount(int prjctCounts) {
    projectsCount = prjctCounts;
  };
  void print() const override {
	Employee::print();
	cout << "Category: " << category << endl
		 << "Projects Count: " << projectsCount << endl;
  }
  
private:
  int category;
  int projectsCount;
};

class Admin : public Employee{
public:
  using Employee::Employee;
  void setAccessLvl(int lvl) {
    accessLvl = lvl;
  };
  void print() const override {
	Employee::print();
	cout << "Access Lvl: " << accessLvl << endl;
  }

private:
  int accessLvl;
};

int main() {
	Worker work1("glebas", "322", 10 , 5);
	work1.setSpeciality(33);
	work1.print();
	
	
	cout << endl;
	
	Engineer eng1;
	eng1.setName("Egorus");
	eng1.setCategory(12);
	eng1.setProjectsCount(52);
	eng1.print();
	
	cout << endl;
	
	Admin adm1;
	adm1.setName("Kirillus");
	adm1.setAccessLvl(5);
	adm1.print();

	
  return 0;
}
