#include <iostream>
using namespace std;

void substring(char *str,int pos,int L)
{
    int count =0;
    int i=0;
    char *sub = new char [L+1];
    while(count<L)
    {
        sub[i] = str[pos+count-1];
        count=count+1;
    }
    sub[count] = '\0';
    while (str[i] != '0' && i < L)
    {
        cout << str[i] ;
        i++;
    }
    cout << "\n";
}
int main()
{
    int LEN;
    char* STR;
    cout << "Enter string length : ";
    cin >> LEN;
    STR = new char [LEN+1];
    cout << "Enter the string : ";
    for(int j = 0 ; j < LEN ; j++)
    {
        cin >> STR[j];
    }
    STR[LEN+1] = '\0';
    cout << "The substrings are : ";
    substring(STR,2, 3);
}    