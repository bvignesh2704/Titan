#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<alloc.h>
#include<bios.h>
#include<fstream.h>

void load();

const int RIGHT=19712,LEFT=19200,UP=18432,DOWN=20480,ENTER=7181,ESC=283;
int b[50][50],count=0;
int xx=0,lo=75,bb,n;
int hb[20][20],flag=0, scorn=0;
char str[30];
int Left = 240, Top = 120, Width = 210, Height = 210 ;
double _YYYY,_MM,_DD,_tempyy,_tempmm;

union REGS i,o;

struct user
{	char uname[20],pwd[20]; };

struct film
{		char n[20],h1[20],h2[20];	};

struct qu
{	char a[100],b[4][40];  };

struct high
{	char name[20]; int score;	}a,c;

struct sum
{  char q[25]; int amt,qty;  };

struct login
{  char id[20],	pass[20]; }log1;

class newsc
{
	public:
	char h[80],h2[80],t[80],b[3][180];

	void news1();
	void modifynews();
};

class stock
{
	public:
	char name[40];	int stok;
	stock(){strcpy(name,"");stok=0;}
	stock(char*,int,char*);
};

void menu2();
void menu4();
void news();

int stock_exists(char*,char*);
sum give_me_the_product(char*,int);
int NoP(char*);
char*itoa(int);
int blank_record(sum);
void create_stock_list(char);
void purchase(char b[8][25],int price[8],char*,char*,char*);
int new_sb_user();
void final_message(char*);
void summary(char*);
void delivery_message(char*);
void user_stuff(char*);
void alter(char b[8][25],char*);
void admin_stuff();
void reinitialise_file_pointer(char*);

void string( char *strsrc , int dsp = 25 )
 {	char c[2];
		for (int iter = 0 ; strsrc[iter] ; iter++)
		{
				c[0] = strsrc[iter];
				c[1] = 0   ;
				outtext(c) ;
				delay(dsp) ;
		}
	}

void create_admins()
{
	login log={"admin","davian"},
				log1={"Muthu","momentum"},
				log2={"vignesh","gold"},
				log3={"khaveesh","slave"};

	ifstream f1("access.dat",ios::binary);
	if(!f1)
	 {
		 f1.close();
		 ofstream f2("access.dat",ios::binary|ios::app);
		 f2.write((char*)&log,sizeof(log));
		 f2.write((char*)&log1,sizeof(log1));
		 f2.write((char*)&log2,sizeof(log2));
		 f2.write((char*)&log3,sizeof(log3));
		 f2.close();
	 }
	 else	 f1.close();
}

void display0()
{
	 setcolor(YELLOW);
	 settextstyle(8,0,5);
	 outtextxy(220,20,"CSC");
	 setcolor(YELLOW);
	 settextstyle(8,0,5);
	 outtextxy(80,60,"PROJECT");
	 setcolor(YELLOW);
	 settextstyle(8,0,5);
	 outtextxy(290,20,"GAME");
	 setcolor(YELLOW);
	 settextstyle(8,0,5);
	 outtextxy(290,60,"2016-2018");
	 setcolor(YELLOW);
	 settextstyle(8,0,1);
	 outtextxy(40,350,"BY");
	 setcolor(YELLOW);
	 settextstyle(8,0,1);
	 outtextxy(40,370,"TITANIANS");
	 settextstyle(8,0,1);
	 outtextxy(40,390,"12 a b");
	 settextstyle(20,0,50);
}

void display()
{
	 setcolor(RED);
	 settextstyle(4,0,5);
	 outtextxy(190,20,"CONNECT 5");
	 setcolor(RED);
	 settextstyle(4,0,5);
	 outtextxy(300,20," ");
	 setcolor(YELLOW);
	 settextstyle(20,0,50);
}

void display1()
{
	 setcolor(RED);
	 settextstyle(4,0,5);
	 outtextxy(225,20,"CONNECT 5");
	 setcolor(YELLOW);
	 settextstyle(20,0,5);
}

void display2()
{
	 setcolor(YELLOW);
	 settextstyle(7,0,5);
   outtextxy(220,20,"CONNECT 5");
	 settextstyle(20,0,50);
}

void display4()
{
	 setcolor(YELLOW);
	 settextstyle(3,0,5);
	 outtextxy(130,20,"SELECT CO-ORDINATE");
	 settextstyle(20,0,50);
}

void help3()
{
		 setbkcolor(BLACK);
		 cleardevice();
		 gotoxy(27,2);
		 cout<<"HELP TO PLAY GAME";
		 delay(350);
		 gotoxy(10,6);
		 cout<<"1). A Strategy game for 2 players.";
		 delay(350);
		 gotoxy(10,8);
		 cout<<"2). The Objective of connect-5 is to make 5 orbs in a row";
		 delay(350);
		 gotoxy(10,10);
		 cout<<"3). Players take turns to place their orbs in cell.";
		 delay(350);
		 gotoxy(10,12);
		 cout<<"4). Once a player makes 5(five) in a row which can be formed horizontal              or vertical or diagonal; the player wins ,so the game ends";
		 delay(350);
		 gotoxy(10,16);
		 getch();
}

void credits()
{
cleardevice();
setbkcolor(BLACK);
setcolor(RED);
outtextxy(275,110,"TITAN GAME PROJECT");
delay(350);
setcolor(BLUE);
{
outtextxy(300,170,"DONE BY");
outtextxy(325,190,"TITANNIANS");
}
delay(350);
setcolor(YELLOW);
{
outtextxy(300,230,"BLESSED TO BE STUDENT OF...");
outtextxy(325,250,"DAV SENIOR SECONDARY");
outtextxy(325,270,"SCHOOL MOGAPPAIR");
}
delay(350);
}

void gameplay3()
{
cleardevice();
setbkcolor(BLACK);
int c=15,r=15,cc=0,cr=0,a,i,j,w=30,x=5,y=5,cp=1;
for(i=0;i<r;i++)
	 for(j=0;j<c;j++)
			{
					b[i][j]=1;
			}
for(i=0;i<r;i++)
	 for(j=0;j<c;j++)
	 {
			rectangle(x+j*w,y+i*w,x+j*w+w,y+i*w+w);
			setcolor(20);
	 }
setcolor(5);
rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
while((a=bioskey(0))!=ESC)
{
 switch(a)
 {

 case LEFT:  if(cp==1)
			 {
			 setcolor(20);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
			 else
			 {
			 setcolor(18);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
			 if(cc==0)
						cc=c-1;
			 else
				cc--;
			 setcolor(5);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 break;
 case RIGHT: if(cp==1)
	     {
	     setcolor(20);
	     rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
			 else
			 {
			 setcolor(18);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
	     if(cc==c-1)
		cc=0;
			 else
		cc++;
			 setcolor(5);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 break;

 case UP:    if(cp==1)
			 {
	     setcolor(20);
	     rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
	     }
	     else
			 {
			 setcolor(18);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
			 if(cr==0)
		cr=r-1;
	     else
	       cr--;
			 setcolor(5);
	     rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 break;

 case DOWN:  if(cp==1)
			 {
			 setcolor(20);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
	     }
	     else
	     {
	     setcolor(18);
			 rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 }
			 if(cr==r-1)
		cr=0;
			 else
		cr++;
	     setcolor(5);
	     rectangle(x+cc*w,y+cr*w,x+cc*w+w,y+cr*w+w);
			 break;

 case ENTER:     if(b[cr][cc]==1)
		 {
		 for(i=0;i<c;i++)
				for(j=0;j<r;j++)
					 {
					 if(cp==1&&b[cr][cc]!=3&&b[cr][cc]==1)
			 {
			 setcolor(18);
			 rectangle(x+j*w,y+i*w,x+j*w+w,y+i*w+w);
			 setfillstyle(1,20);
			 setcolor(20);
			 }
					 else if(b[cr][cc]==1&&b[cr][cc]!=2&&cp==2)
			 {
			 setcolor(20);
			 rectangle(x+j*w,y+i*w,x+j*w+w,y+i*w+w);
			 setfillstyle(1,18);
			 setcolor(18);
			 }
		       }
					 fillellipse(x+cc*w+w/2,y+cr*w+w/2,10,10);
					 if(cp==1)
			 {
				b[cr][cc]=2;
			 }
					 else if(cp==2)
			 {
				b[cr][cc]=3;
			 }
					if(b[cr][cc]==2&&b[cr][cc+1]==2&&b[cr][cc+2]==2&&b[cr][cc+3]==2&&b[cr][cc+4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr][cc+1]==3&&b[cr][cc+2]==3&&b[cr][cc+3]==3&&b[cr][cc+4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr][cc-1]==2&&b[cr][cc-2]==2&&b[cr][cc-3]==2&&b[cr][cc-4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr][cc-1]==3&&b[cr][cc-2]==3&&b[cr][cc-3]==3&&b[cr][cc-4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr][cc+1]==2&&b[cr][cc+2]==2&&b[cr][cc-1]==2&&b[cr][cc-2]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr][cc+1]==3&&b[cr][cc+2]==3&&b[cr][cc-1]==3&&b[cr][cc-2]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr][cc-1]==2&&b[cr][cc-2]==2&&b[cr][cc-3]==2&&b[cr][cc+1]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr][cc-1]==3&&b[cr][cc-2]==3&&b[cr][cc-3]==3&&b[cr][cc+1]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr][cc+1]==2&&b[cr][cc+2]==2&&b[cr][cc+3]==2&&b[cr][cc-1]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr][cc+1]==3&&b[cr][cc+2]==3&&b[cr][cc+3]==3&&b[cr][cc-1]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc]==2&&b[cr+2][cc]==2&&b[cr-1][cc]==2&&b[cr-2][cc]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr+1][cc]==3&&b[cr+2][cc]==3&&b[cr-1][cc]==3&&b[cr-2][cc]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc]==2&&b[cr+2][cc]==2&&b[cr+3][cc]==2&&b[cr+4][cc]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr+1][cc]==3&&b[cr+2][cc]==3&&b[cr+3][cc]==3&&b[cr+4][cc]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr-1][cc]==2&&b[cr-2][cc]==2&&b[cr-3][cc]==2&&b[cr-4][cc]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr-1][cc]==3&&b[cr-2][cc]==3&&b[cr-3][cc]==3&&b[cr-4][cc]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();
			 }
					 else if(b[cr][cc]==2&&b[cr-1][cc]==2&&b[cr+1][cc]==2&&b[cr+2][cc]==2&&b[cr+3][cc]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr-1][cc]==3&&b[cr+1][cc]==3&&b[cr+2][cc]==3&&b[cr+3][cc]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc]==2&&b[cr-1][cc]==2&&b[cr-2][cc]==2&&b[cr-3][cc]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==3&&b[cr+1][cc]==3&&b[cr-1][cc]==3&&b[cr-2][cc]==3&&b[cr-3][cc]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==2&&b[cr-1][cc-1]==2&&b[cr-2][cc-2]==2&&b[cr-3][cc-3]==2&&b[cr-4][cc-4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==3&&b[cr-1][cc-1]==3&&b[cr-2][cc-2]==3&&b[cr-3][cc-3]==3&&b[cr-4][cc-4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==2&&b[cr+1][cc+1]==2&&b[cr+2][cc+2]==2&&b[cr+3][cc+3]==2&&b[cr+4][cr+4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr+1][cc+1]==3&&b[cr+2][cc+2]==3&&b[cr+3][cc+3]==3&&b[cr+4][cc+4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc+1]==2&&b[cr-1][cc-1]==2&&b[cr+2][cc+2]==2&&b[cr-2][cc-2]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr+1][cc+1]==3&&b[cr-1][cc-1]==3&&b[cr+2][cc+2]==3&&b[cr-2][cc-2]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr-1][cc+1]==2&&b[cr-2][cc+2]==2&&b[cr+1][cc-1]==2&&b[cr+2][cc-2]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr-1][cc+1]==3&&b[cr-2][cc+2]==3&&b[cr+1][cc-1]==3&&b[cr+2][cc-2]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");
						 getch();

			 }
		       else if(b[cr][cc]==2&&b[cr+1][cc-1]==2&&b[cr+2][cc-2]==2&&b[cr+3][cc-3]==2&&b[cr+4][cc-4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==3&&b[cr+1][cc-1]==3&&b[cr+2][cc-2]==3&&b[cr+3][cc-3]==3&&b[cr+4][cc-4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==2&&b[cr-1][cc+1]==2&&b[cr-2][cc+2]==2&&b[cr-3][cc+3]==2&&b[cr-4][cc+4]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();
			 }
					 else if(b[cr][cc]==3&&b[cr-1][cc+1]==3&&b[cr-2][cc+2]==3&&b[cr-3][cc+3]==3&&b[cr-4][cc+4]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc-1]==2&&b[cr+2][cc-2]==2&&b[cr+3][cc-3]==2&&b[cr-1][cc+1]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr+1][cc-1]==3&&b[cr+2][cc-2]==3&&b[cr+3][cc-3]==3&&b[cr-1][cc+1]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
			else if(b[cr][cc]==2&&b[cr-1][cc+1]==2&&b[cr-2][cc+2]==2&&b[cr-3][cc+3]==2&&b[cr+1][cc-1]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==3&&b[cr-1][cc+1]==3&&b[cr-2][cc+2]==3&&b[cr-3][cc+3]==3&&b[cr+1][cc-1]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
					 else if(b[cr][cc]==2&&b[cr+1][cc+1]==2&&b[cr-1][cc-1]==2&&b[cr+2][cc+2]==2&&b[cr+3][cc+3]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==3&&b[cr+1][cc+1]==3&&b[cr-1][cc-1]==3&&b[cr+2][cc+2]==3&&b[cr+3][cc+3]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");

			 getch();

			 }
		       else if(b[cr][cc]==2&&b[cr+1][cc+1]==2&&b[cr-3][cc-3]==2&&b[cr-1][cc-1]==2&&b[cr-2][cc-2]==2)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 1 wins");
			 outtextxy(470,110,"Press esc key to exit.");
			 getch();

			 }
		       else if(b[cr][cc]==3&&b[cr+1][cc+1]==3&&b[cr-3][cc-3]==3&&b[cr-2][cc-2]==3&&b[cr-1][cc-1]==3)
			 {
			 setcolor(RED);
			 outtextxy(470,100,"Player 2 wins");
			 outtextxy(470,110,"Press esc key to exit.");
			 getch();
			 }
					 if(cp==1)
				cp=2;
					 else if(cp==2)
				cp=1;
					}
 }
}
}

