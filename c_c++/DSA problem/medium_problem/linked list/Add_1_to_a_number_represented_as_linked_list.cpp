//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* pre=NULL;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node* temp=head;
        Node* pre;
        while(temp!=NULL){
            pre=temp;
             if(((temp->data)+1)/10){
                 temp->data=0;
             }
             else{
                 temp->data+=1;
                 return reverse(head);
             }
             temp=temp->next;
        }
        if(pre->data==0){
            Node* ne=new Node(1);
            pre->next=ne;
            return reverse(head);
        }
         return reverse(head);
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends