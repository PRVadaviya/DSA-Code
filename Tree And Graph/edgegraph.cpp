#include<iostream>
#include<unordered_map>
#include<list>
using namespace std ;

class Graph
{
     unordered_map<string,list< pair<string,int> >> l;

public:

          void edgebulid(string n , string sn , int wt , bool ch)
          {
               l[n].push_back(make_pair(sn,wt));

               if(ch)
               {
                    l[sn].push_back(make_pair(n,wt));
               }
          }

          void print ()
          {
               for(auto p : l)
               {
                    string node = p.first ;
                    list<pair<string,int>>nbrs = p.second;
                    cout << node << " -> ";

                    for(auto sn : nbrs)
                    {    
                         string ch = sn.first ;
                         int wa = sn.second ;

                         cout << "(" << ch << "," << wa <<") " ;
                    }

                    cout << endl ;
               }

          }


};

int main()
{
     Graph g ;
     g.edgebulid("A" , "B" , 10 ,false);          //when write false graph make directed
     g.edgebulid("A" , "C" , 3 ,false);           //when write true graph make undirected
     g.edgebulid("A" , "D" , 5 ,false);
     g.edgebulid("D" , "E" , 7 ,false);
     g.edgebulid("E" , "C" , 9 ,false);
     g.edgebulid("C" , "D" , 15 ,true);
     g.print();

     return 0;
}