#include<iostream>
class TreeNode{
    private:
        int data;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode():data(0),left(nullptr),right(nullptr){}
        TreeNode(int d):data(d),left(nullptr),right(nullptr){}

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
                if(temp->data == key) return temp;
                else if((temp->data > key)) temp=temp->left;
                else temp=temp->right;
            }

            return nullptr;
        }

        void insertNode(TreeNode* &currentNode, TreeNode* newNode){
            if(currentNode == nullptr){
                currentNode=newNode;
                return;
            }
            if(currentNode->data > newNode->data)
                insertNode(currentNode->left,newNode);
            else if(currentNode->data < newNode->data)
                insertNode(currentNode->right,newNode);
            else
                std::cout << "This data already exists, try again" << std::endl;
        }
        void insertNode(TreeNode* newNode){
            if(root == nullptr){
                 root=newNode;
                 return;
            }
            else{
                if(nodeExist(newNode->data)){
                    std::cout<<"This data already exist, try again"<<std::endl;
                    return;
                }
                TreeNode* temp = root;
                 while (temp != nullptr) {
                    if (newNode->data < temp->data) {
                        if (temp->left == nullptr) {
                            temp->left = newNode;
                            std::cout<<"Value Inserted to the Left"<<std::endl;
                            return;
                        } else {
                            temp = temp->left;
                        }
                    } else {
                        if (temp->right == nullptr) {
                            temp->right = newNode;
                            std::cout<<"Value Inserted to the Right"<<std::endl;
                            return;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
            // insertNode(root,newNode);
        }
};


int main(){
    BinarySearchTree BST;
    int choice,data;
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
            std::cout<<"Enter VALUE of Tree Node to INSERT in BST: ";
            std::cin>>data;
            BST.insertNode(new TreeNode(data));
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