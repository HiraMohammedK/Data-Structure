#include <iostream>
using namespace std;

void substring(char *str,int pos,int L)
{
    int count =0;
    char *sub = new char [L+1];
    while(count<L)
    {
        sub[count] = str[pos+count-1];
        count=count+1;
    }
    sub[count] = '\0';
     for(int i=0;i<count;i++){
        cout<<sub[i];
    }
    cout << "\n";
}
int main()
{
    int p,l;
    int option=1;
    char str[30];
    do{
        cout<<"Enter the string: ";
        cin>>str;
        cout<<"Enter the position: ";
        cin>>p;
        cout<<"Enter required length of substring: ";
        cin>>l;
        cout << "Substring : ";
        substring(str,p,l);
        cout<<"\n";
        cout<<"Do you want to continue?"<<endl;
        cout<<"1:Yes\n2:No\nEnter your choice: ";
        cin>>option;
        cout<<"\n";
    }while(option!=2);

}
