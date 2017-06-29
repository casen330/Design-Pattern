#include<iostream>
using namespace std;


//Ä¿±ê
class Current18v{
public:
	virtual void use18v() = 0;
};

//Ô´
class Current220v{
public:
	void use220v(){
		cout << "use 220v" << endl;
	}

};

//ÊÊÅäÆ÷
class Adapter :public Current18v{
public:
	Adapter(Current220v *current220v){
		m_current = current220v;
	}
	virtual void use18v(){
		cout << "Adapter,adapt 220v" << endl;
		m_current->use220v();
	}
private:
	Current220v *m_current;
};

int main(){
	Current220v *curr = new Current220v;
	Adapter *ad = new Adapter(curr);

	ad->use18v();

	delete curr;
	delete ad;

	return 0;
}