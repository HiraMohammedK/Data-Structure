#include<iostream>
#include<cstring>
using namespace std;
int pattern_matching(char text[],int text_length,char pattern[],int pat_length)
{
    int k = 0 ;
    int max = text_length - pat_length + 1;
    while (k <= max)
    {
        int c = 0;
        for(int i = 0 ; i < pat_length ; i++)
        {
            if (pattern[i]!= text[k+i])
            {
                i = pat_length;
            }
            else
            {
                c++;
            }
        }
        if (c==pat_length)
        {
            return k ;
        }
        k++;
    }
    return -1;
}
int main()
{
    char TEXT[30];
    char PATTERN[30];
    int tlen,plen,x;
    int option=1;
    cout<<"\tWELCOME\t"<<endl;
    do{
        cout<<"Enter text: ";
        cin>>TEXT;
        cout<<"Enter pattern: ";
        cin>>PATTERN;
        tlen=strlen(TEXT);
        plen=strlen(PATTERN);
        //positions 1,2,3........
        cout<<"\n";
        x= pattern_matching(TEXT,tlen,PATTERN,plen)+1;
        if(x==0)
        {
            cout<<"Pattern not found"<<endl;
        }
        else
        {
            cout<<"Pattern is present at position "<<x<<endl;
        }
        cout<<"\n";
        cout<<"Do you want to continue?"<<endl;
        cout<<"1:Yes\n2:No\nEnter your choice: ";
        cin>>option;
        cout<<"\n";
    }while(option!=2);
    return 0;
}