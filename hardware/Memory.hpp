class Memory{
    private:
        std::vector<int> ram;
    public:
        Memory(){
            ram.resize(12);
        }
        Memory(int size){
            ram.resize(size);
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