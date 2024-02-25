#include<iostream>
using namespace std; 

class Node
{
     public :
               int data;
               Node* next ;

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


Node* GetMiddle (Node* head)
{
     Node* slow = head ;
     Node* fast = head ->next;

     while(fast != NULL && fast ->next != NULL)
     {
          fast = fast ->next->next;
          slow = slow ->next ;
     }

     return slow ;
}

Node* Reverse(Node* head)
{
     Node* curr = head ;
     Node* next = NULL ;
     Node* prev = NULL ;

     while(curr != NULL)
     {
          next = curr->next;
          curr->next=prev;
          prev = curr ;
          curr = next ;
     }

     return prev ;
}

int  palindrome (Node* head) 
{
     Node* middle = GetMiddle(head);

     Node* temp = middle->next;
     Node* head1 = head ;

     middle->next = Reverse(temp);

     Node* head2 = middle->next  ;
     
     while(head2 != NULL)
     {
          if(head1->data != head2->data)
          {
               return 0;
          }

          head1 = head1 ->next;
          head2 = head2 ->next;
     }

     // temp = middle->next;
     // middle->next = Reverse(temp);     

     return 1;
}


int main()
{
     Node* Node1 = new Node(1);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     insert(tail,4);
     insert(tail,2);
     insert(tail,1);

     print(head);

     cout << palindrome(head) << endl ;
 
     return 0;
}
