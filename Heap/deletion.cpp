#include<iostream>
using namespace std ;
int arr[100] ;


class heap
{
public :

          int size;

          heap()
          {
               size = 0;
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
               cout << endl ;
          }

          void deletefromheap()
          {
               //first node replace by last node
               arr[0] = arr[size] ;

               //remove last node 
               size-- ;

               int i=1 ;

               while(i<size)
               {
                    int leftindex = 2*i ;
                    int rightindex = 2*i+1 ;

                    if(arr[leftindex] > arr[i] && leftindex < size)
                    {
                         swap(arr[leftindex] , arr[i]);
                         i = leftindex ;
                    }
                    else if(arr[rightindex] > arr[i] && rightindex < size)
                    {
                         swap(arr[rightindex] ,  arr[i]);
                         i = rightindex ;
                    }
                    else
                    {
                         return ;
                    }
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
     h.deletefromheap();
     h.print();

     return 0 ;
}

