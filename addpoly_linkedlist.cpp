#include<iostream>
using namespace std;
class Node
{
public:
  int coeff,power;
  Node *next;
  
  Node(int coeff, int power)
  {
    this->coeff = coeff;
    this->power = power;
    this->next = NULL;
  }
};
  
void addPolynomials(Node *head1, Node *head2)
{
  if(head1==NULL && head2==NULL)
    return;
  else if(head1->power == head2->power)
  {cout << " " << head1->coeff +  head2->coeff << "x^" << head1->power << " ";
    addPolynomials(head1->next,head2->next);
  }
  else if(head1->power > head2->power)
  {
    cout << " " << head1->coeff << "x^" << head1->power << " ";
    addPolynomials(head1->next, head2);
  }
  else
  {
    cout << " " << head2->coeff << "x^" << head2->power << " ";
    addPolynomials(head1, head2->next);
  }
}
  
void insert(Node *head, int coeff, int power)
{
  Node *new_node = new Node(coeff,power);
  while(head->next != NULL)
  {
    head = head->next;
  }
  head->next = new_node;
}
  
void printList(Node *head)
{
  cout << "Linked List" << endl;
  while(head != NULL)
  {
    cout << " " << head->coeff << "x" << "^" << head->power;
    head = head->next;
  }
}
int main()
{
  Node *head1=new Node(6,4);
  cout<<"Polynomial 1"<<endl;
  insert(head1,3,3);
  insert(head1,5,2);
  insert(head1,3,0);
  Node *head2 = new Node(2,6);
  insert(head2, 3, 4);
  insert(head2, 5, 3);
  insert(head2, 7, 2);
  insert(head2,4,0);
  printList(head1);
  cout << endl;
  printList(head2);
  cout << endl ;
  cout<<" After polynomial addition:" << endl;
  addPolynomials(head1,head2);
  
  
  return 0;
}