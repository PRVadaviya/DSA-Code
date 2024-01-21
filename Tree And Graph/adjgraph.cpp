#include<iostream>
#include<list>
using namespace std ;

class Graph
{
          int v;
          list<int> *l ;
public:
          Graph(int n)
          {
               this->v = n ;
               l = new list<int>[v] ;
          }

          void Bulid(int p , int q)
          {
               l[p].push_back(q) ;
               l[q].push_back(p);
          }

          void print()
          {
               for(int i=0 ; i<v ; i++)
               {
                    cout << "Vertex" << i << "->" ;
                    for(int nbr :l[i])
                    {
                         cout << nbr << " , " ;
                    }

                    cout << endl ;
               }
          }
};

int main ()
{
     Graph g(4) ;
     g.Bulid(0,1);
     g.Bulid(0,2);
     g.Bulid(1,3);
     g.Bulid(2,3);
     g.Bulid(0,3);
     g.print();

     return 0;
}



