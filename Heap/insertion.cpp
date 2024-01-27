#include<iostream>
using namespace std ;
int arr[100] ;

class heap
{
public : 
          int size ;

          heap()
          {
               size = 0 ;
               arr[0] = -1 ;
          }

          void insert (int val)
          {
               size = size + 1 ;
               int index = size ;
               arr[index] = val ;

               while(index > 1)
               {
                    int parent = index/2 ;

                    if(arr[index] > arr[parent])
                    {
                         swap(arr[index] , arr[parent]);
                         index = parent ;
                    }
                    else
                    {
                         return ;
                    }
               }
          }

          void print ()
          {    
               for(int k = 1 ; k<=size ; k++)
               {
                    cout << arr[k] << " " ;

               }
          }
};


int main ()
{
     heap h ;

     h.insert(50);
     h.insert(20);
     h.insert(10);
     h.insert(80);
     h.insert(30);
     h.insert(100);
     h.print();

     return 0 ;
}