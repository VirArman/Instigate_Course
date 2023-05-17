class CPU{
    private:
        Registers regs;
        Memory* ram;
        ControlUnit CU;
    public:
        CPU(Memory& ram){
            this->ram = &ram;
            CU =  ControlUnit(ram);
        }
        void load(int instruction){
            ram->rewrite(instruction,regs.read(5));
            regs.write(regs.read(5)+1,5);
        }
        void store(int data, int address){
            ram->rewrite(data,address);
        }
        void execute(){
            int instruction = CU.fetch(regs.read(4));
            int* decoded = CU.decode(instruction);
            for (int i = 0; i < 4; i++){
                regs.write(decoded[i],i);
            }
            CU.execute(regs);
            regs.write(regs.read(4)+1,4);
        }
        
};