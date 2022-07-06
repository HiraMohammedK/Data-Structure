#include<iostream>
using namespace std;

int Linear_Search(int data[],int N,int item)
{
    int pos;
    for(pos=1;pos<N;pos++)
    {
    	if (data[pos] == item)
    	{
    		 
    		return pos;
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
 int loc = Linear_Search(data,n,k);
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
