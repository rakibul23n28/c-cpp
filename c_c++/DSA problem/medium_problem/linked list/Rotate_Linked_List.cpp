//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        
        Node* temp=head;
        Node* temp2;
        int i=0,n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(k==n) return head;
        k=k%n;
        temp=head;
        while(temp!=NULL){
            i++;
            if(i==k) {
                temp2=temp->next;
                temp->next=NULL;
                break;
            }
            
            temp=temp->next;
        }
        temp=head;
        head=temp2;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends