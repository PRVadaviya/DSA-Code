#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Item
{
     public : 
               int value ;
               int weight ;
};

bool cmp(pair<double,Item> a , pair<double,Item> b)
{
     return a.first > b.first ;

}

double Francatinal(int w , Item arr[] , int n)
{
     double temp = 0 ;
     vector< pair<double,Item> > pq ;

     for(int i=0 ; i<n ; i++)
     {
          temp = (1.0)*arr[i].value / arr[i].weight ;
          pq.push_back({temp,arr[i]});

          /*
               pair<double,Item> p = make_pair(temp , arr[i]);
               pq.push_back(p);

          */     
     }

     sort(pq.begin() , pq.end() , cmp);

     double TotalAmount = 0 ;

     for(int i=0 ; i<n ; i++)
     {
          if(pq[i].second.weight > w)
          {
               // Franctional part
               TotalAmount += w * pq[i].first ;
               w = 0 ;
          }
          else
          {
               TotalAmount += pq[i].second.value ;
               w = w - pq[i].second.weight ;
          }
     }

     return TotalAmount ;
}


int main()
{
     int n = 3 ;
     Item a[n] ={{60,10},{100,20},{120,30}};

     cout << Francatinal(50 , a , n) << endl ;

     return 0 ;
}