#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class Worker {
friend class Observer;
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
	
    bool operator == (const Worker& worker) const
    {
        return (name == worker.name &&
				post == worker.post && 
				exp == worker.exp && 
				salary == worker.salary);
    }
	
    bool operator != (const Worker& worker) const
    {
        return (name != worker.name ||
				post != worker.post || 
				exp != worker.exp || 
				salary != worker.salary);
    }
	
    Worker& operator = (const Worker& worker)
    {
        name = worker.name;
	post = worker.post;
	exp = worker.exp;
	salary = worker.salary;
    	return *this;
    }
    Worker& operator + (Worker& worker) 
    {
	name += worker.name;
	post += worker.post;
	exp += worker.exp;
	salary += worker.salary;
	return *this;
    }
};

class Observer{
public:
    void printName(Worker& worker) {
	cout << worker.name << endl;
    }

};



int main() {
    Worker worker1 {};
    Worker worker2 {"Gleb", "Engineer", 3, 3};
    
    cout << (worker1 == worker2) << endl;
    cout << (worker1 != worker2) << endl;
    
    worker1.print();
    worker2.print();
    
    worker1 = worker2;
    cout << "after" << endl << endl;
    worker1.print();
    worker2.print();
    
    Observer obs;
    obs.printName(worker2);

    Worker w3 {"Egor", "Director", 3, 7};
    Worker w4 {"Kirill", "Junior", 5, 9};
    Worker w5 {};
    w5 = w3 + w4;
    w5.print(); 
    return 0;
}
