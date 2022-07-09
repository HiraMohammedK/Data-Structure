#include<iostream>
using namespace std;

void BubbleSort(int data[], int N)
{
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j<N-i-1;j++)
        {
            if (data[j] > data[j + 1])
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;        
            
            
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
  cout<<"BUBBLE SORT"<<endl;
  cout<<"\n";
  cout<<"Sorted list:";
  BubbleSort(data,n);
 
 cout<<"\n";

 cout<<"Do you want to continue?"<<endl;
 cout<<"1:Yes\n2:No\nEnter your choice: ";
 cin>>choice;
 cout<<"\n";
 }while(choice!=2);
  return 0;
}