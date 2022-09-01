#include<iostream>
using namespace std;
class node
{
public:
    int info;
    node* link;
    node(){
        info=0;
        link=NULL;
    }
    node(int value)
    {
        info=value;
        link=NULL;
    }
    
};
class linked_list
{
    node* start=NULL;
public:
    linked_list(){}
    linked_list(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            create_node(arr[i]);
        }
    }
    void create_node(int value)
    {
        node* new_node=new node(value);
        if(new_node==NULL)
        {
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL)
        {
            start=new_node;
            return;
        }
        node* ptr=start;
        while (ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new_node;
        new_node->link=NULL;
    }

    node* search_insert(int item)
    {
        node* ptr=start->link;
        node* save=start;
        if(start==NULL){
            return NULL;
        }
        if(start->info>=item)
        {
            return start;
        }
        while(ptr!=NULL)
        {
            if((ptr)->info>=item)
            {
                return save;
            }else
            {
                save=ptr;
                ptr=ptr->link;
            }
        }
        return save;
    }
    void insert(int item)
    {
        node* new_node=new node(item);
        node* loc=search_insert(item);
        if(loc==NULL)
        {
            new_node->link=start;
            start=new_node;
            return;
        }else if(loc==start)
        {
            new_node->link=start;
            start=new_node;
        }else
        {
            new_node->link=loc->link;
            loc->link=new_node;
            return;
        }
    }
    void find(int ITEM,node*& loc,node*& locp){
        node* save;
        node* ptr;
        if(start==NULL){
            loc=NULL,locp=NULL;
            return;
        }
        if(start->info==ITEM){
            loc=start;
            locp=NULL;
            return;
        }
        save=start;
        ptr=start->link;
        while(ptr!=NULL){
            if(ptr->info==ITEM){
                loc=ptr;
                locp=save;
                return;
            }
            save=ptr;
            ptr=ptr->link;
        }
        loc=NULL;
        return;
    }
    void deletion(int ITEM)
    {
        node* loc=new node();
        node* locp=new node();
        find(ITEM,loc,locp);
        if(loc==NULL)
        {
            cout<<ITEM<<"Not found!";
            return;
        }
        if(locp==NULL){
            start=start->link;
        }else
        {
            locp->link=loc->link;
        }

    }
    
    void print()
    {
        node* ptr=start;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }
};

int main(void)
{
    int no_nodes,num_insert,num_delete;
    cout<<"Enter the number of nodes to be created : ";
    cin>>no_nodes;
    int list_arr[no_nodes];
    cout<<"Enter the node values in the list(Ascending order) : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>list_arr[i];
    }
    linked_list list(list_arr,no_nodes);
    list.print();
    cout<<"Enter the value to be inserted : ";
    cin>>num_insert;
    list.insert(num_insert);
    list.print();
    cout<<"Enter the value to be deleted : ";
    cin>>num_delete;
    list.deletion(num_delete);
    list.print();   
    return 0;
}