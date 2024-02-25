// recursion

#include<iostream>
using namespace std ;

class node
{
     public :
          int data ;
          node* next ;

          node(int data)
          {
               this->data = data;
               this->next = NULL ;
          }
};

node* reversenode(node* head)
{
     if(head == NULL || head ->next == NULL)
     {
          return head ;
     }
     
     node* temphead = reversenode(head->next);

     head -> next -> next = head ;
     head -> next = NULL ;

     return temphead ;
}
