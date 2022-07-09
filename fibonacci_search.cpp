#include <iostream>
using namespace std;

int FibonacciSearch(int data[],int N,int item)
{
	int fb2 = 0;
	int fb1 = 1;
	int fb = fb1+fb2;
	while(fb<N){
		fb2 = fb1;
		fb1 = fb;
		fb = fb1+fb2;


	}
	int offset = -1;
	while(fb>1)
	{
		int i = offset + fb2;
		if(data[i]<item)
		{
			fb = fb1;
			fb1 = fb2;
			fb2 = fb - fb1;
			offset = i;
		}
		else if (data[i]>item)
		{
			fb = fb2;
			fb1 = fb1 - fb2;
			fb2 = fb -  fb1;
		}
		else
		{
			return i;
		}
	}
	if (fb==1 and data[offset+1]==item)
	{
		return offset+1;
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
 int pos = FibonacciSearch(data,n,k);
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
