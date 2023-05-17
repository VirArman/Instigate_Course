class ALU{
    public:
        int execute(Registers& regs){
            int res;
            switch (regs.read(0)){
                case 1:
                    res = regs.read(2) + regs.read(3);
                    return res;
            
                default:
                    return -1;
                }
            return -1;
        }
};