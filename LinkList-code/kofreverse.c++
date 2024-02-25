#include<iostream>
using namespace std ;

class node 
{
     public :
               int data ;
               node* prev  ;
               node* next  ;

               node(int d)
               {
                    data = d ;
                    this-> prev = NULL;
                    this-> next = NULL;               
               }
};


void print (node* &ail)
{
     node* ment = ail ; 

     while(ment != NULL)
     {
          cout <<"data---"<< ment -> data << "\t" ;
          ment = ment -> next ;
     }

     cout << endl ;
}

void Inserttail(node* &tail , int d)
{
     node* temp = new node(d);
     temp ->prev = tail ;
     tail-> next = temp ;
     tail = temp ;

}
node* kreverse(node* &head,int k)
{

     if(head==NULL)
     {
          return 0 ;
     }

     node* temp = NULL ;
     node* curr = head ;
     node* prev = NULL ;
     int count = 0 ;

     
     while(curr != NULL && count < k )
     {
          temp = curr -> next ;
          curr ->next = prev ;
          prev = curr ;
          curr = temp ;
          count++;
     }

     if(curr->next != NULL)
     {
          head->next = kreverse(temp,k);
     }
 
     return prev ;

}


int main ()
{
     node* node1 = new node(50);
     node* head = node1 ;
     node* tail = node1 ;
     node* fest = node1 ;
     node* rest = NULL ;

     print(head);
     
     Inserttail(tail,10);
     print(head);

     Inserttail(tail,20);
     print(head);

     Inserttail(tail,30);
     print(head);

     Inserttail(tail,40);
     print(head);

     Inserttail(tail,60);
     print(head);

     rest = kreverse(fest,2);
     print(rest);

     return 0;
}

