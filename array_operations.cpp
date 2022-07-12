//insertion and deletion of an element from an array

#include<iostream>
using namespace std;


class Array_operation
{
  public:
	int insertion_item();
	int deletion_item();
};
int Array_operation::insertion_item()
{
  int N,K,x;
  
  cout<<"Enter the number of elements of array:";
  cin>>N;
  cout<<"\n";
  int A[N];
  cout<<"Enter the elemts of the array:";
  for(int i=0;i<N;i++)
   {
     cin>>A[i];
   }
  cout<<"\n"; 
  cout<<"Enter the element to be inserted:";
  cin>>x;
  cout<<"\n";
  cout<<"Enter the position where to be inserted:";
  cin>>K;
  cout<<"\n";
 int J =N;
 do{
	A[J+1]= A[J];
	J=J-1;
   }while(J>=K-1);
 A[K-1] = x;
 N=N+1;
 for (int i = 0; i < N; i++)
        cout << A[i] << " ";
}
int Array_operation::deletion_item()
{
  int N,K,x;
  
  cout<<"Enter the number of elements of array:";
  cin>>N;
  cout<<"\n";
  int A[N];
  cout<<"Enter the elemts of the array:";
  for(int i=0;i<N;i++)
   {
     cin>>A[i];
   }
  cout<<"\n"; 
  cout<<"Enter the element to be deleted:";
  cin>>x;
  cout<<"\n";
  cout<<"Enter the position where to be deleted:";
  cin>>K;
  x=A[K];
  for(int j=K;j<N-1;j++)
  {
    A[j]=A[j+1];
  }
  N=N-1;
  for (int i = 0; i < N; i++)
        cout << A[i] << " ";
  
 
}
int main()
{
  Array_operation B;
  
 
  //B.insertion_item();
  B.deletion_item();
  return 0;
  
 
}
