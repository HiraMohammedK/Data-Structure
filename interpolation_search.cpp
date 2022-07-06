#include<iostream>
using namespace std;

int interpoltion_search(int data[],int N,int item)
{
    int beg=0;
    int end=N-1;
    int loc;
    while (beg<=end and item>=data[beg] and item<=data[end])
    {
        loc=beg+((item-data[beg])/(data[end]-data[beg]))*(end-beg);
        if(item==data[loc])
        {
            return loc;
        }else if(item>data[loc])
        {
            beg=loc+1;      
        }else
        {
            end=loc-1;
        }
    }
    cout<<"\n";
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
 int pos = interpoltion_search(data,n,k);
 if (pos!=-1)
 {
		cout<<"Element "<<k <<" present at position "<<pos+1 <<endl;
 }
 else
 {
		cout<<k<<" not found in the given array"<<endl;
 }
 cout<<"\n";

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice: ";
 cin>>choice;
 }while(choice!=2);
  return 0;
}