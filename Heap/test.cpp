#include <iostream>
using namespace std;

int main() 
{
	
	int n,a[3];
	cin >> n ;
	
	while(n--)
	{
	    int num,avg,add;
	    cin >> num;
	    
	    avg = num/3;
	    add = num%3;
	    
	    if(add%2 == 0)
	    {
	        a[0] = avg + (add/2) ;
	        a[1] = avg + (add/2) ;
	        a[2] = avg ;
	    }
	    else
	    {
	        a[0] = avg + add ;
	        a[1] = avg ;
	        a[2] = avg ;
	        
	    }
	    
	    cout << a[0]<<" "<< a[1] <<" " << a[2] << endl ;
	    
	}
	return 0;
}