char *_output(double cap)
{
	double dd;
	char CDD[6],CD[6];
	int l = 0;


	dd = cap;

	gcvt(dd,10,CDD);

	l = strlen(CDD);

	if(l == 1)
	{

		  strcpy(CD,"0");
		  strcat(CD,CDD);

	}

		else
		{

		  strcpy(CD,CDD);

		}

     return(CD);
}

int _NumberOfDays(int month, int year)
{

  int No_of_days = 0;
	switch(month)
	{
	   case 1:
	   No_of_days = 31;
	   break;
	   case 2:
	   if((year)%4 == 0)
	   No_of_days = 29;
	   else
	   No_of_days = 28;
	   break;
	   case 3:
	   No_of_days = 31;
	   break;
	   case 4:
	   No_of_days = 30;
	   break;
	   case 5:
	   No_of_days = 31;
	   break;
	   case 6:
	   No_of_days = 30;
	   break;
	   case 7:
	   No_of_days = 31;
	   break;
	   case 8:
	   No_of_days = 31;
	   break;
	   case 9:
	   No_of_days = 30;
	   break;
	   case 10:
	   No_of_days = 31;
	   break;
	   case 11:
	   No_of_days = 30;
	   break;
	   case 12:
	   No_of_days = 31;
	   break;
	}

	return No_of_days;
}

void DrawBox(int left,int top, int width, int height, int bgcolor)
{
  setfillstyle(SOLID_FILL,bgcolor);
  bar(left,top,left+width,top+height);

  setcolor(BLACK);
  line(left+1,top+1,left+width-1,top+1);
  line(left+1,top+1,left+1,top+height-1);
  setcolor(DARKGRAY);
  line(left,top,left+width,top);
  line(left,top,left,top+height);
  setcolor(DARKGRAY);
  line(left+1,top+height-1,left+width-1,top+height-1);
  line(left+width-1,top+1,left+width-1,top+height-1);

}
void DrawCaption(int left, int top, int width, int height, char *str, int col)
{
	setcolor(col);
	outtextxy(left+(width/2)-(textwidth(str)/2)+1,
		   top+(height/2)-(textheight(str)/2)+1,str);
}

char *month(double mon)
{
	char month_name[][80] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

	return (month_name[mon-1]);
}

  int No_Of_Days(char date1[], char date2[])
  {
      int d1, m1, y1;
      int d2, m2, y2;
      int D,M,Y;
      int Arr[12];
      int i,count;
	  y1 = (date1[6] - 48) * 1000 + (date1[7] - 48) * 100 + (date1[8] - 48) * 10 + (date1[9] - 48);
	  m1 = (date1[3] - 48) * 10 + (date1[4] - 48);
	  d1 = (date1[0] - 48) * 10 + (date1[1] - 48);


	  y2 = (date2[6] - 48) * 1000 + (date2[7] - 48) * 100 + (date2[8] - 48) * 10 + (date2[9] - 48);
	  m2 = (date2[3] - 48) * 10 + (date2[4] - 48);
	  d2 = (date2[0] - 48) * 10 + (date2[1] - 48);

       if (y1 > y2 || (m1 > m2 && y1 == y2))
       {
	D = d1;
	M = m1;
	Y = y1;

	d1 = d2;
	m1 = m2;
	y1 = y2;

	d2 = D;
	m2 = M;
	y2 = Y;

       }



	  count = 0;

	  for (i = m1 ; i < (m2 + (y2 - y1) * 12) ; i++)

	  {

	   if (i > 12 )
	   {

	      i = 1;
	      y1 = y1 + 1;
	   }



	   Arr[0] = 31;
	   if (y1 % 4 == 0 )
	   {
		Arr[1] = 29;
	   }
	   else
	   {
	    Arr[1] = 28;
	   }
	   Arr[2] = 31;
	   Arr[3] = 30;
	   Arr[4] = 31;
	   Arr[5] = 30;
	   Arr[6] = 31;
	   Arr[7] = 31;
	   Arr[8] = 30;
	   Arr[9] = 31;
	   Arr[10] = 30;
	   Arr[11] = 31;

	   count = count + (Arr[i - 1]);



	 }

	   count = count + d2 - d1;

	   if (count < 0 )
	   count = count * -1;



	 return count;
   }

   int Name_Of_Day()
   {
     /* Assuming in 2015 on first january the day was thursday. */
	 /* Let S-1 M-2 T-3 W-4 T-5 F-6 S-7 */


	char datebuff[20];
	int _day = 5;
	int total_days = 0;


	strcpy(datebuff,"01");
	strcat(datebuff,"/");
	strcat(datebuff,_output(_MM));
	strcat(datebuff,"/");
	strcat(datebuff,_output(_YYYY));

      total_days = No_Of_Days(datebuff, "01/01/2015");

      if(_YYYY>=2015)
      {

	for(int k=1; k<= total_days; k++)
	{
		_day++;
		if(_day> 7)
		_day = 1;
	}
       }
       else
       {
	 for(int k=1; k<= total_days; k++)
	 {
		_day--;
		if(_day< 1)
		_day = 7;
	 }
       }

	return _day;

   }

void WriteDays(int left, int top)
{
	int No_of_days;
	char str[20];
	int _left = left, _top = top;
	int _col = 0;


	No_of_days = _NumberOfDays((int)_MM, (int)_YYYY);

	left = left+(Name_Of_Day()-1)*30;

	for(int i=0;i< No_of_days;i++)
	{


	    if(left >= _left+210)
	    {
	      left = _left;
	      top += 30;
	    }



	/*****************************/
	 if(_YYYY == _tempyy && _MM == _tempmm && _DD == i+1)
	 {
		setfillstyle(SOLID_FILL,BLUE);
		bar(left-2,top-5,left+15,top+10);
		_col = 1;

	 }
	/*****************************/


	    if(_col == 1)
	    {
	      setcolor(WHITE);
	      _col = 0;
	    }
	    else if(left == _left)
	    setcolor(RED);
	    else
	    setcolor(BLACK);
	    outtextxy(left,top,gcvt(i+1,10,str));
	    left += 30;

	}


}


void Draw()
{

int left=Left,top=Top;
int color = RED;
char str[10];

char days[][2]={"S","M","T","W","T","F","S"};


/******************************************/


  DrawBox(Left,Top,Width,Height,WHITE);
  setfillstyle(SOLID_FILL,DARKGRAY);
  bar(Left+3,Top+3,Left+Width-3,Top+20);

  for(int i=0;i<7;i++)
  {
	setcolor(color);
	outtextxy(left+10,top+8,days[i]);
	left += 30;
	color = LIGHTGRAY;
  }

/*******************************************/


DrawBox(Left,Top-40,Width,40,LIGHTGRAY);
DrawBox(Left+5,Top-30,Width/2-10,20,WHITE);
DrawBox(Left+Width/2+5,Top-30,Width/2-10,20,WHITE);

DrawCaption(Left+5,Top-30,Width/2-10,20,gcvt(_YYYY,10,str),BLUE);
DrawCaption(Left+Width/2+5,Top-30,Width/2-10,20,month(_MM),BLUE);

}

void Init()
{
  char datebuff[9];
  _strdate(datebuff);
  char up[2]={24};
  char down[2]={25};
  char left[2]={27};
  char right[2]={26};

  _YYYY = 2000 + (datebuff[6]-48)*10+datebuff[7]-48;
  _MM = (datebuff[0]-48)*10+datebuff[1]-48;
  _DD = (datebuff[3]-48)*10+datebuff[4]-48;

  _tempyy = _YYYY;
  _tempmm = _MM;

  DrawBox(50,30,570,430,LIGHTGRAY);
  DrawBox(50,30,569,20,BLUE);

  DrawBox(150,350,380,102,LIGHTGRAY);
  setcolor(DARKGRAY);
  rectangle(150,350,530,452);

  setcolor(WHITE);
  outtextxy(55,35,"GUI CALENDAR");
  setcolor(0);
  outtextxy(200,370,"Using Keys :");
  outtextxy(202,390,up);
  outtextxy(204,390," : Increase Year,");
  outtextxy(347,390,down);
  outtextxy(349,390," : Decrease Year");

  outtextxy(200,405,right);
  outtextxy(204,405," : Increase Month,");
  outtextxy(347,405,left);
  outtextxy(349,405," : Decrease Month");

  outtextxy(200,420,"Esc : Exit");
  
}

void calendar()
{
  int gd = DETECT,gm;
  int ch;
  initgraph(&gd,&gm,"c://turboc3//bgi"/* path of bgi graphics */);

  Init();
  Draw();
  WriteDays(Left+10,Top+40);

  do{
  ch = getch();

   switch(ch)
   {
   case 27: //Esc
    exit(0);
   break;
   case 72: // up arrow key - year increases
   if(_YYYY < 2070)
    _YYYY++;
    Draw();
    WriteDays(Left+10,Top+40);
   break;

   case 80: // Down arrow key - year decreases
    if(_YYYY > 1500)
    _YYYY--;

    Draw();
    WriteDays(Left+10,Top+40);
   break;

   case 77: // right arrow key - month increases

     if(_YYYY < 2070)
     _MM++;

   if(_MM>12 && _YYYY < 2070)
   {
     _MM = 1;
     _YYYY++;
   }

    Draw();
    WriteDays(Left+10,Top+40);
   break;

  case 75: // left arrow key - month decreases
  if(_YYYY>1500)
    _MM--;
  if(_MM < 1 && _YYYY > 1500)
  {
	_MM = 12;
	_YYYY--;
  }
   Draw();
   WriteDays(Left+10,Top+40);
  break;

  }

  }while(1);

}
#define X 320
#define Y 240
#define R 150
#define PI 3.14159265
#define color CYAN
#define boundary_color LIGHTRED

float angle_sec=0,angle_min=0,angle_hr=0;
int init_sec=0,init_min =0,init_hr=0;
int start_sec=0, start_min=0, start_hr=0;
float x_hr,y_hr,x_min,y_min;

void Draw_Clock()
{
char str[][3]={"12","1","2","3","4","5","6","7","8","9","10","11"};
float angle=0,x,y;

setcolor(0);
setfillstyle(SOLID_FILL,0);
circle(X,Y,3);
floodfill(X,Y,0);

setcolor(boundary_color);
setfillstyle(SOLID_FILL,boundary_color);
circle(X,Y,R+15);
floodfill(X+R+3,Y,boundary_color);

setcolor(color);
setfillstyle(SOLID_FILL,color);
circle(X,Y,R);
floodfill(X,Y,color);

setcolor(WHITE);

for(int i=1;i<=60;i++)
{
angle = angle+6*(PI/180);
x = X+(R-32)*cos(-angle);
y = Y-(R-32)*sin(-angle);

if(i%5!=0)
putpixel(x,y,15);
}

angle = 0;

for(int j=0;j<12;j++)
{
x = X+(R-30)*sin(angle)-6;
y = Y-(R-30)*cos(angle);
angle = angle+(30*(PI/180));
outtextxy(x,y,str[j]);
}

}

void Second_Hand()
{

float x,y,angle,x1,y1;
char timebuf[9];
int second;

_strtime(timebuf);

second = (timebuf[6]-48)*10+timebuf[7]-48;

if(init_sec==0)
{
angle_sec = angle_sec+(second*6)*(PI/180);
angle_sec = angle_sec-6*(PI/180);
init_sec=1;
start_sec=second;
}
else
angle_sec = angle_sec+6*(PI/180);
angle = angle_sec-6*(PI/180);

x = X+(R-50)*sin(angle_sec);
y = Y-(R-50)*cos(angle_sec);

x1 = X+(R-50)*sin(angle);
y1 = Y-(R-50)*cos(angle);

setlinestyle(0,3,1);

/* Draw line */

setcolor(BLACK);
line(X,Y,x,y);

/* Erase old line */

setcolor(color);
line(X,Y,x1,y1);


}


void Minute_Hand(int rotate)
{

float angle,x1,y1;
char timebuf[9];
int minute;

if(rotate == 1)
{

_strtime(timebuf);

minute = (timebuf[3]-48)*10+timebuf[4]-48;

if(init_min==0)
{
angle_min = angle_min+(minute*6)*(PI/180);
init_min=1;
start_min = minute;
}
else
angle_min = angle_min+6*(PI/180);
angle = angle_min-6*(PI/180);

x_min = X+(R-50)*sin(angle_min);
y_min = Y-(R-50)*cos(angle_min);

x1 = X+(R-50)*sin(angle);
y1 = Y-(R-50)*cos(angle);

setlinestyle(0,3,3);

/* Draw line */

setcolor(BLACK);
line(X,Y,x_min,y_min);

/* Erase old line */

setcolor(color);
line(X,Y,x1,y1);

}
else
{
/* Draw line */

setcolor(BLACK);
line(X,Y,x_min,y_min);

}

}

