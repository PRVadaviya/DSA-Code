// which value is enter in last it's print

#include<iostream>
#include<map>
using namespace std ;

class node
{
     public :
               int data;
               node* next ;

               node(int d)
               {
                    this -> data = d ;
                    this -> next = NULL ;
               }
};

void insert (node* &tail ,int d)
{
     node* temp = new node(d);
     tail -> next = temp ;
     tail = temp ;
}

void print (node* &tail)
{
     node* ment = tail ; 

     while(ment != NULL)
     {
          cout <<"data---"<< ment -> data << "\t" ;
          ment = ment -> next ;
     }

     cout << endl ;
}

node* floycycle (node* head)
{
     node* slow = head ;
     node* fast = head ;

     if(head == NULL)
     {
          return NULL ;
     }

     while(slow != NULL && fast != NULL)         // loop nai hoy to aa condition thi exit thasu
     {                                           //loop mate below condition true thase
          fast = fast -> next ;

          if(fast != NULL)
          {
               fast = fast -> next ;
          }

          slow = slow -> next ;

          if(slow == fast )                  //loop hase tiyare aa ...
          {
               cout << slow -> data << endl ;
               return slow ;
          }

     }

     return NULL ;

}

int main()
{
     node* node1 = new node(10);

     node* head = node1 ;
     node* tail = node1 ;

     print (head);

     insert(tail , 20);
     print(head);

     insert(tail,30);
     print(head);

     insert(tail,40);
     print(head);

     insert(tail,50);
     print(head);

     tail ->next = head ->next ;

     if(floycycle(head) != NULL)
     {
          cout << "yes" << endl ;
     }
     else
     {
          cout << "no" << endl ;
     }

     return 0;
}