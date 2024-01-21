#include<iostream>
#include<map>
#include<list>
using namespace std ;

class Graph
{
     map<int,list<int>>l ;
     
public :

          void adge(int x , int y)
          {
               l[x].push_back(y);
               l[y].push_back(x);
          }

          void DFS(int scr , map<int,bool>&visited)
          {
               cout << scr << "  " ;
               visited[scr] = true ;

               for(auto nbrs : l[scr])
               {
                    if(!visited[nbrs])
                    {
                         DFS(nbrs , visited);
                    }
               }
          }

          void Bulidgraph(int scr)
          {
               map<int,bool>visited;

               for(auto nbr : l)
               {
                    int te = nbr.first ;
                    visited[te] = false ;
               }

               DFS(scr , visited);
          }

};


int main()
{

     Graph g ;
     g.adge(1,2);          
     g.adge(1,0);           
     g.adge(0,3);
     g.adge(2,3);
     g.adge(3,4);
     g.adge(4,5);
     g.Bulidgraph(1);

     return 0 ;
}