#include<iostream>
#include<algorithm>
#include<string>
#include <bits/stdc++.h>
using namespace std ;

/*   PV's approach


string ReverseWord (string s1)
{
     int len = s1.size() ;
     string temp="" ,ans = "";

     for(int i=len-1 ; i>=0 ; i--)
     {
          if(s1[i] == ' ')
          {
               cout << temp << endl;
               ans = ans + string(temp.rbegin() , temp.rend()) + " " ;
               temp = "" ;
          }
          else
          {
               temp = temp + s1[i] ;
          }
     }

     reverse(temp.begin() , temp.end());
     ans += temp ;

     return ans ;
}
*/



string ReverseWord (string s1)
{
     int len = s1.size() ;
     string temp="" ,ans = "";

     for(int i=len-1 ; i>=0 ; i--)
     {
          if(s1[i] == '.')
          {
               reverse(temp.begin() , temp.end());
               ans += temp + "." ;
               temp = "" ;
          }
          else
          {
               temp = temp + s1[i] ;
          }

     } 

     reverse(temp.begin() , temp.end());
     ans += temp ;

     return ans ;
}


int main()
{
     cout << ReverseWord("i.like.very.much") << endl ;
 
 
    return 0 ;
}