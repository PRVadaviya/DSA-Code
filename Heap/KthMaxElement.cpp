// priority queue is store element in decending order (9,5,2,1)

#include<iostream>
#include<queue>
using namespace std ;

// l is staring index
// r is ending index
// k is Kth smallest index

int  KthMaxElEment(int arr[] , int l , int r , int k) 
{
     priority_queue<int>ele ;

     // k element push in queue 

     for(int i=0 ; i<k ; i++)
     {
          ele.push(arr[i]);
     }

     // consider only r-k element 
     for(int j = k ; j<=r ; j++)
     {
          if(arr[j] < ele.top())
          {
               ele.pop();
               ele.push(arr[j]);
          }
     }

          return (ele.top());
}

int main()
{
     int a[7] = {3,6,13,5,26,20,8};
     cout << KthMaxElEment(a,0,6,1) << endl ; 

}