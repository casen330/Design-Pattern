#include<iostream>
using namespace std;

class SubSystemA
{
public:
	void doThing(){
		cout << "SubSystemA run..." << endl;
	}
};
class SubSystemB
{
public:
	void doThing(){
		cout << "SubSystemB run..." << endl;
	}
};
class SubSystemC
{
public:
	void doThing(){
		cout << "SubSystemC run..." << endl;
	}
};
//外观模式包裹子系统
class Facde{
public:
	Facde(){
		sysA = new SubSystemA;
		sysB = new SubSystemB;
		sysC = new SubSystemC;
	}
	~Facde(){
		delete sysA;
		delete sysB;
		delete sysC;
	}
	void doThing(){
		sysA->doThing();
		sysB->doThing();
		sysC->doThing();
	}
private:
	SubSystemA *sysA;
	SubSystemB *sysB;
	SubSystemC *sysC;
};


int main(){

	Facde *facde = new Facde;
	facde->doThing();
	delete facde;

	return 0;
}