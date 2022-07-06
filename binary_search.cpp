#include<iostream>
using namespace std;
int binary_search(int data[],int LB,int UB,int item)
{
    int beg=LB,pos;
    int i=0;
    int end=UB;
    int mid=(beg+end)/2;    
    while(data[mid]!=item and beg<=end)
    {
        
        if(item>data[mid])
        {
            beg=mid+1;
        }else
        {
            end=mid-1;
        }
        mid=(beg+end)/2;
        
    }
    if(data[mid]==item)
    {
        pos=mid+1;
    }else
    {
        pos=-1;
    }
    return pos;
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
 int loc = binary_search(data,0,n,k);
 if (loc!=-1)
 {
		cout<<"Element "<<k <<" present at position "<<loc <<endl;
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