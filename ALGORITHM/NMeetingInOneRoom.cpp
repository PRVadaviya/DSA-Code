#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool cmp(pair<int,int> a , pair<int,int> b )
{
     return a.second < b.second ;
}


int MaxMeeting(int start[] , int end[] , int n)
{
     vector<pair<int,int>> v ;
     int cnt = 0 ;

     for(int i=0 ; i<n ; i++)
     {
          pair<int,int> p = make_pair(start[i] , end[i]);
          v.push_back(p);
     }

     sort(v.begin() , v.end() , cmp);

     int strmet = v[0].first ;
     int endmet = v[0].second ;
     cnt++ ;

     cout << strmet << "  " << endmet <<  endl ;

     for(int i=1 ; i<n ; i++)
     {
          if(endmet < v[i].first)
          {
               cout << v[i].first << "  " << v[i].second <<  endl ;
               cnt++ ;
               endmet = v[i].second ;
          }
     }

     return cnt ;
}


int main()
{
     int start[6] = {1,3,0,5,8,5};
     int end[6] = {2,4,6,7,9,9};

     cout << MaxMeeting(start,end,6) << endl ;

     return 0;
}