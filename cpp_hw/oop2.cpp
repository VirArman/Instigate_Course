#include <iostream>

class Human
{
protected:
    std::string name;
    std::string surname;
    int age;
public:
    Human()
    {
        name = "";
        surname = "";
        age = 0;
    }
    Human(std::string n, std::string s, int a)
    {
        name = n;
        surname = s;
        age = a;
    }
};

class Employee:public Human
{
protected:
    int exp;
};


int main()
{

}