void Hour_Hand(int rotate,int min)
{

float angle,x1,y1;
char timebuf[9];
int hour;

if(rotate == 1)
{

_strtime(timebuf);

hour = (timebuf[0]-48)*10+timebuf[1]-48;
if(hour > 12)
hour = hour-12;
start_hr=hour;

if(init_hr==0)
{
angle_hr = angle_hr+((hour*30))*(PI/180);
angle_hr += (min*6)*(PI/180);
init_hr=1;
}
else
angle_hr = angle_hr+6*(PI/180);

angle = angle_hr-6*(PI/180);

x_hr = X+(R-80)*sin(angle_hr);
y_hr = Y-(R-80)*cos(angle_hr);

x1 = X+(R-80)*sin(angle);
y1 = Y-(R-80)*cos(angle);

setlinestyle(0,1,3);

/* Draw line */

setcolor(BLACK);
line(X,Y,x_hr,y_hr);

/* Erase old line */

setcolor(color);
line(X,Y,x1,y1);

}

else
{
/* Draw line */

setcolor(BLACK);
line(X,Y,x_hr,y_hr);
}


}


void clock1()
{
int gd = DETECT, gm;
int _min;
int degree;
char timebuff[9];

initgraph(&gd,&gm,"c://turboc3//bgi"/* path of bgi graphics*/);

settextstyle(4,0,4);
outtextxy(230,20,"Analog Clock");


settextstyle(0,0,0);

_strtime(timebuff);
outtextxy(300,430,timebuff);

/* Drawing clock, hour hand, minute hand and second hand */

Draw_Clock();
Minute_Hand(1);
Second_Hand();

_min = floor(start_min/12);

degree = start_min - (12*_min);

if(degree == 0)
degree = 1;

Hour_Hand(1,_min);

while(1){


for(int j=start_min;j<=60;j++)
{
for(int i=start_sec;i<60;i++)
{
if(kbhit())
{
closegraph();
exit(0);
}
setcolor(WHITE);

_strtime(timebuff);
outtextxy(300,430,timebuff);

/* Drawing dot at center of the clock */

setcolor(0);
setfillstyle(SOLID_FILL,0);
circle(X,Y,3);
floodfill(X,Y,0);

/* Drawing hour hand, minute hand and second hand */

Second_Hand();
Minute_Hand(0);
Hour_Hand(0,_min);

delay(1000);

setcolor(0);
outtextxy(300,430,timebuff);
}

/* Drawing minute hand after 60 seconds completed */

Minute_Hand(1);
start_sec = 0;

degree++;

if(degree %12 ==0)
Hour_Hand(1,_min);

}
start_min=1;
degree = 1;

}

}

int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

void showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

void hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;	i.x.cx=x1;	i.x.dx=x2;
	int86(0x33,&i,&o);
	i.x.ax=8;	i.x.cx=y1;	i.x.dx=y2;
	int86(0x33,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*y=o.x.dx;
	*x=o.x.cx;
}

void paint()
{
 char col;
 while((col=getch())!='e')
 {
	 int gm,maxx,maxy,x,y,button,prevx,prevy;
	 maxx=getmaxx();
	 maxy=getmaxy();
	 clearviewport();
	 switch(col)
	{
		case 'r':setcolor(RED);	    break;
		case 'g':setcolor(GREEN);	  break;
		case 'b':setcolor(BLUE);  	break;
		case 'y':setcolor(YELLOW);	break;
		default : setcolor(BLUE);
	}
	char c;
	do
	{
		clearviewport();
		rectangle(0,0,maxx,maxy);
		setviewport(1,1,maxx-1,maxy-1,1);
		if(initmouse()==0)
		{
			closegraph();
			restorecrtmode();
			cout<<"mouse driver not loaded";
			exit(1);
		}
		settextstyle(1,HORIZ_DIR,7);
		outtextxy(25,4,"TITAN PAINT");
		restrictmouseptr(1,1,maxx-1,maxy-1);
		showmouseptr();
		while(!kbhit())
		{
			getmousepos(&button,&x,&y);
			if((button&1)==1)
			{
				hidemouseptr();
				prevx=x;		prevy=y;
				while((button&1)==1)
				{
				line(prevx,prevy,x,y);
				prevx=x;
				prevy=y;
				getmousepos(&button,&x,&y);
			}
			showmouseptr();
		}
	}
	c=getch();
}while(c=='c'||c=='C');
}
}

void newsc::news1()
{
		newsc a;
		ifstream fin("news.dat",ios::binary);
		while(fin.read((char *)&a,sizeof(a)))
		{
			cleardevice();

			setbkcolor(BLACK);
			setcolor(YELLOW);
			settextstyle(4,HORIZ_DIR,7);
			outtextxy(40,20,"NEWS CORNER");
			settextstyle(1,0,4);
			outtextxy(40,90,"HEADLINES");
			outtextxy(40,110,"--------");
			outtextxy(30,130,a.h);
			outtextxy(30,160,a.h2);
			outtextxy(30,190,a.t);
			gotoxy(1,16);
			for(int i=0;i<3;i++)
			cout<<a.b[i]<<endl;;
			getch();
		}
}

	void newsc::modifynews()
	{
	newsc a;
	char ch;
	do
	{
		settextstyle(1,0,4);
		outtextxy(250,10,"Modify News");
		settextstyle(1,0,2);
		outtextxy(50,60,"ADD NEWS (A)");
		outtextxy(50,100,"DELETE NEWS (D)");
		char ch1;
		cin>>ch1;
		if(ch1=='A'||ch1=='a')
		{
			cleardevice();
			outtextxy(50,60,"Enter Headline:");
			gotoxy(5,5);
			gets(a.h);
			outtextxy(50,100,"Enter Additional Headline:");
			gotoxy(5,8);
			gets(a.h2);
			outtextxy(50,140,"Enter tag line:");
			gotoxy(5,11);
			gets(a.t);
			outtextxy(50,180,"Enter content:");
			gotoxy(5,15);
			for(int i=0;i<3;i++)
			gets(a.b[i]);
			ofstream fout("news.dat",ios::binary|ios::app);
			fout.write((char *)&a,sizeof(a));
			fout.close();
		}
		else
		{
			news();
			cleardevice();
			outtextxy(50,60,"DELETE NEWS NUMBER:");
			int ch1,i=0;
			cin>>ch1;
			ifstream fin("news.dat",ios::binary);
			ofstream fout("temp.dat",ios::binary);
			while(fin.read((char *)&a,sizeof(a)))
			{
				i++;
				if(i!=ch1)
				fout.write((char *)&a,sizeof(a));
			}
			fin.close();
			fout.close();
			remove("news.dat");
			rename("temp.dat","news.dat");
		}
		cleardevice();
		outtextxy(100,40,"Do you want to add any more news?");
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}


void news()
{	newsc b;	b.news1(); }

void modifynews()
{	newsc b;	b.modifynews(); }

/********************  TRICKY TEST *****************************/

void level(char*a)
{
		cleardevice();
		settextstyle(1,HORIZ_DIR,8);
		setcolor(YELLOW);
		outtextxy(100,120,a);
		getch();
}

void gstuff()
{
			cleardevice();
			settextstyle(3,0,3);
			setbkcolor(BLACK);
}

void correct(char *message,int sc)
{
		char b[20];
		cleardevice();
		setbkcolor(BLACK);
		settextstyle(3,0,7);
		outtextxy(150,120,"CORRECT ");
		settextstyle(3,0,3);
		outtextxy(20,250,message);
		itoa(sc,b,10);
		settextstyle(3,0,7);
		outtextxy(150,320,"Score: ");
		outtextxy(350,320,b);
		getch();
}

void wrong(int sco)
{
	char b[5];
	cleardevice();
	setbkcolor(BLACK);
	settextstyle(3,0,8);
	outtextxy(60,120,"INCORRECT ");
	itoa(sco,b,10);
	settextstyle(3,0,6);
	outtextxy(150,320,"Score: ");
	outtextxy(300,320,b);
	getch();
}

void tricky()
{
	char b[20];
	int score=0;
	setbkcolor(BLACK);

	cleardevice();
	settextstyle(1,HORIZ_DIR,8);
	setcolor(YELLOW);
	outtextxy(60,120,"TRICKY TEST");
	setfillstyle(EMPTY_FILL,0);
	bar3d(100,350,540,400,0,1);
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(260,348,"START");
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(230,410,"PRESS S TO START");
	char ch=getch();
	if(ch=='s'||ch=='S')
	{
		int wrongans=0;
		level("LEVEL 1");
		do
		{
			wrongans=0;			gstuff();
			outtextxy(30,35,"Question:If you look at the clock and the time is 3:15 ");
			outtextxy(30,65,"what is the angle between hour and minute hands??? " );
			outtextxy(30,135,"A: 0 degree  " );
			outtextxy(240,135,"B: 15 degree");
			outtextxy(30,185,"C: 7.5 degree" );
			outtextxy(240,185,"D: 22.5 degree");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');

			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='C')
			{
				score+=10;
				correct("REASON:THE HOUR HAND WILL NOT POINT TO 3",score);
			}
			else
			{
				score-=10;
				wrongans=1;
				wrong(score);
			}
		}while(wrongans);

		level("LEVEL 2");

		do
		{
			wrongans=0;			gstuff();
			outtextxy(30,35,"Question: how many times a day does a clock's ");
			outtextxy(30,65,"          hands overlap??? " );
			outtextxy(30,135,"A: 21  " );outtextxy(240,135,"B: 22");
			outtextxy(30,185,"C: 23 " );outtextxy(240,185,"D: 24");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='B')
			{
				score+=10;
				correct("			REASON:take a clock and count!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;
				wrong(score);
			}
		}while(wrongans);

		level("LEVEL 3");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question:A man was born in 1948 and he recently ");
			outtextxy(30,65,"celebrated his 17th bday which month would have he born???" );
			outtextxy(30,135,"A: Dec  " );outtextxy(240,135,"B: Aug");
			outtextxy(30,185,"C: Jan" );outtextxy(240,185,"D: Feb");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='D')
			{
				score+=10;
				correct("REASON:HE MIGHT HAVE BORN ON 29/FEB/1948",score);
			}
			else
			{
				score-=10;
				wrongans=1;
				wrong(score);
			}
		}while(wrongans);

		level("LEVEL 4");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question:How many bdays an average man has??");
			outtextxy(30,65,"           " );
			outtextxy(30,135,"A: 90  " );outtextxy(240,135,"B: 1");
			outtextxy(30,185,"C: 10 " );outtextxy(240,185,"D: 67");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='B')
			{
				score+=10;
				correct("REASON:A MAN CAN BE BORN ONLY ONCE!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1; wrong(score);
			}
		}while(wrongans);

		level("LEVEL 5");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question:Some months have 31 days how many ");
			outtextxy(30,65,"         months  have 30 days??? " );
			outtextxy(30,135,"A: 5  " );outtextxy(240,135,"B: 7 ");
			outtextxy(30,185,"C: 9 " );outtextxy(240,185,"D: 11");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='D')
			{
				score+=10;
				correct("REASON:months other than feb have days>=30",score);
			}
			else
			{
				score-=10;
				wrongans=1; wrong(score);
			}
		}while(wrongans);

		level("LEVEL 6");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: What no. comes in the sequence ");
			outtextxy(30,65,"          4 , 12 , 28 , 60 , ? " );
			outtextxy(30,135,"A: 124  " );outtextxy(240,135,"B: 88");
			outtextxy(30,185,"C: 102 " );outtextxy(240,185,"D: 140");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='A')
			{
				score+=10;
				correct("          REASON:60*2+4=124!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1; wrong(score);
			}
		}while(wrongans);

		level("LEVEL 7");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: how many bricks does it take to complete ");
			outtextxy(30,65,"  a building made of bricks?? " );
			outtextxy(30,135,"A: infinity  " );outtextxy(240,135,"B:10000");
			outtextxy(30,185,"C: 1 " );outtextxy(240,185,"D: 99999");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='C')
			{
				score+=10;
				correct("REASON:the last brick is needed to complete!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 8");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(15,35,"Question:An electric train moves towards north with speed");
			outtextxy(15,65," of 100mph and wind blow in the direction of west with");
			outtextxy(15,95,"same speed then in which direction does the smoke blow???");
			outtextxy(30,195,"A: Not visible  " );outtextxy(240,195,"B: North west");
			outtextxy(30,255,"C: North east " );outtextxy(240,255,"D: South west");
			outtextxy(30,350,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,350,a);
			if(c=='A')
			{
				score+=10;
				correct("REASON:electric engine can't produce smoke!!!",score);
			}

			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 9");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(15,35,"Question:if it took 8 men 10 months to build a house how");
			outtextxy(15,65,"long will it take for 4 men to build the same house??? " );
			outtextxy(30,135,"A: 20 months  " );outtextxy(300,135,"B: 5 months");
			outtextxy(30,185,"C: less than 1 month " );outtextxy(300,185,"D: 10 months");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='C')
			{
				score+=10;
				correct("REASON:the house is already built!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 10");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: I'm an odd number when you remove an");
			outtextxy(30,65,"alphabet, I become even then guess who I am???");
			outtextxy(30,135,"A: 9 ");outtextxy(240,135,"B: 7");
			outtextxy(30,185,"C: 11 " );outtextxy(240,185,"D: 5");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='B')
			{
				score+=10;
				correct("REASON:seven.remove s.it becomes even!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 11");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: If you have 4 apples and you take away ");
			outtextxy(30,65,"3 from them, how many do you have???  " );
			outtextxy(30,135,"A: 1  " );outtextxy(240,135,"B: 2");
			outtextxy(30,185,"C: 3 " );outtextxy(240,185,"D: 4");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='C')
			{
				score+=10;
				correct("REASON:3.because you took only 3!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 12");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(25,35,"Question:If there were 13 rooster eggs farmer took");
			outtextxy(25,65," 4eggs,4 eggs were rotten,how many were left???");
			outtextxy(30,135,"A: 9 " );outtextxy(240,135,"B: 5");
			outtextxy(30,185,"C: 13 " );outtextxy(240,185,"D: 0");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='D')
			{
				score+=10;
				correct("REASON: Roosters don't lay eggs!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("LEVEL 13");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: If there are 12 fishes and half of  ");
			outtextxy(30,65,"them drown,then how many are left??? " );
			outtextxy(30,135,"A: 12  " );outtextxy(240,135,"B: 6");
			outtextxy(30,185,"C: 2 " );outtextxy(240,185,"D: 8");
			outtextxy(30,300,"Enter Your Answer: ");
			char c,a[2];
			do
			{
				c=getch();
				c=toupper(c);
			}while(c!='A'&&c!='B'&&c!='C'&&c!='D');
			a[0]=c;a[1]=0;
			outtextxy(275,300,a);
			if(c=='A')
			{
				score+=10;
				correct("   REASON : Fishes do not drown!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		level("BONUS");

		wrongans=0;       gstuff();
		outtextxy(30,35,"Question: IN WHICH STATE DOES BAY OF BENGAL FLOW??");
		outtextxy(30,100,"A: WEST BENGAL ORISSA  " );outtextxy(240,150,"B: TAMIL NADU,AP &TELANGANA");
		outtextxy(30,200,"C: GOA KERALA KARNATAKA " );outtextxy(240,250,"D:BOTH A AND B");
		outtextxy(30,300,"Enter Your Answer: ");
		char aa[2];
		char d;
		do
		{
			d=getch();
			d=toupper(d);
		}while(d!='A'&&d!='B'&&d!='C'&&d!='D');
		aa[0]=d;aa[1]=0;
		outtextxy(275,300,aa);
		if(d=='E')
		{
			char  b[5];
			score+=10;
			cleardevice();
			settextstyle(3,0,8);
			outtextxy(80,120,"CORRECT ");
			itoa(score,b,10);
			settextstyle(3,0,6);
			outtextxy(150,320,"Score: ");
			outtextxy(350,320,b);
			getch();
		}
		else
		{
			cleardevice();
			settextstyle(3,0,8);
			outtextxy(60,120,"incorrect");
			itoa(score,b,10);
			settextstyle(3,0,4);
			outtextxy(100,260,"CORRECT ANS::IT FLOWS");
			outtextxy(100,320,"             IN LIQUID STATE");
			getch();
		}

		level("BONUS");

		wrongans=0;       gstuff();
		outtextxy(30,35,"Question: What has cities but no house;forest");
		outtextxy(30,65,"but no trees;water but no fishes");
		outtextxy(30,100,"A: Africa  " );outtextxy(240,150,"B: Antarctica");
		outtextxy(30,200,"C: Europe " );outtextxy(240,250,"D: BOTH A AND B");
		outtextxy(30,300,"Enter Your Answer: ");
		char ab[2];
		char c1;
		do
		{
			c1=getch();
			c1=toupper(c1);
		}while(c1!='A'&&c1!='B'&&c1!='C'&&c1!='D');
		ab[0]=c1;ab[1]=0;
		outtextxy(275,300,aa);
		if(c1=='E')
		{
			score+=10;
			correct("",score);
		}
		else
		{
			wrongans=1;
			cleardevice();

			settextstyle(3,0,8);
			outtextxy(60,120,"incorrect");
			itoa(score,b,10);
			settextstyle(3,0,4);
			outtextxy(100,320,"CORRECT ANS:: A Map");
			getch();
		}

		level("LEVEL 14");

		do
		{
			wrongans=0;     gstuff();
			outtextxy(30,35,"Question: There was a plane crash every single person died");
			outtextxy(30,65,"Then who survived???");
			outtextxy(30,100,"A: Justin Bieber" );outtextxy(240,150,"B: Trump");
			outtextxy(30,200,"C: newton" );outtextxy(240,250,"D:tesla");
			outtextxy(30,300,"Enter Your Answer: ");
			char ac[2];  char c2;
			do
			{
				c2=getch();
				c2=toupper(c2);
			}while(c2!='A'&&c2!='B'&&c2!='C'&&c2!='D');
			ac[0]=c2;ac[1]=0;
			outtextxy(275,300,aa);
			if(c2=='B')
			{
				score+=10;
				correct("  REASON:TRUMP WAS MARRIED!!!",score);
			}
			else
			{
				score-=10;
				wrongans=1;  wrong(score);
			}
		}while(wrongans);

		cleardevice();
		settextstyle(1,HORIZ_DIR,5);
		setcolor(YELLOW);
		itoa(score,b,10);
		outtextxy(20,50,"YOUR SCORE IS :");
		outtextxy(350,50,b);
		if(score>=130)
		outtextxy(20,250,"YOU ARE GENIUS!!!");
		else if(score>=110)
		outtextxy(20,250,"YOU ARE VERY SUPERIOR!!!");
		else if(score>=90)
		outtextxy(20,250,"YOU ARE SUPERIOR!!!");
		else if(score>=60)
		outtextxy(20,250,"YOU ARE NORMAL!!!");
		else if(score>=30)
		outtextxy(20,250,"YOU ARE DULL!!!");
		else
		outtextxy(20,250,"YOU ARE STUPID!!!");
		getch();
	}
}

void anim()
{
	int maxx,maxy,area,x=25,y=25,ch,xdirn=1,ydirn=1;
	char *buff;
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	circle(50,50,25);
	floodfill(50,50,WHITE);

	area=imagesize(25,25,75,75);
	buff=(char *)malloc(area);
	getimage(25,25,75,75,buff);

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,20,maxx,maxy);
	outtextxy(250,10,"Animation");
	while(1)
	{
		if(kbhit())
		{
			ch=getch();
			if(ch=='/r')
			{
				xdirn*=-1;
				ydirn*=-1;
			}
			else		if(ch==27)			break;
		}
		putimage(x,y,buff,XOR_PUT);
		delay(100);
		x+=xdirn*5;
		y+=ydirn*2;
		putimage(x,y,buff,XOR_PUT);

		if(x>maxx-50||x<0)
		{
			delay(10);
			xdirn*=-1;
		}
		if(y>maxy-50||y<20)
		{
			delay(10);
			ydirn*=-1;
		}
	}
	getch();
}

