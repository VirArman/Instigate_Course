#include <iostream>
class Arr {
    private:
        int* arr = nullptr;
        int size = 4;
    public:
        Arr(){
            arr = new int[size];
        }
        Arr(int s){
            size = s;
            arr = new int[size];
        }
        int& operator[](int index){
            if (index >= size) {
                std::cout << "Array index out of bound, exiting";
                exit(1);
            }   
            return arr[index];
        }
        int len()
        {
            return this->size;
        }
        void push(int num){
            //adds number at the end of array
            int* narr = new int[size+1];
            for(int i = 0; i < size; i++){
                narr[i] = arr[i];
            }
            narr[size] = num;
            size++;
            delete [] arr;
            arr = narr;
        }
        void del(int index){
            // deletes array memeber from chosen index
            if (index >= size) {
                std::cout << "Array index out of bound, exiting";
                exit(1);
            }
            int* narr = new int[size-1];
            bool f = false;
            for(int i = 0; i < size; i++)
            {
                if(i == index)
                {
                    f = true;
                    continue;
                }
                if(f)
                    narr[i-1] = arr[i];
                else
                    narr[i] = arr[i];
            }
            size--;
            delete [] arr;
            arr = narr;
        }
        void print(){
             for(int i = 0; i < size; i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
        }
};
int main()
{
    Arr a(5);
    for(int i = 0; i < a.len(); i++){
        a[i] = i+1;
    }
    //a.print();
    a.push(8);
    a.print();
    a.del(5);
    a.print();    
    a.del(2);
    a.print();
    return 0;    
}