#include "iGraphics.h"
#include "myVariable.h"

int win_w = 1366, win_h = 768;
int gamestate=-2;
int enm[1000];
int planeX=win_w/2, planeY=10;
int i=0;
int BG=0, backgroundIndex=0,background_x[]={0,0},background_y[]={0,win_h};
int r=0, g=0,b=0;
struct Planez
{
	int enemyx;
	int enemyy;
	int bomby;
	bool start;
	bool bombing;
};

struct Planez planez[150000];

bool start = false;
bool shoot = false;
bool blast = false;
bool over = false;

//2.EnemyPlane
int enemyx = 20;
int enemyy = 800;

int bullety = planeY + 130;
int n = 12;
int s = 0;
int life = 5;
char score[1000];
char lifes[5];

int planes, bullets,bombs;

int speed = 50;
int enemyspeed = 1;

//3.EnemyPlane
int enemyheight = 140;
int enemywidth = 140;
///////////////////////////////////////////////////////////// loading page changing //////////////////////////
void loadingPage(){
	i++;
}

///////////////////////////////////////////////////////////// changing background //////////////////////////
void change_background()
{ for(int i=0;i<3;i++)
	{
		background_y[i] -= 10; 
		if(background_y[i]+win_h<0) 
			background_y[i] = background_y[(i+1)%2]+win_h; 

	}
}

/*
 function iDraw() is called again and again by the system.
*/

