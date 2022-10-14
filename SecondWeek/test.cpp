#include <iostream>
using namespace std;

class Singleton // 单例模式
{
public:
    static Singleton* getInstance()
    {
        if (instance == nullptr) // 单重检查
        {
            instance = new Singleton();
        }
        return instance;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

private:
    Singleton(){};
    static Singleton* instance;
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;
    Singleton(Singleton&& other) = delete;
    string name;
};

int main()
{
    Singleton* s1 = Singleton::getInstance();

    return 0;
}