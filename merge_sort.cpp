# include <iostream>
using namespace std;

void MERGE(int A[],int R,int LBA,int B[],int S,int LBB,int C[],int LBC)
{
    int NA=LBA,NB=LBB,PTR=LBC;
    int UBA=LBA+R-1,UBB=LBB+S-1;

    while(NA<=UBA && NB<=UBB)
    {
        if(A[NA]<B[NB])
        {
            C[PTR]=A[NA];
            NA=NA+1;
            PTR=PTR+1;
        }
        else
        {
            C[PTR]=B[NB];
            NB=NB+1;
            PTR=PTR+1;
        }
    }

    if(NA>UBA)
    {
        for(int k=0;k<=UBB-NB;k++)
        {
            C[PTR+k]=B[NB+k];
        }
    }
    else
    {
        for(int k=0;k<=UBA-NA;k++)
        {
            C[PTR+k]=A[NA+k];
        }

    }
}

void MERGE_PASS(int A[],int N,int L,int B[])
{
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int LB;

     for(int j= 1;j<=Q;j++)
    {
        LB=(2*j-2)*L;
        MERGE(A,L,LB,A,L,LB+L,B,LB);
    }

    if(R<=L)
    {
        for(int k=0;k<R;k++)
        {
            B[S+k]=A[S+k];
        }
    }
    else
    {
        MERGE(A,L,S,A,R-L,L+S,B,S);
    }
}

void MERGE_SORT(int A[],int B[],int N)
{
    int L=1;
    
    while(L<N)
    {
        MERGE_PASS(A,N,L,B);
        MERGE_PASS(B,N,2*L,A);
        L=4*L;
    }

}

int main()
{
    int N,option;
    int A[30];
    int B[30];
    int n=14,l=1;
    do
    {
        
      cout<<"\tMERGE SORT\t"<<endl;  
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
      MERGE_SORT(A,B,N);
      for(int i=0;i<N;i++)
      {
        cout<<A[i]<<" ";
      }
      cout<<"\n";
      cout<<"Do you want to continue?"<<endl;
      cout<<"1:Yes\n2:No\nEnter your choice: ";
      cin>>option;
      cout<<"\n";
    }while(option!=2);

    
    return 0;
}