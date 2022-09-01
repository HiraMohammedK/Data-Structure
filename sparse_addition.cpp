#include<iostream>
using namespace std;

class SparseMatrix
{
        // Number of Non Zero Entries
        int rows;
        int** M;
    public:
        SparseMatrix(){}
        SparseMatrix(int N);
        void Set_Sparse_Matrix();
        void display();
        friend SparseMatrix operator+(SparseMatrix,SparseMatrix);
        void T(SparseMatrix&);
};

SparseMatrix::SparseMatrix(int N)
{
    // A Sparse matrix has 3 colums
    // Rows depend on number of Non-Zero entries
    rows = N ;
    M = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
    {
        M[i] = new int[3];
    }
}

// To get the User input of the sparse matrix
void SparseMatrix::Set_Sparse_Matrix()
{
    // The First input will be -
    // ROW - COL - rows
    // Then input the entries of the matrix
    cout << "Enter " << rows << " entries : \n";
    for(int r = 0 ; r < rows ; r++)
    {
        for(int c = 0 ; c < 3 ; c++)
        {
            cin >> M[r][c];
        }
    }
}

// Method to print the sparse matrix
void SparseMatrix::display()
{
    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < 3 ; j++ )
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}



SparseMatrix operator+(SparseMatrix A,SparseMatrix B)
{
    //Check if the dimensions are the same
    if (A.M[0][0] != B.M[0][0] || A.M[0][1] != B.M[0][1])
    {
        cout << "Addition not possible\n";
        SparseMatrix C(0);
        return C;
    }
    int Alen = A.rows - 1;
    int Blen = B.rows - 1;
    SparseMatrix C(Alen + Blen);
    int i = 1;int j = 1 ; int k = 1;
    //Set the first row of C
    C.M[0][0] = A.M[0][0];
    C.M[0][1] = A.M[0][1];
    while(i <= Alen && j <= Blen)
    {
        if ((A.M[i][0] > B.M[j][0]) || 
            (A.M[i][0]==B.M[j][0] && A.M[i][1] > B.M[j][1]))
        {
            C.M[k][0] = B.M[j][0];
            C.M[k][1] = B.M[j][1];
            C.M[k][2] = B.M[j][2];
            k++;j++;
        }
        else if((A.M[i][0] < B.M[j][0]) || 
            (A.M[i][0] == B.M[j][0] && A.M[i][1] < B.M[j][1]))
        {
            C.M[k][0] = A.M[i][0];
            C.M[k][1] = A.M[i][1];
            C.M[k][2] = A.M[i][2];
            k++;i++;
        }
        else
        {
            C.M[k][0] = A.M[i][0];
            C.M[k][1] = A.M[i][1];
            C.M[k][2] = A.M[i][2] + B.M[j][2] ;
            k++;i++;j++;
        }
    }

    while(i < Alen)
    {
        C.M[k][0] = A.M[i][0];
        C.M[k][1] = A.M[i][1];
        C.M[k][2] = A.M[i][2];
        k++;i++;
    }
    while(j < Blen)
    {
        C.M[k][0] = B.M[j][0];
        C.M[k][1] = B.M[j][1];
        C.M[k][2] = B.M[j][2];
        k++;j++;        
    }
    C.M[0][2] = k - 1;
    C.rows = k;
    return C ;
}


int main()
{
    int len1,len2;
    cout << "Enter the rows in sparse matrix 1 and 2: ";
    cin >> len1 >> len2 ;
    SparseMatrix S1(len1);
    S1.Set_Sparse_Matrix();
    SparseMatrix S2(len2);
    S2.Set_Sparse_Matrix();
    cout << "S1  : \n";
    S1.display();
    cout << "S2  : \n";
    S2.display();
    cout << "S1 + S2 : \n";
    SparseMatrix S3 = S1 + S2 ;
    S3.display();
    // cout << "Transposes : \n";
    // SparseMatrix S4(len1);
    // S1.T(S4); 
    // S4.display();
    return 0;
}