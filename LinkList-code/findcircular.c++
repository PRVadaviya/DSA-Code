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

bool iscircular(node* &head)
{
     node* temp = head->next ;

    if (head == NULL) 
    {
      return true; 
    }

//     if (head->next == NULL) 
//       {
//           if(head->next->next == head)
//           return true;
//           else
//           return false;
//       }

      while (temp != NULL && temp != head)
       {
        temp = temp ->next;
    }

    if(temp == head)
        return true ;
    else
        return false ;
      
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

     insertnode(tail,9,10);
     print(tail);

     insertnode(tail,3,4);
     print(tail);

     cout << iscircular(tail) << endl ;     

     return 0;
}

