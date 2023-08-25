//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* tep1=head2;
        unordered_map<int,int> m;
        
        while(tep1){
            m[tep1->data]++;
            tep1=tep1->next;
        }
        
        Node* tep2=head1;
        
        Node* pre=NULL;
        Node* new_head=NULL;
        while(tep2){
            if(m.find(tep2->data)!=m.end()){
                Node* n=new Node(tep2->data);
                // m[tep2->data]--;
                if(!new_head){
                    new_head=n;
                }
                else{
                    pre->next=n;
                }
                pre=n;
                
            }
            tep2=tep2->next;
        }
        return new_head;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends