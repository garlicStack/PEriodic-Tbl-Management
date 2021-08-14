#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>


struct element{
		char name[20];
		char sb[5];
		int atm;
		float atms;
		char block;
		char atc[20];
		char prop[250];
	       }p,q;
int rw,cl;
FILE*fp;
void add();
void explor();
void print();
void mainscreen();
void main()
{
	int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

	mainscreen();
	label1:

	printf("\n\n\t\t\t\t\t          MAIN MENU\n");
	printf("\t\t\t\t\t        ~~~~~~~~~~~~~\n");
	printf("\n\t\t\t\t\t  1.Add new Element Information\n");
	printf("\t\t\t\t\t  2.Explore\n");
	printf("\t\t\t\t\t  3.Quit\n");
	printf("\t\t\t\t\t  Enter your Choice:");
	printf("\n\n\n");

	fflush(stdin);
	d=getch();
	switch(d)
	{
		case '1':
		      {
			add();

			break;
		      }
		case '2':
		      {
			explor();
			break;

			}
		case '3':
		      {

			mainscreen();
			printf("THANK YOU\n");
			printf("BYE...........\n");
			getch();
			exit(1);
			break;
			}

		default:
		       {

			mainscreen();

			printf("Wrong choice\n");
			printf("Retype choice\n");
			goto label1;
        	}
        	system("cls");

	}
	mainscreen();
	goto label1;
}
void mainscreen()
{
    system("cls");
	int i,j;
	for(i=2,j=2;i<rw;j++)
	{
		if(j>15)
		j=2;
		printf("%c",'*');
		printf("%c",'*');
		i++;

	}
	for(i=2,j=2;i<cl;i++,j++)
	{
		if(j>15)
		j=2;
		printf("%c",'*');
		printf("%c",'*');

	}

	printf("\n\t\t\t\t\t************************ \n");
	printf("\t\t\t\t\t  Modern Periodic Table\n");
	printf("\t\t\t\t\t        Digital      ");
	printf("\n\t\t\t\t\t************************ \n");

}
void add()
{
    system("cls");
	char ch;
	label1:
	mainscreen();
	printf("\n\t\t\t\t\t  Enter the Information of Elements:\n");

	printf("\n\t\t\t\t\t  Name:");
	fflush(stdin);
	scanf("%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);

	printf("\n\t\t\t\t\t  Symbol:");
	fflush(stdin);
	scanf("%[^\n]",p.sb);
	p.sb[0]=toupper(p.sb[0]);

	printf("\n\t\t\t\t\t  Atomic No:");
	fflush(stdin);
	scanf("%d",&p.atm);

	printf("\n\t\t\t\t\t  Atomic Wt:");
	fflush(stdin);
	scanf("%f",&p.atms);

    printf("\n\t\t\t\t\t  Atomic Config:");
    fflush(stdin);
	scanf("%[^\n]",p.atc);

	printf("\n\t\t\t\t\t  Block:");
	fflush(stdin);
	scanf("%c",&p.block);
	p.block=toupper(p.block);
	if(p.block!='S'&&p.block!='P'&&p.block!='D'&&p.block!='F')
	p.block=' ';

	printf("\n\t\t\t\t\t  About:");
	fflush(stdin);
	scanf("%[^\n]",p.prop);
	p.prop[0]=toupper(p.prop[0]);

	if((fp=fopen("data","ab+"))==NULL)
	{
		printf("Cannot open the file f1");
		getch();
		exit(1);
	}
	fwrite(&p,sizeof(p),1,fp);
	fclose(fp);
	printf("\n\n\n\t\tEnter 'y' for next record(y/n):\n\n");
	ch=getch();
	if(ch=='y')
	{
		goto label1;
	}

}
void explor()
{
    system("cls");
	char d,c;
	FILE *f;
	int given_atmic_no,a,i,tsz,n;
	float given_atmic_mass;
	int flag;
	char string[20];
	startofexplore:
	mainscreen();
	label6:
	printf("\n\n\t\t\t\t\t         SEARCH MENU\n");
	printf("\t\t\t\t\t        ~~~~~~~~~~~~~\n");
	printf("\n\t\t\t\t\t  1.Search by 'NAME'");
	printf("\n\t\t\t\t\t  2.Search by SYMBOL ");
	printf("\n\t\t\t\t\t  3.Search by ATOMIC NUMBER ");
	printf("\n\t\t\t\t\t  4.Search by ATOMIC WEIGHT ");
	printf("\n\t\t\t\t\t  5.Elements of Diff. Blocks ");
	printf("\n\t\t\t\t\t  6.Return to main menu ");
	printf("\n\t\t\t\t\t  Enter your Choice:");
	printf("\n\n\n");
	fflush(stdin);
	d=getch();
	switch(d)
       {
		case '1':
		{
			mainscreen();
			printf("\n\t\t\t\t\t  Enter the Name of Element to be searched:");
			fflush(stdin);
			scanf("%[^\n]",string);

			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.name,string)==0)
				{
					print();

					flag=0;

					break;
				 }
			}
			if(flag==1)
			{
				mainscreen();
				printf("\n\t\t\t\t\t  ::No Element Available::");

			}

			fclose(fp);
			getch();
			break;
		}
		case '2':
		{
			mainscreen();
			printf("\n\t\t\t\t\t  Enter the symbol of Element to be searched: ");
			fflush(stdin);
			scanf("%[^\n]",string);

			string[0]=toupper(string[0]);
			if((fp=fopen("data","rb+"))==NULL)
			{
			printf("\n\t\t\t\t\t   cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(strcmp(p.sb,string)==0)
				{
					print();
					flag=0;
					break;
				 }
			}
			if(flag==1)
			{
				mainscreen();
				printf("\n\t\t\t\t\t  ::No Element Available::");
			}

			fclose(fp);
			getch();
			break;
		}
		case '6':
		{
			return;
		}
		case '3':
		{

			mainscreen();
			printf("\n\t\t\t\t\t  Enter the Atomic No. Element to be searched: ");
			fflush(stdin);
			scanf("%d",&given_atmic_no);
			if((fp=fopen("data","rb+"))==NULL)
			{
			printf("\n\t\t\t\t\t   cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atm==given_atmic_no)
				{
					print();
					flag=0;
					break;
				 }
			}
			if(flag==1)
			{
				mainscreen();
				printf("\n\t\t\t\t\t  ::No Element Available::");
			}

			fclose(fp);
			getch();
			break;
		}
		case '4':
		{
			mainscreen();
			printf("\n\t\t\t\t\t  Enter the Atomic mass of Element to be searched: ");
			fflush(stdin);
			scanf("%f",&given_atmic_mass);
			if((fp=fopen("data","rb+"))==NULL)
			{
			printf("\n\t\t\t\t\t   cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atms==given_atmic_mass)
				{
					print();
					flag=0;
					break;
				 }
			}
			if(flag==1)
			{
				mainscreen();
				printf("\n\t\t\t\t\t  ::No Element Available::");
			}

			fclose(fp);
			getch();
			break;
		}
		case '5':
		{
			mainscreen();
			printf("\n\t\t\t\t\t  Enter the Block: ");
			fflush(stdin);
			scanf("%c",&c);
			c=toupper(c);
			if((f=fopen("temp","wb+"))==NULL)
			{
			printf("\n\t\t\t\t\t   cannot open the temp file 1");
			getch();
			exit(1);
			}
			if((fp=fopen("data","rb+"))==NULL)
			{
			printf("\n\t\t\t\t\t   cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;
			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.block==c)
				{
					fwrite(&p,sizeof(p),1,f);
				 }
			}
			fclose(f);
			fclose(fp);

					 if((f=fopen("temp","rb+"))==NULL)
					      {
						printf("\n\t\t\t\t\t  Cannot open the file");
						getch();
						exit(1);
					      }
					 fseek(f,0,SEEK_END);
					 tsz=ftell(f);
					 n=(int)(tsz/sizeof(p));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(f,i*sizeof(p),SEEK_SET);
						fread(&p,sizeof(p),1,f);
						fseek(f,a*sizeof(p),SEEK_SET);
						fread(&q,sizeof(p),1,f);
						if((p.atm-q.atm)>0)
							{
							fseek(f,i*sizeof(p),SEEK_SET);
							fwrite(&q,sizeof(p),1,f);
							fseek(f,a*sizeof(p),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(p),1,fp);
							}
						}
					}
					rewind(f);
			while(fread(&p,sizeof(p),1,f))
			{
					print();
					getch();
			}
				mainscreen();
				printf("\n\t\t\t\t\t  ::No Element Available::");

			fclose(f);
			getch();
			break;
		}
		default:
		{
				mainscreen();
				printf("\n\t\t\t\t\t  Wrong choice\n");
				printf("\n\t\t\t\t\t  Retype choice\n");
				goto label6;
		}
	}
	goto startofexplore;

}
void print()
{
	mainscreen();
	printf("\n\t\t\t\t\t  Name : ");
	printf("%s",p.name);

	printf("\n\t\t\t\t\t  Symbol : ");
	printf("%s",p.sb);

	printf("\n\t\t\t\t\t  Atomic No : ");
	fflush(stdin);
	printf("%d",p.atm);

	printf("\n\t\t\t\t\t  Atomic Wt : ");
	fflush(stdin);
	printf("%f",p.atms);

	printf("\n\t\t\t\t\t  Atomic Config : ");
	fflush(stdin);
	printf("%s",p.atc);

	printf("\n\t\t\t\t\t  Block : ");
	fflush(stdin);
	printf("%c",p.block);

	printf("\n\t\t\t\t\t  About : ");
	printf("%s",p.prop);
}
