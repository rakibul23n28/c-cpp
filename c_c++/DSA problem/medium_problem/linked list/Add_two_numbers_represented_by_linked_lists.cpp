//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
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
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first1, struct Node* second1)
    {
        Node* first=reverse(first1);
        Node* second=reverse(second1);
        int carry=0;
        Node* head=NULL;
        int sum=0;
        while(first!=NULL||second!=NULL||carry==1){
            sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
            int digit=sum%10;
            Node* value=new Node(digit);
            if(head==NULL) head=value;
            else{
                value->next=head;
                head=value;
            }
            carry=sum/10;
            if(first)  first=first->next;
            if(second) second=second->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends