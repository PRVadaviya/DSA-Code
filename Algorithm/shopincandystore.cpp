#include<iostream>
#include<algorithm>
using namespace std ;


/*

     PV's approach to find minimum cost

int CandyShop(int price[] , int n , int k)
{
     bool check[n] = {false} ;
     int sum = 0 , p , q = n-1; 

     sort(price , price+n);

     for(int i=0 ; i<n ; i++)
     {
          p = k ;

          if(check[i] == false)
          {
               sum += price[i] ;
              check[i] = true ; 
          }

          while(p--)
          {
               if(check[q] == false)
               {
                    check[q] = true ;
                    q-- ;
               }         
          }
     }

     return sum ;
}
*/


void CandyShop (int price[] , int n , int k)
{
     sort(price , price+n);

     // find minimum

     int min = 0 ;
     int buy = 0 ;                 // we can buy cheapest candy (start of array) .
     int free = n-1 ;              // because we should be buy costly candy (end of array) .

     while(buy <= free)
     {
          min = min + price[buy] ;
          buy++ ;
          free = free - k ;
     }

     cout << "Minimum cost -> " << min << endl ;

     // maximum cost

     int maxi = 0 ;
     buy = n-1 ;                        // invertion of above details
     free = 0 ;

     while(buy >= free)
     {
          maxi = maxi + price[buy] ;
          buy--;
          free = free + k ;
     }

     cout << "Maximum cost -> " << maxi << endl ;

}

int main()
{
     int arr[4] = {3,2,1,4};

     CandyShop(arr , 4 , 2)  ;

     return 0 ;
}