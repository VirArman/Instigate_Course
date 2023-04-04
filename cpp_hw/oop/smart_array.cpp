#include <iostream>
class Arr {
    private:
        int* arr = nullptr;
        int size = 0;
    public:
        Arr(){
            arr = new int[size];
        }
        Arr(int s){
            size = s;
            arr = new int[size];
        }
        Arr(int s, int a[]){
            size = s;
            arr = new int[size];
            for(int i = 0; i < size; i++){
                arr[i] = a[i];
            }
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
            return size;
        }
        void push(int num){
            //adds number at the end of array
            size++;
            int* narr = new int[size];
            for(int i = 0; i < size; i++){
                narr[i] = arr[i];
            }
            narr[size-1] = num;
            delete [] arr;
            arr = narr;
        }
        void insert(int num, int index){
            //adds number at the specefic index
            if (index >= size) {
                std::cout << "Array index out of bound, exiting"<<"\n";
                exit(1);
            }
            size++;
            int* narr = new int[size];
            bool f = false;
            for(int i = 0; i < size; i++){
                if(i == index)
                {
                    f = true;
                    narr[i] = num;
                }
                if(f)
                    narr[i+1] = arr[i];
                else
                    narr[i] = arr[i];
            }
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
        ~Arr(){
            delete [] arr;
        }
};
int main()
{

    Arr a;
    int ba[] = {1,3,46};
    Arr b(3,ba);
    b.print();
    a.print();
    a.push(13);
    a.push(21);
    a.insert(56,0);
    a.push(36);
    a.insert(6,1);
    a.print();
    a.del(1);
    a.push(5);
    a.print();
    return 0;    
}