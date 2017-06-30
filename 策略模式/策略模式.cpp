#include<iostream>
using namespace std;

class Strategy
{
public:
	virtual void crypt() = 0;
};

//�ԳƼ��ܣ��ٶȿ죬�ʺϼ��ܴ������ļ����ص㣺������Կ�ͽ�����Կ��һ����
//�ǶԳƼ��ܣ��ٶ���������ǿ�ȸߣ���ȫ�Ըߡ��ص㣺������Կ�ͽ�����Կ��һ������Կ��Ϊ��Կ�ԣ���Ϊ��Կ��˽Կ��
class AES :public Strategy
{
public:
	virtual void crypt(){
		cout << "AES �����㷨" << endl;
	}
};
class DES :public Strategy
{
public:
	virtual void crypt(){
		cout << "DES �����㷨" << endl;
	}
};

//������
class Context
{
public:
	Context(Strategy *s)
	{
		m_strategy = s;
	}
	void myOperator(){
		m_strategy->crypt();
	}
private:
	Strategy *m_strategy;
};



int main(){

	Context *context = NULL;
	Strategy *strategy = new DES;
	Strategy *strategy2 = new AES;
	
	//ʹ��������ִ���㷨
	context = new Context(strategy);
	context->myOperator();

	delete context;
	delete strategy;
	delete strategy2;

	return 0;
}