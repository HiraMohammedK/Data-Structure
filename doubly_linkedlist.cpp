#include<iostream>
using namespace std;
class Node
{
public:
    int info;
    Node* back;
    Node* forw;
    Node()
    {
        info=0;
        back=NULL;
        forw=NULL;
    }
    Node(int val)
    {
        info=val;
        back=NULL;
        forw=NULL;
    }
};
class doubly_linkedlist
{
    Node* start=NULL;
    Node* end=NULL;
public:

    void create_node(int value)
    {
        Node* new_node=new Node(value);
        if(start==NULL)
        {
            start=new_node;
            end=new_node;
            return;
        }
        Node* ptr=start;
        while (ptr->forw!=NULL)
        {
            ptr=ptr->forw;
        }
        ptr->forw=new_node;
        new_node->back=ptr;
        end=new_node;
    }
    doubly_linkedlist(int arr[],int num)
    {
        for(int i=0;i<num;i++)
        {
            create_node(arr[i]);
        }
    }
    Node* insertion_search(int item)
    {
        Node* ptr=start;
        while(ptr->forw!=NULL)
        {
            if((ptr)->info>=item)
            {
                return ptr;
            }
            else
            {
                ptr=ptr->forw;
            }
        }
        return NULL;
    }
    void insert(int item)
    {
        Node* new_node=new Node(item);
        Node* loc=insertion_search(item);
        if(loc==start)
        {
            start=new_node;
            new_node->forw=loc;
            new_node->back=NULL;
            loc->back=new_node;
        }
        else if(loc==NULL)
        {
            new_node->forw=NULL;
            new_node->back=end;
            end=new_node;
            return;
        }
        else
        {
            new_node->forw=loc;
            new_node->back=loc->back;
            (loc->back)->forw=new_node;
            return;
        }
    }
    Node* search(int item)
    {
        Node* ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->info==item)
            {
                return ptr;
            }
            ptr=ptr->forw;
        }
        return NULL;
    }
    void node_delete(int item)
    {
        Node* loc=search(item);
        if(loc==NULL)
        {
            cout<<"Item not found"<<endl;;
            return;
        }
        else if(loc==start)
        {
            (loc->forw)->back=NULL;
            start=loc->forw;
        }
        else if(loc==end)
        {
            (loc->back)->forw=NULL;
            end=loc->back;
        }
        else
        {
            (loc->forw)->back=loc->back;
            (loc->back)->forw=loc->forw;
        }
    }
    void print()
    {
        Node* ptr=start;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->forw;
        }
    }
};
int main()
{
    int n,option,value;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the linked list : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    doubly_linkedlist dl(arr,n);
    cout<<endl;
    do
    {
        cout<<"Select an option\n1:Insertion\n2:Deletion\n3:Exit\n";
        cin>>option;
        cout<<endl;
        switch(option)
        {
            case 1:cout<<"Enter value to be inserted: ";
                   cin>>value;
                   cout<<endl;
                   dl.insert(value);
                   dl.print();
                   cout<<endl;
                   break;
            case 2:cout<<"Enter value to be deleted: ";
                   cin>>value;
                   cout<<endl;
                   dl.node_delete(value);
                   dl.print();
                   cout<<endl;
                   break;
            case  3:break;
        }        
    }while(option!=3);

    return 0;
}