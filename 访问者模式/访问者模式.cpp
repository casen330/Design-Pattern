#include<iostream>
#include<list>
using namespace std;

class ParkElement;

//�����ߣ�����
class Visitor
{
public:
	virtual void visit(ParkElement *p) = 0;
};
//Ԫ�ز��֣�����
class ParkElement
{
public:
	virtual void accept(Visitor *v) = 0;
};

//���幫԰����
class ParkA :public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);  //��԰���շ����߷��ʣ��÷����߷���
	}
};
class ParkB :public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);  //��԰���շ����߷��ʣ��÷����߷���
	}
};

//������԰
class Park :public ParkElement
{
public:
	Park(){
		m_list.clear();
	}
	void setParkElement(ParkElement *p){
		m_list.push_back(p);
	}
	void accept(Visitor *v)
	{
		for (list<ParkElement *>::iterator it = m_list.begin();
			it != m_list.end(); it++)
		{
			//����������һ����˼
			(*it)->accept(v); //��԰A���֣�B���ֽ��չ����߷���
			v->visit(*it);  //�����߷���A���֣�B����
		}
	}
private:
	list<ParkElement *> m_list;
};



//���������
class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "��๤A ��� ��԰A���ֵĴ�ɨ��" << endl;
	}
};
class VisitorB :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "��๤B ��� ��԰A���ֵĴ�ɨ��" << endl;
	}
};

//������
class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement *p)
	{
		cout << "�����߷��ʹ�԰�ĸ�������" << endl;
	}
};

void main1(){
	Visitor *vA = NULL;
	Visitor *vB = NULL;
	ParkElement *pA = NULL;
	ParkElement *pB = NULL;
	vA = new VisitorA;
	vB = new VisitorB;
	pA = new ParkA;
	pB = new ParkB;

	pA->accept(vA);
	pB->accept(vB);

	delete vA;
	delete vB;
	delete pA;
	delete pB;
}

void main2(){
	Visitor *vM = NULL;
	Park *p = NULL;
	ParkElement *pA = NULL;
	ParkElement *pB = NULL;
	vM = new ManagerVisitor;
	p = new Park;
	pA = new ParkA;
	pB = new ParkB;
	p->setParkElement(pA);
	p->setParkElement(pB);
	//������԰���� �����߷���
	p->accept(vM);
	delete vM;
}


int main(){
	//main1();
	main2();
	return 0;
}