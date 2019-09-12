#include <bits/stdc++.h>
using namespace std;

bool issafe(int mat[4][4],int row,int col)
{
    int i,j;
    for(i=col; i>=0; i--)
        if (mat[row][i])
            return false;

    for(i=row,j=col; i>=0 && j>=0; i--, j--)
        if(mat[i][j])
            return false;

    for(i=row,j=col; i<4 && j>=0; i++, j--)
        if(mat[i][j])
            return false;
    
    

    return true;
}

bool queen(int mat[4][4],int col)
{
    int i,j;
    if(col>=4)
        return true;
    for(i=0; i<4; i++)
    {
        if(issafe(mat,i,col)){
            mat[i][col]=1;
        if(queen(mat,col+1))
            return true;

        mat[i][col]=0;
        }

    }
 return false;
}

int main()
{
    int mat[4][4] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 

    if(queen(mat,0)==true)
        cout<<"solution exist"<<endl;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<mat[i][j];
        cout<<endl;
    }

    return 0;
}