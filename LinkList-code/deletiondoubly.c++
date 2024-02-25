
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

void Inserttail (node* &tail , int d)
{
     node* temp = new node(d);
     temp ->prev = tail ;
     tail-> next = temp ;
     tail = temp ;

}

void deletiondoubly(node* &head,node* &tail, int pos)
{
     node* temp = head ;
     node* curr = head ;
     node* prev = NULL ;
     int count=1;

     if(pos == 1)
     {
          node* memp = head ;
          head = head -> next ;
          head ->prev = NULL ;
          memp->next = NULL ;
          memp->prev = NULL ;
          delete memp ;
     }

     while(count < pos)
     {
          prev = curr ;
          curr = curr -> next ;
          count++;
     }

     if(curr->next == NULL)
     {
          curr->prev = NULL ;
          prev->next = NULL ;
          tail=prev;  
          delete curr ;    
     }
     else
     {
          prev->next = curr->next ;
          curr->prev = NULL ;
          curr->next->prev = NULL ;
          curr -> next = NULL ;
          delete curr ; 
     }

}

int main ()
{
     node* node1 = new node(10) ;
     
     node* tail = node1 ;
     node* head = node1 ;

     print(head);

     Inserttail(tail,20);
     print(head);

     Inserttail(tail,30);
     print(head);

     Inserttail(tail,40);
     print(head);

     cout << head->data << endl; 

     deletiondoubly(head,tail,2);
     print(head);

     cout << head->data << endl; 
     cout << tail->data << endl; 
 

     return 0;
}