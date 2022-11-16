#include <iostream>
#include <cstdio>


class BASE
{
public:
    void f1()
    {
    	printf("1");
    	f2();
    }

    virtual void f2()
    {
		printf("2");
    }
};

class CHILD: public BASE
{
public:
    void f1()
    {
		printf("3");
		BASE::f2();
    }

    virtual void f2()
    {
    	printf("4");
    }
};

int main()
{
    CHILD o;
    BASE *b = &o;
    b->f1();
    b->f2();
    return 0;
}