void load()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(YELLOW);
	int x=170;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(170,180,"LOADING,PLEASE WAIT");
	for(int i=0;i<300;++i)
	{
		if(i%10==0) delay(15);
		delay(15);
		line(x,200,x,220);
		x++;
	}
	delay(500);
	cleardevice();
}

void kollywood()
{
	film a[10]={"NAYAGAN","MANI RATNAM","KAMAL HAASAN",
		"SIVAJI","SHANKAR","RAJINIKANTH",
		"THUPPAKKI","A.R.MURUGADOSS","VIJAY",
		"BOMBAY","MANI RATNAM","ARWIND SWAMY",
		"SINGAM","HARI","SURIYA",
		"PARUTHIVEERAN","AMEER SULTAN","KARTHI",
		"VISARANAI","VETRIMAARAN","DINESH",
		"BAAHUBALI","SS RAJAMOULI","PRABHAS",
		"THERI","ATLEE","VIJAY",
		"AADUKALAM","VETRIMAARAN","DHANUSH"};
	cleardevice();
	load();
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,8);
	setcolor(YELLOW);
	outtextxy(80,120,"KOLLY WOOD");
	setfillstyle(EMPTY_FILL,0);
	bar3d(100,350,540,400,0,1);
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(260,348,"START");
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(230,410,"PRESS S TO START");
	char ch=getch();
	if(ch=='s'||ch=='S')
	{
		for(int m1=0;m1<10;m1++)
		{
			char y[20];
			int k1=0;
			setfillstyle(SOLID_FILL,5);
			cleardevice();
			setbkcolor(RED);
			settextstyle(1,HORIZ_DIR,7);
			setcolor(YELLOW);
			outtextxy(60,50,"! KOLLY WOOD !");
			outtextxy(60,95,"-----------");
			settextstyle(7,0,3);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(0,430,400,480);
			outtextxy(30,440,"titan game developers inc.");
			int k=m1;
			int flag=0;
			char z[20];
			for(int i=0;i<strlen(a[k].n);i++)
			z[i]='_';
			z[i]=0;
			settextstyle(2,0,10);
			outtextxy(100,200,z);
			outtextxy(100,350,"DIRECTOR : ");
			outtextxy(350,350,a[k].h1);
			char b[10]="KOLLYWOOD";
			char d[10]={0};
			for(int j=0;flag!=9;j++)
			{
				int s5=0;
				char c;
				do
				{
					s5=0;
					c=toupper(getch());
					for(int i=0;i<k1;i++)
					if(c==y[i])
					s5++;
				}while(s5);
				y[k1++]=c;
				int tp;
				tp=0;
				for(int w=0;w<strlen(a[k].n);w++)
				{
					if(c==a[k].n[w])
					{
						z[w]=c;
						tp++;
						outtextxy(100,200,z);
					}
				}
				for(w=0;w<1&&!tp;w++)
				{
					d[flag]=b[flag];
					d[++flag]='\0';
					outtextxy(100,275,d);
					if(flag==5)
					{
						outtextxy(100,385,"ACTOR : ");
						outtextxy(300,385,a[k].h2);
					}
				}
				if(flag==9)
				scorn++;
				if(strcmpi(z,a[k].n)==0)
				{
					delay(500);
					break;
				}
			}
		}
	}
}

void kolly()
{
	int a,b,c;
	cleardevice();
	kollywood();
	cleardevice();
	outtextxy(110,160,"YOUR SCORE IS : : ");
	settextstyle(7,0,8);
	char scor[20];
	itoa(100*(10-scorn),scor,10);
	outtextxy(110,180,scor);
	getch();
}


