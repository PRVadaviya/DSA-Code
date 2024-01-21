#include<iostream>
#include<vector>
using namespace std ;
const int N = 10e3 ;
vector<pair<int,int>>v[N] ;

void BulidGraph(int n , int ed)
{
     int v1,v2,wt;
     cout << "enter vertex 1 , vertex 2 and weighted" << endl ;
     for(int i = 0 ; i<ed ; i++)
     {
          cin>>v1>>v2>>wt;
          v[v1].push_back({v2,wt});
          v[v2].push_back({v1,wt});
     }

}

void print(int n)
{
     int cnt = 0 ;
     for(int cnt=0 ; cnt< n ; cnt++)
     {
          // pair<int,int> a ;
          // a = v[cnt][cnt] ;
          // cout << cnt << "-->" << a.first << "  " << a.second << endl ;  
     
          for (pair<int,int> i : v[cnt])
          {
               cout << i.first << i.second ;

          }
     }
}

int main()
{
     int n,ad ;
     cout << "enter a no of node and adj" << endl ;
     cin >> n >> ad ;
     BulidGraph(n,ad);
     print(ad);
     return 0;
}



