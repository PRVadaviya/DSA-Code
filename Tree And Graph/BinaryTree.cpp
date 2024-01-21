#include<iostream>
using namespace std ;

class Node
{
     public :
               int data ;
               Node* Left;
               Node* right;

               Node()
               {

               }

               Node(int d)
               {
                    this->data = d ;
                    this->Left = NULL;
                    this->right = NULL;
               }
};


               void print (Node* root)
               {
                    while(root->right != NULL)
                    {
                         cout << root->data << "   " ;
                         root = root ->right ;
                    }
               }


              void Insert(Node* Root)
               {
                    Node* temp = Root;

                    char c ;
                    int d ;
                    cout << "where to insert left or right this element : "  << endl;
                    cin >> c ;
                    cout << "enter element what you want insert" << endl ;
                    cin >> d ;

                    if(Root == NULL)
                    {
                         Node* nn = new Node(d);
                         temp = nn;
                         Root = nn;
                         return ;
                    }

                    if(c == 'R')
                    {
                         if(temp->right == NULL)
                         {
                              Node* nn = new Node(d);
                              temp->right = nn;
                         }
                         else
                         {
                              Insert(temp->right);
                         }
                         
                    }
                    else if(c == 'L')
                    {
                         if(Root->Left == NULL)
                         {
                              Node* nn = new Node(d);
                              temp->Left = nn;
                         }
                         else
                         {
                              Insert(temp->Left);
                         }
                    }
                    else
                    {
                         cout << "invalid input" << endl ;
                    }

                    print(Root);
               }

int main ()
{
     int a,i=0;
     Node n1;
     Node* root = NULL;

     // while(1)
     // {
     //      cout << "do you want to insert more element then enter 1 otherwise enter 0" << endl ;
     //      cin >> a;

     //      if(a == 1)
     //           Insert(root);
     //      else
     //      {
     //           cout << " your tree is prepared " << endl ;
     //           break;
     //      }
     // }


          while(i<=3)
          {
               Insert(root);
               i++;
          }
     

     return 0 ;
}