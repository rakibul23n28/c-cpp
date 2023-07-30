// Singly Linked list Operations
/*
1.appendNode()
2.prependNode()
3.insertNodeAfter()
4.deleteNodeByKey()
5.updateNodeByKey()
6.print()
*/

#include<iostream>

class Node {
private:
    int key;
    int data;
    Node* next;

public:
    Node() : key(0), data(0), next(NULL) {}
    Node(int k, int d) : key(k), data(d), next(NULL) {}

    // Allow SinglyLinkedList class to access private members
    friend class CircularLinkedList;
};

class CircularLinkedList{
    private:
        Node* head;
    public:
        CircularLinkedList():head(nullptr){};
        CircularLinkedList(Node* n):head(n){};

// Check if node exists using key value
        Node* nodeExists(int key){
            Node* temp=NULL;
            Node* ptr=head;
            if(ptr==NULL){
                return temp;
            } 
            else{
                do
                {
                    if(ptr->key==key){
                        temp=ptr;
                    }
                    ptr=ptr->next;
                } while (ptr!=head);
                return temp;
                
            }
        }
//append a node to the List
        void appendNode(Node* n){
            if(nodeExists(n->key) != NULL){
                std::cout<<"Node already exists with key value: "<<n->key<<". Append another node with different Key value"<<std::endl;
            }
            else{
                if(head==NULL){
                    head=n;
                    n->next=head;
                    std::cout<<"Node appended"<<std::endl;
                }
                else{
                    Node* ptr=head;
                    while (ptr->next != head)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->next=head;
                    std::cout<<"Node appended"<<std::endl;
                }
            }
        }
//prepent a node in list
        void prependNode(Node* n){
            if(nodeExists(n->key) != NULL){
                std::cout<<"Node already exists with key value: "<<n->key<<". Append another node with different Key value"<<std::endl;
            }
            else{
                if(head==NULL){
                    head=n;
                    n->next=head;
                    std::cout<<"Node prepended"<<std::endl;
                }
                else{
                    Node* ptr=head;
                    while (ptr->next != head)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->next=head;
                    head=n;
                    std::cout<<"Node prepended"<<std::endl;
                }
                
            }
        }
//Inserr a node after a particular node in the List
        void insertNodeAfter(int key,Node* n){
            Node* ptr=nodeExists(key);
            if(ptr==NULL){
                std::cout<<"No Node exists with key value"<<std::endl;
            }
            else{
                if(nodeExists(n->key) != NULL){
                std::cout<<"Node already exists with key value: "<<n->key<<". insert another node with different Key value"<<std::endl;
                }else{
                    if(ptr->next==head){
                        n->next=head;
                        ptr->next=n;
                        std::cout<<"Node inserted at the end "<<std::endl;
                    }
                    else{
                        n->next=ptr->next;
                        ptr->next=n;
                        std::cout<<"Node inserted between"<<std::endl;
                    }

                }   
            }
        }
    // Delete a node with a particular key
    void deleteNodeByKey(int key) {
        Node* ptr=nodeExists(key);
        if(ptr==NULL){
            std::cout<<"no Node exists with key value"<<std::endl;
        }
        else{
             if (ptr==head)
            {
                if(head->next==head){
                    head=NULL;
                    delete(ptr);
                    std::cout<<"Head node deleted..List empty"<<std::endl;
                }
                else {
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                    delete (ptr);
                    std::cout << "Node with key value " << key << " deleted from the beginning of the list." << std::endl;
                }
            }
            else{
                Node* temp=NULL;
                Node* preptr=head;
                Node* currptr=head->next;
                while (currptr!=NULL)
                {
                    if(currptr->key==key){
                        temp=currptr;
                        currptr=NULL;
                    }
                    else{
                        preptr=preptr->next;
                        currptr=currptr->next;
                    }
                }
                preptr->next=temp->next;
                delete(ptr);
                std::cout << "Node with key value " << key << " deleted ." << std::endl;
            }
            
        }
    }

//updateNode By key
        void updateNodeByKey(int key,int data){
            Node* ptr=nodeExists(key);
            if(ptr!=NULL){
                ptr->data=data;
                std::cout<<"Node Data Updated Successfully"<<std::endl;
            }
            else{
                std::cout<<"NOde Does't exists with key value :"<<key<<std::endl;
            }
        }

//printing 
        void printList(){
            if(head==NULL){
                std::cout<<"no Node in Linked list"<<std::endl;
            }else{
                std::cout<<"head address : "<<head<<std::endl;
                std::cout<<"circular Linked List values :";
                Node* ptr=head;
                do
                {
                    std::cout<<"("<<ptr->key<<","<<ptr->data<<", "<<ptr->next<<")-->";
                    ptr=ptr->next;
                }while (ptr != head);
                std::cout<<std::endl;
            }
        }

        
};


int main(){
    CircularLinkedList s;
  int option;
  int key1, k1, data1;
   Node* n1 = nullptr;
  do {
    std::cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
    std::cout << "1. appendNode()" << std::endl;
    std::cout << "2. prependNode()" << std::endl;
    std::cout << "3. insertNodeAfter()" << std::endl;
    std::cout << "4. deleteNodeByKey()" << std::endl;
    std::cout << "5. updateNodeByKey()" << std::endl;
    std::cout << "6. print()" << std::endl;
    std::cout << "7. Clear Screen" << std::endl << std::endl;

    std::cin >> option;
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      std::cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
       n1 = new Node(key1, data1);
      s.appendNode(n1);
      //std::cout<<n1.key<<" = "<<n1.data<<std::endl;
      break;

    case 2:
      std::cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
       n1 = new Node(key1, data1);
      s.prependNode(n1);
      break;

    case 3:
      std::cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << std::endl;
      std::cin >> k1;
      std::cout << "Enter key & data of the New Node first: " << std::endl;
      std::cin >> key1;
      std::cin >> data1;
       n1 = new Node(key1, data1);

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      std::cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << std::endl;
      std::cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      std::cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      std::cout << "Enter Proper Option number " << std::endl;
    }

  } while (option != 0);
    return 0;
}