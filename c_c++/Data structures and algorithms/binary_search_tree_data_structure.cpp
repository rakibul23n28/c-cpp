#include<iostream>
#include<cmath>
const int SPACE = 5;
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
        int getBalanceFactor(TreeNode* node){
            if(node == nullptr) return -1;
            return (heightTreeHelper(node->left) - heightTreeHelper(node->right));
        }
        TreeNode* rightRotate(TreeNode* node){
            TreeNode* returnNode=node->left;
            TreeNode* extraNode=returnNode->right;

            //change
            returnNode->right=node;
            node->left=extraNode;

            return returnNode;

        }
        TreeNode* leftRotate(TreeNode* node){
            TreeNode* returnNode=node->right;
            TreeNode* extraNode=returnNode->left;

            //change
            returnNode->left=node;
            node->right=extraNode;

            return returnNode;

        }
        void insertNodeHelper(TreeNode* &currentNode, TreeNode* newNode){
            if(currentNode == nullptr){
                currentNode = newNode;
                return;
            }
            if(currentNode->data > newNode->data){
                insertNodeHelper(currentNode->left, newNode);
            }
            else if(currentNode->data < newNode->data){
                insertNodeHelper(currentNode->right, newNode);
            }
            else{
                std::cout << "This data already exists, try again" << std::endl;
            }
            //bf means Baalance factor
            int bf=getBalanceFactor(currentNode);
            if(bf > 1){
                if(currentNode->left->data > newNode->data){
                    currentNode = rightRotate(currentNode);
                }else{
                    currentNode->left=leftRotate(currentNode->left);
                    currentNode=rightRotate(currentNode);
                }
            }else if(bf < -1){
                if(currentNode->right->data < newNode->data){
                    currentNode=leftRotate(currentNode);
                }else{
                    currentNode->right=rightRotate(currentNode->right);
                    currentNode=leftRotate(currentNode);
                }

            }

        }
        void printPreorderHelper(TreeNode* node){
            if(node == nullptr) return;
            std::cout << node->data << " --> ";
            printPreorderHelper(node->left);
            printPreorderHelper(node->right);
        }
        void printInorderHelper(TreeNode* node){
            if(node == nullptr) return;
            printInorderHelper(node->left);
            std::cout<<node->data<<" --> ";
            printInorderHelper(node->right);
        }
        void printPostorderHelper(TreeNode* node){
            if(node == nullptr) return;
            printPostorderHelper(node->left);
            printPostorderHelper(node->right);
            std::cout<<node->data<<" --> ";
        }
        void print2DHelper(TreeNode* node, int space){
            if(node == nullptr) return;
            space=space+SPACE;
            print2DHelper(node->right, space);
            std::cout<<std::endl;
            for(int i=SPACE;i<space;i++) std::cout<<" ";
            std::cout<<node->data<<std::endl;
            print2DHelper(node->left, space);

        }
        void printLevelorderHelper(TreeNode* node,int level){
            if(node == nullptr) return;
            else if(level == 0) {
                std::cout<<node->data<<" --> ";
            }
            else{
                printLevelorderHelper(node->left,level-1);
                printLevelorderHelper(node->right,level-1);
            }
        }
       
        int heightTreeHelper(TreeNode* node){
            if(node == nullptr) return -1;
            int leftHeight=heightTreeHelper(node->left);
            int rightHeight=heightTreeHelper(node->right);
            return std::max(leftHeight,rightHeight)+1;
        }
        TreeNode* deleteNodeHelper(TreeNode* &node,int data){
            if(node == nullptr) return node;
            else if(node->data > data){
                node->left = deleteNodeHelper(node->left,data);
            }
            else if(node->data < data){
                node->right = deleteNodeHelper(node->right,data);
            }
            else{
                if(node->left == nullptr){
                    TreeNode* temp=node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == nullptr){
                    TreeNode* temp=node->left;
                    delete node;
                    return temp;
                }
                else{
                    TreeNode* temp=minNode(node->right);
                    node->data=temp->data;
                    node->right=deleteNodeHelper(node->right,temp->data);
                }
            }

            int bf=getBalanceFactor(node);
            if(bf == 2){
                if(getBalanceFactor(node->left) >= 0){
                    node = rightRotate(node);
                }else if(getBalanceFactor(node->left) == -1){
                    node->left=leftRotate(node->left);
                    node=rightRotate(node);
                }
            }else if(bf == -2 ){
                if(getBalanceFactor(node->right) <= 0){
                    node=leftRotate(node);
                }else if(getBalanceFactor(node->right) ==1){
                    node->right=rightRotate(node->right);
                    node=leftRotate(node);
                }

            }
            return node;

        }
        TreeNode* minNode(TreeNode* node){
            TreeNode *temp=node;
            while(temp->left != nullptr){
                temp=temp->left;
            }
            return temp;
        }
    public:

        BinarySearchTree():root(nullptr){}
        BinarySearchTree(TreeNode* newNode):root(newNode){}

        bool isEmpty(){
            return root == nullptr;
        }
        TreeNode* getRoot(){
            return root;
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

        void insertNode(TreeNode* newNode){
            // if(root == nullptr){
            //      root=newNode;
            //      return;
            // }
            // else{
            //     if(nodeExist(newNode->data)){
            //         std::cout<<"This data already exist, try again"<<std::endl;
            //         return;
            //     }
            //     TreeNode* temp = root;
            //      while (temp != nullptr) {
            //         if (newNode->data < temp->data) {
            //             if (temp->left == nullptr) {
            //                 temp->left = newNode;
            //                 std::cout<<"Value Inserted to the Left"<<std::endl;
            //                 return;
            //             } else {
            //                 temp = temp->left;
            //             }
            //         } else {
            //             if (temp->right == nullptr) {
            //                 temp->right = newNode;
            //                 std::cout<<"Value Inserted to the Right"<<std::endl;
            //                 return;
            //             } else {
            //                 temp = temp->right;
            //             }
            //         }
            //     }
            // }
            insertNodeHelper(root,newNode);
        }
        void printPreorder(){
            std::cout << "Pre-order traversal:" << std::endl;
            printPreorderHelper(root);
            std::cout<<std::endl;
        }
        void printInorder(){
            std::cout << "In-order traversal:" << std::endl;
            printInorderHelper(root);
            std::cout<<std::endl;
        }
        void printPostorder(){
            std::cout << "Post-order traversal:" << std::endl;
            printPostorderHelper(root);
            std::cout<<std::endl;
        }
        void print2D(){
            std::cout << "2D- print:" << std::endl;
            print2DHelper(root,0);
            std::cout<<std::endl;

        }
        TreeNode* iterativeSearch(int value){
            TreeNode* temp = root;

            while (temp != nullptr) {
                if (value == temp->data)
                    return temp;
                else if (value < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            
            return nullptr;
        }
        int heightTree(){
            return heightTreeHelper(root);
        }
         void printLevelOrderBFS(){
            std::cout << "Level-order traversal(Breadth First Search):" << std::endl;
            int heightTree=heightTreeHelper(root);
            for (int i=0;i<=heightTree;i++){
                printLevelorderHelper(root,i);
            }
            std::cout<<std::endl;

         }
         TreeNode* deleteNode(int data){
            return deleteNodeHelper(root,data);
         }

};


int main(){
    BinarySearchTree BST;
    int choice,data;
    do {
        choice = 0;
        std::cout<<"What operation do you want to perform?"<<std::endl;
        std::cout<<"0: For Exit The Code"<<std::endl;
        std::cout<<"1: Insert Node"<<std::endl;
        std::cout<<"2: Search Node"<<std::endl;
        std::cout<<"3: Delete Node"<<std::endl;
        std::cout<<"4: Print BST values"<<std::endl;
        std::cout<<"5: Height of a Tree"<<std::endl;
        std::cout<<"6: Clean Screen"<<std::endl;

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
            std::cout<<"Enter a data For Searching: ";
            std::cin>>data;
            if(BST.iterativeSearch(data)){
                std::cout << "Data " << data << " found in the tree." << std::endl;
            }
            else{
                std::cout << "Data " << data << " is not found in the tree." << std::endl;
            }
            break;
        case 3:
            std::cout<<"Delete"<<std::endl;
            std::cout<<"Enter VALUE of Tree Node to DELETE in BST: ";
            std::cin>>data;
            if(BST.deleteNode(data)){
                std::cout << "Data " << data << " deleted from the tree." << std::endl;
            }
            else{
                std::cout << "Data " << data << " is not found in the tree." << std::endl;
            }
            break;
        case 4:
            std::cout<<"Print and TRAVERSE BST"<<std::endl;
            BST.printPreorder();
            BST.printInorder();
            BST.printPostorder();
            BST.print2D();
            BST.printLevelOrderBFS();
            break;
        case 5:
            std::cout<<"Height of This Tree"<<std::endl;
            std::cout<<"The height of this binary tree is: "<<BST.heightTree()<<std::endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            break;
        }
        
    } while (choice != 0);
    
    return 0;
}