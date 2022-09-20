#include <cstdio>
using namespace std;

class base {
public:
    base() { printf("call construct of base\n"); }
    virtual ~base() { printf("call destruct of base\n"); }
    virtual void push() { printf("call push of base\n"); }
    void pop() { printf("call pop of base\n"); }
};

class derived : public base {
public:
    derived() { printf("call construct of derived\n"); }
    ~derived() { printf("call destruct of derived\n"); }
    void push() override { printf("call push of derived\n"); }
    void pop() { printf("call pop of derived\n"); }
};

int main()
{
    base* b = new derived;
    b->push();
    b->pop();
    delete b;
    return 0;
}