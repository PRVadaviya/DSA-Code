#include<iostream>
#include<queue>
#include<bits/stdc++.h>
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

          Node(int d)
          {
               this->data = d ;
               this->left = NULL;
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
     root->left = BulidTree(root->left);
     
     cout << "enter a data for insert in right side of : " << data <<endl ;
     root->right = BulidTree(root->right);

     return root;

}


void Level(Node* root)
{
     if(root == NULL)
     {
          return ;
     }

     queue<Node*>q;

     q.push(root);

     while(!q.empty())
     {
          Node *curr = q.front() ;
          cout << curr->data << "  " ;

          if(curr->left != NULL)
          {
               q.push(curr->left);
          }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
          if(curr->right != NULL)
          {    
               q.push(curr->right);
          }

          q.pop();
     }

}

int main()
{
     Node* ans = NULL;
     ans = BulidTree(ans);

     Level(ans);
     
     return 0;
}


int integerBreak(int n) 
    {
        if(n<4)
            return (n-1);

            if((n%3) == 0)
            {
                return (pow(3,(n/3))) ;
            }
            else if((n%3) == 1)
            {
                return (pow(3,(n/3)-1)*4);
            }
            else if((n%3) == 2)
            {
                return (pow(3,(n/3))*2);        //  8 / 3 = 2 ,  8-2=6  => 3*3 = 6 
            }

            return 1 ;
    }