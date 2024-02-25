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

               ~node()
               {
                    int a = this->data ;

                    if(this->next != NULL)
                    {
                         delete next;
                         next = NULL ;
                    }

                    cout << "run destructor" << a << endl ;
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

void deletion (node* tail , int value )
{
     if(tail == NULL)
     {
          cout << "not a posible" << endl ;
     }
     else
     {
          node* prev = tail ;
          node* curr = prev -> next ;

          while(curr->data != value)
          {
               prev = curr ;
               curr = curr->next;
          }

          // print karva mate 

          if(curr == prev)  //1 node ll
          {
               tail = NULL ;
          }
          else if(curr == tail)  //>=2  node ll  
          {
               tail = prev ;
          }

          prev->next = curr->next;
          curr->next = NULL ;
          delete curr ;
     }
}


int main ()
{
     node* tail = NULL ;

     insertnode(tail,5,3);
     print(tail);

     insertnode(tail,3,5);
     print(tail);

     insertnode(tail,5,7);
     print(tail);

     insertnode(tail,7,9);
     print(tail);

     insertnode(tail,5,10);
     print(tail);

     deletion(tail,9);
     print(tail);


     return 0;
}