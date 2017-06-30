#include<iostream>
using namespace std;

class Context
{
public:
	Context(int n){
		m_num = n;
	}
	int getNum(){
		return m_num;
	}
	void setNum(int n)
	{
		m_num = n;
	}
	int getRes(){
		return m_res;
	}
	void setRes(int res)
	{
		m_res = res;
	}
private:
	int m_num;
	int m_res;
};
//解释器抽象
class Express
{
public:
	virtual void interpreter(Context *c) = 0;
protected:
	Context *m_context;
};
//加法解释器
class PlusExpression :public Express
{
public:
	PlusExpression()
	{
		m_context = NULL;
	}
	void interpreter(Context *c){
		int num = c->getNum();
		num++;
		c->setNum(num);
		c->setRes(num);
	}
};
//减法解释器
class MinusExpression :public Express
{
public:
	MinusExpression()
	{
		m_context = NULL;
	}
	void interpreter(Context *c){
		int num = c->getNum();
		num--;
		c->setNum(num);
		c->setRes(num);
	}
};
int main(){
	Express *expressPlus = NULL;
	Express *expressMina = NULL;
	Context *context = NULL;
	expressPlus = new PlusExpression;
	expressMina = new MinusExpression;
	context = new Context(11);
	cout << context->getNum() << endl;

	expressMina->interpreter(context);
	cout << context->getRes() << endl;

	context = new Context(11);
	cout << context->getNum() << endl;
	expressPlus->interpreter(context);
	cout << context->getRes() << endl;

	delete expressPlus;
	delete context;
	delete expressMina;

	return 0;
}