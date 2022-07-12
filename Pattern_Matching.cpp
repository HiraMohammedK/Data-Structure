#include<iostream>
using namespace std;
int pattern_matching(char text[],int text_len,char pattern[],int pat_len)
{
    int k = 0 ;
    int max = text_len - pat_len + 1;
    while (k <= max)
    {
        int count = 0;
        for(int i = 0 ; i < pat_len ; i++)
        {
            if (pattern[i]!= text[k+i])
            {
                i = pat_len;
            }
            else
            {
                count++;
            }
        }
        if (count==pat_len)
        {
            return k ;
        }
        k++;
    }
    return -1;
}
int main(){
    char t[7]="School",p[3]="ol";
    cout<<pattern_matching(t,6,p,2);
    return 0;
}