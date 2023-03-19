#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
void draw_rect(int, int);
void draw_rtriangle(int);
std::string longest_symb(std::string str);
std::string change_case(std::string str);
int find(char* str, char* substr);
bool is_substr(char* str, char* substr);
std::string replace_a(std::string str)
int main()
{
    //int a = 6, b =4;
    //draw_rect(6,4);
    //draw_rtriangle(5);
    //std::string str = "helloyy worlxxxd";
    char nstr[] = "complicated";
    char substr[] = "ct";
    //std::cout<<longest_symb(str)<<std::endl;
    //std::cout<<find(nstr, substr)<<std::endl;
    std::string str = "AbCd";
    std::cout<<change_case(str)<<std::endl;
    std::cout<<is_substr(nstr,substr)<<std::endl;
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

void Guess_num()
{//Task 10
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int num_guesses = 0;

    while (true) {
        std::cout << "Guess a number between 1 and 100: ";
        int guess;
        std::cin >> guess;
        num_guesses++;
        if (guess > number) {
            std::cout << "Too high!\n";
        } else if (guess < number) {
            std::cout << "Too low!\n";
        } else {
            break;
        }
    }

    std::cout << "Congratulations! You guessed the right number in " << num_guesses << " guesses!\n";
}

std::string longest_symb(std::string str)
{// task 30
    std::string max = "";
    std::string temp = "";
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        if(str[i]==str[i+1]) temp += str[i];
        else temp = "";
        if(max.size() < temp.size()) max = temp;            
    }
    max += max[0];
    return max;
}

int find(char* str, char* substr)
{//task 31
    size_t len = strlen(str);
    size_t sub_len = strlen(substr);
    for(int i = 0; i < len; i++)
    {
        int temp = 0;
        for(int j = 0; j < sub_len; j++)
        {
            if(str[i+j] == substr[j]) temp++;
            else break;
        }
        if(temp == sub_len) return i;
    }
    return -1;
}

std::string change_case(std::string str)
{//task 32.1
    std::string res = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            res += str[i] + 32; 
        }
        if(str[i] >= 97 && str[i] <= 122)
        {
            res += str[i] - 32;     
        } 
    }
    return res;
}


bool is_anagram(std::string str)
{// task 32.2
    int len = str.size();
    std::string rev_str = "";
    for(int i = len-1; i >= 0; i--)
    {
        rev_str += str[i];
    }
    return rev_str == str;
}

bool is_substr(char* str, char* substr)
{//task 33
    if(find(str, substr) == -1)
    {
        return false;
    }else
    {
        return true;
    }
}

std::string replace_a(std::string str)
{//task 34
    std::string res = "";
    for(int i = 0; i < str.size(); i++)
    {
        res += str[i];
        if(str[i] == 'a')
        {
            res += 'b';
        }
    }
    return res;
}

























