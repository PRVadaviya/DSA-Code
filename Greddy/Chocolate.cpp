#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
using namespace std ;

int Chocolate(vector<int> &a , int m)
{
     sort(a.begin() , a.end());

     int i = 0 , j = m-1 , diff , mini = INT_MAX ;

     while(j < a.size() )
     {
          diff = a[j] - a[i] ;
          mini = min(mini , diff);
          i++ ;
          j++ ;
     }

     return mini ;
}


int main()
{
     vector<int>cho = {1,2,4,6,5,7} ;

     cout << Chocolate(cho , 3) << endl ;

     return 0 ;
}