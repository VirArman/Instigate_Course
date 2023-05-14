#include <vector>
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
};