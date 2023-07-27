#include<iostream>
#include<string>

class Stack{
    private:
        int top;
        int array_size;
        int* arr;

    public:
        Stack(int n){
            array_size=n;
            top=-1;
            arr=new int[array_size];
            for(int i=0;i<array_size;i++){
                arr[i]=0;
            }
        }
        bool isEmpty(){
            return top == -1;
        }
        bool isFull(){
            return top == (array_size-1);
        }
        void push(int value){
            if (isFull()){
                std::cout<<"Stack overFlow"<<std::endl;
            }
            else{
                top++;
                arr[top]=value;
            }
        }
        int pop(){
            if(isEmpty()){
                std::cout<<"Stack is emply"<<std::endl;
                return 0;
            }
            else{
                int popvalue=arr[top];
                arr[top]= 0 ;
                top--;
                return popvalue;
            }
        }
        int count(){
            return top+1;
        }
        int peek(int pos){
            if(isEmpty()){
                std::cout<<"Stack is emply"<<std::endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }
        void change(int pos,int value){
            if(isEmpty()){
                std::cout<<"Stack is emply"<<std::endl;
                return;
            }
            else{
                if(pos>top) {
                    std::cout<<"enter Valid position ,try aging"<<std::endl;
                    return;
                }
                arr[pos]=value;
                std::cout<<"Item change location "<<pos<<std::endl;
                return;
            }
        }
        void display() {
                for (int i = array_size-1; i >= 0; i--) {
                    std::cout << arr[i] <<std::endl;
                }
                std::cout << std::endl;
            
        }
};



int main(){
    int array_size;
    std::cout<<"Enter array size:";
    std::cin>>array_size;
    Stack stack(array_size);
    int option,postion,value;
    do
    {
        std::cout<<"1.push()\n2.pop()\n3.isEmpty()\n4.isFull()\n5.peek()\n6.count()\n7.change()\n8.display()\n9.Clean Screen\n";
        std::cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout<<"Enter a number: ";
            std::cin>>value;
            stack.push(value);
            break;
        case 2:
            std::cout<<"Pop value: "<<stack.pop()<<std::endl;
            break;
        case 3:
            if (stack.isEmpty()) std::cout<<"stack is empty"<<std::endl;
            else std::cout<<"stack is not empty"<<std::endl;
            break;
       case 4:
            if (stack.isFull()) std::cout<<"stack is full"<<std::endl;
            else std::cout<<"stack is not full"<<std::endl;
            break;
        case 5:
            std::cout<<"Enter a position of the item: ";
            std::cin>>postion;
            std::cout<<"Value of peek position is: "<<stack.peek(postion)<<std::endl;
            break;
        case 6:
            std::cout<<"total items: "<<stack.count()<<std::endl;
            break;
        case 7:
            std::cout<<"Enter position: ";
            std::cin>>postion;
            std::cout<<"Enter a value: ";
            std::cin>>value;
            stack.change(postion,value);
            break;
        case 8:
            stack.display();
            break;
        case 9:
            system ("CLS");
            break;
        
        default:
            std::cout<<"enter valid option"<<std::endl;
                break;
            }
    } while (option!=0);
    

    return 0;
}