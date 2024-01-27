#include<iostream>
#include<vector>
using namespace std ;

void heapify(vector<int>&arr , int n , int i)
{
     int larg = i ;
     int left = 2*i + 1;
     int right = 2*i + 2 ;

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


vector<int> mergetwo (vector<int>&heap1 , vector<int>&heap2)
{
     vector<int>ans ;

    // copy(heap1.begin(), heap1.end(), back_inserter(heap2));

     //bulid merge vector 

    for(int i=0 ; i<heap1.size() ; i++)
    {
          ans.push_back(heap1[i]);
    } 

    for(int i=0 ; i<heap2.size() ; i++)
    {
          ans.push_back(heap2[i]);
    } 

     // bulid merge heap 

    int size = ans.size();

    for(int i = size/2 - 1 ; i>=0 ; i--)
    {
          heapify(ans , size , i);
    }

    return ans ;

}

int main()
{

     vector<int>a {1,2,3,4};
     vector<int>b {5,6,7,8};
     vector<int>answer ;

     answer = mergetwo(a,b);

     for(auto i : answer)
     {
          cout << i << " ";
     }

     return 0 ;
}