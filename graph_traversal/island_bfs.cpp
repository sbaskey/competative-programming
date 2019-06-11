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

void bfs(int mat[M][N],bool processed[M][N],int i,int j)
{
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));

    processed[i][j]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int k=0; k<8; k++)
        {
            if(issafe(mat,x + row[k],y + col[k],processed))
            {
                processed[x + row[k]][y + col[k]]=true;
                q.push(make_pair(x + row[k],y + col[k]));
            }

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
				bfs(mat, processed, i, j);
				island++;
			}
		}
	}

	cout << "Number of islands are " << island << endl;

	return 0;

}
