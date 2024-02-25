// which value is insert those print last (line to line print )

#include<iostream>
using namespace std; 

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


void insert (node* &tail ,int d)
{
     node* temp = new node(d);
     tail -> next  = temp ;
     tail = tail -> next ;      // tail = temp ;
}


void print (node* &ail)
{
     node* ment = ail ; 

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
     node* head = node1 ;                         //node1 is pointed both of (head,ail) this reason we passs
     node* ail = node1 ;                          //head then after print all element (check replace head to ail)
     print (head);                                //ail ma je change thase te head ma pan thase

     insert(ail , 12);

     print(head);

     insert(ail,24);

     print(head);

     return 0;
}