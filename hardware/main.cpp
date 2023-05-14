#include <iostream>
#include <bits/stdc++.h>
#include "CPU.hpp"

int main(){
    CPU cp;
    cp.load(0b0001100001100111);
    cp.execute();
    return 0;
}