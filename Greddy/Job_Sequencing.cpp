#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Job
{
     public : 
               int profit ;
               int id ;
               int deadline;
};

bool cmp (Job a , Job b)
{
     return a.profit > b.profit ;
}


int Job_Sequencing(Job arr[] , int n)
{
     sort(arr , arr + n , cmp);

     int maxDeadLine = INT_MIN ;

     for(int i=0 ; i<n ; i++)
     {
          maxDeadLine = max(maxDeadLine , arr[i].deadline) ;
     }

     vector<int> schedule(maxDeadLine+1 , -1) ;

     int maxProfit = 0 ;
     int count = 0 ;

     for(int i=0 ; i<n ; i++)
     {
          int currProfit = arr[i].profit ;
          int currDeadLine = arr[i].deadline ;
          int currId = arr[i].id ;

          for(int k = currDeadLine ; k>0 ; k--)
          {
               if(schedule[k] == -1)
               {
                    count++ ;
                    maxProfit += currProfit ;
                    schedule[k] = currId ;
                    break;
               }
          }
     }

     cout << count << endl ;

     return maxProfit ;
}


int main()
{
     int n = 4 ;
     Job pass[n] = {{20,1,4},{10,2,1},{40,3,1},{30,4,1}};

     cout << Job_Sequencing(pass , n) << endl ;
     return 0 ;
}
