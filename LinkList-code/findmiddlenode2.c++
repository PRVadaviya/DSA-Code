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
                    this-> next = NULL;               
               }
};

node* getmiddle(node* head)
{
     node* slow = head ;
     node* fast = head->next ;


     if(head == NULL || head->next == NULL)
     {
          return head ;
     }

     // if(head->next->next == NULL)   //not a need also run in below algo 
     // {
     //      return head->next;
     // }


     while(fast != NULL)
     {
          fast = fast->next;

          if(fast != NULL)
          {
               fast = fast -> next ;
          }
          slow = slow -> next;
     }
     return slow ;
}

void print(node* &head)
{
     node* temp = head ;

     while(temp != NULL)
     {
          cout <<"data -- "<< temp->data << "\t" ;
          temp = temp->next ;
     }

     cout << endl ;

}

void insert (node* &ail ,int d)
{
     node* temp = new node(d);
     ail -> next  = temp ;
     ail = ail -> next ;      // ail = temp ;
}

void specialprint(node* head)
{
     cout << head->data << endl ;
}

int main ()
{
     node* node1 = new node(10);
     node* head = node1 ;
     node* tail = node1;
     node* res = NULL ;
     node* fes = node1 ;

     print (tail);

     insert(head , 20);
     print(tail);

     insert(head , 30);
     print(tail);

     res= getmiddle(tail);
     specialprint(res);

     return 0;
}
