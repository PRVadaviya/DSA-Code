#include<iostream>
using namespace std;

class heap
{
    public:
 
    int size;
    int arr[100];

    heap()
    {
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        int parent;

        while(index > 1)
        {
            parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
        
    }

    void deletefromheap()
    {

        if(size == 0)
        {
            cout<<"NO delete" <<endl;
            return;
        }
        arr[1]=arr[size];
        size--;

        int i = 1;
        while(i < size)
        {
            int leftindex = 2*i; 
            int rightindex = 2*i+1; 

            if(size > leftindex && arr[i] < arr[leftindex])
            {
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(size > rightindex && arr[i] < arr[rightindex])
            {
                swap(arr[i],arr[rightindex]);
                i=rightindex; 
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i ;
    int right = 2*i + 1;
    
// starting from 1 index that is >=

    if(n>=left && arr[i]<arr[left])
    {
        largest = left;    
    }

    if(n>=right && arr[i]<arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
       swap(arr[largest],arr[i]);
       heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n)
{
    int size = n;

    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);

    }
}


int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();


    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"heapify arr is :"<<endl;

    for(int i=1;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;

    heapsort(arr,n);

    cout<<"heapsort arr is :"<<endl;

    for(int i=1;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;



}