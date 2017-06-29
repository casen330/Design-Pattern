#include<iostream>
using namespace std;

//������
class Subject{
public:
	virtual void sailbook() = 0;

};
//�������
class RealSubject :public Subject{
public: 
	virtual void sailbook(){
		cout << "sail book..." << endl;
	}
};

//����������
class dangdangProxy :public Subject{
public:
	virtual void sailbook(){
		RealSubject *rsb = new RealSubject;
		discount();
		rsb->sailbook();
	}
	void discount(){
		cout << "˫ʮһ����" << endl;
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