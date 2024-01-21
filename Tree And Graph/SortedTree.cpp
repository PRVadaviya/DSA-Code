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

void postorder(Node* root)
{
     if(root == NULL)
     {
          return ;
     }

     postorder(root->left);
     postorder(root->right);
     cout << root->data << "  " ;

}


int main()
{
     Node* root = NULL;

     takeinput(root);
     postorder(root);

     return 0;
}