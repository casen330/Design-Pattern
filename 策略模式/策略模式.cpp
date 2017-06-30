#include<iostream>
using namespace std;

class Strategy
{
public:
	virtual void crypt() = 0;
};

//对称加密：速度快，适合加密大数据文件。特点：加密秘钥和解密秘钥是一样的
//非对称加密：速度慢，加密强度高，安全性高。特点：加密秘钥和解密秘钥不一样。秘钥分为密钥对，分为公钥和私钥。
class AES :public Strategy
{
public:
	virtual void crypt(){
		cout << "AES 加密算法" << endl;
	}
};
class DES :public Strategy
{
public:
	virtual void crypt(){
		cout << "DES 加密算法" << endl;
	}
};

//上下文
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
	
	//使用上下文执行算法
	context = new Context(strategy);
	context->myOperator();

	delete context;
	delete strategy;
	delete strategy2;

	return 0;
}