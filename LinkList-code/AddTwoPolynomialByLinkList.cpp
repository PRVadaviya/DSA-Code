#include<iostream>
using namespace std ;

class poly 
{

public :
          int coff ;
          int expo ;
          poly* next ;
          poly* head ;

          poly(int co , int ex)
          {
               coff = co ;
               expo = ex ;
               this ->next = NULL ;
               head = NULL;
          }

          poly()
          {

          }

          void insert ( int co , int ex)
          {
               if(this->head == NULL)
               {
                    poly* temp = new poly(co,ex);
                    head = temp ;
                    return ;
               }
               else
               {
                    poly* temp = new poly(co,ex);
                    poly *t = head;
                    while(t -> next != NULL)
                    {
                         t = t -> next;
                    }
                    t -> next = temp;
                    return ;

               }

          }

          void addition ( poly p1,poly p2,int k1,int k2)
          {

               poly p3(0,0) ;
               
               poly* index1 = p1.head ;
               poly* index2 = p2.head ;
               int i=0,j=0;

               while(i<k1 && j<k2)
               {
                         if(index1->expo == index2->expo)
                         {  
                              p3.insert((index1->coff+index2->coff ) , (index1->expo));
                              index1 = index1->next;
                              index2 = index2->next;
                              i++;
                              j++;
                         }
                         else if(index1->expo > index2->expo)
                         {
                              p3.insert((index1->coff) , (index1->expo));
                              index1 = index1->next;
                              i++;
                         }
                         else if(index1->expo < index2->expo)
                         {
                              p3.insert((index2->coff) , (index2->expo));
                              index2 = index2->next;
                              j++;
                         }
               }

               while(i<k1)
               {
                    p3.insert((index1->coff) , (index1->expo));
                    index1 = index1->next;
                    i++;
               }

               while(j<k2)
               {
                    p3.insert((index2->coff) , (index2->expo));
                    index2 = index2->next;
                    j++;
               }

               poly* res = p3.head ;

               while(res != NULL)
               {
                    cout << res->coff<<"X^"<<res->expo<<"+ " ;
                    res = res->next ;
               }
          }
};



int main ()
{
     poly p1(0,0) ;
     poly p2(0,0),p4(0,0) ;

     int k1 ,k2 , ex , co ;
     //poly* r1 = NULL ;
     //poly* r2 = NULL ;

     cout << "enter a no of node1" << endl   ;
     cin >> k1 ;
     cout << "enter a no of node2" << endl   ;
     cin >> k2 ;

     cout << "enter first ll" << endl ;
     for(int i=0 ; i<k1 ; i++)
     {
          cout << "coff "<<i+1 <<":" ;
          cin >> co ;
          cout << "expo "<<i+1 <<":" ;
          cin >> ex ;

          p1.insert(co,ex);
     }

     cout << "enter a second ll" << endl ;

     for(int i=0 ; i<k2 ; i++)
     {
          cout << "coff "<<i+1 <<":" ;
          cin >> co ;
          cout << "expo "<<i+1 <<":" ;
          cin >> ex ;

          p2.insert(co,ex);
     }

     p4.addition(p1,p2,k1,k2);

     return 0;

}