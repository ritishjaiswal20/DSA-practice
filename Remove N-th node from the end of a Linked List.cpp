#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
}*first;
void create()
{
    node*p;
    p=new node;
    int n;
    cout<<"enter the lenght of the linked list";
    cin>>n;
    int x;
    cin>>x;
    p->data=x;
    p->next=0;
    first=p;
    for(int i=1;i<n;i++)
    {
      cin>>x;
      node *t;
      t=new node;
      t->data=x;
      t->next=0;
      p->next=t;
      p=t;
    }
}


void delet(int n)
{
    node* slow;
    node* fast;
    slow=first;
    fast=first;
    while(n)
    {
        fast=fast->next;
        n--;
    }
    if(fast==0)
    {
        node* p=first;
        first=first->next;
        delete(p);
    }
    else{
          while(fast->next)
          {
            fast=fast->next;
            slow=slow->next;
           } 
           slow->next=slow->next->next;
           
    }
  
}



void display()
{ 
    
    cout<<"hey buddy";
    node*p= first;
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
}
int main()
{ 
     create();
     cout<<endl;
     delet(5);
     display();
     return 0;

    
}

//2nd method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        int l=0;
        ListNode*p=head;
        while(p)
        {
            p=p->next;
            l++;
        }
        p=head;
        int k=l-n;
        if(k==0)
        {
            ListNode*q=head;
            head=head->next;
            delete(q);
            return head;
        }
        ListNode*r=NULL;
        while(k)
        {   
            r=p;
            p=p->next;
            k--;
        }
        r->next=p->next;
        return head;
    }
};
