#include <iostream>

int digit_sum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

bool ispalindrome(int num)
{
    int newnum = 0;
    int temp = num;
    while(temp > 0)
    {
        newnum *= 10;
        newnum += temp % 10;
        temp /= 10;
    }
    return num == newnum;
}

int main()
{
    int num = 0;
    std::cout<<"Insert number: ";
    std::cin>>num;
    std::cout<<"The sum of digits of number "<<num<<" is "<<digit_sum(num)<<std::endl;
    std::cout<<"Is palindrome: "<<ispalindrome(num)<<std::endl;
    return 0;
}
