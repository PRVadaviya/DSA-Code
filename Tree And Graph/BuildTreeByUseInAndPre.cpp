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

Node* solve (int in[] , int pre[] , int index , int instart , int inend ,int n)
{
     if(index >= n || instart > inend)
     {
          return NULL;
     }

     int element = pre[index++];
     int pos = findit(in , element , n);

     Node* root = new Node(element);

     root->Left = solve(in , pre , index , instart , pos-1 , n);
     root->right = solve(in , pre , index , pos+1 , inend , n);

     return root ;

}

Node* BulidTree(int in[] , int pre[] , int n)
{
     int preorderstart = 0 ;
     Node* ans1 = solve(in , pre , preorderstart , 0 , n-1 , n);
     return ans1;
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

int main ()
{
     int a[4]={2,4,6,8};
     int b[4]={2,4,8,6};
     Node* ans = BulidTree(a , b, 4);
     postorder(ans);

     return 0 ;
}