
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



void Inserthead (node* &head ,node* &tail, int d)
{
     if(head == NULL)
     {
          node* temp = new node(d);
          head = temp;
          tail=temp;
     }
     else
     {
     node* temp = new node(d) ;
     temp -> next = head ;
     head -> prev = temp ;
     head = temp ;
     }
}

void Inserttail (node* &head,node* &tail , int d)
{
     if(tail == NULL)
     {
          node* temp = new node(d);
          tail = temp;
          head = temp ;
          
     }
     else
     {
     node* temp = new node(d);
     temp ->prev = tail ;
     tail -> next = temp ;
     tail = temp ;
     }

}

void insertatpossition(node* &tail , node* &head ,int d ,int pos)
{
     node* temp = head ;

     int count = 1;

     while(count < pos-1)
     {
          temp = temp->next;
          count++;
     }

     if(pos==1)
     {
          Inserthead(head ,tail, d);
          return ;
     }

     if(temp->next == NULL)
     {
          Inserttail(head,tail,d);
          return ;
     }
     else
     {
          node* nodeadd = new node(d);

          temp->next->prev =  nodeadd ;
          nodeadd->prev = temp ;
          nodeadd->next = temp->next ;
          temp->next = nodeadd ;

     }

}
int main ()
{
     node* head = NULL ;
     node* tail = NULL ;

     Inserttail(head,tail,10);
     print(head);

     Inserttail(head,tail,20);
     print(head);

     Inserthead(head,tail,30);
     print(head);

     Inserttail(head,tail,40);
     print(head);

     insertatpossition(head,tail,50,4);
     print(head);

     return 0;
}