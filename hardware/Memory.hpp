#include <vector>
#include <iostream>
class Memory{
    private:
        std::vector<int> ram;
    public:
        Memory(int size){
            ram.resize(size);
        }
        void load(int data){
            ram.push_back(data);
        }
        void rewrite(int data, int address){
            ram[address] = data;
        }
        int read(int address){
            return ram[address];
        }
        void print(){
            for(int i = 0; i < ram.size();i++){
                std::cout<<ram[i]<<"\n";
            }
        }
};