void quiz()
{
    cleardevice();
    load();
    cleardevice();
    setbkcolor(BLACK);
    setcolor(YELLOW);
    settextstyle(4,HORIZ_DIR,10);
    outtextxy(240,80,"Quiz");
    settextstyle(1,0,4);
    outtextxy(300,240,"Press S to start ");
    char s1;
    s1=getch();
    cleardevice();
    if(s1=='s'||s1=='S')
    {
        qu q;
        int cr[20]= {0},ic=0;
        int k2=0,s2[50];
        randomize();
        char b1[20][20];
        int v=1,d=0;
        ifstream fin("QUIZ.dat",ios::binary);
        fin.seekg(0,ios::end);
        int p=fin.tellg()/sizeof(q);
        while(v)
        {
            int k4=1,k10;
            ic=0;
            cleardevice();
            fflush(stdin);
            outtextxy(20,30,"Enter Player name : ");
            gotoxy(14,5);
            gets(b1[d]);
            while((ic+cr[d])<10)
            {
                int k9=0,x;
                do
                {
                    k9=0;
                    x=random(p);
                    for(int k3=0; k3<k2; k3++)
                        if(s2[k3]==x)
                            k9++;
                }
                while(k9);
                s2[k2++]=x;
                settextstyle(1,0,2);
                char y;
                cleardevice();
                fin.seekg((x)*sizeof(q));
                fin.read((char *)&q,sizeof(q));
                outtextxy(10,20,"Question : ");
                settextstyle(1,0,1);
                outtextxy(150,20,q.a);
                settextstyle(1,0,2);
                outtextxy(20,60,"Options : ");
                randomize();
                do
                {
                    k4=random(4);
                }
                while(k4==k10);
                k10=k4;
                outtextxy(150,60,"A .");
                outtextxy(150,100,"B .");
                outtextxy(150,140,"C .");
                outtextxy(150,180,"D .");
                int k3;
                switch(k4)
                {
                case 0:
                    for(k3=0; k3<4; k3++)
                        outtextxy(200,60+k3*40,q.b[k3]);
                    break;
                case 1:
                    outtextxy(200,60,q.b[1]);
                    outtextxy(200,100,q.b[0]);
                    for(k3=2; k3<4; k3++)
                        outtextxy(200,60+k3*40,q.b[k3]);
                    break;
                case 2:
                    outtextxy(200,60,q.b[1]);
                    outtextxy(200,100,q.b[2]);
                    outtextxy(200,140,q.b[0]);
                    outtextxy(200,180,q.b[3]);
                    break;
                case 3:
                    for(k3=1; k3<4; k3++)
                        outtextxy(200,60+(k3-1)*40,q.b[k3]);
                    outtextxy(200,180,q.b[0]);
                    break;
                }
                outtextxy(30,245,"Your Answer : ");
                gotoxy(30,17);
                cin>>y;
                if(y!='A'+k4&&y!='a'+k4)
                {
                    ic++;
                    outtextxy(20,290,"Sorry you got it WRONG!!");
                    outtextxy(20,325,"Expected Answer : ");
                    gotoxy(30,22);
                    cout<<char('A'+k4);
                }
                else
                {
                    cr[d]++;
                    outtextxy(20,300,"Congratulations you got it RIGHT!!");
                }
                outtextxy(20,358,"Correct : ");
                gotoxy(17,24);
                cout<<cr[d]<<"/10 ";
                outtextxy(250,358,"Incorrect : ");
                gotoxy(50,24);
                cout<<ic<<"/10";
                getch();
            }
            cleardevice();
            outtextxy(100,50,"Do you want to play another round?");
            gotoxy(45,5);
            char e=getchar();
            if(e=='y'||e=='Y')
                v++;
            else v=0;
            d++;
        }
        cleardevice();
        outtextxy(250,50,"High Scores");
        char _cr[20];
        high b[10];
        for(int h=0; h<d; h++)
        {
            strcpy(b[h].name,b1[h]);
            b[h].score=100*cr[h];
        }
        for(h=0; h<d-1; h++)
        {
            int max=b[h].score,k=h;
            for(int j=h+1; j<d; j++)
                if(max<b[j].score)
                {
                    max=b[j].score;
                    k=j;
                }
            c=b[h];
            b[h]=b[k];
            b[k]=c;
        }
	   outtextxy(40,75,"YOUR SCORES :");
        for(h=0; h<d; h++)
        {
            itoa(b[h].score,_cr,10);
            outtextxy(50,100+50*h,"Player ");
            outtextxy(200,100+50*h,b[h].name);
            outtextxy(400,100+50*h,": ");
            outtextxy(450,100+50*h,_cr);
        }
        ifstream f("QUSC.dat",ios::binary);
        int l=0;
		outtextxy(40,100+50*h++,"PREVIOUS SCORES :");
        while(f.read((char *)&a,sizeof(a)))
        {
            itoa(a.score,_cr,10);
            outtextxy(50,100+50*h,"Player ");
            outtextxy(200,100+50*h,a.name);
            outtextxy(400,100+50*h,": ");
            outtextxy(450,100+50*h,_cr);
            h++;
			l++;
			b[l+d]=a;
        }
		d+=l;
		for(h=0; h<d-1; h++)
        {
            int max=b[h].score,k=h;
            for(int j=h+1; j<d; j++)
                if(max<b[j].score)
                {
                    max=b[j].score;
                    k=j;
                }
            c=b[h];
            b[h]=b[k];
            b[k]=c;
        }
		for(h=0;h<d;h++)
			for(int j=h+1;j<d;j++)
				if(strcmp(b[h].name,b[j].name)==0)/*&&b[h].score>=b[j].score)*/
				{
					for(int k=j;k<d-1;k++)
						b[k]=b[k+1];
					d--;
					j--;
				}
		f.close();
           fin.close();
		remove("QUSC.dat");
		ofstream fout("QUSC.dat",ios::binary);
		for(h=0;h<d;h++)
			fout.write((char *)&b[h],sizeof(b[h]));
		fout.close();
	}
	else if(s1=='h'||s1=='H')
	{
		cleardevice();
        outtextxy(250,50,"High Scores");
        char _cr[20];
        ifstream f("QUSC.dat",ios::binary);
        int h=0;
        while(f.read((char *)&a,sizeof(a)))
        {
            itoa(a.score,_cr,10);
            outtextxy(50,200+50*h,"Player ");
            outtextxy(200,200+50*h,a.name);
            outtextxy(400,200+50*h,": ");
            outtextxy(450,200+50*h,_cr);
            h++;
		}
		f.close();
		char ch=getch();
		if(ch=='q'||ch=='Q')
			quiz();
	}
    getch();
}
void change()
{
	ofstream fout("Quiz.dat",ios::binary|ios::app|ios::nocreate);
	qu q;
	char ch;
	do
	{
		cleardevice();
		outtextxy(100,50,"Enter Question : ");
		gotoxy(20,5);
		gets(q.a);
		outtextxy(100,100,"Enter Options : ");
		for(int i=0;i<4;i++)
		{
			gotoxy(20,9+2*i);
			gets(q.b[i]);
		}
		fout.write((char *)&q,sizeof(q));
		cleardevice();
		settextstyle(1,0,3);
		outtextxy(100,150,"Do you want to add any more questions ?");
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fout.close();
}

void mind()
{
		 cleardevice();
		 setbkcolor(BLACK);
		 gotoxy(27,2);
		 cout<<"HELP TO PLAY GAME";
     delay(350);
		 gotoxy(10,6);
     cout<<"1). A MEMORY GAME FOR ONE PLAYER.";
     delay(350);
		 gotoxy(10,8);
     cout<<"2). The Objective of MIND MAZE is to chek the memory of the player";
     delay(350);
     gotoxy(10,10);
		 cout<<"3). Player has to remember the char displayed on first screen and  must enter it on 2 nd";
		 delay(350);
		 gotoxy(10,12);
     cout<<"4). The game includes 2 levels ";
     delay(350);
		 gotoxy(10,16);
		 getch();

		 cleardevice();
	int i;
	load();
	setbkcolor(BLACK);
	char c[2],d[11],scor[10];
	int score=0;
	settextstyle(4,HORIZ_DIR,8);
	setcolor(YELLOW);
	outtextxy(80,120,"MIND MAZE");

	setfillstyle(EMPTY_FILL,0);
	bar3d(100,350,540,400,0,1);
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(260,348,"START");
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(230,410,"PRESS S TO START");

	char ch=getch();
	if(ch=='s'||ch=='S')
	{
		cleardevice();
		setfillstyle(SOLID_FILL,RED);
		for(i=1;i<=8;i++)
		{
			setfillstyle(SOLID_FILL,5);
			cleardevice();
			setbkcolor(RED);
			settextstyle(4,HORIZ_DIR,6);

			setcolor(YELLOW);
			outtextxy(80,60,"! MIND MAZE !");
			outtextxy(80,95,"= ==== ==== =  ");

			settextstyle(7,0,3);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(0,430,400,480);
			outtextxy(30,440,"titan game developers inc.");
			setfillstyle(SOLID_FILL,CYAN);

			bar(400,350,640,480);
			outtextxy(410,360,"YOUR SCORE IS : : ");
			score+=(i-1)*100;
			itoa(score,scor,10);
			settextstyle(7,0,8);
			outtextxy(410,380,scor);

			setfillstyle(SOLID_FILL,MAGENTA);
			for(int m=0;m<i;m++)
			bar(80*m+10,193,80*(m+1),270);
			char a[20];
			char b[40]={' '};
			randomize();
			for(m=0;m<i;m++)
			{
				a[m]=random(10)+48;
			}
			a[m]=0;

			int x=20,d1=0;
			settextstyle(7,0,6);
			for(int x1=0;a[d1];x1+=2)
			b[x1]=a[d1++];
			b[x1]=0;

			for(int i1=0;b[i1];i1+=2)
			{
				moveto(40*i1+25,190);
				c[0]=b[i1];
				c[1]=0;
				outtext(c);
				delay(125);
				x+=50;
			}
			delay(2000);

			cleardevice();
			setbkcolor(RED);
			settextstyle(4,HORIZ_DIR,6);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,8);
			outtextxy(80,60,"! MIND MAZE !");
			outtextxy(80,95,"= ==== ==== =");
			settextstyle(7,0,3);
			setfillstyle(SOLID_FILL,CYAN);
			bar(0,430,400,480);

			outtextxy(30,440,"titan game developers inc.");

			setfillstyle(SOLID_FILL,MAGENTA);

			bar(400,350,640,480);
			outtextxy(410,360,"YOUR SCORE IS : : ");

			settextstyle(7,0,8);
			outtextxy(410,380,scor);
			setfillstyle(SOLID_FILL,DARKGRAY);
			for(m=0;m<i;m++)
			bar(80*m+10,193,80*(m+1),270);
			settextstyle(7,0,6);

			for(i1=0;i1<2*i;i1+=2)
			{
				moveto(40*i1+25,190);
				d[i1/2]=getch();
				c[0]=d[i1/2];
				c[1]=0;
				outtext(c);
				delay(125);
				x+=0;
			}
			d[i1/2]=0;

			if(strcmpi(a,d)!=0)
			{
				cleardevice();
				int wrong[]={
					90+40,100-30,
					180+40,100-30,
					270+40,220-30,
					360+40,100-30,
					450+40,100-30,
					340+40,250-30,
					450+40,400-30,
					360+40,400-30,
					360+40,400-30,
					270+40,280-30,
					180+40,400-30,
					90+40,400-30,
					200+40,250-30,
					90+40,100-30
				};
				setbkcolor(DARKGRAY);
				setfillstyle(1,RED);
				drawpoly(14,wrong);
				fillpoly(14,wrong);
				settextstyle(7,0,7);
				setcolor(RED);
				outtextxy(120,370,"INCORRECT!!!...");
			 delay(1500);
				break;
			}
			else
			{
				cleardevice();
				int tick[]={
					150,150,
					220,270,
					500,140,
					520,210,
					200,320,
					100,170,
					150,150
				};
				setfillstyle(1,GREEN);
				drawpoly(7,tick);
				fillpoly(7,tick);
				settextstyle(7,0,7);
				setcolor(GREEN);
				outtextxy(160,370,"CORRECT!!!...");
				delay(1500);
				continue;
			}
		}
	}

	getch();
	if(i==9)
	{
		cleardevice();
		settextstyle(4,HORIZ_DIR,8);
		setcolor(YELLOW);
		outtextxy(80,120,"MIND MAZE");
		settextstyle(7,0,7);
		outtextxy(200,250,"LEVEL 2");
		setfillstyle(EMPTY_FILL,0);
		bar3d(100,350,540,400,0,1);
		settextstyle(1,HORIZ_DIR,5);
		outtextxy(260,348,"START");
		settextstyle(1,HORIZ_DIR,2);
		outtextxy(230,410,"PRESS S TO START");

		ch=getch();
		if(ch=='s'||ch=='S')
		{
			cleardevice();
			setfillstyle(SOLID_FILL,RED);
			for(int i=1;i<=8;i++)
			{
				setfillstyle(SOLID_FILL,DARKGRAY);
				cleardevice();
				setbkcolor(RED);
				settextstyle(4,HORIZ_DIR,6);

				setcolor(YELLOW);
				outtextxy(80,60,"! MIND MAZE !");
				outtextxy(80,95,"= ==== ==== =  ");
				setfillstyle(SOLID_FILL,DARKGRAY);
				bar(0,430,400,480);
				settextstyle(7,0,3);
				outtextxy(30,440,"titan game developers inc.");
				setfillstyle(SOLID_FILL,MAGENTA);
				bar(400,350,640,480);
				outtextxy(410,360,"YOUR SCORE IS : : ");
				score+=(i-1)*100;
				itoa(score,scor,10);
				settextstyle(7,0,8);
				outtextxy(410,380,scor);

				setfillstyle(SOLID_FILL,CYAN);
				for(int m=0;m<i;m++)
				bar(80*m+10,193,80*(m+1),270);
				char a[20];
				char b[40]={' '};
				randomize();
				for(m=0;m<i;m++)
				{
					a[m]=random(26)+97;
				}
				a[m]=0;

				int x=20,d1=0;
				settextstyle(7,0,6);
				for(int x1=0;a[d1];x1+=2)
				b[x1]=a[d1++];
				b[x1]=0;

				for(int i1=0;b[i1];i1+=2)
				{
					moveto(40*i1+25,190);
					c[0]=b[i1];
					c[1]=0;
					outtext(c);
					delay(125);
					x+=50;
				}
				delay(2000);

				cleardevice();
				setbkcolor(RED);
				settextstyle(4,HORIZ_DIR,6);
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,8);
				outtextxy(80,60,"! MIND MAZE !");
				outtextxy(80,95,"= ==== ==== =");
				settextstyle(7,0,3);
				setfillstyle(SOLID_FILL,CYAN);
				bar(0,430,400,480);

				outtextxy(30,440,"titan game developers inc.");
				setfillstyle(SOLID_FILL,MAGENTA);
				bar(400,350,640,480);
				outtextxy(410,360,"YOUR SCORE IS : : ");
				setfillstyle(SOLID_FILL,DARKGRAY);
				settextstyle(7,0,8);
				outtextxy(410,380,scor);
				for(m=0;m<i;m++)
				bar(80*m+10,193,80*(m+1),270);
				settextstyle(7,0,6);

				for(i1=0;i1<2*i;i1+=2)
				{
					moveto(40*i1+25,190);
					d[i1/2]=getch();
					c[0]=d[i1/2];
					c[1]=0;
					outtext(c);
					delay(125);
					x+=0;
				}
				d[i1/2]=0;

				if(strcmpi(a,d)!=0)
				{
					cleardevice();
					int wrong[]={
						90+40,100-30,
						180+40,100-30,
						270+40,220-30,
						360+40,100-30,
						450+40,100-30,
						340+40,250-30,
						450+40,400-30,
						360+40,400-30,
						360+40,400-30,
						270+40,280-30,
						180+40,400-30,
						90+40,400-30,
						200+40,250-30,
						90+40,100-30
					};
					setbkcolor(DARKGRAY);
					setfillstyle(1,RED);
					drawpoly(14,wrong);
					fillpoly(14,wrong);
					settextstyle(7,0,7);
					setcolor(RED);
					outtextxy(120,370,"INCORRECT!!!...");
					delay(1500);
					break;
				}
				else
				{
					cleardevice();
					int tick[]={
						150,150,
						220,270,
						500,140,
						520,210,
						200,320,
						100,170,
						150,150
					};
					setfillstyle(1,GREEN);
					drawpoly(7,tick);
					fillpoly(7,tick);
					settextstyle(7,0,7);
					setcolor(GREEN);
					outtextxy(160,370,"CORRECT!!!...");
					delay(1500);
					continue;
				}
			}
		}
	}
	cleardevice();
	setbkcolor(RED);
	setcolor(YELLOW);
	settextstyle(7,0,6);
	outtextxy(0,50,"YOUR FINAL SCORE IS....");
	settextstyle(7,0,14);
	outtextxy(160,200,scor);
	getch();
}

void gif()
{
	cleardevice();
	float x;
	cout<<"Enter the number for which greatest integer has to be found";
	cin>>x;
	cout<<"Greatest integer of the given number is "<<floor(x);
}

float fact(int x)
{
	if(x>=0)
	{
	float m=1;
	cleardevice();
	for(int i=1;i<=x;i++)
	   m*=i;
	return m;
	}
	else return 0;
}

