#include <iostream>
#include "insertion_sort.cpp"
class Human
{
public:
    std::string name;
    std::string surname;
    int age;
    Human(std::string n, std::string s, int a)
    {
        this->name = n;
        this->surname = s;
        this->age = a;
    }
};

int main()
{
    Human arr[] = {Human("John","Smith",16),Human("Andrew","Brown", 25),Human("John","Snow",32),Human("Mark","Hammel",18)};
    
    for(int i = 0; i < 4; i++)
    {
        Human temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j].age > temp.age)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i = 0; i < 4;i++)
    {
        std::cout<<arr[i].name<<" "<<arr[i].surname<<" "<<arr[i].age<<std::endl;
    }
}
