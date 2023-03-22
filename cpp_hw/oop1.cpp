#include <iostream>
#include "insertion_sort.cpp"
class Human
{
    std::string name;
    std::string surname;
    int age;
public:
//Constructors    
    Human()
    {
        name = "";
        surname = "";
        age = 0;
    }
    Human(std::string n, std::string s, int a)
    {
        this->name = n;
        this->surname = s;
        this->age = a;
    }

//Overloaded Operators
    friend std::ostream& operator<<(std::ostream& os, const Human& h)
    {
        os<<h.name<<" "<<h.surname<<" "<<h.age;
        return os;
    }

    bool operator>(const Human& other)
    {
        return this->age > other.age;
    }
    bool operator<(const Human& other)
    {
        return this->age < other.age;
    }
//Getters and Setters
    void set_age(int value)
    {
        age = value;
    }
    void set_name(std::string value)
    {
        name = value;
    }
    void set_surname(std::string value)
    {
        surname = value;
    }
    int get_age()
    {
        return age;
    }
    std::string get_name()
    {
        return name;
    }
    std::string get_surname()
    {
        return surname;
    }
};

int main()
{
    Human arr[] = {Human("John","Smith",16),Human("Andrew","Brown", 25),Human("John","Snow",32),Human("Mark","Hammel",18)};
    
    for(int i = 0; i < 4; i++)
    {
        Human temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i = 0; i < 4;i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
}
