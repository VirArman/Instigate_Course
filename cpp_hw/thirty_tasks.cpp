#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "thirty_tasks.h"
int main()
{
    //int a = 6, b =4;
    //draw_rect(6,4);
    //draw_rtriangle(5);
    //std::string str = "helloyy worlxxxd";
    //char nstr[] = "complicated";
    //char substr[] = "ct";
    //std::cout<<longest_symb(str)<<std::endl;
    //std::cout<<find(nstr, substr)<<std::endl;
    //std::string str = "AbCd";
    //std::cout<<change_case(str)<<std::endl;
    //std::cout<<is_substr(nstr,substr)<<std::endl;
    
    std::cout<<change_num_sys(1234,8)<<std::endl;
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
void roles_changed()
{// task 11
    int tries = 7;
    int guess = 0;
    int l = 1;
    int r = 100;
    int a;
    std::cout << "think of a number 1-100\ni'll try to guess it\n";
    while (!guess && tries != 0)
    {
        std::cout << "\nmy guess is " << (l+r)/2 << std::endl;
        std::cout << "1.too high\n2.too low\n3.correct\n";
        std::cin >> a;
        if (a == 1) r = (l+r)/2;
        else if (a == 2) l = (l+r)/2;
        else if (a == 3) guess = 1;
        tries -= 1;
    }
    std::cout << "\ntries used: " << 7 - tries;
}

void num_occur()
{//task 12
    int arr[10] = {0};
    int a;
    do 
    {
        std::cin >> a;
        if (a < 11 && a > 0) arr[a - 1] += 1;
    }
    while (a != -1);
    
    for (int i = 0; i < 10; i++)
    {
        std::cout << i + 1 << ":" <<arr[i] << std::endl;
    }
}

void dec_bin()
{//task 13
    int n;
    bool binaryNum[4] = {0};
    bool one[4] = {0};
    int two[4] = {0};
    int i = 0;
    std::cin >> n;
    int num = n;
    while (n != 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    //one
    for (int i = 0; i < 4; i++)
    {
        if (binaryNum[i] == 0) one[i] = 1;
        if (binaryNum[i] == 1) one[i] = 0;
    }
    //two
    for (int j = 0; j < 4; j++)
    {
        two[j] = one[j];
    } 
    for (int j = 0; j < 4; j++)
    {
        if (one[j] == 1) two[j] = 0;
        if (one[j] == 0) {two[j] = 1; break;}
    } 
    if (num > 0) 
    {
        for (int j = 3; j >= 0; j--)
            std::cout << binaryNum[j] << " ";
    }
    if (num < 0) 
    {
        for (int j = 3; j >= 0; j--)
            std::cout << two[j] << " ";
    }
}

void bin_dec()
{//task 14
    int dec = 0, i = 0, rem, n;
    std::cin >> n;

    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * std::pow(2, i);
        ++i;
    }
    std::cout << dec;
}

void reversed()
{//task 16
    int rev = 0, num;
    std::cin >> num;
    while(num > 0)
    {
        rev = rev * 100 + (num % 10);
        num = num / 10;
    }
    rev *= 10;
    std::cout << "the reversed number: " << rev << std::endl;
}

void e_num()
{//task 17
    double sum = 0;
    int fact = 1, num;
    std::cin >> num;
    for (int i = 1; i <= num; i++)
    {
       fact *= i;         
       sum += 1.0/fact;   
    }
    std::cout << sum;
}
void armstrong_num()
{//task 18
    int n;
    std::cin >> n;
    int temp = n;
    int p = 0;
    while (n > 0) {
        int rem = n % 10;
        p = (p) + (rem * rem * rem);
        n = n / 10;
    }
      if (temp == p) {
        std::cout<<("Yes");
    }
    else {
        std::cout<<("No");
    }
}

void max()
{//task 19
    int arr[] = { 10, 324, 45333, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    std::cout << max;
}

void most_used_digits()
{//task 20
    int arr[] = {11, 12, 253, 33, 41, 55, 565, 557, 67, 18, 19, 159, 99, 101};
    int n = sizeof(arr) / sizeof(arr[0]);
    int digit_count[10] = {0}; 
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        while(num > 0) {
            int digit = num % 10;
            digit_count[digit]++;
            num /= 10;
        }
    }
    int max_count = 0, most_frequent_digit = 0;
    for(int i = 0; i < 10; i++) {
        if(digit_count[i] > max_count) {
            max_count = digit_count[i];
            most_frequent_digit = i;
        }
    }
    std::cout << "the most frequent digit is " << most_frequent_digit << std::endl;
}

void is_sorted()
{// task 21
    int arr[] = {11, 12, 253, 33, 41, 55, 565, 557, 67, 18, 19, 159, 99, 101};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prev_num, current_num;
    bool ascending = true, descending = true;
    prev_num = arr[0];
    for(int i = 1; i < n; i++)
    {
        current_num = arr[i];
        if(current_num >= prev_num) {
            descending = false;
        }
        if(current_num <= prev_num) {
            ascending = false;
        }
        prev_num = current_num;
    }
    if(ascending || descending) std::cout << "yes";
    else std::cout << "no";
}

void sort()
{//task 22
    int arr[] = {11, 12, 253, 33, 41, 55, 565, 557, 67, 18, 19, 159, 99, 101};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    std::cout << "The sorted array in ascending order is: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool is_degree(int k, int n)
{//task 27.1
    bool res = false;
    while(n >= k)
    {
        if(n % k == 0)
        {
            res = true;
        }else
        {
            res = false;
            break;
        }
        n /= k;
    }
    return res;
}

int change_num_sys(int n, int k)
{// task 27.2
    int res = 0;
    while(n > 0)
    {
        res *= 10;
        res += n % k;
        n /= k;
    }
    res = inverse_num(res);
    return res;
}

int* biggest_divisor(int arr1[], int arr2[], int n)
{//task 29
    int* res = new int[n];
    int greater = arr1[0], lesser = arr2[0]; 
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] >= arr2[i])
        {
            greater = arr1[i];
            lesser = arr2[0];
        }
        else
        {
            greater = arr2[i];
            lesser = arr1[i];
        }
        for(int j = 0; j <= lesser; j++)
        {
            if(greater % j == 0 && lesser % j == 0)
                res[i] = j;
        }
    }
    return res;
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



void delete_duplicates(std::string sentence)
{	
	std::string str;
	std::cout << "Enter a sentence:" << std::endl;
	getline(std::cin, str);
	std::string newSentence;
	for(int i = 0; i < sentence.size(); i++){
		if(sentence[i] != sentence[i-1]){
			newSentence += sentence[i];
		}		
	}
	std::cout << newSentence << std::endl;
}


