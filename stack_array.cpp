#include <iostream>
using namespace std;


class Stack
{
	int top,max;
	int stack_array[100];
public:
	Stack()
	{
		top = -1;
		max = 100;
	}
	void push(int val);
	int pop();
	void printStack(){
        for(int i=0;i<=top;i++){
            cout<<stack_array[i]<<" ";
        }
        cout<<endl;
    }
};

void Stack::push(int item)
{
	if(top>=max)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	top++;
	stack_array[top] = item;
}

int Stack::pop()
{
	if(top<0)
	{
		cout<<"Underflow"<<endl;
		return 0;
	}
	int item =  stack_array[top];
	top--;
	return item;
}

int main() 
{
	Stack S;
	int option,value,choice;
	do{
	    cout<<"Select any of the following options:\n1:Push operation\n2:Pop operation\n3:Print stack\n";
	cout<<"Enter your choice: ";
	cin>>option;
	cout<<endl;
	switch(option)
	{
	    case 1:cout<<"Enter value to be pushed:";
	           cin>>value;
	           S.push(value);
	           cout<<endl;
	           break;
	    case 2:
	           S.pop();
	           break;
	    case 3:
	           S.printStack();
	           break;
	}
	cout<<endl;
	cout<<"Do you want to continue\n1:Yes\n2:No\nEnter your choice: ";
	cin>>choice;
	}while(choice!=2);
	
	return 0;
}