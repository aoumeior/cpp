/*************************************************************************
    > File Name: singletontest.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月21日 星期三 13时02分51秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>

class Singleton
{

private:
	static Singleton *m_pInstance;
	Singleton()
	{
	}

public:
	static Singleton *GetInstance()
	{

		if (m_pInstance == NULL)
		{
			m_pInstance = new Singleton();
			return m_pInstance;
		}
		return m_pInstance;
	}
	void out()
	{
		printf("Singleton\n");
	}
	~Singleton()
	{
		m_pInstance = NULL;
	}
};

Singleton *Singleton::m_pInstance = NULL;

int main()
{

	Singleton *sig = Singleton::GetInstance();
	sig->out();
	delete sig;
}