void npr()
{
	float x,y;
	cleardevice();
	int n,r;
	cout<<"\n\nP(n,r)";
	cout<<"\n\nEnter n: ";
	cin>>n;
	cout<<"\n\nEnter r : ";
	cin>>r;
	if(r>n)
		cout<<"\n\ninvalid operation";
	else
		{
		 x=fact(n);
		 y=fact(n-r);
		 cout<<"\n\n\n\t\tNo of permutations : "<<x/y;
		}
}

void ncr()
{
	float x,y,z;
	cleardevice();
	int n,r;
	cout<<"\n\nP(n,r)";
	cout<<"\n\nEnter n: ";
	cin>>n;
	cout<<"\n\nEnter r : ";
	cin>>r;
	if(r>n)
		cout<<"\n\ninvalid operation";
	else
		{
	   x=fact(n);
	   y=fact(n-r);
	   z=fact(r);
		 cout<<"\n\n\n\t\tNo of Combinations : "<<(x/y)/z;
	  }
}

void hcf()
{
	cleardevice();
	int x,y,z,m;
	cout<<"Enter the 1st number : ";
	cin>>x;
	cout<<"Enter the 2nd number : ";
	cin>>y;
	if(x>y)		z=x;
	else	z=y;

	for(int i=1;i<=z;i++)
	if(x%i==0&&y%i==0)
	m=i;
	cout<<"\n\tHCF of given two numbers is "<<m;
}

void converter()
{
char xh;
cleardevice();
double x;
do
{
cleardevice();
cout<<"\n1.degree to radian           2.radian to degree";
cout<<"\n3.metre to mile              4.mile to metre";
cout<<"\n5.metre to foot              6.foot to metre";
cout<<"\n7.metre to inch              8.inch to metre";
cout<<"\n9.celcius to kelvin          10.kelvin to celcius";
cout<<"\n11.celcius to fahrenheit     12.fahrenheit to celcius";
cout<<"\n13.sqft to acre              14.acre to sqft";
cout<<"\n15.USD to INR                16.INR to USD ";
cout<<"\n17.kmph to mph               18.kmph to mps";
cout<<"\n19.joule to calorie          20.joule/s to HP";
int ch;
cout<<"\n\n\t\t\tenter your choice : ";
cin>>ch;
cleardevice();
cout<"\n\n\n";
switch(ch)
{
case 1:cout<<"Degree : : ";
       cin>>x;
       cout<<"Radian : : "<<x*3.14/180;
       break;
case 2:cout<<"Radian : : ";
			 cin>>x;
       cout<<"Degree : : "<<x*180/3.14;
			 break;
case 3:cout<<"Metre : : ";
       cin>>x;
       cout<<"Mile : : "<<x*0.0006213689;
			 break;
case 4:cout<<"Mile : : ";
			 cin>>x;
			 cout<<"Metre : : "<<x*1609.35;
       break;
case 5:cout<<"Metre : : ";
       cin>>x;
       cout<<"Foot : : "<<x*3.28083;
       break;
case 6:cout<<"Foot : : ";
       cin>>x;
       cout<<"Metre : : "<<x*0.3048;
       break;
case 7:cout<<"Metre : : ";
			 cin>>x;
       cout<<"Inch : : "<<x*39.37007874;
			 break;
case 8:cout<<"Inch : : ";
       cin>>x;
       cout<<"Metre : : "<<x*0.0254;
			 break;
case 9:cout<<"Celcius : : ";
			 cin>>x;
			 cout<<"Kelvin : : "<<x+273.15;
       break;
case 10:cout<<"Kelvin : : ";
       cin>>x;
       cout<<"Celcius : : "<<x-273.15;
       break;
case 11:cout<<"Celcius : : ";
       cin>>x;
       cout<<"Fahrenheit : : "<<x*1.8+32;
       break;
case 12:cout<<"Fahrenheit : : ";
			 cin>>x;
       cout<<"Celcius : : "<<(x-32)/1.8;
			 break;
case 13:cout<<"SQFT : : ";
       cin>>x;
       cout<<"Acre : : "<<x*0.00002295;
			 break;
case 14:cout<<"Acre : : ";
			 cin>>x;
			 cout<<"SQFT : : "<<x*43560;
       break;
case 15:cout<<"USD : : ";
       cin>>x;
       cout<<"INR : : "<<x*65.1;
       break;
case 16:cout<<"INR : : ";
       cin>>x;
       cout<<"USD : : "<<x*0.01536;
       break;
case 17:cout<<"kmph: : ";
			 cin>>x;
       cout<<"mph : : "<<0.6213711;
			 break;
case 18:cout<<"kmph : : ";
       cin>>x;
       cout<<"mps : : "<<x*5/18;
			 break;
case 19:cout<<"Joule : : ";
			 cin>>x;
			 cout<<"Calorie : : "<<x/4.184;
			 break;
case 20:cout<<"Joule/s : : ";
			 cin>>x;
			 cout<<"hp : : "<<x*0.0013;
			 break;
}
cout<<"\n\n\t\tdo you want to continue with conversions : : ";
cin>>xh;
}while(xh=='y'||xh=='Y');
}


void lcm()
{
	cleardevice();
	int x,y,i,z1,z2;
	cout<<"Enter the 1st number : ";
	cin>>x;
	cout<<"Enter the 2nd number : ";
	cin>>y;
	if(x>y)
	{
		z1=x;
		z2=y;
	}
	else
	{
		z1=y;
		z2=x;
	}
	for(i=z1;i<=(x*y);i+=z1)
	{
		if(i%z2==0)
		{
			cout<<"\n\tLCM of the two numbers is "<<i;
			break;
		}
	}
}

void loading()
{
	int i,j,k=90;
	setbkcolor(DARKGRAY);
	while(!kbhit())
	{
		settextstyle(4,HORIZ_DIR,3);
		outtextxy(255,240,"Loading ...");
		setcolor(YELLOW);
		for(i=k;i<=360+k;i+=20)
		{
			for(j=0;j<50;j++)
			arc(300,250,k,i,90+j);
		}break;
	}
}

void changepassword()
{
	fstream f("UPWD.dat",ios::binary|ios::in|ios::out|ios::nocreate);
	char y1[20];
	char y2[30];
	outtextxy(20,20,"Current User name :");
	gotoxy(44,3);
	gets(y2);
	outtextxy(20,60,"current password : ");
	gotoxy(44,7);
	gets(y1);
	user u;
	int k=0;
	while(f.read((char *)&u,sizeof(u)))
	if(!(strcmp(y1,u.pwd)&&strcmp(y2,u.uname)))
	{
		k=f.tellg()-sizeof(u);
		break;
	}
	if(k!=0)
	{
		outtextxy(40,80,"verified");
		delay(400);
		cleardevice();
		outtextxy(20,20,"New Password :");
		gotoxy(44,3);
		gets(u.pwd);
		f.seekp(k);
		f.write((char *)&u,sizeof(u));
		getch();
	}
	else
	{
		outtextxy(20,40,"Incorrect credentials");
		delay(400);
		getch();
	}
	f.close();
}

void calculator()
{
	char v;
	do
	{
		cleardevice();
		bar(145,5,452,472);
		setfillstyle(SOLID_FILL,6);
		setcolor(BLUE);
		settextstyle(4,HORIZ_DIR,4);
		outtextxy(155 ,-5,"titan digital calculator");
		setfillstyle(SOLID_FILL,5);
		bar(150,30,447,467);
		setfillstyle(SOLID_FILL,3);
		setcolor(BLACK);
		settextstyle(1,HORIZ_DIR,2);
		outtextxy(35,160," ");
		bar(155,35,443,120);
		settextstyle(1,HORIZ_DIR,5);
		bar(155,130,224,190);
		outtextxy(180,130,"C");
		bar(227,130,296,190);
		outtextxy(242,130,"\\b");
		bar(299,130,368,190);
		outtextxy(320,130,"/");
		bar(371,130,443,190);
		outtextxy(400,136,"*");
		bar(155,193,224,258);
		outtextxy(180,200,"7");
		bar(227,193,296,258);
		outtextxy(255,200,"8");
		bar(299,193,368,258);
		outtextxy(320,200,"9");
		bar(371,193,443,258);
		outtextxy(395,195,"-");
		bar(155,261,224,326);
		outtextxy(180,270,"4");
		bar(227,261,296,326);
		outtextxy(255,270,"5");
		bar(299,261,368,326);
		outtextxy(320,270,"6");
		bar(371,261,443,326);
		outtextxy(395,270,"+");
		bar(371,329,443,462);
		outtextxy(395,365,"=");
		bar(155,329,224,394);
		outtextxy(180,340,"1");
		bar(227,329,296,394);
		outtextxy(255,340,"2");
		bar(299,329,368,394);
		outtextxy(320,340,"3");
		bar(155,397,224,462);
		outtextxy(180,405,"%");
		bar(227,397,296,462);
		outtextxy(255,405,"0");
		bar(299,397,368,462);
		outtextxy(330,390,".");
		char x1[25],x2[25],x3;
		int z1=0,z3=0;
		float f1,f2,f3;
		gotoxy(21,4);
		gets(x1);
		for(int z2=0;z2<=strlen(x1);z2++)
		if(x1[z2]!='*'&&x1[z2]!='/'&&x1[z2]!='+'&&x1[z2]!='-'&&x1[z2]!='\0'&&x1[z2]!='^')
		x2[z3++]=x1[z2];
		else
		{
			x2[z3]='\0';
			z3=0;
			z1++;
			if(z1==1)
			{
				x3=x1[z2];
				f1=atof(x2);
			}
			else
			f2=atof(x2);
		}
		switch(x3)
		{
		case '*':f3=f1*f2;break;
		case '/':f3=f1/f2;break;
		case '+':f3=f1+f2;break;
		case '-':f3=f1-f2;break;
		case '^':f3=pow(f1,f2);
		}
		setbkcolor(BLACK);
		gotoxy(21,6);
		cout<<'='<<f3;
		v=getch();
	}while(v=='c'||v=='C');
}

stock::stock(char *stname,int q, char *file)
{
	stock f;
	strcpy(f.name,stname);
	f.stok=q;
	int g=stock_exists(f.name,file);
	if(!g)
		{
		 ofstream fin(file,ios::binary|ios::app);
		 fin.write((char*)&f,sizeof(f));
		 fin.close();
		}
}

sum give_me_the_product(char*file,int a)
{
	sum Jar;
	ifstream fin(file,ios::in|ios::binary|ios::nocreate);
	fin.seekg((a-1)*sizeof(Jar),ios::beg);
	fin.read((char*)&Jar,sizeof(Jar));
	fin.close();
	return Jar;
}


char*itoa(long int n)
{	char s[20];	ltoa(n,s,10);	return s; }

int stock_exists(char *stname,char *file)
{
 stock s;
 int t=0;
 ifstream fin(file,ios::binary|ios::in);
 while(fin.read((char*)&s,sizeof(s)))
 {
			if(strcmp(s.name,stname)==0)
			{ t++; break; }
 }
 fin.close();
 return t;
}

int NoP(char*file)
 {
	 ifstream ff(file,ios::binary);
	 ff.seekg(0,ios::end);
	 long t1=ff.tellg();
	 t1/=sizeof(sum);
	 int t=t1;
	 ff.close();
	 return t;
 }

int blank_record(sum a)
 {
		if(strlen(a.q)==0)
		return 1;
		else
		return 0;
 }

void create_stock_list(char c)
{
 switch(c)
 {
 case 'f':
 case 'F':{ char b[8][25]={"Burger","Idli","Pizza","Dosa",
													 "Schezwan Fried rice","Chapathi",
													 "Noodles","Addai"};
						for(int ka=0;ka<8;ka++)
						{stock _1(b[ka],100,"fstock.dat");}
					}
					 break;

 case 'g':
 case 'G': {
						char c[8][40]={"Tata salt","Amul cheese","Arun ice(2 pc)",
						 "Amul ghee 250ml","Society masala tea 500g","Bru coffee",
						 "Patanjali Noodles","Basmati rice"};
						for(int ka=0;ka<8;ka++)
						{stock _1(c[ka],100,"gstock.dat");}

					 }break;
 case 'v':
 case 'V':{ char c[8][20]={"Tomato","Potato","Cabbage","Carrot",
													 "Cucumber","Bitter gourd","Onion","Chilly"};
						for(int ka=0;ka<8;ka++)
						{stock _1(c[ka],100,"vstock.dat");}
					} break;

 case 'b':
 case 'B':{ char c[8][25]={"Pizza","Arun ice(4 Nos)","Onion",
														 "Tomato(5 kg)","Society tea 1.5 kg ",
														 "Iron box","Toaster","Pendrive - 64gb"};
						for(int ka=0;ka<8;ka++)
						{stock _1(c[ka],100,"bstock.dat");}
					} break;

 case 'e':
 case 'E':{ char c[8][25]={"Hard disk 1tb","Power bank 4500mA",
														"Pendrive 64gb","Toaster","Microwave oven",
														"Speakers ","Wrist Watch","Induction cook top"};
						for(int ka=0;ka<8;ka++)
						{stock _1(c[ka],100,"estock.dat");}
					 }break;
 } //switch case
}


