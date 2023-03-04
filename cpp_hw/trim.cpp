std::string mytrim(std::string);
std::string front_trim(std::string);
std::string back_trim(std::string);

std::string mytrim(std::string str)
{
    str = front_trim(str);
    str = back_trim(str);
    return str;   
}
std::string front_trim(std::string str)
{
    bool start = false;
    std::string res = "";
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!start && str[i] != ' ') start = true;
        if(start) res += str[i];
    }
    return res;
}
std::string back_trim(std::string str)
{
    std::string res = "";
    int count = 0;
    for(int i = str.size() - 1; str[i] == ' ' ; i--) count++;
    for(int i = 0; i < str.size()-count; i++)
    {
        res += str[i];
    }
    return res;
}
