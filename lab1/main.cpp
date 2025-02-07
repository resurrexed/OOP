#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Worker {
private:
    string name;
    string post;
    int exp;
    int salary;

public:
    Worker() : name(""), post(""), exp(0), salary(0) {}
    Worker(string userName = "", string userPost = "", int userExp = 0, int userSalary = 0) : name(userName), post(userPost), exp(userExp), salary(userSalary) {}
    Worker(worker &p) : name(p.name), post(p.post), exp(p.exp), salary(p.salary);
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

int main() {
    srand(time(NULL));
    const int SIZE = 50;
    vector<Worker> workers(SIZE);

    string names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    string posts[] = {"Engineer", "Manager", "Analyst", "Developer", "Designer"};

    for (int i = 0; i < SIZE; ++i) 
    {
        workers[i].setName(names[rand() % 5]);
        workers[i].setPost(posts[rand() % 5]);
        workers[i].setExp(rand() % 15 + 1);
        workers[i].setSalary(rand() % 100 + 1);
    }


    int exp;
    cout << "Enter experience to filter: ";
    cin >> exp;

    for (const auto& worker : workers) 
    {
        if (worker.getExp() > exp) 
	{
            worker.print();
        }
    }

    cout << "--------END-TASK-1--------\n" << endl;


    int salary;
    cout << "Enter salary to filter: ";
    cin >> salary;

    for (const auto& worker : workers) 
    {
        if (worker.getSalary() > salary) 
	{
            worker.print();
        }
    }

    cout << "--------END-TASK-2--------\n" << endl;

    string post;
    cout << "Enter post to filter: ";
    cin >> post;

    for (const auto& worker : workers) 
    {
        if (worker.getPost() == post) 
	{
            worker.print();
        }
    }

    cout << "--------END-TASK-3--------\n" << endl;

    return 0;
}
