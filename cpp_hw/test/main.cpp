#include <iostream>
#include <fstream>

int digit_sum(int num);
int inverse_num(int num);
bool isfloating(std::string line);
int getting_digits(std::string line);
bool non_digit(std::string line);

int main(int argc, char* argv[])
{
    if(argv[1] == NULL)
    {//user mod
        try
        {
            std::cout << "Insert number " << "\n";
            std::string line = "";
            std::cin >> line;
            int num = 0;
            if(isfloating(line))
                throw 1;
            num = getting_digits(line);
            std::cout << digit_sum(num) << "\n";
        }
        catch(int err)
        {
            if(err == 1)
                std::cout << "The program works only with integers" << "\n";
        }
    }//checking the existance of testing flag
    else if(std::string(argv[1]) == "-t")
    {//testing mod
        std::ofstream output_file(argv[3]);
        output_file.clear();
        try
        {
            std::ifstream input_file(argv[2]);
            if(!input_file)
            {
                std::cout << "Input file does not exist" << "\n";
                throw 1;
            } 
            int num;
            std::string line;
            while (getline (input_file, line)) 
            {//Reading from file and writeing results in output file 
                try
                {
                    if(isfloating(line))
                        throw 2;
                    if(non_digit(line))
                    {
                        throw 3;
                    }
                    num = getting_digits(line);
                    output_file << digit_sum(num) << "\n";
                }
                catch(int err)
                {
                    if(err == 2)
                        output_file << "The program works only with integers" << "\n";
                    if(err == 3)
                        output_file << "The line must contain only digits" << "\n";
                }
            }
            output_file.close();
            input_file.close();
        }
        catch(int err)
        {
            if(err == 1)
                output_file << "Input file does not exist" << "\n";
            
        }
        
    }else
    {
        std::cout << "Entered flag does not exist " << "\n";
        std::cout << "You need to enter -t and name of input and output files " << "\n";        
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
bool non_digit(std::string line)
{//Chekcs the line. If it has char that does not represent number it returns true
    bool res = true;
    for(int i = 0; i < line.size() ; i++)
    {
        if(isdigit(line[i]) || line[i] == '-')
            res = false;
        else
            return true;
    }
    return res;
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