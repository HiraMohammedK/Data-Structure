#include<iostream>
using namespace std;

void InsertionSort(int data[], int N) 
{
   int temp,k,ptr;
   for(k=1;k<N;k++)
   {
       temp=data[k];
       ptr=k-1;
       while(temp<data[ptr])
       {
           data[ptr+1]=data[ptr];
           ptr=ptr-1;
       }
      data[ptr+1]=temp;
   }
    
    
    for(int i = 0; i<N; i++)
    {
      cout << data[i] << " ";

    }
    cout << endl;
}
int main()
{
   int n;
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
  cout<<"INSERTION SORT"<<endl;
  cout<<"Sorted list:";
  InsertionSort(data,n);
 
 cout<<"\n";

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice: ";
 cin>>choice;
 cout<<"\n";
 }while(choice!=2);
  return 0;
}   
   
