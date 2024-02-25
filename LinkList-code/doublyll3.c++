
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

               ~node()
               {
                    int value = this->data ;

                    if(this->next == NULL)
                    {
                         delete next ;
                         this->next = NULL ;
                    }
                    
                    cout << "destructor run--" << value << endl  ; 
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



void Inserthead (node* &head , int d)
{
     node* temp = new node(d) ;
     temp -> next = head ;
     head -> prev = temp ;
     head = temp ;
}

void Inserttail (node* &tail , int d)
{
     node* temp = new node(d);
     temp ->prev = tail ;
     tail -> next = temp ;
     tail = temp ;

}

void insertatpossition(node* &tail , node* &head ,int d ,int pos)
{
     node* temp = head ;
     node* nodeadd = new node(d);
     int count = 1;

     while(count < pos-1)
     {
          temp = temp->next;
          count++;
     }

     if(pos==1)
     {
          Inserthead(head , d);
          return ;
     }

     if(temp->next == NULL)
     {
          Inserttail(tail,d);
          return ;
     }
     else
     {
          temp->next->prev =  nodeadd ;
          nodeadd->prev = temp ;
          nodeadd->next = temp->next ;
          temp->next = nodeadd ;
     }

}

void deletion (node* &head , int position)
{
     int count = 1;
     node* temp = head;

     if(position == 1)
     {
          head = temp -> next ;
          temp -> next -> prev = NULL ;
          temp -> next = NULL ;
          delete temp ;
     }

     while(count < position-1)
     {
          temp = temp -> next ;
          count++ ;
     }

     if(temp -> next == NULL)
     {
          temp ->prev = NULL ;
          delete temp ;
     }
     else
     {
          node* curr = head ;
          node* prev = NULL ;

          int count = 1 ;

          while(count < position)
          {
               prev = curr ;
               curr = curr -> next ;
               count++;
          }

          curr ->prev = NULL ;
          prev -> next = curr -> next ;
          curr ->next = NULL ;
          delete curr;
     }
}


int main ()
{
     node* node1 = new node(10) ;
     node* head = node1 ;
     node* tail = node1 ;

     print(head);

     Inserttail(tail,20);
     print(head);

     Inserttail(tail,30);
     print(head);

     insertatpossition(tail,head,40,4);
     print(head);

     cout << "head -- " << head->data << endl ;
     cout << "tail -- " << tail->data << endl ;

     return 0;
}