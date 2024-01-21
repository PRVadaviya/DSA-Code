#include<iostream>
using namespace std ;

class Node
{
public: 
          int data;
          Node* left;
          Node* right;

          Node(int d)
          {
               data = d ;
               this->left = NULL ;
               this->right = NULL ;
          }
};

Node* InsertBst(Node* root , int d )
{
     if(root == NULL)
     {
          root = new Node(d);
          return root;
     }

     if(d > root->data)
     {
          root->right = InsertBst(root->right , d);
     }
     else
     {
         root->left = InsertBst(root->left , d); 
     }

     return root ;

}

void takeinput(Node* &root)
{ 
     int d ;
     cin >> d ;

     while(d != -1)
     {
          root = InsertBst(root , d);
          cin >> d ;
     }

}

//iterative

bool SearchBST(Node* root , int key)
{
     Node* temp = root ;

     while(temp != NULL)
     {
          if(temp->data == key)
          {
               return true ;
          }

          if(key > root->data)
          {
               temp = temp ->right ;
          }
          else
          {
               temp = temp ->left ;
          }
     }

     return false ;
}

/*
//recursive
bool SearchInBST(Node* root , int key)
{
     if(root == NULL)
     {
          return false;
     }

     if(root->data == key)
     {
          return true ;
     }

     if(key>root->data)
     {
          return SearchInBST(root->right , key);
     }
     else
     {
          return SearchInBST(root->left , key);
     }
}
*/

int main()
{
     int x,y ;
     Node* root = NULL;

     takeinput(root);

     cout << endl << "which element you want to find " <<endl ;
     cin >> x ;

     SearchBST(root , x) == 1 ?  cout << "Is Here" << endl : cout << "Is not Here" << endl ;
     

     return 0;
}

