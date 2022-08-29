#include <iostream>
using namespace std;

bool saddle_point(int **matrix,int m,int n)
{
	int row_min,ci,k;
	for (int i = 0; i < m; i++) 
	{
		row_min = matrix[i][0];
		ci = 0;
		for (int j = 0; j < n; j++) 
		{
			if (row_min>matrix[i][j]) 
			{
				row_min = matrix[i][j];
				ci = j;
			}
		}
		for (k = 0; k < m; ++k) 
		{
			if (row_min<matrix[k][ci])
				break;
		}
		if (k==m)
		{
			cout<<"Saddle point: "<<row_min<<endl;
			return true;
		}
	}
	return false;
}



int main() 
{
	int **mat,row,col;
	int choice=1;
	cout<<"\tWELCOME\t"<<endl;
	cout<<"\n";
	do{
	    cout<<"Enter number of rows and columns: ";
	cin>>row>>col;
	mat = new int *[row];
	for (int i = 0; i < row;i++) 
	{
		mat[i] = new int[col];
	}
	cout<<"\nEnter values"<<endl;
	for (int i = 0; i < row;i++) 
	{
		for (int j = 0; j < col;j++) 
		{
			cin>>mat[i][j];
		}
	}
    if(saddle_point(mat, row, col) == false)
    {
    	cout<<"No Saddle Point Found"<<endl;
    }
    
    cout<<"Do you want to continue?\n1:Yes\n2:No\nEnter your choice: ";
    cin>>choice;
    cout<<endl;
	}while(choice!=2);
	
	return 0;
}