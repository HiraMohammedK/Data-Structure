#include<iostream>

using namespace std;

class Node {
  public:
   int key;
  	int data;
  	Node * next;

  Node() {
    data = 0;
    next = NULL;
  }
  Node(int d) 
  {
    data = d;
    next = NULL;
  }
};

class Queue 
{
  public:
  	Node *front;
  	Node *rear;
  	
    Queue() 
	 {
      front = NULL;
      rear = NULL;
    }
    
    bool isEmpty()
    {
    	if(front==NULL && rear==NULL)
    	{
    		return true;
		}
		else
		{
			return false;
		}
	 }
	 
	void enqueue(Node *n) 
   {
    if (isEmpty())
      {
        front = n;
        rear = n;
        cout<<"Node inserted successfully"<<endl;
      }
    else
    {
      rear->next=n;
      rear=n;
      //top = n;
      cout<<"Node inserted successfully"<<endl;
    }
    
   }
	
	Node* dequeue() 
    {
        Node *temp=NULL;
      if (isEmpty()) 
      {
          cout << "Queue is Empty" << endl;
          return NULL;
      } 
      else 
      {
        if(front==rear)
        {
          temp=front;
          front = NULL;
          rear = NULL;  
          return temp;
        }
        else
        {
          temp=front;
          front = front->next;  
          return temp;
        }
          
       }
    }
	 
	 
	 void display() 
    {
      if(isEmpty())
      {
        cout << "Queue is Empty" << endl;
      }
    else
    {
        Node *temp=front;
        while(temp!=NULL)
        {
          cout<<temp->data<<" ";
          temp=temp->next;
      	}
      cout<<endl;
    }
    
    }
	 
  	
};
 
int main() {
  Queue q;
  int option, data;
 
  do {
    cout << "What operation do you want to perform?"
	 <<"Select Option number" << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. display()" << endl;
    cout << "4. exit "<<endl;
	 Node * new_node = new Node();
	 cin>>option;
    
    switch (option) {
    case 1:
      cout << "Enter value: ";
      cin >> data;
      new_node->data = data;
      q.enqueue(new_node);
      break;
    case 2:
      new_node = q.dequeue();
      delete new_node;
		cout<<endl;
      break;
    case 3:
      q.display();
      cout << endl;
      break;
    
    case 4:
      break;

    }
 
  } while (option != 4);
 
  return 0;
}