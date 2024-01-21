#include<iostream>
using namespace std ;

class Node
{
     public :
               int data ;
               Node* Left;
               Node* right;

               Node(int d)
               {
                    this->data = d ;
                    this->Left = NULL;
                    this->right = NULL;
               }
};

int findit(int in[] , int element , int n)
{
     for(int i=0 ; i<n ; i++)
     {
          if(in[i] == element)
          {
               return i ;
          }
     }
     return 0;
}

Node* solve (int in[] , int post[] , int &index , int instart , int inend ,int n)
{
     if(index < 0 || instart > inend)
     {
          return NULL;
     }

     int element = post[index--];

     int pos = findit(in , element , n);
     Node* root = new Node(element);

     root->right = solve(in , post , index , pos+1 , inend , n);
     root->Left = solve(in , post , index , instart , pos-1 , n);
     
     return root ;

}

Node* BulidTree(int in[] , int post[] , int n)
{
     int postorderstart = n-1 ;
     Node* ans1 = solve(in , post , postorderstart , 0 , n-1 , n);
     return ans1;
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

int main ()
{
     int a[8]={4,8,2,5,1,6,3,7};
     int b[8]={8,4,5,2,6,7,3,1};
     Node* ans = BulidTree(a , b, 8);
     preorder(ans);

     return 0 ;
}