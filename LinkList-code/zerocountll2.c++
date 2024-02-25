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

void InsertTail(Node* &tail , Node* curr)
{
     tail ->next = curr ;
     tail = curr ;
}


Node* NodeSort (Node* &head) 
{
     Node* curr = head ;

     Node* zerohead = new Node(-1);          //dumy node ne head ane tail point kare 6    
     Node* zerotail = zerohead ;

     Node* onehead = new Node(-1);
     Node* onetail = onehead ;

     Node* twohead = new Node(-1);
     Node* twotail = twohead ;

     while(curr != NULL)
     {
          int value = curr -> data ;

          if(value == 0)
          {
               InsertTail(zerotail , curr);       // apporach - 3 === new linklist create kari ne ahiya ppointer and 0 1 2 pass kari ne 
          }
          else if(value == 1)
          {
               InsertTail(onetail , curr);
          }
          else if(value == 2)
          {
               InsertTail(twotail , curr);
          }

          curr = curr -> next;

     }

     // let's merge three ll

     if(onehead->next != NULL)
     {
          zerotail->next = onehead ->next;
     }
     else
     {
          zerotail->next = twohead ->next ;
     }

     onetail->next = twohead->next ;
     twotail->next = NULL ;

      head = zerohead->next;

      // delete dummy node

     delete zerohead ;
     delete onehead ;
     delete twohead ;

     return head ;

}


int main()
{
     Node* Node1 = new Node(0);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     insert(tail,1);
     insert(tail,2);
     insert(tail,0);
     insert(tail,2);
     insert(tail,1);
     insert(tail,2);
     print(head);

     result=NodeSort(head);
     print(result);


     return 0;
}
