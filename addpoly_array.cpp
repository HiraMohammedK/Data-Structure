#include <iostream>
using namespace std;

void printPoly(int* p,int d);

void addPoly(int* p1,int* p2,int d1,int d2)
{
	int newDegree = max(d1,d2);
	int *sum = new int[newDegree+1];
	int i;
	for (i = 0; i <= min(d1,d2); ++i) 
	{
		sum[i] = p1[i]+p2[i];
	}
	if(d1==d2)
	{
		printPoly(sum, newDegree);
		return;
	}
	else if(d1>d2){
		for (int var = i; var <= d1; var++) 
		{
			sum[var] = p1[var];
		}
		printPoly(sum, newDegree);
		return;
	}
	else
	{
		for (int x = i; x <= d2; x++) 
		{
			sum[x] = p2[x];
		}
		printPoly(sum, newDegree);
		return;
	}
}

int max(int n1,int n2)
{
	if (n1>n2)
	{
		return n1;
	}
	return n2;
}

int min(int n1,int n2)
{
	if (n1>n2)
	{
		return n2;
	}
	return n1;
}

void printPoly(int* p,int d)
{
    int x;
	for (x = d;x > 0; x--) 
	{
	    if(p[x]!=0)
	    {
		cout<<p[x]<<"x"<<x;
		cout<<" + ";
	    }
	}
	cout<<p[x];
}

int main() 
{
	int array1[] = {5,4,10,11,25};
	int array2[] = {50,5,10,11,25};
	addPoly(array2,array1, 4,4);
	return 0;
}