#include<stdio.h>
#include <conio.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>	
void clrscr(void)
{
   system("cls") ;	//clear screen.
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition.Y;
}
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}

int getKey(void)
{
    int ch = getch();
    if (ch == 0 || ch == 224)
        ch = 500 + getch();
    return ch;
}
int userbattingfirst(int w)
{
	int px,py,i,s=0,wkt=0,u,c,cx,cy,ux,uy;
	//time_t t;
	clrscr();
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(25,2);	
	printf(" YOU ARE BATTING.\n\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("YOU:- ");
	ux=wherex();
	uy=wherey();	
	printf("\nCOMP:-");
	cx=wherex();
	cy=wherey();
	while(1)
	{
		//printf("\n\nENTER YOUR TURN BETWEEN 1 AND 6:");
		//gotoxy(ux,uy);
		
		if(wherex()>75)
		{
			printf("\n\n\n");
			printf("\nYOU:- ");
			ux=wherex();
			uy=wherey();	
			printf("\nCOMP:-");
			cx=wherex();
			cy=wherey();
			 
		}
		gotoxy(ux,uy);
		u=getch();
		u-='0';
		//scanf("%d",&u);
		if(u<1 || u>6)
		{
			//printf("\n\nWRONG INPUT, PLEASE ENTER BETWEEN 1 AND 6.\n");
			printf("\a");
			continue;
		}
		printf("%d",u);
		ux=wherex();
		uy=wherey();
		//srand(time(&t));
		c=(rand() % 6)+1;
		gotoxy(cx,cy);
		printf("%d",c);
		cx=wherex();
		cy=wherey();
		if(c==u)
		{
			wkt++;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("YOUR SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
			/*printf("\n\nGOT YOU! YOU ARE OUT!!!!");*/printf("\a");
			//printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);
			if(wkt==w)
			{
				printf("\n\n\n\nYOU ARE ALL OUT!\n\n YOUR SCORE WAS %d.\n\nCOMPUTER NEEDS %d RUNS TO WIN",s,s+1);
				printf("\n\nPRESS ANY KEY TO CONTINUE\n");
				if(getch())
					return s;
			}
			else
			{
			//	printf("\n\nYOUR SCORE IS %d FOR THE LOSS OF %d WICKETS.\n.",s,wkt);
			}
		}
		else
		{
		//	printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);
			s+=u;
			//printf("\n\nYOUR SCORE IS %d FOR THE LOSS OF %d WICKET(S).\n",s,wkt);
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("YOUR SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
		}
	}	
}	
int computerbattingfirst(int w)
{
	int px,py,i,s=0,wkt=0,u,c,ux,uy,cx,cy;
	time_t t;
	clrscr();
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(25,2);	
	printf("COMPUTER IS BATTING.\n\n"); 
	for(i=0;i<80;i++)
		printf("-");
	printf("\nCOMP:-");
	cx=wherex();
	cy=wherey();	
	printf("\nYOU:- ");
	ux=wherex();
	uy=wherey();
	while(1)
	{
		//gotoxy(ux,uy);
	//	printf("\n\nENTER YOUR TURN BETWEEN 1 AND 6:");
		
		if(wherex()>75)
		{
			printf("\n\n\n");
			printf("\nCOMP:-");
			cx=wherex();
			cy=wherey();	
			printf("\nYOU:- ");
			ux=wherex();
			uy=wherey();
		}
			gotoxy(ux,uy);
		u=getch();
		u-='0';
		if(u<1 || u>6)
		{
		/*	printf("\n\nWRONG INPUT, PLEASE ENTER BETWEEN 1 AND 6.\n");*/printf("\a");
			continue;
		}
	
		printf("%d",u);
		ux=wherex();
		uy=wherey();
		//srand(time(&t));
		c=(rand() % 6)+1;
		gotoxy(cx,cy);
		printf("%d",c);
		cx=wherex();
		cy=wherey();
		if(c==u)
		{
			wkt++;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("COMPUTER'S SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
			/*printf("\n/nOUT!!!!");*/printf("\a");
		//	printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);
			if(wkt==w)
			{
				printf("\n\n\n\nCOMPUTER IS ALL OUT!\n\n COMPUTER'S SCORE IS %d.\n\nYOU NEED %d RUNS TO WIN",s,s+1);
				printf("\n\nPRESS ANY KEY TO CONTINUE\n");
				if(getch())
					return s;
			}
			else
			{
			/*	px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("COMPUTER'S SCORE-'%3d/%2d                  ",s,wkt);
			gotoxy(px,py);*/
			//	printf("\n\nCOMPUTER'S SCORE IS %d FOR THE LOSS OF %d WICKET(S).\n.",s,wkt);
			}
		}
		else
		{
		//	printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);
			s+=c;
			//printf("\n\nCOMPUTER'S' SCORE IS %d FOR THE LOSS OF %d WICKET(S).\n",s,wkt);
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("COMPUTER'S SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
		}
	}	
}
void computerbattingsecond(int user,int w)
{
	int i,px,py,s=0,wkt=0,u,c,ux,uy,cx,cy;
	time_t t;
	clrscr();
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(25,2);	
	printf(" COMPUTER IS BATTING.\n\n\n\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("\nCOMP:-");
	cx=wherex();
	cy=wherey();	
	printf("\nYOU:- ");
	ux=wherex();
	uy=wherey();
	while(1)
	{
		//printf("\n\nENTER YOUR TURN BETWEEN 1 AND 6:");
		
		
		if(wherex()>75)
		{
			printf("\n\n\n");
			printf("COMP:-");
			cx=wherex();
			cy=wherey();	
			printf("\nYOU:- ");
			ux=wherex();
			uy=wherey();
		}
		gotoxy(ux,uy);
		u=getch();
		u-='0';
		if(u<1 || u>6)
		{
		/*	printf("\n\nWRONG INPUT, PLEASE ENTER BETWEEN 1 AND 6.\n");*/printf("\a");
			continue;
		}
		
		printf("%d",u);
		ux=wherex();
		uy=wherey();
	//	srand(time(&t));
		c=(rand() % 6)+1;
		gotoxy(cx,cy);
		printf("%d",c);
		cx=wherex();
		cy=wherey();
		if(c==u)
		{
			wkt++;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("COMPUTER'S SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
		/*	printf("\n\n OUT!!!!!");*/printf("\a");
		//	printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);
			if(wkt==w)
			{
					px=wherex();
					py=wherey();
					gotoxy(16,4);
					if(s==user)
					printf("               MATCH TIED                                            ");
					else
					printf("           YOU WON BY %d RUNS!                                 ",user-s);
					gotoxy(px,py);
					if(s==user)
						printf("\n\n\n\nMATCH TIED! TWO SIDES COULDN'T BE SEPERATED");
					else	
				printf("\n\n\n\nCOMPUTER IS ALL OUT.\n\nYOU WON!\n\nCOMPUTER LOST BY %d RUNS",user-s);
				break;
			}
			else
			{
					px=wherex();
					py=wherey();
					gotoxy(16,4);
					if(s==user)
				printf("               MATCH TIED                                            ");
					else
				printf("NEED %d MORE RUNS TO WIN WITH %d WICKETS IN HAND                 ",user-s+1,w-wkt);
				gotoxy(px,py);
			//	printf("\n\nCOMPUTER'S SCORE IS %d. IT NEEDS %d MORE RUNS TO WIN WITH %d WICKET(S) IN HAND.\n.",s,s-user+1,w-wkt);
			}
		}
		else
		{
			//printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.\n\n",u,c);
			s+=c;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("COMPUTER'S SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
			if(s>user)
			{
				printf("\n\n\n\nYOU LOST!\n\nCOMPUTER WON BY %d WICKET(S)",w-wkt);
				px=wherex();
				py=wherey();
				gotoxy(16,4);
					printf("      COMPUTER WON BY %d WICKET(S)                               ",w-wkt);
					gotoxy(px,py);
				break;
			}
			px=wherex();
			py=wherey();
			gotoxy(16,4);
			if(s==user)
			printf("              MATCH TIED                                                      ");
			else
			printf("NEED %d MORE RUNS TO WIN WITH %d WICKETS IN HAND                 ",user-s+1,w-wkt);
			gotoxy(px,py);
		//	printf("\n\n COMPUTER NEEDS %d MORE RUNS TO WIN WITH %d WICKET(S) IN HAND.\n.",user-s+1,w-wkt);
		}
	}	
}
void userbattingsecond(int user,int w)
{
	int i,px,py,s=0,wkt=0,u,c,ux,uy,cx,cy;
	time_t t;
	clrscr();
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(25,2);	
	printf(" YOU ARE BATTING.\n\n\n\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("\nYOU:- ");
	ux=wherex();
	uy=wherey();	
	printf("\nCOMP:-");
	cx=wherex();
	cy=wherey();	
	while(1)
	{
	//	printf("\n\nENTER YOUR TURN BETWEEN 1 AND 6:");
		
		
		if(wherex()>75)
		{
			printf("\n\n\n");
			printf("YOU:- ");
			ux=wherex();
			uy=wherey();	
			printf("\nCOMP:-");
			cx=wherex();
			cy=wherey();
		}
		gotoxy(ux,uy);
		u=getch();
		u-='0';
		if(u<1 || u>6)
		{
			/*printf("\n\nWRONG INPUT, PLEASE ENTER BETWEEN 1 AND 6.\n");*/printf("\a");
			continue;
		}
		
		printf("%d",u);
		ux=wherex();
		uy=wherey();
	//	srand(time(&t));
		c=(rand() % 6)+1;
		gotoxy(cx,cy);
		printf("%d",c);
		cx=wherex();
		cy=wherey();
		if(c==u)
		{
			wkt++;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("YOUR SCORE- %3d/%2d                  ",s,wkt);
			gotoxy(px,py);
			/*printf("\n\nYOU ARE OUT!!!!!");
			printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.",u,c);*/printf("\a");
			if(wkt==w)
			{
				px=wherex();
					py=wherey();
					gotoxy(16,4);
					if(s==user)
					printf("               MATCH TIED                                            ");
					else
					printf("       YOU LOST! COMPUTER WON BY %d RUNS         ",user-s);     
					gotoxy(px,py);
					if(s==user)
						printf("\n\n\n\nMATCH TIED! TWO SIDES COULDN'T BE SEPERATED");
					else	
						printf("\n\n\n\nYOU ARE ALL OUT.\n\nCOMPUTER WON!\n\nYOU LOST BY %d RUNS",user-s);
				break;
			}
			else
			{
				px=wherex();
					py=wherey();
					gotoxy(16,4);
				if(s==user)
					printf("               MATCH TIED                                            ");
				else	
					printf("NEED %d MORE RUNS TO WIN WITH %d WICKETS IN HAND                 ",user-s+1,w-wkt);
				gotoxy(px,py);
				//printf("\n\nYOUR SCORE IS %d. YOU NEED %d MORE RUNS TO WIN WITH %d WICKET(S) IN HAND.\n.",s,user-s+1,w-wkt);
			}
		}
		else
		{
			//printf("\n\nYOU ENTERED %d AND COMPUTER GAVE %d IN ITS TURN.\n\n",u,c);
			s+=u;
			px=wherex();
			py=wherey();
			gotoxy(25,2);
			printf("YOUR SCORE-%3d/%2d                  ",s,wkt);
			gotoxy(px,py);
			if(s>user)
			{
				px=wherex();
				py=wherey();
				gotoxy(16,4);
					printf("         YOU WON BY %d WICKET(S)                            ",w-wkt);
					gotoxy(px,py);
				printf("\n\n\n\nYOU WON BY %d WICKET(S)!",w-wkt);
				break;
			}
			px=wherex();
			py=wherey();
			gotoxy(16,4);
			if(s==user)
			printf("              MATCH TIED                                                      ");
			else
			printf("NEED %d MORE RUNS TO WIN WITH %d WICKETS IN HAND                 ",user-s+1,w-wkt);
			gotoxy(px,py);
		//	printf("\n\nYOUR SCORE IS %d. YOU NEED %d MORE RUNS TO WIN WITH %d WICKET(S) IN HAND.\n.",s,user-s+1,w-wkt);
		}
	}	
}
int main()
{
	int i,toss,c1,u1,x,s,q,l,w,cx,cy,cyf,r;
	time_t t;
		ShowConsoleCursor(false);
	char a[5],z[][10]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN"};
	srand(time(&t));
//
	for(i=0;i<80;i++)
		printf("-");	
	gotoxy(25,2);	
	printf(" WELCOME     USER\n\n");
	for(i=0;i<80;i++)
		printf("-");	
/*	while(1)
	{	
		printf("HOW MANY WICKETS?:");
		fflush(stdin);
		scanf("%d",&w);
		if(w<1 || w>10)
		{
			printf("\n\aWRONG INPUT. PLEASE ENTER BETWEEN 1 TO 10.\n\n");
			continue;
		}
		break;
	}*/printf("\n\nCHOOSE NO OF WICKETS:\n\n\n");
		cx=wherex();
		cy=wherey();
		cyf=cy;
		gotoxy(cx+3,cy);
		printf("%c",16);
		for(i=1;i<=10;i++)
		{
			gotoxy(cx+5,cy+2*i-2);
			printf("%s",z[i-1]);
		}
		gotoxy(cx+3,cy);
		while(1)
		{
			r=getKey();
			if(r==13)
				break;
			else if(r==580)
			{	
				gotoxy(cx+3,cy);
				printf(" ");
				gotoxy(cx+3,cy+2);
				cy=wherey();
				if(cy<=28)
				printf("%c",16);
				else
				{
					gotoxy(cx+3,cyf);
					cy=cyf;
					printf("%c",16);
				}
				gotoxy(wherex()-1,wherey());
			}
			else if(r==572)
			{	
				gotoxy(cx+3,cy);
				printf(" ");
				gotoxy(cx+3,cy-2);
				cy=wherey();
				if(cy>=10)
				printf("%c",16);
				else
				{
					gotoxy(cx+3,28);
					cy=28;
					printf("%c",16);
				}
				gotoxy(wherex()-1,wherey());
			}
			
		}
		cy=wherey();
		if(cy==10)
			w=1;
		else if(cy==12)
			w=2;
		else if(cy==14)
			w=3;
		else if(cy==16)
			w=4;
		else if(cy==18)
			w=5;
		else if(cy==20)
			w=6;
		else if(cy==22)
			w=7;
		else if(cy==24)
			w=8;
		else if(cy==26)
			w=9;
		else 
			w=10;									
	//printf("\n\n\n\nPRESS ANY KEY TO CONTINUE");	

		clrscr();
		for(i=0;i<80;i++)
			printf("-");	
		gotoxy(19,2);	
		printf(" LADIES AND GENTLEMAN,ITS TOSS TIME!! \n\n");
		for(i=0;i<80;i++)
			printf("-");	
	printf("\n\n");
	cx=wherex();
	cy=wherey();
	cyf=cy;
	gotoxy(cx+3,cy);
	printf("%c",16);
	printf(" EVEN");
	gotoxy(cx+3,cy+2);
	printf("  ODD");
	while(1)      /*taking input from user for the toss*/
	{
		r=getKey();
			if(r==13)
				break;
			else if(r==580)
			{
			
		      	  gotoxy(cx+3,cy);
						printf(" ");
						gotoxy(cx+3,cy-2);
						cy=wherey();
						if(cy>=7)
						printf("%c",16);
						else
						{
							gotoxy(cx+3,9);
							cy=9;
							printf("%c",16);
						}
						gotoxy(wherex()-1,wherey());
		            
		          
		      }
		      else if(r==572)
		      {
		      gotoxy(cx+3,cy);
						printf(" ");
						gotoxy(cx+3,cy+2);
						cy=wherey();
						if(cy<=9)
						printf("%c",16);
						else
						{
							gotoxy(cx+3,cyf);
							cy=cyf;
							printf("%c",16);
						}
						gotoxy(wherex()-1,wherey());
		            
		           
				  }
		
		
			
	}
	if(wherey()==7)
		toss=0;
	else 
		toss=1;	


	
	c1=(rand() % 6)+1;

	printf("\n\n\nENTER ANY NO BETWEEN 1 AND 6 FOR THE TOSS:-");
	while(1)
	{
		
		/*scanf("%d",&u1);*/u1=getch();
		u1-='0';		
		if(u1<1 || u1>6)
		/*	printf("\nWRONG INPUT, PLEASE ENTER BETWEEN 1 AND 6.\n");*/printf("\a");
		else 
		{
			printf("%d",u1);
			break;
		}
	}
	//printf("u1=%d",u1);
	x=u1+c1;
	clrscr();
	for(i=0;i<80;i++)
			printf("-");	
		gotoxy(19,2);	
		printf(" LADIES AND GENTLEMAN,ITS TOSS TIME!! \n\n");
		for(i=0;i<80;i++)
			printf("-");
	if((x%2==toss))
	{
		printf("\n\nYOU HAVE WON THE TOSS.\n\nWHAT WOULD YOU CHOOSE?\n\n");
		cx=wherex();
		cy=wherey();
	//	printf("%d",cy);
		cyf=cy;
		gotoxy(cx+3,cy);
		printf("%c",16);
		printf(" BATTING");
		gotoxy(cx+3,cy+2);
		printf("  BOWLING");
	//	printf("%d",wherey());
		while(1)      /*taking input from user for the toss*/
		{
			r=getKey();
			if(r==13)
				break;
			else if(r==580)//down
			{	
				gotoxy(cx+3,cy);
				printf(" ");
				gotoxy(cx+3,cy+2);
				cy=wherey();
				if(cy<=13)
				printf("%c",16);
				else
				{
					gotoxy(cx+3,cyf);
					cy=cyf;
					printf("%c",16);
				}
				gotoxy(wherex()-1,wherey());
			}
			else if(r==572)
			{	
				gotoxy(cx+3,cy);
				printf(" ");
				gotoxy(cx+3,cy-2);
				cy=wherey();
				if(cy>=11)
				printf("%c",16);
				else
				{
					gotoxy(cx+3,13);
					cy=13;
					printf("%c",16);
				}
				gotoxy(wherex()-1,wherey());
			}
			
		}
		if(wherey()==11)
			l=1;
		else 
			l=2;	

		while(1)
		{
			/*l=getch();
			l-='0';
			if(l<1 || l>2)
				/*printf("\n\nWRONG CHOICE, PLEASE ENTER CAREFULLY.\n");*/
			/*else
			{
				printf("\n%d",l);*/
				switch(l)
				{
					case 1:printf("\n\n\n\nYOU HAVE ELECTED TO BAT FIRST:\n ");
						printf("\nPRESS ANY KEY TO CONTINUE");
						if(getch())
						{
							s=userbattingfirst(w);
							computerbattingsecond(s,w);	
							break;
						}	
					case 2: printf("\n\nYOU HAVE ELECTED TO BOWL FIRST:\n ");
							printf("\nPRESS ANY KEY TO CONTINUE");
						if(getch())
						{
							s=computerbattingfirst(w);
							userbattingsecond(s,w);
							break;
						}
				}
				break;
			
		}
	}

	else
	{
		printf("\n\nCOMPUTER HAVE WON THE TOSS AND HAS DECIDED TO ");
	//	srand(time(&t));
		q=(rand() % 2);
		switch(q)
		{
			case 0:printf("BAT FIRST.\n");
					printf("\nPRESS ANY KEY TO CONTINUE");
						if(getch())
						{
					s=computerbattingfirst(w);
					userbattingsecond(s,w);
					break;
					}
			case 1:printf("BOWL FIRST.\n");
					printf("\nPRESS ANY KEY TO CONTINUE");
						if(getch())
						{
				s=userbattingfirst(w);
				computerbattingsecond(s,w);
					break;
					}
		}	
	}
	printf("\n\nPRESS ANY KEY TO CONTINUE");
	if(getch())
	{
			clrscr();
		for(i=0;i<80;i++)
		printf("-");	
		gotoxy(25,2);	
		printf(" THANK YOU FOR PLAYING!");
		gotoxy(23,4);
		printf("DEVELOPED BY RIDDHI DUTTA\n\n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n\nPRESS ANY KEY TO TERMINATE\n");
		getch();
	}
}


