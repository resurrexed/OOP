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
    worker(string &_name, string &_post, int _exp, int _salary)
    {
        name=_name;
        post=_post;
        exp=_exp;
        salary=_salary;
    }
    worker(worker &p)
    {
      name=p.name;
      post=p.post;
      exp=p.exp;
      salary=p.salary;
    }
    ~worker(){};
    void setname(string &_name)
    {
      name=_name;
    }
    void setpost(string &_post)
    {
      post=_post;
    }
    void setexp(int _exp)
    {
      exp=_exp;
    }
    void setsalary(int _salary)
    {
      salary=_salary;
    }
    string getname()
    {
      return name;
    }
    string getpost()
    {
      return post;
    }
    int getexp()
    {
      return exp;
    }
    int getsalary()
    {
      return salary;
    }

    void Print()
    {
        cout<<"Name- "<<name<<"\nPost- "<<post<<"\nExpirience- "<<exp<<"\nSalary- "<<salary<<"\n"<<endl;
    }

};
int main()
{
  int size=50;
  worker p[size];
  for(int i=0;i<size;i++)
  {
      string name=to_string(rand() % 20+1);
      string post=to_string(rand() % 10+1);
      p[i].setname(name);
      p[i].setpost(post);
      p[i].setexp(rand() % 15);
      p[i].setsalary(rand() % 100);
  }
  cout<<"Please enter expirience, salary and post to filter"<<endl;
  int exp,salary;
  string post;
  cin>>exp>>salary>>post;
  for(int i=0;i<50;i++)
  {
    if(p[i].getexp()>exp) p[i].Print();
    else continue;
  }
  cout<<"End of 1 task"<<endl;
  for(int i=0;i<50;i++)
  {
    if(p[i].getsalary()>salary) p[i].Print();
    else continue;
  }
  cout<<"End of 2 task"<<endl;
  for(int i=0;i<50;i++)
  {
    if(p[i].getpost()==post) p[i].Print();
    else continue;
  }
  cout<<"End of work";
  return 0;
}
