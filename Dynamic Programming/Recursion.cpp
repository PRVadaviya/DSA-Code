#include<iostream>
#include<vector>
using namespace std ;

// top - down approach

int fib (int dp[] , int n)
{
     if(n == 1 || n == 0)
     {
          return n;
     }

     if(dp[n] != -1)
     {
          return dp[n] ;
     }

     dp[n] =  fib(dp , n-1) + fib(dp , n-2) ;

     return dp[n] ;
}


int main ()
{
     int n=7 ;
     int dp[n+1] ;

     for(int i=0 ; i<=n ; i++)
     {
          dp[i] = -1 ;
     }

     cout << fib(dp,n) << endl ;
     return 0 ;
}


// Bottom - Up approach


int fib (int n)
{
     int dp[n+1] ;

     dp[0] = 0 ;
     dp[1] = 1 ;

     for(int i=2 ; i<=n ; i++)
     {
          dp[i] = dp[i-1] + dp[i-2] ;
     }

     return dp[n] ;
}

int main() 
{
     cout << fib(7) << endl ;
     return 0 ;
}

// space optimization

int fib (int n)
{
     int a = 0 ;
     int b = 1 ;
     int curr ;

     for(int i=0 ; i<n ; i++)
     {
          curr = a + b ;

          b = a ;
          a = curr ;   
     }

     return a ;
}

int main() 
{
     cout << fib(7) << endl ;
     return 0 ;
}