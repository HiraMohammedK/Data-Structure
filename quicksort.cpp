#include <iostream>
using namespace std;

void swap(int *array , int pos1, int pos2)
{
	int temp;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

int partition(int *array,int start,int end)
{
    int pivot = array[start];
    int i = start;
    int j = end;
    int temp;
    while(i<j){
            while(array[i]<=pivot)
            {
                i++;
            }
            while(array[j]>pivot)
            {
                j--;
            }
            if(i<j){
                swap(array,i,j);
            }
        }
    swap(array,start,j);
    return j;
}

void QuickSort(int *array,int start,int end)
{
    int pos;
    if(start<end)
    {
        pos = partition(array,start,end);
        QuickSort(array,start,pos-1);
        QuickSort(array,pos+1,end);
    }
}



int main()
{
  int length;
  int *arr;
  cout<<"Enter the length of the array: ";
  cin>>length;
  cout<<"Enter the elements of the array: ";
  for(int i=0;i<length;i++)
  {
      cin>>arr[i];
  }
  QuickSort(arr,0,length-1);
  cout<<"After quick sort implementation"<<endl;
  for(int i=0;i<length;i++)
  {
      cout<<arr[i]<<" ";
  }
 
}