void purchase(char b[8][25],long int price[8],char *category,char *file,char*human)
{
	int l;
	long q=0;
	 setbkcolor(0);
	 setcolor(YELLOW);
	 settextstyle(4,HORIZ_DIR,5);
	 outtextxy(45,10,category);
	 bar3d(10,140,620,200,0,1);
	 bar3d(10,220,620,280,0,1);
	 bar3d(10,300,620,360,0,1);
	 bar3d(10,380,620,440,0,1);
	 settextstyle(1,HORIZ_DIR,3);

	 int y=145;

	 for(l=0;l<8;l+=2)
	 {
			outtextxy(45,y,b[l]);
			char cht[10];
			ltoa(price[l],cht,10);
			outtextxy(45,y+25,cht);
			ltoa(price[l+1],cht,10);
                outtextxy(380,y,b[l+1]);
			outtextxy(380,y+25,cht);
			y+=80;
	 }
	 getch();

	 char savu;
	 int quantity[8],i;
	 stock tl[8];
	 do
	 {
		 cleardevice();

		 setbkcolor(0);
		 setcolor(2);
		 settextstyle(4,HORIZ_DIR,3);
		 outtextxy(15,10,"Sb");
		 setcolor(YELLOW);
		 settextstyle(4,HORIZ_DIR,5);
		 outtextxy(45,17,"Your Order Please:-");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(45,75,"Name");
		 outtextxy(300,75,"Qty	");
		 getch();
		 outtextxy(45,97,b[0]);
		 gotoxy(40,8);
		 cin>>quantity[0];
		 outtextxy(45,115,b[1]);
		 gotoxy(40,9);
		 cin>>quantity[1];
		 outtextxy(45,133,b[2]);
		 gotoxy(40,10);
		 cin>>quantity[2];
		 outtextxy(45,151,b[3]);
		 gotoxy(40,11);
		 cin>>quantity[3];
		 outtextxy(45,169,b[4]);
		 gotoxy(40,12);
		 cin>>quantity[4];
		 outtextxy(45,187,b[5]);
		 gotoxy(40,13);
		 cin>>quantity[5];
		 outtextxy(45,205,b[6]);
		 gotoxy(40,14);
		 cin>>quantity[6];
		 outtextxy(45,223,b[7]);
		 gotoxy(40,15);
		 cin>>quantity[7];

		 cleardevice();

		 int n=0;

		 ifstream fb(file,ios::binary);
		 fb.seekg(0);
		 for(i=0;i<8;i++)
		 {
				fb.read((char*)&tl[i],sizeof(tl[i]));
		 }
		 fb.close();

		 for(l=0;l<8;l++)
		 {
				while((tl[l].stok-quantity[l])<0)
				{
					 cout<<tl[l].name<<" is available in less quantity than what u require";
					 cout<<endl<<"Maximum quantity available is : "<<tl[l].stok;
					 cout<<"\nEnter the quantity : ";
					 cin>>quantity[l];
				}
		 }

		 cleardevice();
		 setbkcolor(BLACK);

		 setcolor(2);
		 settextstyle(4,HORIZ_DIR,3);
		 outtextxy(15,10,"Sb");
		 setcolor(YELLOW);
		 settextstyle(4,HORIZ_DIR,5);

		 outtextxy(45,17,"Your Order Summary:-");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(45,75,"Name");
		 outtextxy(300,75,"Qty	");
		 outtextxy(400,75,"Amount");
		 int x=82,y=7;

		 for(n=0;n<8;n++)
		 if(quantity[n])
		 {
			x+=15;
			y++;
			outtextxy(45,x,b[n]);
			gotoxy(40,y); cout<<quantity[n];
			gotoxy(55,y);cout<<price[n]*quantity[n];
		 }

		 long int q=0;//calculating bill amount
		 for(n=0;n<8;n++)
			q+=price[n]*quantity[n];

		 outtextxy(200,260,"GRAND TOTAL=>");
		 gotoxy(55,18);cout<<q;
		 outtextxy(45,350,"Tap 'Y' to alter your order ");
		 outtextxy(45,380,"Tap any other key for processing the order ");
		 savu=getch();
	 } while(savu=='Y'||savu=='y');

	 cleardevice();
	 for(l=0;l<8;l++)
	 {
			tl[l].stok-=quantity[l];
	 }

	 ofstream ft(file,ios::trunc|ios::binary);
	 ft.close();
	 ft.open(file,ios::app|ios::binary);
	 for(l=0;l<8;l++)
	 {
			ft.write((char*)&tl[l],sizeof(tl[l]));
	 }
	 ft.close();

	 /******************************************/

		sum t[8]; //to store the things which user has brought
		for(int aa1=0;aa1<8;aa1++)
		{
			 strcpy(t[aa1].q,b[aa1]);
			 t[aa1].qty=quantity[aa1];
			 t[aa1].amt=quantity[aa1]*price[aa1];
		}

	 //creating log of orders placed

	 strcpy(str,human);
	 strcat(str,".dat");

	 ofstream f1(str,ios::binary|ios::app);
	 for(aa1=0;aa1<8;aa1++)
	 {
			if(t[aa1].qty)
			f1.write((char*)&t[aa1],sizeof(t[aa1]));
	 }

		sum abc={"",0,0};
		f1.write((char*)&abc,sizeof(abc));
		f1.close();

		final_message(human);
		delivery_message(human);
}

int new_sb_user()
{
int bf=0;
fstream f1("access.dat",ios::binary|ios::in|ios::out|ios::app);
f1.seekg(0,ios::end);
long top=f1.tellg( );
top/=sizeof(log1);

 if(top<15)
 {
	 cout<<"Enter login id : ";
	 gets(log1.id);
	 cout<<"Set ur security code : ";
	 gets(log1.pass);
	 top++;
	 f1.seekg(0,ios::end);
	 f1.write((char*)&log1,sizeof(log1));
	 bf=1;
 }
 else
 cout<<"Our app has reached more than 15 million account holders so outof space will upade and lt u know";
 f1.close();

return bf;
}

void final_message(char*ah)
{
 cleardevice();
 setbkcolor(YELLOW);
 setfillstyle(SOLID_FILL,12);
 bar3d(10,10,620,70,0,1);
 setcolor(BLACK);
 settextstyle(1,HORIZ_DIR,5);
 outtextxy(20,15,"Sb");
 settextstyle(1,HORIZ_DIR,4);
 setcolor(BLACK);
 outtextxy(220,10,"SMALL BASKET");
 outtextxy(120,40,"one stop shop for all your daily needs");
 settextstyle(1,HORIZ_DIR,3);
 bar3d(10,80,620,480,0,1);
 setfillstyle(SOLID_FILL,13);
 outtextxy(20,100,"Order Successfully Completed");
 outtextxy(20,150,"Name: ");
 outtextxy(200,150,ah);
 outtextxy(20,190,"Address: Plot No.R40B 120 Feet road ");
 outtextxy(20,220,"         Mogappair, Chennai-50 ");
 getch();
 cleardevice();
}

void summary(char*god)
{
	cleardevice();
	setbkcolor(BLACK);

	int x=82,y=7,check;
	cleardevice();

	 setbkcolor(0);
	 setcolor(2);
	 settextstyle(4,HORIZ_DIR,3);
	 outtextxy(15,10,"Sb");
	 setcolor(YELLOW);
	 settextstyle(4,HORIZ_DIR,5);
	 outtextxy(45,17,"Your Order History :-");
	 outtextxy(50,40," Order ");

	 settextstyle(1,HORIZ_DIR,3);
	 outtextxy(45,75,"Name");
	 outtextxy(300,75,"Qty	");
	 outtextxy(400,75,"Amount");

	 strcpy(str,god);
	 strcat(str,".dat");

	 int nop=NoP(str);
	 cout<<nop<<" ";
	 sum bd;

	 for(int bv=1;bv<nop;bv++)
	 {
		 reinitialise_file_pointer(str);
		 bd=give_me_the_product(str,bv);
		 check=blank_record(bd);
		 if(check)
		 {
			 getch();
			 cleardevice();
			 setbkcolor(0);
			 setcolor(2);
			 settextstyle(4,HORIZ_DIR,3);
			 outtextxy(15,10,"Sb");
			 setcolor(YELLOW);
			 settextstyle(4,HORIZ_DIR,5);
			 outtextxy(45,17,"Your Order History :-");
			 outtextxy(50,40," Order ");

			 settextstyle(1,HORIZ_DIR,3);
			 outtextxy(45,75,"Name");
			 outtextxy(300,75,"Qty	");
			 outtextxy(400,75,"Amount");
				x=82;y=7;
		 }
		 else
		 {
				x+=17;
				y++;
				outtextxy(45,x,bd.q);
				gotoxy(40,y); cout<<bd.qty;
			 gotoxy(55,y);cout<<bd.amt;
		 }
	}
	 getch();

}

void delivery_message(char*demigod)
{
cleardevice();
setbkcolor(YELLOW);
setfillstyle(SOLID_FILL,12);
bar3d(10,10,620,70,0,1);
settextstyle(1,HORIZ_DIR,5);
setcolor(BLACK);
outtextxy(20,15,"Sb");
settextstyle(1,HORIZ_DIR,4);
setcolor(BLACK);
outtextxy(220,10,"SMALL BASKET");
settextstyle(1,HORIZ_DIR,3);
outtextxy(120,40,"one stop shop for all your daily needs");
bar3d(10,80,620,480,0,1);
setfillstyle(SOLID_FILL,13);
outtextxy(100,100,"Name: ");
outtextxy(0,100,demigod);
outtextxy(220,150,"    Your order will reach the given address");
outtextxy(20,190,"       in few nanoseconds  ");
settextstyle(1,HORIZ_DIR,2);
bar3d(10,435,620,475,0,1);
outtextxy(120,431,"1 CRORE INDIANS ARE SMALL BASKETEERS!!!");
outtextxy(220,450,"SMALL BASKET BIG JOY");
getch();
}

void user_stuff(char*person)
{
char de;
do
{
	cleardevice();
	setbkcolor(YELLOW);
	setfillstyle(SOLID_FILL,12);
	bar3d(10,10,620,70,0,1);
	settextstyle(1,HORIZ_DIR,5);
	setcolor(BLACK);
	outtextxy(20,15,"Sb");
	settextstyle(1,HORIZ_DIR,4);
	setcolor(1);
	outtextxy(220,10,"SMALL BASKET");
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(120,40,"one stop shop for all your daily needs");
	setfillstyle(SOLID_FILL,13);
	bar3d(10,80,160,130,0,1);
	bar3d(170,80,320,130,0,1);
	bar3d(330,80,480,130,0,1);
	bar3d(490,80,620,130,0,1);
	bar3d(10,140,620,230,0,1);
	bar3d(10,240,620,330,0,1);
	bar3d(10,340,620,430,0,1);
	settextstyle(1,HORIZ_DIR,2);
	bar3d(10,435,620,475,0,1);
	outtextxy(120,431,"1 CRORE INDIANS ARE SMALL BASKETEERS!!!");
	outtextxy(220,450,"SMALL BASKET BIG JOY");
	setcolor(1);
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(12,81,"Food(F)");
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(20,100,"and Beverage");
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(176,83,"Grosseries(G)");
	outtextxy(332,82,"Vegetables(V)");
	outtextxy(492,82,"My Summary(S)");
	setcolor(RED);
	outtextxy(175,175,"   ELECTRONICS(E)  ");
	outtextxy(175,275,"BEST DEAL FOR EVER!!!(B)");
	setcolor(2);
	outtextxy(45,345,"Choice: ");
	gotoxy(20,23);

	char chr;
	chr=getch();
	chr=toupper(chr);
	cout<<chr;
	getch();

	create_stock_list(chr);

	cleardevice();
	switch(chr)
	{
		case 'f':
		case 'F':  long int dd[8]={140,40,200,40,200,40,90,50};
								char b[8][25]={"Burger","Idli","Pizza","Dosa",
								"Schezwan Fried rice",	"Chapathi","Noodles","Addai"};
								purchase(b,dd,"Food and Beverages","fstock.dat",person);
						 break;

		case 'g':
		case 'G':  long int e[8]={50,170,50,140,200,140,90,150};
								char c[8][25]={"Tata salt","Amul cheese",
											"Arun ice(2 pc)","Amul ghee 250ml",
									"Society masala tea 500g","Bru coffee",
									"Patanjali Noodles","Basmati rice"};
								purchase(c,e,"Groceries","gstock.dat",person);
							 break;
	 case 'v':
	 case 'V':	char d[8][25]={"Tomato","Potato","Cabbage","Carrot",
											"Cucumber","Bitter gourd","Onion","Chilly"};
							long int it[8]={50,40,50,40,20,40,60,50};
							purchase(d,it,"Vegetables","vstock.dat",person);
						break;
	 case 'b':
	 case 'B': char cf[8][25]={"Pizza","Arun ice(4 Nos)","Onion",
													 "Tomato(5 kg)","Society tea 1.5 kg ",
												"Iron box","Toaster","Pendrive - 64gb"};
							long int ef[8]={50,170,20,100,550,2099,1700,650};
							purchase(cf,ef,"BEST DEAL FOR EVER","bstock.dat",person);
						break;
	 case 'e':
	 case 'E':   char cd[8][25]={"Hard disk 1tb","Power bank 4500mA","Pendrive 64gb","Toaster","Microwave oven ","Speakers ","Wrist Watch","Induction cook top"};
								long int ed[8]={5000,1700,999,1990,1550,2099,1700,1650};
								purchase(cd,ed,"ELECTRONICS","estock.dat",person);
						 break;
	 case 's':
	 case 'S': summary(person);break;
	}

 cleardevice();
 setcolor(1);
 outtextxy(100,220,"		For further orders tap 'Y'    ");
 outtextxy(100,250,"Tap any other key for quiting app");

 de=getch();
}while(de=='y'||de=='Y');

}


