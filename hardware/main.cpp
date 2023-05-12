#include <iostream>
#include <bits/stdc++.h>
int* decode(int code){
    int* res = new int[4];
    for(int i = 3; i >= 0; i-- ){
        res[i] = 0b1111 & code;
        code = code >> 4;
    }
    return res;
}

int main(){
    int* res = decode(6555);
    for (int i = 0; i < 4; i++){
        std::bitset<4> bits(res[i]);
        std::cout<<bits<<std::endl;   
    }
    return 0;
}