#include<iostream>
using namespace std;



class Fruit{
public:
	virtual void sayname() = 0;
};
class Banana :public Fruit
{
public:
	void sayname(){
		cout << "banana" << endl;
	}
};
class Apple :public Fruit  //苹果类
{
public:
	void sayname(){
		cout << "apple" << endl;
	}
};

class AbstractFactory{
public:
	virtual Fruit* createproduct() = 0;
};

class bananaFactory :public AbstractFactory
{
public:
	virtual Fruit* createproduct()
	{
		return new Banana;
	}
};

class appleFactory :public AbstractFactory  //苹果工厂
{
public:
	virtual Fruit* createproduct(){
		return new Apple;
	}
};

///添加新的产品

class Pear :public Fruit
{
public:
	virtual void sayname(){
		cout << "Pear" << endl;
	}
};
class pearFactory :public AbstractFactory
{
public:
	virtual Fruit* createproduct()
	{
		return new Pear;
	}
};


void main(){
	AbstractFactory *factory = NULL;
	Fruit *fruit = NULL;

	factory = new bananaFactory;  //new一个对应的工厂
	fruit = factory->createproduct();
	fruit->sayname();
	delete fruit;
	delete factory;

	factory = new pearFactory;
	fruit = factory->createproduct();
	fruit->sayname();
	delete fruit;
	delete factory;
}