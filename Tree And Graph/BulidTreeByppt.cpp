#include<iostream>
using namespace std ;

class Node
{
public :
          Node* left ;
          Node* right;
          int data ;

          Node()
          {

          }
};

Node* makeNode()
{
     Node* temp = new Node();
     temp->left = NULL ;
     temp->right = NULL ;
     return temp;
}

void Insert(Node* &root , Node* New)
{
     char c;
     cout << "where are you insert left or right" << root->data << endl ;
     cin >> c ;

     if(c == 'l')
     {
          if(root->left== NULL)
               root->left=New;
          else
               Insert(root->left,New);
     }
     else if(c == 'r')
     {
          if(root->right == NULL)
               root->right = New;
          else
               Insert(root->right,New);
     }
     else
     {
          cout << "Invalid enter " << endl ;
     }

}

int main()
{
     Node* root ;
     Node* New ;
     root = NULL;
     int d ;
     char c ;
     do
     {
          cout << "enter a data" << endl;
          cin >> New->data ;

          if(root == NULL)
          {
               root = New ;
          }
          else
          {
               Insert(root , New);
          }

          cout << "do you want insert more element" ;
          cin >> c ;

     } while (c == 'y');
     
     return 0;
}