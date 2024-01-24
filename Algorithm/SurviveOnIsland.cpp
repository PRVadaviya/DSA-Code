#include<iostream>
using namespace std ;

int Survive(int n , int m ,int s)       // write on notes
{

     int sunday = s/7 ;
     int buy = s - sunday ;
     int totalfood = s*m ;
     int ans = 0 ;

     if(totalfood % n == 0)
     {
          ans = totalfood / n ;
     }
     else
     {
          ans = totalfood / n + 1 ;
     }

     if(buy <= ans)                     // pass to test case those written on note 
     {
          return -1 ;
     }
     else
     {
          return ans ;
     }
}




int main ()
{
     cout << Survive(1,1,10) << endl ;
     return 0;
}