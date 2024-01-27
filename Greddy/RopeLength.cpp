#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

int RopeLength(long long arr[] , long long n)
{
     priority_queue< long long , vector<long long> , greater<long long> > pq ;
     
     for(int i=0 ; i<n ; i++)
     {
          pq.push(arr[i]);
     }

     long long cost = 0 , mergelength ;

     while(pq.size() > 1)
     {
          long long first = pq.top();
          pq.pop();

          long long second = pq.top();
          pq.pop() ;

          mergelength = first + second ;

          cost += mergelength ;

          pq.push(mergelength);

     }

     return cost ;

}


int main()
{
     long long rope[] = {3,4,2,6} ;

     cout << RopeLength(rope , 4) << endl ;


     return 0 ;
}