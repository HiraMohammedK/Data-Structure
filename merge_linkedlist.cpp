#include <iostream>
using namespace std;

class Node
{
	int data;
	Node* link;
public:
	Node(){
		this->link = NULL;
		this->data = 0;
	}
	Node(int val){
		this->data = val;
		this->link = NULL;
	}
	int getValue(){
		return data;
	}
	void setValue(int val){
		this->data = val;
		this->link = NULL;
	}
	friend class LinkedList;
};

class LinkedList{
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}
	void createNode(int);
	void printNode();
	void mergeList(LinkedList list1,LinkedList list2);
};

void LinkedList::createNode(int val){
	Node* newNode = new Node(val);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = new Node();
	temp = head;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	temp->link = newNode;
}

void LinkedList::printNode(){
	Node* temp = new Node();
	temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp = temp->link;
	}
	cout<<endl;
}

void LinkedList::mergeList(LinkedList list1,LinkedList list2){
	Node* temp1 = list1.head;
	Node* temp2 = list2.head;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->getValue()>temp2->getValue()){
			createNode(temp2->getValue());
			temp2 = temp2->link;
		}
		else{
			createNode(temp1->getValue());
			temp1 = temp1->link;
		}
	}
	while(temp1!=NULL){
		createNode(temp1->data);
		temp1 = temp1->link;
	}
	while(temp2!=NULL){
		createNode(temp2->data);
		temp2 = temp2->link;
	}
}

int main() {
	LinkedList li1;
	LinkedList li2;

	cout<<"List - 1"<<endl;
	li1.createNode(5);
	li1.createNode(9);
	li1.createNode(11);
	li1.createNode(32);
	li1.createNode(55);
	li1.createNode(66);
	li1.createNode(120);
	li1.printNode();

	cout<<"List - 2"<<endl;
	li2.createNode(15);
	li2.createNode(25);
	li2.createNode(35);
	li2.createNode(45);
	li2.createNode(200);
	li2.printNode();

	LinkedList li3;
	cout<<"Merged List"<<endl;
	li3.mergeList(li1, li2);
	li3.printNode();
	return 0;
}