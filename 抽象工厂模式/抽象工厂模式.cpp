#include<iostream>
using namespace std;

class AbstractFruit{
public:
	virtual void sayName() = 0;
};

class AbstractFactory{
public:
	virtual AbstractFruit * createBanana() = 0;
	virtual AbstractFruit * createApple() = 0;
};


class NorthBanana :public AbstractFruit{
public:
	virtual void sayName(){
		cout << "North Banana" << endl;
	}
};
class NorthApple :public AbstractFruit{
public:
	virtual void sayName(){
		cout << "North Apple" << endl;
	}
};

class SouthBanana :public AbstractFruit{
public:
	virtual void sayName(){
		cout << "South Banana" << endl;
	}
};
class SouthApple :public AbstractFruit{
public:
	virtual void sayName(){
		cout << "South Apple" << endl;
	}
};


class NorthFactory :public AbstractFactory{
	 AbstractFruit *createBanana(){
		 return new NorthBanana;
	}
	 AbstractFruit *createApple(){
		 return new NorthApple;
	 }
};

class SouthFactory :public AbstractFactory{
	AbstractFruit *createBanana(){
		return new SouthBanana;
	}
	AbstractFruit *createApple(){
		return new SouthApple;
	}
};



int main(){
	AbstractFactory *factor = NULL;
	AbstractFruit *fruit = NULL;
	
	factor = new SouthFactory;
	fruit = factor->createApple();
	fruit->sayName();
	delete fruit;
	fruit = factor->createBanana();
	fruit->sayName();
	delete fruit;



	delete factor;
	return 0;
}