#include<iostream>
using namespace std ;

int queue[5];
const int n = 5 ;
int front=-1 , rear = -1 ;

void insert (int i)
{
    if(front==(rear+1)%n)
    {
        cout <<"queue is full" << endl ;
        return ;
    }
    
    if(front==-1)
    {
        rear=0;
        front=0;
        queue[rear]=i;
        cout << "this element is inserted :" << queue[rear] << endl ; 
        return ;  
    }
    else
    {
        rear=(rear+1)%n ;
        queue[rear] = i ;
        cout << "this element is inserted :" << queue[rear] << endl ;
    }
}

void qdelete()
{
    if(front==rear)
    {
        cout << "this element is deleted :" << queue[front] << endl ; 
        front=rear=-1;
    }

    if(front==-1)
    {
        
        cout << "queue is empty" << endl ;
        return ;
    }
    else
    {
        cout << "this element is deleted :" << queue[front] << endl ;
        front = (front+1)%n;
    }
}

int main ()
{
    insert(10);
    insert(20);
    insert(30);
    insert(23);
    insert(64);
    qdelete();
    qdelete();
    qdelete();
    
    insert(33);
    insert(66);
    insert(99);
    insert(20);
    
    return 0;
}