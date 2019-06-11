#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

#define M 10
#define N 10


//all possible movement
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

bool issafe(int mat[M][N],int x,int y,bool processed[M][N])
{
return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
		(mat[x][y] && !processed[x][y]);
}

void dfs(int mat[M][N],bool processed[M][N],int i,int j)
{

    processed[i][j]=true;
    
        
        for(int k=0; k<8; k++)
        {
            if(issafe(mat,i + row[k],j + col[k],processed))
            {
                processed[i + row[k]][j + col[k]]=true;
                dfs(mat,processed,i+ row[k],j + col[k]);
            }

        }
}

int main()
{
    int mat[M][N]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

    bool processed[M][N];

    memset(processed,0,sizeof(processed));


    int island = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// start BFS from each unprocessed node and
			// increment island count
			if (mat[i][j] && processed[i][j] == 0)
			{
				dfs(mat, processed, i, j);
				island++;
			}
		}
	}

	cout << "Number of islands are " << island << endl;

	return 0;

}
