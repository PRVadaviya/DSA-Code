#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<vector>
using namespace std ;
const int N = 10e3 ;
class Graph
{
          vector<pair<int,int>>g[N];
          set<pair<int,int>>st ;
public:

          void adge(int x,int y,int wt)
          {
               g[x].push_back({y,wt});
               //directed graph that reason .....
          }

          void dijikstra(int scr)
          {
               vector<int> visited(N,0) ;
               vector<int>dist (N , 0);


               st.insert({0,scr});      //(distant , node value)
               dist[scr] = 0;           //new distanted node create

               while(st.size() > 0)
               {
                    auto node = *st.begin();      // auto is here pair type
                    int v = node.second ;
                    int v_dist = node.first ;
                    st.erase(st.begin());

                    if(visited[v])
                    {
                         continue ;
                    }

                    visited[v] = 1 ;

                    for(auto child : g[v])
                    {
                         int child_v = child.first ;        // in this pair first is node value and second is wt(distant)
                         int wt = child.second ;            // here , input node 

                         if(dist[v] + wt < dist[child_v])
                         {
                              dist[child_v] = dist[v] + wt ;
                              st.insert({dist[child_v] , child_v});
                         }
                    }
               }

               print(st);
          }

          void print(set<pair<int,int>>ans)
          {
               cout << "fth" ;
                for(auto it=ans.begin(); it!=ans.end(); ++it) 
               { 
                    cout << "we";
                    cout<< it->first <<" "<< it->second <<endl; 
               }

          }
};


int main()
{
     Graph g;
     g.adge(1,2,12);
     g.adge(1,4,5);
     g.adge(4,3,2);
     g.adge(3,2,3);
     g.dijikstra(1);
     return 0;
}