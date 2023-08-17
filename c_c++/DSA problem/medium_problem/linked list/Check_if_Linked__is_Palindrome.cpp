//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* mid){
        Node* curr=mid;
        Node* pre=NULL;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    bool isPalindrome(Node *head)
    {
        Node* s=head;
        Node* f=head;
        while(f!=NULL&&f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        Node* rev=reverse(s);
        Node* temp=head;
        while(rev!=NULL){
            if(temp->data!=rev->data) return 0;
            rev=rev->next;
            temp=temp->next;
        }
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends