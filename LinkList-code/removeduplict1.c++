#include<iostream>
using namespace std; 

class Node
{
     public :
               int data;
               Node* next ;

               Node(int d)
               {
                    this -> data = d ;
                    this -> next = NULL ;
               }
};


void insert (Node* &tail ,int d)
{
     Node* temp = new Node(d);
     tail -> next  = temp ;
     tail = tail -> next ;      // tail = temp ;
}

void print (Node* &ail)
{
     Node* ment = ail ; 

     while(ment != NULL)
     {
          cout <<"data---"<< ment -> data << "\t" ;
          ment = ment -> next ;
     }

     cout << endl ;
}


Node *removeDuplicates(Node* head)
{
    if(head == NULL)
    {
        return NULL ;
    }
    
    Node* curr = head ;
    
    while(curr->next != NULL)
    {
        
        if((curr->next != NULL) && (curr->data) == (curr->next->data))
        {
            Node* next_to = curr -> next -> next ;
            
            Node* deletenode = curr->next ;
            delete (deletenode);            // also run (curr->next )
            
            curr -> next = next_to ;
        }
        else
        {
            curr = curr ->next ;
        }
        
    }

    return head ;
    
}


int main()
{
     Node* Node1 = new Node(10);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     print (head);

     insert(tail , 20);
     print(head);

     insert(tail,20);
     print(head);

     insert(tail,40);
     print(head);

     insert(tail,50);
     print(head);

     result = removeDuplicates(head);
     print(result);

     return 0;
}

