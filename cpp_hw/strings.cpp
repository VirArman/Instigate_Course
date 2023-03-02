#include <iostream>
int main()
{
    std::string mstr,max = "", min, temp = "";
    std::cout<<"Insert sentence\n";
    std::getline(std::cin,mstr);
    for(int i = 0; mstr[i] != '\0'; i++)
    {
        if(mstr[i] == ' ')
        {
            temp = "";
        } else
        {
            temp += mstr[i];
        }
        if(temp.size() > max.size())
        {
            max = temp;
        }
        
    }
    temp = "";
    min = max;
    for(int i = 0; mstr[i] != '\0'; i++)
    {
        if(mstr[i] == ' ')
        {
            temp = "";
        } else
        {
            temp += mstr[i];
        }
        
        if(temp.size() < min.size())
        {
            min = temp;
        }
    }
   
    std::cout<<"The longest word in sentence is "<<max<<std::endl;
    std::cout<<"The shortest word in sentence is "<<min<<std::endl;
}