void alter(char b[8][25],char *file)
{
	int up,l;
	cleardevice();
	setbkcolor(YELLOW);
	setfillstyle(SOLID_FILL,12);
	bar3d(10,10,620,70,0,1);
	settextstyle(1,HORIZ_DIR,5);
	setcolor(BLACK);
	outtextxy(20,15,"Sb");
	settextstyle(1,HORIZ_DIR,4);
	setcolor(BLACK);
	outtextxy(220,10,"SMALL BASKET");
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(120,40,"one stop shop for all your daily needs");
	setfillstyle(SOLID_FILL,13);
	settextstyle(1,HORIZ_DIR,2);
	bar3d(10,435,620,475,0,1);
	outtextxy(120,431,"1 CRORE INDIANS ARE SMALL BASKETEERS!!!");
	outtextxy(220,450,"SMALL BASKET BIG JOY");
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(17,120,"1.Alter Quantity");
	outtextxy(17,150,"2.Check Stock Availablity");
	outtextxy(45,345,"Choice: ");
	gotoxy(20,23);
	cin>>up;
	int i;

	stock tz[8];
	ifstream fb(file,ios::binary|ios::in);
	fb.seekg(0);
	for(i=0;i<8;i++)
	{
	 fb.read((char*)&tz[i],sizeof(tz[i]));
	}
	fb.close();

	if(up==1)
	{
	 int a[8],i;
	 cleardevice();
	 i=8;
	 setbkcolor(0);
	 setcolor(2);
	 settextstyle(4,HORIZ_DIR,3);
	 outtextxy(15,10,"Sb");
	 setcolor(YELLOW);
	 settextstyle(4,HORIZ_DIR,5);
	 outtextxy(45,17,"Upadting Stocks ");
	 settextstyle(1,HORIZ_DIR,3);
	 outtextxy(45,75,"Name");
	 outtextxy(300,75,"Qty	");
	 getch();
	 outtextxy(45,97,b[0]);
	 gotoxy(40,8);
	 cin>>a[0];
	 outtextxy(45,115,b[1]);
	 gotoxy(40,9);
	 cin>>a[1];
	 outtextxy(45,133,b[2]);
	 gotoxy(40,10);
	 cin>>a[2];
	 outtextxy(45,151,b[3]);
	 gotoxy(40,11);
	 cin>>a[3];
	 outtextxy(45,169,b[4]);
	 gotoxy(40,12);
	 cin>>a[4];
	 outtextxy(45,187,b[5]);
	 gotoxy(40,13);
	 cin>>a[5];
	 outtextxy(45,205,b[6]);
	 gotoxy(40,14);
	 cin>>a[6];
	 outtextxy(45,223,b[7]);
	 gotoxy(40,15);
	 cin>>a[7];

	 cleardevice();
	 int n=0;
	 for(l=0;l<8;l++)
	 {
		while(a[l]<0)
		{
		 cout<<b[l]<<"has been invalidly filled\n";
		 cout<<endl<<"Minimum quantity updatable is : 0 \n\n";
		 cout<<"Enter the quantity : ";
		 cin>>a[l];
		}
	 }
	 for(n=0;n<8;n++)
		tz[n].stok+=a[n];

	 cleardevice();
	 setbkcolor(BLACK);
	 setcolor(2);
	 settextstyle(4,HORIZ_DIR,3);
	 outtextxy(15,10,"Sb");
	 setcolor(YELLOW);
	 settextstyle(4,HORIZ_DIR,5);
	 outtextxy(45,17,"Current Availablity of Stock");
	 settextstyle(1,HORIZ_DIR,3);
	 outtextxy(45,75,"Name");
	 outtextxy(300,75,"Qty	");
	 int x=82,y=7;
	 for(n=0;n<i;n++)
	 {
		x+=15;
		y++;
		outtextxy(45,x,b[n]);
		gotoxy(40,y); cout<<tz[n].stok;
	 }

	 ofstream fb1(file,ios::trunc|ios::binary);
	 fb1.close();

	 fb1.open(file,ios::binary|ios::app);
	 fb1.seekp(0);
	 for(l=0;l<8;l++)
	 {
		fb1.write((char*)&tz[l],sizeof(tz[l]));
	 }
	 fb1.close();
	 getch();
	}
	else if(up==2)
	{
		int n;
		cleardevice();
		setbkcolor(BLACK);
		setcolor(2);
		settextstyle(4,HORIZ_DIR,3);
		outtextxy(15,10,"Sb");
		setcolor(YELLOW);
		settextstyle(4,HORIZ_DIR,5);
		outtextxy(45,17,"Current Availablity of Stock");
		settextstyle(1,HORIZ_DIR,3);
		outtextxy(45,75,"Name");
		outtextxy(300,75,"Qty	");
		int x=82,y=7;
		for(n=0;n<i;n++)
		{
		 x+=15;
		 y++;
		 outtextxy(45,x,b[n]);
		 gotoxy(40,y); cout<<tz[n].stok;
		}
	 getch();
	}

}

void admin_stuff()
{
	char qwerty;
	do
	{
		 cleardevice();
		 setbkcolor(YELLOW);
		 setfillstyle(SOLID_FILL,12);
		 bar3d(10,10,620,70,0,1);
		 settextstyle(1,HORIZ_DIR,5);
		 setcolor(BLACK);
		 outtextxy(20,15,"Sb");

		 settextstyle(1,HORIZ_DIR,4);
		 setcolor(BLACK);
		 outtextxy(220,10,"SMALL BASKET");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(120,40,"one stop shop for all your daily needs");
		 setfillstyle(SOLID_FILL,13);
		 bar3d(10,80,160,130,0,1);
		 bar3d(170,80,320,130,0,1);
		 bar3d(330,80,480,130,0,1);
		 bar3d(490,80,620,130,0,1);
		 bar3d(10,140,620,230,0,1);
		 bar3d(10,240,620,330,0,1);
		 bar3d(10,340,620,430,0,1);
		 settextstyle(1,HORIZ_DIR,2);
		 bar3d(10,435,620,475,0,1);
		 outtextxy(120,431,"1 CRORE INDIANS ARE SMALL BASKETEERS!!!");
		 outtextxy(220,450,"SMALL BASKET BIG JOY");
		 setcolor(YELLOW);
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(12,81,"Food(F)");
		 settextstyle(1,HORIZ_DIR,2);
		 outtextxy(20,100,"and Beverage");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(176,83,"Grosseries(G)");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(332,82,"Vegetables(V)");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(492,82," ADMIN ");
		 setcolor(RED);
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(175,175," ELETRONICS (E) ");
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(175,275,"BEST DEAL FOR EVER!!!(B)");
		 setcolor(2);
		 settextstyle(1,HORIZ_DIR,3);
		 outtextxy(45,345,"Choice: ");
		 gotoxy(20,23);
		 char chr;
		 chr=getch();
		 chr=toupper(chr);
		 cout<<chr;
		 getch();
		 create_stock_list(chr);
		 switch(chr)
		 {
			case 'f':
			case 'F':{
								char b[8][25]={"Burger","Idli","Pizza","Dosa",
								"Schezwan Fried rice",	"Chapathi","Noodles","Addai"};
								alter(b,"fstock.dat");
						 }break;

			case 'g':
			case 'G': {
								char c[8][25]={"Tata salt","Amul cheese",
											"Arun ice(2 pc)","Amul ghee 250ml",
									"Society masala tea 500g","Bru coffee",
									"Patanjali Noodles","Basmati rice"};
							 alter(c,"gstock.dat");
							 }break;
		 case 'v':
		 case 'V':{	char c[8][25]={"Tomato","Potato","Cabbage","Carrot",
											"Cucumber","Bitter gourd","Onion","Chilly"};
							alter(c,"vstock.dat");
						}break;
		 case 'b':
		 case 'B':{ char c[8][25]={"Pizza","Arun ice(4 Nos)","Onion",
													 "Tomato(5 kg)","Society tea 1.5 kg ",
												"Iron box","Toaster","Pendrive - 64gb"};
							alter(c,"bstock.dat");
						}break;
		 case 'e':
		 case 'E': {  char c[8][25]={"Hard disk 1tb","Power bank 4500mA",
												 "Pendrive 64gb","Toaster","Microwave oven ",
											"Speakers ","Wrist Watch","Induction cook top"};
								alter(c,"estock.dat");
						 }break;
		}
	cleardevice();
	setbkcolor(BLACK);
	setcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(20,120,"Do you want to alter any other category ? ");
	gotoxy(45,14);
	qwerty=getch();
} while(qwerty=='y'||qwerty=='Y');
}

void reinitialise_file_pointer(char*file)
{
	 ifstream f1(file,ios::binary|ios::in);
	 f1.seekg(0,ios::beg);
	 f1.close();
}
void create_questions()
{
ifstream f1("quiz.dat",ios::binary);
if (f1) f1.close();
else
{
ofstream f2("quiz.dat",ios::binary|ios::app);
{ qu d={"Coldest planet",
	 "Neptune",
	 "Saturn",
	 "Uranus",
	 "jupiter"
	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"Present RBI Governor",
"urjit patel",
"raguram  rajan",
"manmohan singh",
"narendra modi"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"country which lost most people during WW2",
"japan",
"russia",
"usa",
"china"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"largest animal",
"blue whale",
"elephant",
"rhino",
"hippo"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"smallest bird",
"hummingbird",
"sparrow",
"eagle",
"crow" 	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"bali is located here",
"indonesia",
"cuba",
"brazil",
"australia"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"european unions working capital",
"brussels",
"frankfurt",
"paris",
"stockholm"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"world's richest man",
"bill gates",
"paul stick",
"ambani",
"ratan tata"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"people's president",
"abdul kalam",
"pranab",
"pratiba",
"ramnarayan"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"most powerful man in the world",
"vladimir putin",
"donald trump",
"obama",
"modi"      	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"lok pal activist",
"anna hazare",
"kejriwal",
"kailash satyarthi",
"irom sharmila"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"war memorial in delhi",
"india gate",
"qutub minar",
"tajmahal",
"redfort"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"she is lara croft:tomb rider",
"angelina jolie",
"rosamund pike",
"hathaway",
"selina" 	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"highest grossing south indian film",
"baahubali",
"endhiran",
"sivaji",
"viswaroopam"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"production company of 2.0",
"lyca",
"studio green",
"cloud9",
"escape artists"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"entomology is science that studies",
"insects",
"plants",
"birds",
"parasites"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"dictator of iraq",
"saddam hussain",
"osama",
"mohammad",
"mansoor"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"national animal of china",
"giant panda",
"lion",
"tiger",
"cheetah"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"which turkish city has a name of cartoon character",
"batman",
"superman",
"mickey mouse",
"hulk"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"mediterranean sea and red sea are joined by ______ canal",
"suez canal",
"grand canal",
"panama canal",
"erie canal"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"a dancer who won the most grammy awards",
"michael jackson",
"adele",
"sinatra",
"skrillex"  	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"famous band known as the quarrymen",
"beatles",
"u2",
"santana",
"toto"      	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"world's largest office building",
"pentagon",
"white house",
"burj khalifa",
"taipei 101"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"in which city was titanic built",
"belfast",
"liverpool",
"madrid",
"leeds"     	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"fish with a snake like body",
"eel",
"horsefish",
"stingray",
"arowana"   	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"no of oscars titanic got",
"eleven",
"ten",
"nine",
"twelve"    	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"name of computers from which internet has emerged",
"arpanet",
"difference engine",
"ibm",
"eniac"     	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"inventor of steam engine",
"james watt",
"diesel",
"karl benz",
"sadi carnot"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"first olympic was held here",
"greece",
"spain",
"italy",
"france"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"the power to decide an election petition is vested in the",
"parliament",
"supreme court",
"high court",
"election commission"	};
f2.write((char*)&d,sizeof(d));
}
{
qu d={"the ratio of width of our national flag to its length is",
"3:5",
"2:3",
"2:4",
"3:4"};
f2.write((char*)&d,sizeof(d));
}

f2.close();
}
}

void create_news()
{
ifstream f1("news.dat",ios::binary);
if(!f1)
{
	 f1.close();
	 ofstream f2("news.dat",ios::binary|ios::app);
 newsc a;

 strcpy(a.h,"Gravitational wave scientists");
 strcpy(a.h2," win 2017 Nobel Physics Prize");
 strcpy(a.t,"");
 strcpy(a.b[0],"The three are Rainer Weiss of the Massachusetts");
 strcpy(a.b[1]," Institute of Technology and Barry Barish");
 strcpy(a.b[2]," and Kip Thorne of the California Institute of Technology.");
 f2.write((char*)&a,sizeof(a));

 strcpy(a.h,"Police Probe Las Vegas Shooter's Motive");
 strcpy(a.h2,"At least 59 killed");
 strcpy(a.t,"Deadliest shooting in modern U.S. history");
 strcpy(a.b[0],"Police struggled to determine the motive of the shooter");
 strcpy(a.b[1],"-Stephen Paddock-who killed himself in the hotel room");
 strcpy(a.b[2]," from which he fired onto a concert. More than 520 were injured.");
 f2.write((char*)&a,sizeof(a));

 strcpy(a.h,"Chennai braces for more rains");
 strcpy(a.h2,"Schools remain shut");
 strcpy(a.t,"Coastal packets of Chennai affected");
 strcpy(a.b[0],"Parts of Chennai received 30 cm of rain.");
 strcpy(a.b[1],"Schools will be closed on 4th November.");
 strcpy(a.b[2],"Air operations affected.");
 f2.write((char*)&a,sizeof(a));

 f2.close();
}
		f1.close();
}

char*capitalise(char a[])
{
	for(int i=0;i<strlen(a);i++)
		if(!i||a[i-1]==' '||a[i-1]=='.')
			a[i]=toupper(a[i]);
	return a;
}

void essentials()
{
	create_admins();
	create_news();
	create_questions();
}

