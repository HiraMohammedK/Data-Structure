#include<iostream>
using namespace std;


class Array_operation
{
  public:
	void insertion_item(int A[],int N);
	void deletion_item(int A[],int N);
};
void Array_operation::insertion_item(int A[],int N)
{
  int K,x;
  
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
void Array_operation::deletion_item(int A[],int N)
{
  int K,x;
  
  
  cout<<"Enter the element to be deleted:";
  cin>>x;
  cout<<"\n";
  cout<<"Enter the position where to be deleted:";
  cin>>K;
  x=A[K];
  for(int j=K;j<N;j++)
  {
    A[j-1]=A[j];
  }
  N=N-1;
  for (int i = 0; i < N; i++)
        cout << A[i] << " ";
  
 
}
int main()
{
  Array_operation B;
  int N,option;
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
  
  do{
      cout<<"Select any one of the following operations"<<endl;
      cout<<"1:Insertion\n2:Deletion\n3:Exit\nEnter your choice: ";
      cin>>option;
      cout<<"\n";
      switch(option)
      {
      case 1: B.insertion_item(A, N);
              N=N+1;
              cout<<"\n";
              break;
      case 2: B.deletion_item(A, N);
              N=N-1;
              cout<<"\n";
              break;
       case 3: break;       
       }
  }while(option!=3);
  
  
  
 
}