void iDraw()
{
	//place your drawing codes here
	iClear();

	if(gamestate==-2)//////////////////// loading page ///////////////////
	{
		iShowImage(0,0,win_w,win_h,loadingPic[i]);
	    if(i==4)
		{
			gamestate=-1;
		}
	}

	
	if(gamestate==-1)//////////////////////// manu page ////////////////
	{
		iShowImage(0,0,win_w,win_h,cover[0]);
		int button_x=50,button_y=win_h-150;
		for(int i=0;i<5;i++)
		{
			iShowImage(button_x,button_y,150,70,button[i]);
			button_y=button_y-90;
			button_x=button_x+50;
		}
		iShowImage(win_w-150,60,120,80,home);
	}
	else if(gamestate==0)////////////////// new game //////////////////
	{
		if (!gamestate==0)
		{
			iSetColor(r, g, b);
			iText(850, 50, "Press S to start", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		for(int i=0; i<2 ;i++){
			iShowImage(0,background_y[i],win_w,win_h,background[i]);
		}
		
		iShowImage( planeX,planeY,100,120,plane[0]);
		
		iShowImage(win_w-150,60,120,80,back);

		//Scoring
		iSetColor(150, 250, 250);
		iText(1210, 700, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1290, 700, score, GLUT_BITMAP_TIMES_ROMAN_24);
		//iShowImage(1150, 690, 40, 40, 0);
		sprintf_s(score, "%d", s); //Scoring
		
		iSetColor(0, 0, 0);
		iRectangle(1320, 580, 11, 102);
		iSetColor(255, 0, 0);
		iText(1210, 580, "Health : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iFilledRectangle(1320,580, 10, life);
		sprintf_s(lifes, "%d", life); //Lives
	//}
	if (gamestate==0)
		{
			for (int i = 0; i < n; i++)
			{
				if (planez[i].start)
				{
					iShowImage(planez[i].enemyx, planez[i].enemyy, enemyheight, enemywidth, enm[0] );  //EnemyPlane

					if (planez[i].bombing)
					{
						if (planez[i].enemyy >= -200 && planez[i].enemyy<=900)
						iShowImage(planez[i].enemyx + 40, planez[i].bomby + 35, 60, 60, enm[3]);
					}
				}
				if (blast)
				{
					//iShowImage(plane[i].enemyx, plane[i].enemyy, 160, 160, image[9]);
					blast = false;

				}
			}
			//For Bombing
			 //Enemybomb
		}
		for (int i = 0; i < n; i++)
		{
			//Upcoordinate change
			planez[i].enemyy -= enemyspeed;
			//Restarting
			if (planez[i].enemyy <= -200)
			{
				planez[i].enemyy = 900;
			}

		}

		//For shooting
		if (shoot)
		{
			iShowImage(planeX + 50, bullety, 60, 60, enm[2]); //Bullet
		}

		//iShowImage(200, bomby, 40, 40, image[15]);
		if (over)
	{
		gamestate=0;
		iShowImage(0, 0, 1366, 768, enm[1]);
		iSetColor(150, 250, 250);
		iText(620, 200, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(690, 200, score, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(r, g, b);
		iText(620, 60, "Press Space To Play Again", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(620, 20, "Press b To Go To Main Menu", GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	}

	else if(gamestate==1)////////////////// high score ////////////////
	{
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==2)////////////////// option //////////////////
	{
		iShowImage(0,0,win_w,win_h,option);
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==3)////////////////// about ///////////////////
	{
		iShowImage(0,0,win_w,win_h,about);
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==4)//////////////// credit ///////////////////
	{
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==5)//////////////// home ////////////////////
	{
		exit(0);
	}
}


void restart()
{
	int a = 20;
	int bo = 900;
	for (int i = 0; i < n; i++)
	{
		planez[i].enemyx = a;
		planez[i].enemyy = bo+rand()%900;
		//plane[i].enemyy = bo;
		//rying random values
		//plane[i].enemyy = rand() % bo;

		planez[i].bomby = planez[i].enemyy + 10;


		planez[i].start = true;
		planez[i].bombing = true;
		a += 140;
	}
}

void planechange()
{
	if (gamestate==0)
	{
		
		//Enemy Plane's Movement
		for (int i = 0; i < n; i++)
		{
			//Upcoordinate change
			planez[i].enemyy -= enemyspeed;
			//Restarting
			if (planez[i].enemyy <= -200)
			{
				planez[i].enemyy = 900;
			}

		}

		//Bullet Plane Collisons
		for (int i = 0; i < n; i++)
		{
			if (planez[i].start)
			{
				if (planez[i].enemyy >= -200 && planez[i].enemyy <= 900)
				{
					if ((planeX + 50) >= planez[i].enemyx && (planeX + 50) <= (planez[i].enemyx + 160))
					{
						if (bullety >= planez[i].enemyy && bullety <= planez[i].enemyy + 160)
						{
							planez[i].start = false;
							blast = true;
							s++;
						}
					}
					else if (bullety == planez[i].enemyy && bullety == planez[i].enemyy + 160)
					{
						if ((planeX + 50) >= planez[i].enemyx && (planeX + 50) <= (planez[i].enemyx + 160))
						{
							planez[i].start = false;
							blast = true;
							s++;
						}
					}
				}
				//iShowImage(plane[i].enemyx + 40, plane[i].bomby + 35, 60, 60, image[15]);

				if (planez[i].enemyx + 40 >= planeX && planez[i].enemyx + 40 <= planeX + 160)
				{

					if ((planez[i].enemyx + 40 + 60) >= planeX && planez[i].enemyx && (planez[i].enemyx + 40 + 60) <= planeX+160)
					if ((planez[i].bomby + 35) >= planeY && (planez[i].bomby + 35) <= planeY + 160)
						life--;
					if (life == 0)
					{
						gamestate=0;
						over = true;
						start = false;
						//reset();
					}
				}

				if (planeX >= planez[i].enemyx && planeX <= planez[i].enemyx + 160)
				{
					if (planeY + 90 >= planez[i].enemyy && planeY + 90 <= planez[i].enemyy + 160)
					{
						if (planez[i].start)
						{
							life--;
							planez[i].start = false;
							if (life == 0)
							{
								gamestate=0;
								start = false;
								
								over = true;
								//reset();
							}
						}
						//iPauseTimer(planes);
					}
				}

				else if (planeX + 120 >= planez[i].enemyx && planeX + 120 <= planez[i].enemyx + 160)
				{

					//if (planey + 50 >= plane[i].enemyy && planey + 50 <= plane[i].enemyy + 160)
					if (planez[i].enemyy >= planeY &&  planez[i].enemyy <= planeY + 50)
					{
						if (planez[i].start)
						{
						//	iPauseTimer(planes);
							life--;
							planez[i].start = false;
							if (life == 0)
							{
								gamestate=0;
								start = false;
								over = true;
								//reset();
							}
						}

					}
				}
			}
			//Plane Plane Collison

			//Restarting
			if (!planez[0].start  && !planez[1].start  && !planez[2].start  && !planez[3].start  && !planez[4].start && !planez[5].start && !planez[6].start && !planez[7].start && !planez[8].start)
			{
				
				restart();

			}

		}
	}
	//RGB Coloring
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;


}

void bulletchange()
{
	if (gamestate == 0)
	{
		if (shoot)
		{
			bullety += speed;
			if (bullety >= win_h || bullety <= 0)
			{
				bullety = planeY + 130;
			}
		}
	}
}

int a = 20;
int bo = 900;
void setplane()
{
	for (int i = 0; i < n; i++)
	{

		planez[i].enemyx = a;
		planez[i].enemyy = bo + rand()%1000;
		//trying random values
		//plane[i].enemyy = rand()%bo;
		planez[i].bomby = planez[i].enemyy+10;

		planez[i].start = true;
		planez[i].bombing = true;
		a += 140;
	}


}
void bombchange()
{
	if (gamestate==0)
	{
		for (int i = 0; i < n; i++)
		{

			if (planez[i].bomby  <-200)
				planez[i].bomby = planez[i].enemyy;

				planez[i].bomby -= 30;

			/*if (plane[i].bomby  >70)
				bombing = true;
			else
				bombing = false;
				*/
		}
	}
}



void reset()
{
	start = false;
	shoot = false;
	life = 100;
	s = 0;
	restart();
}
/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}
void iPassiveMouseMove(int mx, int my)
{
	
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(gamestate==-1)/////////////manu mousemove
		{
			if(mx>50 && mx<200 && my>win_h-150 && my<win_h-80)///////new game
			   gamestate=0;
		    else if(mx>100 && mx<250 && my>win_h-240 && my<win_h-170)/////high score
			   gamestate=1;
		    else if(mx>150 && mx<300 && my>win_h-330 && my<win_h-260)/////option
			   gamestate=2;
		    else if(mx>200 && mx<350 && my>win_h-420 && my<win_h-350)/////about
			   gamestate=3;
		    else if(mx>250 && mx<400 && my>win_h-510 && my<win_h-440)/////credit
			   gamestate=4;
		    else if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)/////home
			   gamestate=5;

		}

		else if(gamestate==0)/////////////new game
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=-1;

		}

		else if(gamestate==1)////////////high score
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=-1;
		}
		else if(gamestate==2)////////////option
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=-1;
		}
		else if(gamestate==3)//////////about
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=-1;
		}
		else if(gamestate==4)/////////credit
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=-1;
		}
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if(gamestate==0)//////////////////// new game //////////////////////
	{
		if(key == 'x')
		{
			shoot = true;
		}
		if(key == 'c')
		{
			shoot = false;
		}
		if(key == 'd')
		{
			if(planeX<win_w-110)
				planeX=planeX+10;
		}
		else if(key == 'a')
		{
			if(planeX>10)
				planeX=planeX-10;
		}
		else if(key == 'w')
		{
			if(planeY<win_h-120)
				planeY=planeY+10;
		}
		else if(key == 's')
		{
			if(planeY>1)
				planeY=planeY-10;
		}
		else if (key == ' ')
	    {
			
		if (over)
		{
			
			over = false;
			reset();
			
		}
		else if(key == 'b')
		{
			if(over)
			{
				
				gamestate=-1;
				
			}
		}
	}

	}
	
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	else if(gamestate==0)//////////////////////// new game /////////////////////////
	{
		if(key == GLUT_KEY_RIGHT)
		{
			if(planeX<win_w-110)
				planeX=planeX+10;
		}
		else if(key == GLUT_KEY_LEFT)
		{
			if(planeX>10)
				planeX=planeX-10;
		}
		else if(key == GLUT_KEY_UP)
		{
			if(planeY<win_h-120)
				planeY=planeY+10;
		}
		else if(key == GLUT_KEY_DOWN)
		{
			if(planeY>1)
				planeY=planeY-10;
		}
	}

}

int main()
{
	//place your own initialization codes here.

	setplane();
		planes = iSetTimer(100, planechange);
		bullets = iSetTimer(20, bulletchange);
		bombs = iSetTimer(20, bombchange);
		PlaySound("music//intro", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(win_w, win_h, "Warrior of Air");


	showImage();
	iSetTimer(1700,loadingPage);
	iSetTimer(250,change_background);
	enm[0]=iLoadImage("plane\\enemy1.png");
	enm[1]=iLoadImage("images\\gameover.png");
	enm[2]=iLoadImage("images\\bullet2.png");
	enm[3]=iLoadImage("images\\bullet2.png");
	iStart(); // it will start drawing

	return 0;
}

