#include<iostream>
using namespace std;

//书店抽象
class Subject{
public:
	virtual void sailbook() = 0;

};
//具体书店
class RealSubject :public Subject{
public: 
	virtual void sailbook(){
		cout << "sail book..." << endl;
	}
};

//代理，当当网
class dangdangProxy :public Subject{
public:
	virtual void sailbook(){
		RealSubject *rsb = new RealSubject;
		discount();
		rsb->sailbook();
	}
	void discount(){
		cout << "双十一打折" << endl;
	}
private:
	Subject *m_subject;
};

int main(){
	Subject *s = new dangdangProxy;
	s->sailbook();
	delete s;
	return 0;
}