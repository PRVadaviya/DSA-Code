#include<iostream>
using namespace std; 

class Node
{
     public :
               int data;
               Node* next ;
               Node* pre;

               Node(int d)
               {
                    this -> data = d ;
                    this -> next = NULL ;
               }
};

void insert (Node* &tail ,int d)
{
     Node* temp = new Node(d);
     tail -> next  = temp ;
     tail = tail -> next ;      // tail = temp ;
}

void print (Node* &ail)
{
     Node* ment = ail ; 

     while(ment != NULL)
     {
          cout <<"data---"<< ment -> data << "\t" ;
          ment = ment -> next ;
     }

     cout << endl ;
}

Node*  ReverseDoubly (Node* &head)
{
     Node* curr = head ;
     Node* prev = NULL ;
     //cout << head->data ;

     while(curr != NULL)
     {
          curr->pre = curr ->next ;
          curr ->next = prev ; 
          prev = curr ;
          curr = curr -> pre  ;         //pre is important (don't write next)
     }
   
     return prev ;
                                       
}


int main()
{
     Node* Node1 = new Node(10);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     insert(tail,20);
     insert(tail,30);
     insert(tail,40);
     insert(tail,50);
     
     print(head);

     // cout << head->data << endl ;
     // cout << tail->data << endl ;

     result = ReverseDoubly(head);

     print(result);

     cout << result->next->pre->data << endl ;

     return 0;
}
