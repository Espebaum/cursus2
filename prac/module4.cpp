#include <iostream>

void	leakcheck(void)
{
	system("leaks a.out");
}

class Parent{
	public:
		void show(){
			printf("this is parent\n");
		}
};

class Child : public Parent{
	public:
		void show(){
			printf("this is child\n");
		}
};

class ChildChild : public Child{
	public:
		void show(){
			printf("this is childchild\n");
		}
};

int main(){
	
	atexit(leakcheck);

    Parent * p = new Parent;
    Child * c = new Child;
    ChildChild * cc = new ChildChild;

    p->show();
    c->show();
    cc->show();

	delete	p;
	delete	c;
	delete	cc;
}

