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

Node* BulidTree (Node* root)
{
     int data ;
     cout << "enter a data "  << endl ;
     cin >> data ;
     root = new Node(data);

     if(data == -1)
     {
          return NULL;
     }

     cout << "enter a data for insert in left side of : " << data <<endl ;
     root->Left = BulidTree(root->Left);
     
     cout << "enter a data for insert in right side of : " << data <<endl ;
     root->right = BulidTree(root->right);

     return root;
}

void inorder(Node* root)
{
     if(root == NULL)
     {
          return ;
     }

     inorder(root->Left);
     cout << root->data << "  " ;
     inorder(root->right);
}

void preorder(Node* root)
{
     if(root == NULL)
     {
          return ;
     }

     cout << root->data << "  " ;
     preorder(root->Left);
     preorder(root->right);

}

void postorder(Node* root)
{
     if(root == NULL)
     {
          return ;
     }

     postorder(root->Left);
     postorder(root->right);
     cout << root->data << "  " ;

}

int main()
{
     Node* ans = NULL;
     ans = BulidTree(ans);
     inorder(ans);
     cout << endl ;
     preorder(ans);
     cout << endl ;
     postorder(ans);
     cout << endl ;

     return 0;
}


