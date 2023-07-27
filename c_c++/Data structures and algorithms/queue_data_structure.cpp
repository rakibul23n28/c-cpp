#include<iostream>

class Queue{
    private:
        int front;
        int rear;
        int array_size;
        int* arr;
    public:
        Queue(int n){
            front=-1;
            rear=-1;
            array_size=n;
            arr=new int[array_size];
            for (int i = 0; i < array_size; i++)
            {
                arr[i]=0;
            }
            
        }
        bool isEmpty(){
            return (front==-1 && rear==-1);
        }
        bool isFull(){
            return rear==(array_size-1);
        }
        void enQueue(int value){
            if (isFull()) {
                std::cout<<"Queue is full"<<std::endl;
                return;
            }
            else if (isEmpty())
            {
               rear=0;
               front=0;
               arr[rear]=value;
            }
            else{
                rear++;
                arr[rear]=value;
            }
            
        }
        int deQueue(){
            int x;
            if(isEmpty()){
                std::cout<<"Queue is empty"<<std::endl;
                return 0;
            }
            else if (rear==front)
            {
                x=arr[front];
                arr[front]=0;
                rear=-1;
                front=-1;
                return x;
            }
            else{
                x=arr[front];
                arr[front]=0;
                front++;
                return x;
            }
            
        }
        int count(){
            return (rear-front)+1;
        }
        void display(){
            for (int i = 0; i < array_size; i++)
            {
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
        }
        ~Queue() {
            delete[] arr;
        }

};


int main(){
    int array_size;
    std::cout<<"Enter array size:";
    std::cin>>array_size;
    Queue queue(array_size);
    int option,value;
    do
    {
        std::cout<<"1.enQueue()\n2.dequeue()\n3.isEmpty()\n4.isFull()\n5.count()\n6.display()\n7.Clean Screen\n";
        std::cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout<<"for enQueue, Enter a number: ";
            std::cin>>value;
            queue.enQueue(value);
            break;
        case 2:
            std::cout<<"deQueue value: "<<queue.deQueue()<<std::endl;
            break;
        case 3:
            if (queue.isEmpty()) std::cout<<"queue is empty"<<std::endl;
            else std::cout<<"queue is not empty"<<std::endl;
            break;
       case 4:
            if (queue.isFull()) std::cout<<"queue is full"<<std::endl;
            else std::cout<<"queue is not full"<<std::endl;
            break;
        case 5:
            std::cout<<"total items: "<<queue.count()<<std::endl;
            break;
        case 6:
            queue.display();
            break;
        case 7:
            system ("CLS");
            break;
        
        default:
            std::cout<<"enter valid option"<<std::endl;
                break;
            }
    }while(option!=0);


    return 0;
}