#include<iostream>
using namespace std ;

class node
{
     public :
               int data ;
               node* next ;

               node(int d)
               {
                    data = d ;
                    this-> next = NULL;               
               }


};

void insertnode(node* &tail , int element , int d)
{

     //when insert first element 
     if(tail == NULL)
     {
          node* curr = new node(d);
          curr->next = curr ;
          tail = curr ;
     }
     else
     {
          node* temp = tail ;
          node* newnode = new node(d);

          while(element != temp->data)
          {
               temp = temp->next ;
          }

          newnode->next = temp->next;
          temp->next = newnode;

     }

}


void print(node* tail)
{
     node* temp = tail ;

     do
     {
          cout << tail->data << "  ";
          tail = tail->next ;   

     } while (tail != temp);

     cout << endl ;
     
}



node* GetMid(node* head)
{

     node* fast = head->next ;
     node* slow = head ;
     

     while(fast != head && fast->next != head)
     {
          fast = fast->next ;
          slow = slow ->next ;
          fast = fast->next ;
     }


     return slow;
}


void convert (node* &head)
{
     node* prin = head ;

     node* mid = NULL;
     mid = GetMid(head);

     node* temp = mid ;

     node* secondll = mid->next ;
     node* lastele = mid->next ;

     //first ll is circular
     mid ->next = prin ;
     print(prin);
     
     
     //make second ll
     if(secondll->next == head)          //after a mid only one element is there
     {
          secondll->next == lastele ;
          print(secondll);
     }
     else
     {
          while(secondll != head )
          {
               secondll = secondll->next ;
          }

          secondll->next = lastele ;
          print(lastele);
     }

     
}

int main ()
{
     node* tail = NULL ;

     insertnode(tail,5,3);
     insertnode(tail,3,5);
     insertnode(tail,5,7);
     insertnode(tail,7,9);
     insertnode(tail,9,10);
     insertnode(tail,10,20);
     print(tail);

     convert(tail);

     return 0;
}