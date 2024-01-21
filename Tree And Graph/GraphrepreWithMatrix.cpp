#include<iostream>
#include<vector>
using namespace std ;
const int n = 10e3;      //10^3
int graph[n+1][n+1];
vector<pair<int,int>> v[n];


void BulidMatrix(int n , int edge)
{
     int v1,v2,wt;
     cout << "enter a two link node" << endl ;

     for(int i=0 ; i<edge ; i++)
     {
          cin >> v1 >> v2 >> wt ;
          graph[v1][v2]=1;
          graph[v2][v1]=1;         //if graph is undirected

          v[v1].push_back({v2,wt});   
          v[v2].push_back({v1,wt});   
     }
}

void print(int n)
{

     for(int i=0 ; i<n ; i++)
     {
          for(int j=0 ; j<n ; j++)
          {
               cout << graph[i][j] << " ";
          }
          cout << endl ;
     }
}

int main()
{
     int n,edj ;
     cout << "enter a no of node and adj" << endl ;
     cin >> n >> edj ;
     BulidMatrix(n , edj);
     print(n);
     return 0;
}



