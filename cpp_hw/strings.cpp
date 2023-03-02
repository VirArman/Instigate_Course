#include <iostream>
std::string get_longest(std::string);
std::string get_shortest(std::string);
//std::string mytrim(std::string);
//std::string front_trim(std::string);
//std::string back_trim(std::string);
int main()
{
    std::string mstr;
    std::cout<<"Insert sentence\n";
    std::getline(std::cin,mstr);
//    mstr = mytrim(mstr);
    std::string min = get_shortest(mstr);
    std::string max = get_longest(mstr);
    std::cout<<"The longest word in sentence is "<<max<<std::endl;
    std::cout<<"The shortest word in sentence is "<<min<<std::endl;
}

std::string get_longest(std::string str)
{
    std::string max = "";
    std::string temp = ""; 
    for(int i = 0; str[i] != '\0'; i++)
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
    bool flag = true;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            if(flag)
            {
                min = temp;
                flag = false;
            }
            if(temp.size() < min.size()) 
                min = temp;
            temp = "";
        } else  temp += str[i];
    }
    return min;
}
/*
std::string mytrim(std::string str)
{
    str = front_trim(str);
    str = back_trim(str);
    return str;   
}
std::string front_trim(std::string str)
{
    bool start = false;
    int delta = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(!start && str[i] != ' ' )
        {
            start = true;
            delta = i;
        }
        if(start)
        {
            str[i-delta] = str[i];
        }
    }
    return str;
}
std::string back_trim(std::string str)
{
    bool end = false;
    int delta = 0;
    for(int i = str.size() - 1; i >= 0 ; i--)
    {
        if(!end && str[i] != ' ' )
        {
            end = true;
            delta = i - 1;
        }
        if(end)
        {
            str[i + delta] = str[i];
        }
    }
    return str;
}
*/
