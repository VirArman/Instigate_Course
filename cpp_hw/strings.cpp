#include <iostream>
#include <string>
#include "trim.cpp"
std::string get_longest(std::string);
std::string get_shortest(std::string);
int main()
{
    std::string mstr, same = "";
    std::cout<<"Insert sentence\n";
    std::getline(std::cin,mstr);
    mstr = mytrim(mstr);
    std::string min = get_shortest(mstr);
    std::string max = get_longest(mstr);
    for(int i = 0; i < min.size(); i++)
    {
        for(int j = i; j<max.size(); j++)
        {
            if(min[i] == max[j]) 
            {
                same += min[i];
                break;
            }
        }
    }
    std::cout<<"The longest word in sentence is "<<max<<std::endl;
    std::cout<<"The shortest word in sentence is "<<min<<std::endl;
    std::cout<<"The same letters used in longest and shortest words "<<same<<std::endl;
}

std::string get_longest(std::string str)
{
    std::string max = "";
    std::string temp = ""; 
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ') temp = "";
        else temp += str[i];
        if(temp.size() > max.size()) max = temp;
        
    }
 return max;
}

std::string get_shortest(std::string str)
{
    std::string min;
    std::string temp = "";
    bool first_word = true;
    for(int i = 0; i < str.size(); i++)
    {   
        bool new_word = false;
        if(str[i] == ' ')
        {
            if(first_word)
            {
                min = temp;
                first_word = false;
            }
            new_word = true;
        }else  temp += str[i];
        if(i == str.size()-1) new_word = true;
        if(new_word && temp.size() < min.size()) min = temp;
        if(new_word) temp = "";
    }
    return min;
}
