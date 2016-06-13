#include<stdio.h>
#include<conio.h>
int array[20][20];
static int row;
static int column;
static int queen;
static int state[10][2];

int check(void);
void main()
{
	int temp=queen;
	printf("Enter the rows");
	scanf("%d",&row);
	printf("Enter the no of columns:");
	scanf("%d",&column);
	printf("Enter the no of the queens:");
	scanf("%d",&queen);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			array[i][j]=0;
		}
	}

	for(int i=0;i<row;i++)
	{

		array[i][j]=1;

	}









}
void tick(int l,int m)
{

	for(int i=0;i<row;i++)
	{
		array[i][m]=1;

	}
	for(int i=0;i<column;i++)
	{
		array[l][i]=1;
	}
	for(






}

int check(void)
{
	int flag=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(array[i][j]==1)
			{
				flag=1;
				break;
			}
		}
	}
	return(flag);
}