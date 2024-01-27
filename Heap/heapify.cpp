#include<iostream>
using namespace std ;

void heapify(int arr[] , int n , int i)
{
     int larg = i ;
     int left = 2*i ;
     int right = 2*i + 1 ;

     if(left < n && arr[larg] < arr[left])
     {
          larg = left ;
     }

     if(right < n && arr[larg] < arr[right])
     {
          larg = right ;
     }

     if(larg != i)
     {
          swap(arr[larg] , arr[i]);
          heapify(arr , n , larg);
     }
}

int main ()
{
     int arr[6]={-1,54,53,55,52,50};
     int n = 5 ;

     for(int i = n/2 ; i>0 ; i--)
     {
          heapify(arr , n , i);
     }

     for(int j=1 ; j<=n ; j++)
     {
          cout << arr[j] << "  " ;
     }


     return 0 ;
}
