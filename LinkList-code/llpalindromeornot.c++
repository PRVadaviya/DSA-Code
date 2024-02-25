#include<iostream>
#include<vector>
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

int  palindrome (Node* &head) 
{
     vector<int>v1;
     Node* temp = head ;

     while(temp != NULL)
     {
          v1.push_back(temp ->data);
          temp = temp ->next ;
     }

     int n= v1.size();
     int e = n-1 ;
     int s=0 ;

     while(s<=e)
     {
          if(v1[s] != v1[e])
          {
               return 0 ;
          }

          s++;
          e--;

     }
     return 1;
}


int main()
{
     Node* Node1 = new Node(1);

     Node* head = Node1 ;
     Node* tail = Node1 ;
     Node* result = NULL ;
 
     insert(tail,2);
     insert(tail,4);
     insert(tail,1);

     print(head);

     cout << palindrome(head) << endl ;
 
     return 0;
}
