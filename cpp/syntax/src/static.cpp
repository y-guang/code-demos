#include <iostream>

class ClassA
{
private:
    static int cnt;
public:
    ClassA();
    ~ClassA();
    static int getCnt() { return cnt; };
};

int ClassA::cnt = 0; // note: static member must be initialized outside class

ClassA::ClassA()
{
    cnt++;
}

ClassA::~ClassA()
{
    cnt--;
}

int main(int argc, char const *argv[])
{
    ClassA a;
    std::cout << ClassA::getCnt() << std::endl;

    {
        ClassA b;
        std::cout << ClassA::getCnt() << std::endl;
    }

    std::cout << ClassA::getCnt() << std::endl;
    
    return 0;
}
