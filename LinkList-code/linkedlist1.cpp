// which value is enter in last it's print

#include<iostream>
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

void print (node* &head)
{
     node* ment = head ; 

     while(ment != NULL)
     {
          cout <<"data---"<< ment -> data << "\t" ;
          ment = ment -> next ;
     }

     cout << endl ;
}


int main()
{
     node* node1 = new node(10);
     //cout <<"data--"<< node1 -> data << endl ;
    // cout <<"next--"<< node1 -> next << endl ;
     node* head = node1 ;
     print (head);

     insert(head , 20);
     print(head);

     insert(head,30);
     print(head);

     insert(head,40);
     print(head);

     return 0;
}