#include<iostream>
class TreeNode{
    private:
        int data;
        int key;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode():data(0),key(0),left(nullptr),right(nullptr){}
        TreeNode(int d,int k):data(d),key(k),left(nullptr),right(nullptr){}

        friend class BinarySearchTree;
};
class BinarySearchTree{
    private:
        TreeNode* root;
    public:
        BinarySearchTree():root(nullptr){}
        BinarySearchTree(TreeNode* newNode):root(newNode){}

        bool isEmpty(){
            return root == nullptr? true : false;
        }
        TreeNode* nodeExist(int key){
            if (root == nullptr)
                return nullptr; 

            TreeNode* temp=root;

            while(temp != nullptr){
                if(temp->key == key) return temp;
                else if((temp->key > key)) temp=temp->left;
                else temp=temp->right;
            }

            return nullptr;
        }
        void insertNode(TreeNode* newNode){
            if(root == nullptr){
                 root=newNode;
                 return;
            }
            else{
                if(nodeExist(newNode->key)){
                    std::cout<<"This key already exist, try again"<<std::endl;
                    return;
                }
                TreeNode* temp = root;
                 while (temp != nullptr) {
                    if (newNode->data < temp->data) {
                        if (temp->left == nullptr) {
                            temp->left = newNode;
                            return;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == nullptr) {
                            temp->right = newNode;
                            return;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
        }
};


int main(){
    BinarySearchTree BST;
    int choice,data,key;
    do {
        std::cout<<"What operation do you want to perform?"<<std::endl;
        std::cout<<"0: For Exit The Code"<<std::endl;
        std::cout<<"1: Insert Node"<<std::endl;
        std::cout<<"2: Search Node"<<std::endl;
        std::cout<<"3: Delete Node"<<std::endl;
        std::cout<<"4: Print BST values"<<std::endl;
        std::cout<<"5: Clean Screen"<<std::endl;

        std::cin>>choice;
        switch (choice)
        {
        case 0:
            break;

        case 1:
            std::cout<<"Insert"<<std::endl;
            std::cout<<"Enter  data and key For Insertion"<<std::endl;
            std::cin>>data>>key;
            BST.insertNode(new TreeNode(data,key));
            break;
        case 2:
            std::cout<<"Search"<<std::endl;
            break;
        case 3:
            std::cout<<"Delete"<<std::endl;
            break;
        case 4:
            std::cout<<"Print and TRAVERSE BST"<<std::endl;
            break;
        case 5:
            system("cls");
            break;
        default:
            break;
        }
        
    } while (choice != 0);
    
    return 0;
}