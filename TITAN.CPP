#include"titan.h"
user u;
void main()
{
                    essentials();
	create_admins();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	int x,y;
	char c='E',cha;
	cleardevice();

	ifstream fin("access.dat",ios::binary);
	user l;
	settextstyle(3,HORIZ_DIR,5);
	cleardevice();
	char opening[]="TITAN";
	for( x=0;x<strlen(opening);x++)
	 {
		char b[2];
		b[0]=opening[x];
		b[1]='\0';
		outtextxy(280,40+(40*x),b);
		delay(100);
	 }
	cleardevice();

for(int i3=3;i3<10;i3++)
{ cleardevice();
 setbkcolor(i3);
	for( x=0;x<strlen(opening);x++)
	{
	 char b[2];
	 b[0]=opening[x];
	 b[1]='\0';
	 outtextxy(280,40+(40*x),b);
	 delay(100);
	}
 delay(100);
}

		char me;
	cleardevice();
	char name[20],pass[20];
	settextstyle(4,HORIZ_DIR,3);
	 outtextxy(22,10,"New user :");
	gotoxy(50,2);
	cin>>me;
	me=tolower(me);
	int 	bf=0;
	if(me=='y')
	{
		int ld=1;
		fin.seekg(0);
		user book;
		int v5=0;
		do
		{
			ld=1;
			cout<<"\n\nEnter login id : ";
			gotoxy(50,7+3*v5);
			gets(l.uname);

		while(fin.read((char*)&book,sizeof(book)))
		{
		 if(!strcmp(l.uname,book.uname))
		 {
		 ld=0;break;
		 }
		 }
		 if(ld==0)
			cout<<"Sorry already the user name is under existence \n \tTry for another one";
			v5++;
			fin.seekg(0);
			}while(!ld);
		cout<<"\n\nSet your security code : ";
		gotoxy(60,7+3*v5);
		gets(l.pwd);
		fin.close();
		ofstream fout("access.dat",ios::binary|ios::app);
		fout.write((char*)&l,sizeof(l));
		fout.close();
		bf=1;
	 }

	do
	{
		char name[20],pass[20];
		settextstyle(3,HORIZ_DIR,3);
		setcolor(YELLOW);
		cleardevice();
		setbkcolor(BLACK);
		settextstyle(4,HORIZ_DIR,9);
		outtextxy(0,150,"TITAN");
		line(420,20,420,450);
		line(424,20,424,450);
		settextstyle(1,0,2);
		outtextxy(440,115,"Username :");
		outtextxy(440,190,"Password :");

		bar(440,150,720,180);
		bar(440,235,720,265);
		setfillstyle(SOLID_FILL,1);
		bar(440,320,720,350);
		outtextxy(500,317,"LOGIN");
		gotoxy(58,11);
		gets(name);
		int w=0;
		ifstream fin("access.dat",ios::binary);
		if(!fin)
		exit(1);
		while ( fin.read((char *)&u,sizeof(u)))
		{
			if (strcmp(name,u.uname)==0)
			{
				w++;
				break;
			}
		}
		if(w==0)
		{
			outtextxy(440,270,"Invalid id ");
			getch();
			cleardevice();
			exit(1);
		}
		else
		{
			gotoxy(58,16);
			int o=0;
			do
			{
				pass[o]=getch();
				if(pass[o]=='\b')
				{
					cout<<pass[o];
					o-=2;
					bar(440,235,720,265);
					gotoxy(58,16);
					for(int i=0;i<=o;i++)
					cout<<"*";
				}
				else if(pass[o]!='\n')
				{
					cout<<pass[o];
					delay(200);
					cout<<"\b*";
				}
				o++;
			}while(/*pass[o-1]!='\n'*/o<=strlen(u.pwd));
			pass[o-1]='\0';
			//cout<<pass;
			if (strcmp(pass,u.pwd))
			{
				outtextxy(440,275,"Incorrect password ");
				fflush(stdin);
				getch();
				cleardevice();
				exit(1);
			}
			fin.close();
			cleardevice();
			settextstyle(4,HORIZ_DIR,8);
			setcolor(YELLOW);
			outtextxy(110,120,"  TITAN ");
			setfillstyle(EMPTY_FILL,0);
			bar3d(100,350,540,400,0,1);
			settextstyle(1,HORIZ_DIR,5);
			outtextxy(260,348,"START");
			settextstyle(1,HORIZ_DIR,2);
			outtextxy(160,210,"INDIA\'S SECOND ALL IN ONE APP");
			outtextxy(230,410,"PRESS S TO START");
			char ch=getch();
			if(ch=='s'||ch=='S')
			{
				cleardevice();
				loading();
				do
				{
					cleardevice();
					setbkcolor(WHITE);
					setcolor(BLUE);
					settextstyle(4,HORIZ_DIR,8);
					moveto(180,10); string("TITAN");
					settextstyle(1,0,4);
					moveto(120,100);string("1. Calculator");
					moveto(120,140);string("2. Quiz");
					moveto(120,180);string("3. News corner");
					moveto(120,220);string("4. Mind Maze");
					moveto(120,260);string("5. Mathematical Operations");
					moveto(120,300);string("6. Kollywood Game");
					moveto(120,340);string("0. More Options");

					int option;
					outtextxy(120,380,"Enter your choice : ");
					gotoxy(56,24);
					cin>>option;
					if(option==0)
					{
						cleardevice();

						moveto(120,20);string("7. Paint");
						moveto(120,60);string("8. Game");
						moveto(120,100);string("9. Calendar");
						moveto(120,140);string("10. Clock");
						moveto(120,180);string("11.Tricky test");
						moveto(120,220);string("12.Small basket");
						moveto(120,260);string("13. Change Password");
						if(strcmpi(u.uname,"admin")==0)
						{
							outtextxy(120,300,"14. Modify Quiz Questions");
							outtextxy(120,340,"15.change news");
						}
						outtextxy(120,400,"Enter your choice : ");
						gotoxy(56,24);
						cin>>option;
					}
					switch(option)
					{
						case 1:		load();	calculator();		getch();		break;
						case 2:   cleardevice();		quiz(); 					break;
						case 3:		cleardevice();    news();           break;
						case 4:	  mind();   						              break;
						case 5: char _a;
							do
							{
								cleardevice();
							 setbkcolor(BLACK);
							 int dave;
							 cout<<"\n\t1.LCM        \t2.HCF         \t3.GREATEST INTEGER FUNCTION";
							 cout<<"\n\n\t4.Factorial\t5.Permutations\t6.Combinations";
							 cout<<"\n\n\t7.Converter";
							 cout<<"\n\n\nEnter your choice:";
							 cin>>dave;
								switch(dave)
								{
									case 1:	lcm();		break;
									case 2:	hcf();		break;
									case 3:	gif();		break;
									case 4: cleardevice();
													cout<<"\n\nENTER A NUMBER:";
													int x;	 cin>>x;
													cout<<"\n\n\n\t\t\tFactorial : "<<fact(x);
													break;
									case 5: npr();	 break;
									case 6: ncr();	 break;
									case 7: setbkcolor(BLACK); converter();		 break;
									default:cout<<"Invalid";
								}
							 cout<<"\nDo you want to continue with mathematical operations ";
							 cin>>_a;
						}while(_a=='Y'||_a=='y');
						 break;
						case 6:	cleardevice();	kolly();		break;
						case 7: load();	cleardevice(); setbkcolor(BLACK);
										paint(); 					          break;
						case 8:	load();  cleardevice();  display2();
										setbkcolor(GREEN); setfillstyle(1,RED);
										bar(255,175,355,225); outtextxy(275,200,"NEW GAME");
										bar(255,250,355,300); outtextxy(275,275,"  HELP");
										bar(255,325,355,375); outtextxy(275,350," CREDITS");
										int xx=1; setcolor(WHITE);
										rectangle(255,100+xx*lo,355,150+xx*lo);
										int bb=bioskey(0);
										while(bb==ESC||bb==UP||bb==DOWN||bb==ENTER)
										{
											 setcolor(GREEN);
											 rectangle(255,100+xx*lo,355,100+xx*lo+50);
											 switch(bb)
											 {
													 case ESC:goto q1; 	break;
													 case UP :    if(xx==1)		xx=3;
																				else if(xx>1)	xx--;	 break;
													 case DOWN:  if(xx==3)		xx=1;
																			 else if(xx<3)xx++;	   break;
													 case ENTER: if(xx==1)	 gameplay3();
																			 if(xx==2)   help3();
																			 if(xx==3)
																			 {  credits();  getch();  }
											 }
											setcolor(WHITE);
											rectangle(255,100+xx*lo,355,100+xx*lo+50);
											bb=bioskey(0);
										 }			break;
						case 9:  cleardevice();	calendar();	break;
						case 10: cleardevice();	clock1();		break;
						case 11: cleardevice();	tricky();		break;
						case 12: if(strcmpi(u.uname,"admin"))
										 user_stuff(u.uname);
										 else
										 admin_stuff();
											 break;
						case 13: cleardevice();	setbkcolor(BLACK);
										 setcolor(YELLOW); changepassword();
											break;
						case 14: cleardevice();	change();		break;
						case 15: modifynews();	getch();		break;
						default : outtextxy(120,380,"Invalid choice");
					}
					q1:
					getch();
					cleardevice();

					setbkcolor(BLACK);
					setcolor(YELLOW);
					settextstyle(1,HORIZ_DIR,2);
					outtextxy(20,120,"Do you want to glance at any other application? ");
					gotoxy(45,14);
					cha=getch();
				}while(cha=='y'||cha=='Y');
				cleardevice();
				settextstyle(4,HORIZ_DIR,7);
				setcolor(RED);
				outtextxy(5,50," PRESENTED BY : :");
				settextstyle(3,HORIZ_DIR,4);
				setcolor(BLUE);
				outtextxy(200,225,"* B.Vignesh  XII 'B'   ");
				outtextxy(200,200,"* N.Khaveesh XII 'A'   ");
				outtextxy(200,175,"* AL.Muthu   XII 'A'   ");
				getch();
				cleardevice();
				setbkcolor(BLACK);
				settextstyle(4,HORIZ_DIR,14);
				setcolor(YELLOW);
				outtextxy(55,120,"THANK YOU");
				setfillstyle(EMPTY_FILL,0);
				bar3d(100,350,540,400,0,1);
				settextstyle(1,HORIZ_DIR,5);
				outtextxy(260,348,"EXIT");
				settextstyle(1,HORIZ_DIR,2);
				outtextxy(230,410,"PRESS E TO EXIT");
				c=getch();
				if (c=='E'||c=='e')
				exit(0);
			}
		}
	}while(c!='E');
	closegraph();
}
