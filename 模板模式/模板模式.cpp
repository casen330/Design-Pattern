#include<iostream>
using namespace std;

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

	void Make() //模板函数,把业务逻辑做好了，
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
};

class Jeep :public MakeCar
{
public:
	virtual void MakeHead(){
		cout << "jeep head" << endl;
	}
	virtual void MakeBody(){
		cout << "Jeep body" << endl;
	}
	virtual void MakeTail(){
		cout << "Jeep tail" << endl;
	}
};

class Bus :public MakeCar
{
public:
	virtual void MakeHead(){
		cout << "Bus head" << endl;
	}
	virtual void MakeBody(){
		cout << "Bus body" << endl;
	}
	virtual void MakeTail(){
		cout << "Bus tail" << endl;
	}
};

int main(){
	MakeCar *car = new Bus;
	car->Make();
	delete car;

	MakeCar *car2 = new Jeep;
	car2->Make();
	delete car2;
	return 0;
}

