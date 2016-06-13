#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<dos.h>

int count=0;

int puzzle[3][3]={{0}};

int closed[300][3][3]={0};
int a=0,b=0;

struct opened
{
	int matrix[3][3];
	int i;
	int j;
	struct opened *link;
}*firsto=NULL,tpo;

int solution[3][3];

void printpuzzle(int p1[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",p1[i][j]);
		printf("\n");
	}
}

int equalp(int p1[3][3],int p2[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			if(p1[i][j]!=p2[i][j])
				return 0;
	}
	return 1;
}

void insertnode(int p1[3][3])
{
	struct opened *ptr;
	ptr=(struct opened *)malloc(sizeof(struct opened));
	int i,j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ptr->matrix[i][j]=p1[i][j];
			if(p1[i][j]==0)
			{
				ptr->i=i;
				ptr->j=j;
			}
		}
	}

	if(firsto==NULL)
	{
		firsto=ptr;
		firsto->link=NULL;
	}
	else
	{
		ptr->link=firsto;
		firsto=ptr;
	}
}

void insertopen()
{
	int aa;
	int flag=0;
	int p1[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			p1[i][j]=puzzle[i][j];
	}

	if(b!=2)                        //right
	{
		aa=puzzle[a][b];
		p1[a][b]=puzzle[a][b+1];
		p1[a][b+1]=aa;
		flag=1;
	}
	if(flag==1)
	{
		insertnode(p1);
   /*		printf("-------\n");
		printpuzzle(puzzle);
		printpuzzle(p1);
		printf("------\n");
		getch();        */
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				p1[i][j]=puzzle[i][j];
		}
		flag=0;
	}

	if(b!=0)   			//left
	{
		aa=puzzle[a][b];
		p1[a][b]=puzzle[a][b-1];
		p1[a][b-1]=aa;
		flag=1;
	}
	if(flag==1)
	{
		insertnode(p1);
    /*		printf("-------\n");
		printpuzzle(puzzle);
		printpuzzle(p1);
		printf("--------\n");
		getch();   */
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				p1[i][j]=puzzle[i][j];
		}
		flag=0;
	}

	if(a!=2)           		//down
	{
		aa=puzzle[a][b];
		p1[a][b]=puzzle[a+1][b];
		p1[a+1][b]=aa;
		flag=1;
	}
	if(flag==1)
	{
		insertnode(p1);
    /*		printf("-------\n");
		printpuzzle(puzzle);
		printpuzzle(p1);
		printf("---------\n");
		getch();     */
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				p1[i][j]=puzzle[i][j];
		}
		flag=0;
	}

	if(a!=0)   			//up
	{
		aa=puzzle[a][b];
		p1[a][b]=puzzle[a-1][b];
		p1[a-1][b]=aa;
		flag=1;
	}
	if(flag==1)
	{
		insertnode(p1);
    /*		printf("-------\n");
		printpuzzle(puzzle);
		printpuzzle(p1);
		printf("------------\n");
		getch();  */
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				p1[i][j]=puzzle[i][j];
		}
		flag=0;
	}
}

void returnopen()
{
	struct opened *ptr;
	ptr=firsto;
	int i,j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			puzzle[i][j]=ptr->matrix[i][j];
			if(puzzle[i][j]==0)
			{
				a=ptr->i;
				b=ptr->j;
			}
		}
	}
	ptr=ptr->link;
	free(firsto);
	firsto=ptr;
}

int checkclose(int p1[3][3])
{
	int check,ret;
	check=count-1;
	int i,j;
	int p2[3][3];

	while(check>=0)
	{
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				p2[i][j]=closed[check][i][j];
		ret=equalp(p1,p2);
		if(ret==1)
			return 1;
		check--;
	}
	return 0;
}

void insertclose(int p1[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			closed[count][i][j]=p1[i][j];
	}
	count++;
}

void main()
{
	int fg=0;
	int f=0;
	f++;
	clrscr();
	printf("Enter initial state:\n");
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			scanf("%d",&puzzle[i][j]);
			if(puzzle[i][j]==0)
			{
				a=i;
				b=j;
			}
		}

	printf("Enter solution:\n");
	for(i=0;i<3;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&solution[i][j]);

	printf("Step %d:\n",f);
	printpuzzle(puzzle);
	printf("\n\n");
	fg=equalp(puzzle,solution);
	if(fg==1)
	{
		printf("\n\nSolution Found:\n");
		printpuzzle(puzzle);
		getch();
		exit(0);
	}

	insertclose(puzzle);

	while(1)
	{
	insertopen();

	returnopen();

	again:fg=checkclose(puzzle);
	if(fg==1)
	{
		returnopen();
		goto again;
	}
	fg=equalp(puzzle,solution);
	if(fg==1)
	{
		printf("\n\nSolution Found:\n");
		printpuzzle(puzzle);
		getch();
		break;
	}
	insertclose(puzzle);
	f++;
	printf("Step %d:\n",f);
	printpuzzle(puzzle);
	printf("\n\n");
	delay(100);
	}

	getch();
}
