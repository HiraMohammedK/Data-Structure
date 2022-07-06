#include<iostream>
using namespace std;

int ternary_search(int data[],int N,int item)
{
    int beg=0;
    int end=N-1;
    int mid1,mid2;
    
    while (beg<=end)
    {
        mid1=((end-beg)/3)+beg;
        
        mid2=2*((end-beg)/3)+beg;
     
        if(item==data[mid1])
        {
            return mid1;
        }
         else if(item==data[mid2])
         {
            return mid2;
        }
         else if(item<data[mid1])
         {
            end=mid1-1;
        }
         else if(item>data[mid2])
         {
            beg=mid2+1;
        }
         else if (item<data[mid2] and item>data[mid1])
         {
            beg=mid1+1;
            end=mid2-1;
        } 
    }
    return -1;    
}
int main()
{
    int k,n;
 int choice=1;
 do
 {
    int count=0;
 int *data;
 cout<<"Enter the number of elements of the array: ";
 cin>>n;
 cout<<"Enter the elements of the array: ";
  for(count=0; count<n; count++)
  {
      cin>>data[count];
  }
 cout<<"Enter element to search: ";
 cin>>k;
 int loc = ternary_search(data,n,k);
 if (loc!=-1)
 {
		cout<<"Element "<<k <<" present at position "<<loc+1 <<endl;
 }
 else
 {
		cout<<k<<" is not present in the given array"<<endl;
 }
 cout<<"\n";

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice: ";
 cin>>choice;
 }while(choice!=2);

    
    return 0;
}