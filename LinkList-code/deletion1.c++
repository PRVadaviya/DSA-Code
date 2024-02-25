// delete generic element

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


void insert (node* &tail ,int d)
{
     node* temp = new node(d);
     tail -> next  = temp ;
     tail = tail -> next ;      // tail = temp ;
}


void deletion (node* &head ,node* &tail, int position)
{
     if(position == 1)
     {
          node* temp = head ;
          head = head -> next ;
          temp->next = NULL ;
          delete temp ;
     }
     else
     {
          node* curr = head ;
          node* prev = NULL ;

          int count = 1 ;

          while(count < position)
          {
               prev = curr ;
               curr = curr -> next ;
               count++;
          }

          prev->next = curr->next ;
          tail = prev ;                 // hw question , that solution 
          //curr->next = NULL ;
          delete curr;

     }

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

int main()
{
     node* node1 = new node(10);

     node* head = node1 ;                         //node1 is pointed both of (head,ail) this reason we passs
     node* tail = node1 ;                          //head then after print all element (check replace head to ail)
     print (head);                                //ail ma je change thase te head ma pan thase

     insert(tail , 20);
     print(head);

     insert(tail,30);
     print(head);

     deletion(head ,tail , 3);          // when delete last element tail point garbage value 
     print(head);
     
     cout << "head -- " << head->data << endl ;
     cout << "tail -- " << tail->data << endl ;

     return 0;
}