#include <iostream>
int is_prime(int);
int bigger_prime(int);
int closest_prime(int);
int main()
{
    int num;
    std::cout<<"Insert your number "<<std::endl;
    std::cin>>num;
    std::cout<<"is prime "<<is_prime(num)<<std::endl;
    std::cout<<"The bigger prime is "<<bigger_prime(num)<<std::endl;
    std::cout<<"The closest prime is "<<closest_prime(num)<<std::endl;

}
int is_prime(int n)
{
    int temp = 0;
    for(int i = 2; i < n/2; i++) if(n % i == 0) temp++;
    if(temp == 0 && n != 1) return true;
    else return false;
}
int bigger_prime(int n)
{
    for(int i = n; ; i++) if(is_prime(i)) return i;
}
int closest_prime(int n)
{
    int j = n-1;
    for(int i = n; ; i++)
    {
        if(is_prime(i)) return i;
        if(is_prime(j)) return j;
        j--;
    } 
}
