#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Counter{
    friend class Observer;
private:
    int value=5;

public:
    bool operator == (const Counter& counter) const
    {
	return value ==counter.value;
    }
    bool operator != (const Counter& counter) const
    {
        return value != counter.value;
    }
    Counter& operator = (const Counter& counter)
    {
        value = counter.value;
        return *this;   // возвращаем ссылку на текущий объект
    }
};
class Observer{
public:
    void GetInfo(Counter &data)
    {
        cout<<data.value<<endl;
    }
};

int main()
{
    Counter data;
    Observer obs;
    obs.GetInfo(data);
    return 0;	
}
