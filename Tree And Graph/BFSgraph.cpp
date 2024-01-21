#include<iostream>
#include<list>
#include<queue>
#include<map>

using namespace std ;

class Graph
{
     map< string , list<string> > l ;
public :

          void edgebulid(string x ,string y)
          {
               l[x].push_back(y);
               l[y].push_back(x);
          }

          void bft(string scr)
          {
               queue<string> q ;
               map<string,bool>visited ;

               q.push(scr);
               visited[scr] = true ;

               while(!q.empty())
               {
                    string te = q.front();
                    q.pop();
                    cout << te << "  " ;
                    for(string s : l[te])
                    {
                         if(!visited[s])
                         {
                              q.push(s);
                              visited[s] = true ;
                         }
                    }
               }
          }
};




int main ()
{
     Graph g ;
     g.edgebulid("A" , "B" );          //when write false graph make directed
     g.edgebulid("A" , "C" );           //when write true graph make undirected
     g.edgebulid("D" , "E" );
     g.edgebulid("E" , "C" );
     g.edgebulid("C" , "D" );
     g.bft("A");


     return 0 ;
}