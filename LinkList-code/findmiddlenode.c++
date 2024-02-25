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

int getlenth(node* head)
{
     node* temp = head ;
     int count= 0 ;

     while(temp != NULL)
     {
          count++;
          temp = temp ->next ;
     }

     return count ;
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

node* middlenode(node* head)
{
     node* present = head ;
     int r = getlenth(head);

     int ans = r/2 ;

     while(ans--)
     {
          present =present->next ;
     }

     return present ;

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
     node* res = NULL;
     node* fes = node1 ;

 
     print (tail);

     insert(head , 20);
     print(tail);

     insert(head,30);
     print(tail);

     insert(head,40);
     print(tail);

     insert(head,50);
     print(tail);

     res = middlenode(fes);
     specialprint(res);


     return 0;
}