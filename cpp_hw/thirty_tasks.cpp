#include <iostream>
#include <cmath>
void draw_rect(int, int);
void draw_rtriangle(int);

int main()
{
    int a = 6, b =4;
    draw_rect(6,4);
    draw_rtriangle(5);
}
int dig_sum(int num)
{//task 1
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}
int inverse_num(int num)
{//task 2
    int newnum = 0;
    while(num > 0)
    {
        newnum *= 10;
        newnum += num % 10;
        num /= 10;
    }
    return newnum;
}
bool is_prime(int n)
{//task 3
    int temp = 0;
    for(int i = 2; i < std::sqrt(n); i++) if(n % i == 0) temp++;
    if(temp == 0 && n != 1) return true;
    else return false;
}
void print_primes(int n)
{//task 3.1
    for(int i = 1; i < n; i++)
    {
        if(is_prime(i))
        {
            std::cout<<"The number "<<i<<" is prime"<<std::endl;
        }
    }
}
bool ispalindrome(int num)
{//task 4
    return num == inverse_num(num);
}
int num_concate(int num1, int num2)
{//task 5
    int tmp = num2;
    int count = 0, res = 0;
    while(tmp > 0)
    {
        count++;
        tmp /= 10;
    }
    res = num1 * std::pow(10,count)+num2;
    return res;
}
bool ispower(int num)
{//task 6
    while(num > 0)
    {
        if(num % 2 != 0)
        {
            return false;
        }
        num /= 2;
    }
    return true;
}
void draw_rect(int n, int m)
{//task 7
    char symb;
    std::cout<<"Insert symbol \n";
    std::cin>>symb;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || i == m-1) std::cout<<symb;
            else if(j == 0 || j == n-1)std::cout<<symb;
            else std::cout<<' ';
        }
        std::cout<<std::endl;
    }
}
void draw_rtriangle(int n)
{//task 8
    std::string s = "";
    for(int i = 0; i < n; i++)
    {
        s += '*';
        std::cout<<s<<std::endl;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = n; j >= 0; j--)
        {
            if(j <= i) std::cout<<'*';
            else std::cout<<' ';
        }
        std::cout<<std::endl;
    }
}








