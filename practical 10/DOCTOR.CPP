#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void presc_cold();
void cold();
void main()

{
int a[10],i;
int flag=0;
clrscr();
printf("welcome to medical DIAGNOSIS system");

/*printf("list of question\n");*/

/*printf("select maximum 5 symptoms\n");      */

printf("list of symptoms\n");
/*symptoms of cold*/


printf("1.coughing");

printf("\n3.runny nose");

printf("\n4.nasal congetsion");




/*symptoms of fever*/

printf("\nafter selection enter 0\n");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);


if(a[i]==0)
	{
	break;
	}
}

/*-----------------------------*/

if(a[0]==1||a[1]==1||a[2]==1||a[3]==1||a[4]==1)
{

	if(a[0]==3||a[1]==3||a[2]==3||a[3]==3||a[4]==3)
	{
		printf("you are suffering from cold & cough");
	}

	presc_cold();
	flag=1;
}

/*--------------------------------------*/
if(flag==0)
{
	if(a[0]==1||a[1]==1||a[2]==1||a[3]==1||a[4]==1)
	{
		if(a[0]==4||a[1]==4||a[2]==4||a[3]==4||a[4]==4)
		{
		printf("you are suffering from cold & cough");
		presc_cold();
		}

	}

}

if(flag==0)
{
	if(a[0]==1||a[1]==1||a[2]==1||a[3]==1||a[4]==1)
	{
		if(a[0]==3||a[1]==3||a[2]==3||a[3]==3||a[4]==3)
		{
			if(a[0]==4||a[1]==4||a[2]==4||a[3]==4||a[4]==4)
			{
			printf("you are suffering from cold & cough");

			}
			presc_cold();
		}
	}

}

if(flag==0)
{
	if(a[0]==4||a[1]==4||a[2]==4||a[3]==4||a[4]==4)
	{
		printf("\nyou are suffering from cold");
	}
	cold();
}

/*if(flag==0)
{
	if(a[2]==1||a[2]==2||a[2]==3||a[2]==4||a[2]==5||a[2]==6)
	{
	printf("you are suffering from cold & cough");
	}
}

if(flag==0)
{
	if(a[3]==1||a[3]==2||a[3]==3||a[3]==4||a[2]==5||a[2]==6)
	{
	printf("you are suffering from cold & cough");
	}
} */



getch();


}

void presc_cold()
{
	char choice;

	printf("\ndo you want prescription::");
	cin>>choice;

	if(choice=='y')
	{
	printf("please choose any one of the following syrup\n");

	printf("\nlintus");
	printf("\ncodeine");
	printf("\nephidrine");
	printf("\n\nlist of tablets[choose any one]with above listed syrup");
	printf("\ndextromethorphan");
	printf("\nhydroxyzine");
	printf("\nperiactin");


	}



}


void cold()
{
	char choice;
	printf("\ndo you want prescription::");
	cin>>choice;
	if(choice=='y')
	{
		printf("choose any one tablet(2 times per day after diet)");

		printf("\ndextromethorphan");
		printf("\nhydroxyzine");
		printf("\nperiactin");
	}
}