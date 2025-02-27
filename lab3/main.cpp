#include <iostream>

class Worker {
private:
  string name;
  string post;
  int exp;
  int salary;

public:
  Worker(string userName = "", string userPost = "", int userExp = 0, int userSalary = 0) : name(userName), post(userPost), exp(userExp), salary(userSalary) {}
  Worker(const Worker &p) : name(p.name), post(p.post), exp(p.exp), salary(p.salary) {}
  ~Worker(){};
  void setName(const string& userName) { name = userName; }
  void setPost(const string& userPost) { post = userPost; }
  void setExp(int userExp) { exp = userExp; }
  void setSalary(int userSalary) { salary = userSalary; }

  string getName() const { return name; }
  string getPost() const { return post; }
  int getExp() const { return exp; }
  int getSalary() const { return salary; }

  void print() const 
  {
      cout << "Name: " << name << endl
           << "Post: " << post << endl
           << "Experience: " << exp << endl
           << "Salary: " << salary << endl << endl;
  }
};

class Worker : public Employee {
public:
  void setSpeciality(int spec) {
    speciality = spec;
  };

private:
  int speciality; 
};

class Engineer : public Employee {
public:
  void setSpeciality(int spec) {
    speciality = spec;
  };

private:

  int category;
  int projectsCount;
};

class Admin : public Employee{
public:
  void setSpeciality(int spec) {
    speciality = spec;
  };

private:
  int accessLvl;
}

int main() {

  return 0;
}
