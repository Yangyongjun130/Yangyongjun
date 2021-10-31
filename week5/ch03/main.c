#include<stdio.h>
const int n = 4;
int Matrix[n][2] = { 20,2,2,15,15,40,40,4 };
int cost[n][n];
int root[n][n];

int Proc(int i, int r, int j)
{
	return Matrix[i][0] * Matrix[r][1] * Matrix[j][1];
}
int pri(int i, int r, int j)
{
	if (i == r && r == j)
		return -1;
	pri(i, root[i][r], r);
	pri(r + 1, root[r + 1][j], j);
	printf(" %d ", root[i][j] + 1);

}
int main()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j <= n - 1; j++)
		{
			if (j == i)
			{
				cost[i][j] = 0;
				root[i][j] = i;
				continue;
			}
			for (int r = i; r <= j - 1; r++)
			{
				int temp = cost[i][r] + cost[r + 1][j] + Proc(i, r, j);
				if (cost[i][j] == 0)
				{
					cost[i][j] = temp;
					root[i][j] = r;
				}
				else if (cost[i][j] != 0 && cost[i][j] >= temp)
				{
					cost[i][j] = temp;
					root[i][j] = r;
				}
			}
		}
	}
	printf("least multiply times = %d\n", cost[0][n - 1]);
	printf("compute sequece is:\n");
	pri(0, root[0][n - 1], n - 1);

}
