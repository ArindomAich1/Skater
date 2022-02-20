#include<graphics.h>

using namespace std;
void grass(int,int);
void bg(void);
void player(int,int);
void obstacle(int,int);
void gameOver(void);
void label(void);
void scoreBoard(int);

int main()
{
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm,(char*)"");
	
	START:
	cleardevice();
	fflush(stdin);
	int xpos=220,ypos=295;
	int xobs=getmaxx(),yobs=295;
	int score =0;
	
	int page=0;
	string str;
	bool jump=false,check=false;	//check will check going upward or downward
	
	
	while(true)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		
		bg();
		label();
		player(xpos,ypos);
		obstacle(xobs,yobs);
		score++;
		
		scoreBoard(score);

		xobs-=7;
		
		if(ypos==295&& GetAsyncKeyState(VK_SPACE))
		{
			jump=true;
			check=true;
		}
		
		if(jump&&check)
		{
			ypos-=4;
			if(ypos<200)
				check=false;
			
		}
		
		if(jump&&!check)
		{
			ypos+=4;
			if(ypos>295)
			{
				ypos=295;
				jump=false;
			}
		}
		if(xobs<0)
			xobs=getmaxx();
		
		
		if(abs(xpos-xobs)<5&&(yobs-ypos)<75)
		{
			setvisualpage(page);
			gameOver();
			goto START;
				
		}
		
		page=1-page;
		delay(10);
		
		
		
	}
	
}

void bg()
{
	setfillstyle(SOLID_FILL, GREEN);
	bar(0,370,639,479);
	
	grass(50,370);
	grass(100,370);
	grass(160,370);
	grass(210,370);
	grass(270,370);
	grass(350,370);
	grass(430,370);
	grass(470,370);
	grass(540,370);
	grass(600,370);
}

void grass(int x, int y)
{
	setcolor(GREEN);
	arc(x-15,y,0,90,15);
	arc(x+15,y,90,180,15);
	line(x,y-20,x,y);
}

void player(int x, int y)
{
	//body
	setfillstyle(SOLID_FILL, BLUE);
	bar(x-15,y-20,x+15,y+20);
	
	//legs
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(x-15,y+20,x+15,y+30);
	bar(x-15,y+20,x-10,y+60);
	bar(x+10,y+20,x+15,y+60);
	
	//skate board
	setfillstyle(SOLID_FILL,BROWN);
	bar(x-27,y+60,x+27,y+65);
	setcolor(DARKGRAY);
	circle(x-18,y+70,5);
	circle(x+18,y+70,5);
	
	//hand
	setcolor(BROWN);
	line(x-15,y-20,x-30,y+20);
	line(x+15,y-20,x+30,y+20);
	
	//head
	circle(x,y-30,10);
	
}

void obstacle(int x, int y)
{
	setfillstyle(SOLID_FILL, RED);
	bar(x-10,y,x+10,y+75);
}

void label()
{
	setcolor(WHITE);
	rectangle(500,20, 630, 100);
	outtextxy(520,35,"Arindom Aich");
	outtextxy(520,50,"444 Member");
	outtextxy(520,65,"Daemon");
}
void gameOver()
{
	bar(159,119,479,359);
	outtextxy(280,200,"GAME OVER");
	outtextxy(230,230,"Press P key to play again");
	while(true)
	{
		char d=getch();
		if(d=='p'||d=='P')
			break;
	}
	
}

void scoreBoard(int score)
{
	char a[8];
	sprintf(a,"%d", score);
	
	outtextxy(20,20,a);
	
}











