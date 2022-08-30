#include<iostream>
using namespace std;
class transposeM
{
    int m1[20][20],m2[20][20],i,j,row,column,t;
public:
    void read()
    {
        t=0;
        cout<<"Enter the number of row: ";
        cin>>row;
        cout<<"enter the number of column: ";
        cin>>column;
        cout<<endl;
        cout<<"Enter the elements of the matrix: "<<endl;
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                cin>>m1[i][j];

                if(m1[i][j])
                {
                    t++;
                    m2[t][0]=i+1;
                    m2[t][1]=j+1;
                    m2[t][2]=m1[i][j];

                }


            }
        }

        m2[0][0]=row;
        m2[0][1]=column;
        m2[0][2]=t;
    }

    void displaysp()
    {
    cout<<"Sparse Matrix: \n";
        for(i=0;i<=t;i++){
            for(j=0;j<3;j++){
                cout<<m2[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void transpose()
    {
        int transpose[20][3];

        transpose[0][0]=m2[0][0];
        transpose[0][1]=m2[0][1];
        transpose[0][2]=m2[0][2];
        cout<<"Transpose: \n";
        int q=1;
        for(i=1;i<=column;i++)
        {
            for(int p=1;p<=t;p++)
            {
                if(m2[p][1]==i)
                {
                    transpose[q][0]=m2[p][0];
                    transpose[q][1]=m2[p][1];
                    transpose[q][2]=m2[p][2];
                    q++;

                }
            }
        }

        for(i=0;i<=column;i++)
        {
            for(j=0;j<3;j++)
            {
                cout<<transpose[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    void display()
    {
        for(i=0;i<row;i++)
        {
                for(j=0;j<column;j++)
                {
                    cout<<m1[i][j]<<" ";


                }
                cout<<"\n";
            }

    }
};
int main()
{
    transposeM obj;
    obj.read();
    obj.display();
    obj.displaysp();
    obj.transpose();
    return 0;
}