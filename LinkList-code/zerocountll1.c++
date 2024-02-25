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

Node* Nodesort (Node* &head) 
{
     int zero =0 ;
     int first =0 ;
     int second = 0 ;

     Node* result = NULL ;
     Node* temp = head ;

     while(temp -> next != NULL)
     {
          if(temp->data==0)
               zero++;
          else if(temp->data==1)
               first++;
          else if(temp->data==2)
               second++;

          temp = temp ->next ;
     }

     temp = head ;

     while(temp -> next != NULL)
     {
          if((zero) != 0)
          {
          temp->data=0 ;
          zero--;
          }
          else if((first) != 0)
          {
          temp->data=1 ;
          first--;
          }
          else if((second) != 0)
          {
          temp->data=2 ;
          second--;
          }

          temp = temp -> next ;
     }

     return head ;

}


int main()
{
     Node* Node1 = new Node(0);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     insert(tail,1);
     insert(tail,2);
     insert(tail,0);
     insert(tail,2);
     insert(tail,1);
     insert(tail,2);
     print(head);

     result=Nodesort(head);
     print(result);


     return 0;
}
