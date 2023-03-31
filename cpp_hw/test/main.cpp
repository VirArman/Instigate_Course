#include <iostream>
#include <fstream>

int digit_sum(int num);
int inverse_num(int num);
bool isfloating(std::string line);
int getting_digits(std::string line);

int main(int argc, char* argv[])
{
    //checking the existance of testing flag
    if(argv[1][0] == '-' && argv[1][1] == 't')
    {//testing mod
        std::string input = argv[2];
        std::string output = argv[3];
        std::ifstream input_file(input);
        std::ofstream output_file(output);
        int num;
        std::string line;
        while (getline (input_file, line)) 
        {//Reading from file 
            try
            {
                if(isfloating(line))
                    throw 1;
                num = getting_digits(line);
                output_file << digit_sum(num) << "\n";
            }
            catch(int err)
            {
                if(err == 1)
                    output_file << "The program works only with integers" << "\n";
            }
        }
        output_file.close();
        input_file.close();
    }else
    {//user mod
        //work in progress
    }
    return 0;
}
bool isfloating(std::string line)
{//Check if the line contains numbers with floating point
    for(int i = 1; i < line.size() + 1; i++)
    {
        if(isdigit(line[i-1]) && line[i] == '.' && isdigit(line[i+1]))
        {
            return true;
        }
    }
    return false;
}
int getting_digits(std::string line)
{//finds digits from line, concatinates them and creates integer
    int num = 0;
    for(int i = 0; i < line.size(); i++)
    {
        if(isdigit(line[i]))
        {
            num *= 10;
            num += line[i]-48;
        }
    }
    if(line[0] == '-') num *= -1;
    return num;
}
int digit_sum(int num)
{//counts sum of digits
    int sum = 0;
    if(num > 0)
    {
        while(num > 0)
        {
            sum += num % 10;
            num = num / 10;
        }
    }else
    {
        while(num < 0)
        {
            sum += num % 10;
            num = num / 10;
        }
        sum = abs(sum);
    }
    
    return sum;
}
int inverse_num(int num)
{
    int new_num = 0;
    while(num > 0)
    {
        new_num *= 10;
        new_num += num % 10;
        num /= 10;
    }
    return new_num;
}