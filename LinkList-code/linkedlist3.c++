//insert middle node
// generic code
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


void inserthead(node* &head , int d)
{
     node* temp = new node(d);
     temp -> next = head ;
     head = temp ;
}

void inserttail (node* &ail ,int d)
{
     node* temp = new node(d);
     ail -> next  = temp ;
     ail = ail -> next ;      // ail = temp ;
     
}

void midinsert (node* &tail , node* &head , int position , int d)
{
     int count = 1;
     node* temp = head ;

     while(count < position-1)
     {
          temp = temp ->next ;
          count++;
     }

     if(position==1)
     {
          inserthead(head , d);
          return ;
     }

     if(temp -> next == NULL)
     {
          inserttail(tail , d);
          return;
     }

     node* midvalue = new node(d);

     midvalue->next = temp ->next;

     temp -> next = midvalue ;
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

     inserttail(ail , 12);

     print(head);

     inserttail(ail,24);

     print(head);

     midinsert(ail , head , 4 , 38);

     print(head);
     
     cout << ail->data << endl ;
     
     cout << head->data << endl ;
     return 0;
}