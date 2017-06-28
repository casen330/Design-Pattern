#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;
private:
};

class Banana : public Fruit
{
public:
	virtual void getFruit(){
		cout << "Banana" << endl;
	}
};

class Apple :public Fruit
{
public:
	virtual void getFruit(){
		cout << "Apple" << endl;
	}
};

class Factory
{
public:
	Fruit *create(char *p){
		if (strcmp(p,"Banana")==0)
		{
			return new Banana;
		}
		else if (strcmp(p, "Apple")==0)
		{
			return new Apple;
		}
		else
		{
			cout << "Not port" << endl;
		}
	}
};

void main(){
	Factory *f = new Factory;
	Fruit *fruit = NULL; //����һ��ָ���������ĸ���ָ�������
	fruit = f->create("Banana");
	fruit->getFruit();
	delete fruit;
	
	fruit = f->create("Apple");
	fruit->getFruit();
	delete fruit;
	delete f;
}

