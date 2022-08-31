#include <iostream>
using namespace std;

class Node
{
	
public:
    int data;
	Node* link;
	Node()
	{
		this->data = 0;
		this->link=NULL;
	}
	Node(int val)
	{
		this->data = val;
		this->link = NULL;
	}
	
    class Stack;
};

class Stack
{
	Node* top;
public:
	Stack()
	{
		top = NULL;
	}
	void push(int val);
	void pop();
	void print();

void push(int val)
{
	Node* newNode = new Node(val);
	if(top==NULL)
	{
		top = newNode;
		cout<<"Pushed Successfully"<<endl;
		return;
	}
	newNode->link=top;
	top = newNode;
	

}

void pop()
{
	if(top==NULL)
	{
		cout<<"Stack Underflow"<<endl;
	}
	Node* temp = NULL;
	temp = top;
	top = top->link;
	delete temp;
}

void print()
{
	Node* temp = top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" "<<endl;
		temp = temp->link;
	}
}
    
};

int main() 
{
	Stack A;
	A.push(11);
	A.push(22);
	A.push(33);
	A.push(44);
	A.print();
	A.pop();
	A.print();
	A.pop();
	A.print();
	return 0;
}