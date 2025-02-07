#include <iostream>
#include <cstring>
using namespace std;
class worker{
  private:
    string name;
    string post;
    int exp;
    int salary;
  public:
    worker(): name(""), post(""), exp(0), salary(0) {}
    worker(string &userName, string &userPost, int userExp, int userSalary)
    {
        name = userName;
        post = userPost;
        exp = userExp;
        salary = userSalary;
    }
    worker(worker &p)
    {
      name = p.name;
      post = p.post;
      exp = p.exp;
      salary = p.salary;
    }
    ~worker(){};
	
    void setName(string &userName)
    {
      name=userName;
    }
    void setPost(string &userPost)
    {
      post=userPost;
    }
    void setExp(int userExp)
    {
      exp=userExp;
    }
    void setSalary(int userSalary)
    {
      salary=userSalary;
    }
    string getName()
    {
      return name;
    }
    string getPost()
    {
      return post;
    }
    int getExp()
    {
      return exp;
    }
    int getSalary()
    {
      return salary;
    }

    void print()
    {
        cout << "Name: " << name << endl
			 << "Post: " << post << endl
			 << "Expirience: " << exp << endl
			 << "Salary: " << salary << endl << endl;
    }

};
int main()
{
  int size = 50;
  worker p[size];
  for(int i = 0; i < size; i++)
  {
      string name = to_string(rand() % 20+1);
      string post = to_string(rand() % 10+1);
      p[i].setName(name);
      p[i].setPost(post);
      p[i].setExp(rand() % 15);
      p[i].setSalary(rand() % 100);
  }
  
  int exp;
  cout << "Please enter expirience to filter" << endl;
  cin >> exp;
  for(int i = 0;i < 50; i++)
  {
    if(p[i].getExp() > exp) {
		p[i].print();
	}
	else {
		continue;
	}
  }
  cout << "--------END-TASK-1--------\n" << endl;
  
  int salary;
  cout << "Please enter salary to filter" << endl;
  cin >> salary;
  
  for(int i = 0; i < 50; i++)
  {
    if(p[i].getSalary()>salary) {
		p[i].print();
	}
	else {
		continue;
	}
  }
  cout << "--------END-TASK-2--------\n" << endl;
  
  string post;
  cout << "Please enter post to filter" << endl;
  cin >> post;
  
  for(int i=0;i<50;i++)
  {
    if(p[i].getPost() == post) {
		p[i].print();
    }
	else {
		continue;
	}
  }
  cout << "--------END-TASK-3--------\n" << endl;
  return 0;
}
