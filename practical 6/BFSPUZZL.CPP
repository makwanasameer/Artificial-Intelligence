#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<dos.h>

int count=0;
long int puzzle=0;
long int closed[1000]={0};
int a=0,b=0;
struct opened
{
	long int matrix;
	int i;
	int j;
	struct opened *link;
}*firsto=NULL,*last=NULL,tpo;
long int solution=0;
int mat[3][3];

void printpuzzle()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}

int equalp(long int p1,long int p2)
{
	if(p1!=p2)
		return 0;
	else
		return 1;
}

void insertnode(int p1[3][3])
{
	struct opened *ptr;
	ptr=(struct opened *)malloc(sizeof(struct opened));
	int i,j;
	long int t=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t=(t*10)+p1[i][j];
			if(p1[i][j]==0)
			{
				ptr->i=i;
				ptr->j=j;
			}
		}
	}
	ptr->matrix=t;
	if(firsto==NULL)
	{
		firsto=ptr;
		last=ptr;
		firsto->link=NULL;
	}
	else
	{
		last->link=ptr;
		last=ptr;
		ptr->link=NULL;
	}
}

void insertopen()
{
	int aa;
	int flag=0;
	int p1[3][3];
	int i,j;
	long int t=0;
	int ret=0;
	int checkclose(long int);

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			p1[i][j]=mat[i][j];

	if(a!=0)   			//up
	{
		aa=mat[a][b];
		p1[a][b]=mat[a-1][b];
		p1[a-1][b]=aa;
		flag=1;
	}
	if(flag==1)
	{
		t=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				t=(t*10)+p1[i][j];

		ret=checkclose(t);
		if(ret==0)
			insertnode(p1);

		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				p1[i][j]=mat[i][j];
		flag=0;
	}

	if(a!=2)           		//down
	{
		aa=mat[a][b];
		p1[a][b]=mat[a+1][b];
		p1[a+1][b]=aa;
		flag=1;
	}
	if(flag==1)
	{
		t=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				t=(t*10)+p1[i][j];

		ret=checkclose(t);
		if(ret==0)
			insertnode(p1);
		t=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				p1[i][j]=mat[i][j];
		flag=0;
	}

	if(b!=0)   			//left
	{
		aa=mat[a][b];
		p1[a][b]=mat[a][b-1];
		p1[a][b-1]=aa;
		flag=1;
	}
	if(flag==1)
	{
		t=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				t=(t*10)+p1[i][j];

		ret=checkclose(t);
		if(ret==0)
			insertnode(p1);

		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				p1[i][j]=mat[i][j];
		flag=0;
	}

	if(b!=2)                        //right
	{
		aa=mat[a][b];
		p1[a][b]=mat[a][b+1];
		p1[a][b+1]=aa;
		flag=1;
	}
	if(flag==1)
	{
		t=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				t=(t*10)+p1[i][j];

		ret=checkclose(t);
		if(ret==0)
			insertnode(p1);

		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				p1[i][j]=mat[i][j];
		flag=0;
	}
}

void returnopen()
{
	struct opened *ptr;
	ptr=firsto;
	int i,j;

	long int t=0;
	t=ptr->matrix;
	puzzle=t;
	for(i=2;i>=0;i--)
	{
		for(j=2;j>=0;j--)
		{
			mat[i][j]=t%10;
			t=t/10;
			if(mat[i][j]==0)
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

int checkclose(long int p1)
{
	int check,ret;
	check=count-1;
	int i,j;
	long int t;

	while(check>=0)
	{
		t=closed[check];
		ret=equalp(p1,t);
		if(ret==1)
			return 1;
		check--;
	}
	return 0;
}

void insertclose(long int p1)
{
	closed[count]=p1;
	count++;
}

void main()
{
	int fg=0;
	int f=0;
	int p1[3][3];
	f++;
	clrscr();
	printf("Enter initial state:\n");
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j]==0)
			{
				a=i;
				b=j;
			}
			puzzle=(puzzle*10)+mat[i][j];
		}

	printf("Enter solution:\n");
	for(i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			scanf("%d",&p1[i][j]);
			solution=(solution*10)+p1[i][j];
		}

	printf("Step %d:\n",f);
	printpuzzle();
	printf("\n\n");
	fg=equalp(puzzle,solution);
	if(fg==1)
	{
		printf("\n\nSolution Found:\n");
		printpuzzle();
		getch();
		exit(0);
	}

	insertclose(puzzle);

	while(1)
	{
	insertopen();

	returnopen();

	fg=equalp(puzzle,solution);
	if(fg==1)
	{
		printf("\n\nSolution Found:\n");
		printpuzzle();
		getch();
		break;
	}

	insertclose(puzzle);
	f++;
	printf("Step %d:\n",f);
	printpuzzle();
	printf("\n\n");
	getch();
	}

	getch();
}
