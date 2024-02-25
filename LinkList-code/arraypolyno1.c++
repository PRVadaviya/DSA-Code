#include<iostream>
#include<vector>
using namespace std ;

class poly
{
     public :
               int coff;
               int expo;
};

void add(poly p1[100] ,poly p2[100],poly p3[100],int t1,int t2 )
{
     int i=0,j=0,k=0;
     int t3;

     while(i<t1 && j<t2)
     {
          if(p1[i].expo == p2[j].expo)
          {
               p3[k].coff = p1[i].coff + p2[j].coff ; 
               p3[k].expo = p1[i].expo ;
               i++;
               j++;
               k++;
          }
          else if(p1[i].expo > p2[j].expo)
          {
               p3[k].expo = p1[i].expo;
               p3[k].coff = p1[i].coff;
               k++;
               i++;
          }
          else if(p1[i].expo < p2[j].expo)
          {
               p3[k].expo = p2[j].expo;
               p3[k].coff = p2[j].coff;
               k++;
               j++;
          }
     }

     while(i<t1)
     {
          p3[k].expo = p1[i].expo;
          p3[k].coff = p1[i].coff;
          k++;
          i++;   
     }

     while(j<t2)
     {
          p3[k].expo = p2[j].expo;
          p3[k].coff = p2[j].coff;
          k++;
          j++;   
     }


     for(int i=0 ; i<k ; i++)
     {
     cout << p3[i].coff<<"X^"<<p3[i].expo<<" + ";
     }

}


int main ()
{
     int k1 ,k2 ,ans;
     poly p1[10],p2[10],p3[10];

     cin >> k1 >> k2 ;

     cout << "enter first " << endl ;

     for (int i=0 ; i<k1 ; i++)
     {
          cin >> p1[i].coff ;
          cout << "X^" ;
          cin >> p1[i].expo ;
          cout << "+" ;
     }

     cout << "enter second " << endl ;

     for (int i=0 ; i<k2 ; i++)
     {
          cin >> p2[i].coff ;
          cout << "X^" ;
          cin >> p2[i].expo ;
          cout << "+";
     }

    add(p1,p2,p3,k1,k2);

     return 0;
}