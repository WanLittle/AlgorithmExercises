#pragma once
#include "../BASE.h"

class S_2_Singleton : public BASE {
public:
	virtual void main()
	{
	}
    // 线程安全的单例模式
    class Singleton
    {
    private:
        Singleton() { }
        ~Singleton() { }
    public:
        static Singleton* GetInstance()
        {
            static Singleton* pInstance;
            if (pInstance == nullptr)
                pInstance = new Singleton();
            return pInstance;
        }
    };
};