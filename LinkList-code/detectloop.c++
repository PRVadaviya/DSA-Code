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

void insert (node* &head ,int d)
{
     node* temp = new node(d);
     temp -> next = head ;
     head = temp ;
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

bool DetectLoop (node* head)
{
     node* temp = head ;
     map <node* , bool> visited ;

     if(temp == NULL)
     {
          return false ;
     }

     while(temp != NULL)
     {
          if(visited[temp] == true )         // inbulid fuction
          {
               cout << temp->data << endl ;
               return true;
          }

          visited[temp] = true ;
          temp = temp -> next ;
     }

     return false ;
     
}


int main()
{
     node* node1 = new node(10);

     node* head = node1 ;
     node* tail = node1 ;

     print (tail);

     insert(tail , 20);
     print(tail);

     insert(tail,30);
     print(tail);

     insert(tail,40);
     print(tail);

     insert(tail,50);
     print(tail);


     head->next = tail->next ;    //add in prev 

     cout << DetectLoop(head) << endl ;

     return 0;
}