#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

class Node
{
     public : 
               int data ;
               Node* left ;
               Node* right ;

               Node(int x)
               {
                    data = x ;
                    left = NULL ;
                    right = NULL ;
               }
};


class cmp
{
     public : 
               bool operator()(Node* a , Node* b)
               {
                    return a->data > b->data ;
               }
};

void transfer(string temp , Node* root , vector<string> ans )
{
     if(root->left == NULL && root->right == NULL)
     {
          ans.push_back(temp);
          return ;
     }

     transfer(temp + "0" , root->left , ans);
     transfer(temp + "1" , root->right, ans);
}


vector<string> HuffMan (string s , vector<int> f , int n)
{
     priority_queue< Node* , vector<Node*> , cmp > pq;

     for(int i=0 ; i<n ; i++)
     {
          Node* nn = new Node(f[i]) ;
          pq.push(nn);
     }

     while(pq.size() > 1)
     {
          // create sum node and adding tree
          Node* first = pq.top() ;
          pq.pop() ;

          Node* second = pq.top() ;
          pq.pop() ;

          Node* mergenode = new Node(first->data + second->data) ; 
          mergenode->left = first ;
          mergenode->right = second ;
          
          pq.push(mergenode);
 
     }

          // create vactor of left = 0 and right = 1
          
          Node* root = pq.top() ;
          string temp = "" ;
          vector<string> ans ;

          transfer(temp , root , ans); 

          return ans ;

}

int main()
{
     string pass = "abcdef" ;
     vector<int> fre = {5,9,12,13,16,45} ;

    vector<string>pnt = HuffMan(pass , fre , 6);

    for(int i=0 ; i<pnt.size() ; i++)
    {
          cout << pnt[i] << " " ;
    }
    
    return 0 ;
}