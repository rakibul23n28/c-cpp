//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
    void sortlist(Node* head){
        vector<int> sortt;
        Node* temp = head;
        while(temp){
            sortt.push_back(temp->data);
            temp=temp->next;
        }
        sort(sortt.begin(),sortt.end());
        temp = head;
        int i=0;
        while(temp){
            temp->data=sortt[i++];
            temp=temp->next;
        }
    }
    Node* removedup(Node* head){
        Node* temp=head;
        Node* new_head=NULL;
        Node*pre=NULL;
        while(temp&&temp->next){
            if(temp->data != temp->next->data){
                Node* neww=new Node(temp->data);
                if(new_head==NULL){
                    new_head=neww;
                }
                else{
                    pre->next=neww;
                }
                pre=neww;
            }
            temp=temp->next;
        }
        if(temp->data!=pre->data){
            Node* neww=new Node(temp->data);
            pre->next=neww;
        }
        return new_head;
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node* temp =head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head2;
        sortlist(head1);
        Node* new_head=removedup(head1);
        return new_head;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends