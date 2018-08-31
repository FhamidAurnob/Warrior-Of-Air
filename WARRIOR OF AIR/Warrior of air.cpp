#include "iGraphics.h"
#include "myVariable.h"


int i=0; ////loading page changing variable  
int coverpage=0; ////cover page changing variable
int BG=0, backgroundIndex=0,background_x[]={0,0},background_y[]={0,win_h};

struct enemyPlane  //////////////////////////////structure for enemy planes /////////////////////////////////
{
	int enemy_x;
	int enemy_y;
	int bomby;
	bool start;
	bool bombing;
};

struct enemyPlane planez[150000];

///////////////////////////////////////////////////////////// loading page changing //////////////////////////
void loadingPage(){
	i++;
}
///////////////////////////////////////////////////////////// cover page changing //////////////////////////
void coverPage(){
	if(coverpage==5)
			coverpage=0;
	coverpage++;
}

///////////////////////////////////////////////////////////// changing background //////////////////////////
void change_background()
{ 
	for(int i=0;i<2;i++)
	{
		background_y[i] -= 1; 
		if(background_y[i]+win_h<0) 
			background_y[i] = win_h-2; 

	}
}
///////////////////////////////***************For restart the game ***********/////////////////////////////////
void restart()
{
	int a = 20;
	int bo = 900;
	for (int i = 0; i < n; i++)
	{
		planez[i].enemy_x = a;
		planez[i].enemy_y = bo+rand()%900;
		planez[i].bomby = planez[i].enemy_y + 10;


		planez[i].start = true;
		planez[i].bombing = true;
		a += 140;
	}
}
////////////////////********** Plane Plane Collison // Enemy Plane's Movement // Bullet Plane Collisons ************/////////////////
void planechange()
{
	if (gamestate==201||gamestate==202)
	{
		//////////////////////************Enemy Plane's Movement
		for (int i = 0; i < n; i++)
		{
			//Upcoordinate change
			planez[i].enemy_y -= enemyspeed;
			//Restarting
			if (planez[i].enemy_y <= -200)
			{
				planez[i].enemy_y = 900;
			}

		}
		///////////////////////////////*************** Bullet Plane Collisons ************************/////////////////////////////////
		for (int i = 0; i < n; i++)
		{
			if (planez[i].start)//////////////player's plane bullet collison
			{
				if (planez[i].enemy_y >= -200 && planez[i].enemy_y <= 900)
				{
						if ((planeX + 50) >= planez[i].enemy_x && (planeX + 50) <= (planez[i].enemy_x + 160))
					{	
						if (bullety >= planez[i].enemy_y && bullety <= planez[i].enemy_y + 160)
						{
							planez[i].start = false;
							blast = true;
							s++;
						}
					}				
				else if (bullety == planez[i].enemy_y && bullety == planez[i].enemy_y + 160)
					{
						if ((planeX + 50) >= planez[i].enemy_x && (planeX + 50) <= (planez[i].enemy_x + 160))
						{
							planez[i].start = false;
							blast = true;
							s++;
						}
					}
				}
				if (planez[i].enemy_x + 40 >= planeX && planez[i].enemy_x + 40 <= planeX + 160)
				{

					if ((planez[i].enemy_x + 40 + 60) >= planeX && planez[i].enemy_x && (planez[i].enemy_x + 40 + 60) <= planeX+160)
					if ((planez[i].bomby + 35) >= planeY && (planez[i].bomby + 35) <= planeY + 160)
					{
						life--;
					}
					if (life == 0)
					{
						
						over = true;
						start = false;
						//reset();
					}
				}

				if (planeX >= planez[i].enemy_x && planeX <= planez[i].enemy_x + 160)
				{
					if (planeY + 90 >= planez[i].enemy_y && planeY + 90 <= planez[i].enemy_y + 160)
					{
						if (planez[i].start)
						{
							life--;
							planez[i].start = false;
							if (life == 0)
							{
								
								start = false;
								
								over = true;
								//reset();
							}
						}
						//iPauseTimer(planes);
					}
				}

				else if (planeX + 120 >= planez[i].enemy_x && planeX + 120 <= planez[i].enemy_x + 160)
				{

					//if (planey + 50 >= plane[i].enemyy && planey + 50 <= plane[i].enemyy + 160)
					if (planez[i].enemy_y >= planeY &&  planez[i].enemy_y <= planeY + 50)
					{
						if (planez[i].start)
						{
						//	iPauseTimer(planes);
							life--;
							planez[i].start = false;
							if (life == 0)
							{
								
								start = false;
								over = true;
								//reset();
							}
						}

					}
				}
			}
		}
		
		

		
			///////////Plane Plane Collison

			/////////Restarting
			if (!planez[1].start  && !planez[2].start  && !planez[3].start  && !planez[4].start && !planez[5].start && !planez[6].start )
			{
				
				restart();

			}

	}
	//RGB Coloring
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
}
//////////////////////************Player's bullet movement **************///////////////////////
void bulletchange()
{
	if (gamestate == 201||gamestate==202)
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

////////////////////////*************** for randdom plane **********////////////////////////
int a = 20;
int bo = 900;
void setplane()
{
	for (int i = 0; i < n; i++)
	{

		planez[i].enemy_x = a;
		planez[i].enemy_y = bo + rand()%900;
		//trying random values
		//plane[i].enemyy = rand()%bo;
		planez[i].bomby = planez[i].enemy_y+10;

		planez[i].start = true;
		planez[i].bombing = true;
		a += 140;
	}


}
//////////////////////************Enemy's bullet movement **************///////////////////////
void bombchange()
{
	if (gamestate==201||gamestate==202)
	{
		for (int i = 0; i < n; i++)
		{

			if (planez[i].bomby  <-200)
				planez[i].bomby = planez[i].enemy_y;

				planez[i].bomby -= 30;
		}
	}
}


////////////////////**************** For reset the game **************/////////////////////////////
void reset()
{
	start = false;
	shoot = false;
	life = 100;
	s = 0;
	restart();
}

void enemyPlaneCordinateChange()
{
	for (int i = 0; i < n; i++)

		{
			//Upcoordinate change
			planez[i].enemy_y -= enemyspeed;
		}
}
/*
 function iDraw() is called again and again by the system.
*/

void iDraw()
{
	//place your drawing codes here
	iClear();

	if(gamestate==0)//////////////////// loading page ///////////////////
	{
		iShowImage(0,0,win_w,win_h,loadingPic[i]);
	    if(i==4)
		{
			gamestate=1;
			i=0;
		}
	}

	
	else if(gamestate==1)//////////////////////// manu page ////////////////
	{
		iClear();
		iShowImage(0,0,win_w,win_h,cover[coverpage]);
		
		if(newgame_blink==0) ///////////// new game
			iShowImage(50,win_h-150,150,70,button[0]);
		if(newgame_blink==1)
			iShowImage(50,win_h-150,150,70,blink[0]);

		if(highscore_blink==0)///////////// high score
			iShowImage(100,win_h-240,150,70,button[1]);
		if(highscore_blink==1)
			iShowImage(100,win_h-240,150,70,blink[1]);

		if(option_blink==0)/////////////// option
			iShowImage(150,win_h-330,150,70,button[2]);
		if(option_blink==1)
			iShowImage(150,win_h-330,150,70,blink[2]);

		if(about_blink==0)///////////// about
			iShowImage(200,win_h-420,150,70,button[3]);
		if(about_blink==1)
			iShowImage(200,win_h-420,150,70,blink[3]);

		if(credit_blink==0)///////////// credit
			iShowImage(250,win_h-510,150,70,button[4]);
		if(credit_blink==1)
			iShowImage(250,win_h-510,150,70,blink[4]);
		
		if(home_blink==0)
		{
			iShowImage(win_w-150,60,120,80,home);
		}
		if(home_blink==1)
			iShowImage(win_w-150,60,120,80,homeBlink);
		
	}
	else if(gamestate==2 || gamestate==201 || gamestate==202)////////////////// new game //////////////////
	{
		
		for(int i=0; i<2 ;i++){
				iShowImage(0,background_y[i],win_w,win_h,background[i]);
			}
		
		iShowImage( planeX,planeY,100,120,plane[0]);

		iShowImage(win_w-120,win_h-80,120,80,back);

		////////********* Scoring *********/////////
		iSetColor(150, 250, 250);
		iText(5,win_h-50, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(90,win_h-50, score, GLUT_BITMAP_TIMES_ROMAN_24);
			
		sprintf_s(score, "%d", s);/////////* scoring                     
		
		iSetColor(255, 0, 0);
		iRectangle(90,win_h-190, 11, 102);
		iSetColor(255, 0, 0);
		iText(5,win_h-190, "Health : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iFilledRectangle(90,win_h-190, 10, life);
		sprintf_s(lifes, "%d", life); //////* Lives

		if (shoot) //////**** players shooting
			{
				iShowImage(planeX + 50, bullety, 30, 30, bullet[1]); ///////****** player's Bullet fireing **********///////////
				iShowImage(planeX + 25, bullety, 30, 30, bullet[1]); ///////****** player's Bullet fireing **********///////////
			}

		if (gamestate==2)
		{
			iShowImage(0,0,win_w,win_h,mission[0]);
			iSetColor(r, g, b);
			iText(win_w/2-50,win_h/2, "Press s to start", GLUT_BITMAP_TIMES_ROMAN_24);
			
		}
		if(gamestate==201)
		{

			for (int i = 0; i < n; i++)
			{
				if (planez[i].start)
				{
					iShowImage(planez[i].enemy_x, planez[i].enemy_y, enemyheight, enemywidth, enemy[1] );  //EnemyPlane

					if (planez[i].bombing)
					{
						if (planez[i].enemy_y >= -200 && planez[i].enemy_y<=900)
						{
						   iShowImage(planez[i].enemy_x + 40, planez[i].bomby + 35, 30, 30, bullet[1]);//////Enemyplane bullet show
						   iShowImage(planez[i].enemy_x + 80, planez[i].bomby + 35, 30, 30, bullet[1]);//////Enemyplane bullet show
						}
					}
				}
				if (blast)
				{
					blast = false;
				}
		   }
			
		}

		if (gamestate ==202)
		{ 
			for(int i=0;i<5;i++,planez[i].enemy_x+150)
			 {
				 if (planez[i].start)
				 {
					 iShowImage(planez[i].enemy_x, planez[i].enemy_y, enemywidth,enemyheight , enemy[3] );  //EnemyPlane

					 if (planez[i].bombing)
					 {
						 if (planez[i].enemy_y >= -enemyheight && planez[i].enemy_y<=win_h)
						 {
						    iShowImage(planez[i].enemy_x+50, planez[i].bomby + 35, 30, 30, bullet[1]);//////Enemyplane bullet show
						 }
					 }
				 }
				 if (blast)
				 {
					 blast = false;
				 }
			  }
		}

		if (over)
			{
				iShowImage(0, 0, win_w, win_h, gameover);
				iSetColor(150, 250, 250);
				iText(620, 200, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(690, 200, score, GLUT_BITMAP_TIMES_ROMAN_24);

				iSetColor(r, g, b);
				iText(620, 50, "Press Space To Play Again", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(620, 30, "Press b To Go To Main Menu", GLUT_BITMAP_TIMES_ROMAN_24);
		
			}
	
	    

	}
	else if(gamestate==3)////////////////// high score ////////////////
	{
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==4)////////////////// option //////////////////
	{
		iShowImage(0,0,win_w,win_h,option);
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==5)////////////////// about ///////////////////
	{
		iShowImage(0,0,win_w,win_h,about);
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==6)//////////////// credit ///////////////////
	{
		iShowImage(win_w-150,60,120,80,back);
	}
	else if(gamestate==7)//////////////// home ////////////////////
	{
		exit(0);
	}
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
	if(gamestate==1)/////////////manu page mousemove
		{
			if(mx>50 && mx<200 && my>win_h-150 && my<win_h-80)///////new game
			   newgame_blink=1;
		    else if(mx>100 && mx<250 && my>win_h-240 && my<win_h-170)/////high score
			   highscore_blink=1;
		    else if(mx>150 && mx<300 && my>win_h-330 && my<win_h-260)/////option
			   option_blink=1;
		    else if(mx>200 && mx<350 && my>win_h-420 && my<win_h-350)/////about
			   about_blink=1;
		    else if(mx>250 && mx<400 && my>win_h-510 && my<win_h-440)/////credit
			   credit_blink=1;
		    else if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)/////home
			{
				home_blink=1;
			}
			else
			{
				home_blink=0;
				newgame_blink=0;
				highscore_blink=0;
				about_blink=0;
				option_blink=0;
				credit_blink=0;
			}
			
		}
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
		if(gamestate==1)/////////////manu page mousemove
		{
			if(mx>50 && mx<200 && my>win_h-150 && my<win_h-80)///////new game
			   gamestate=2;
		    else if(mx>100 && mx<250 && my>win_h-240 && my<win_h-170)/////high score
			   gamestate=3;
		    else if(mx>150 && mx<300 && my>win_h-330 && my<win_h-260)/////option
			   gamestate=4;
		    else if(mx>200 && mx<350 && my>win_h-420 && my<win_h-350)/////about
			   gamestate=5;
		    else if(mx>250 && mx<400 && my>win_h-510 && my<win_h-440)/////credit
			   gamestate=6;
		    else if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)/////home
			   gamestate=7;

		}

		else if(gamestate==201 || gamestate==202 )/////////////new game
		{
			if(mx>win_w-120 && mx<win_w && my>win_h-80 && my<win_h)
				gamestate=1;

		}

		else if(gamestate==3)////////////high score
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=1;
		}
		else if(gamestate==4)////////////option
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=1;
		}
		else if(gamestate==5)//////////about
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=1;
		}
		else if(gamestate==6)/////////credit
		{
			if(mx>win_w-150 && mx<win_w-30 && my>60 && my<140)
				gamestate=1;
		}
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	
	if(gamestate==2 && key == 's')
		{
			gamestate=201;
		}
	else if(gamestate==201||gamestate==202)//////////////////// new game //////////////////////
	{
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
		if(key == 'x')
		{
			shoot = true;
		}
		if(key == 'c')
		{
			shoot = false;
		}
		else if (key == ' ')
	    {
			if (over)
		    {
			   over = false;
			   reset();	
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

	if (key ==  GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	else if(gamestate==201||gamestate==202)//////////////////////// new game /////////////////////////
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


	iInitialize(win_w, win_h, "Warrior of Air");


	showImage();
	iSetTimer(1700,loadingPage);
	iSetTimer(3000,coverPage);
	iSetTimer(10,change_background);
	iSetTimer(10,enemyPlaneCordinateChange);
	setplane();
	planes = iSetTimer(300, planechange);
	bullets = iSetTimer(60, bulletchange);
	bombs = iSetTimer(30, bombchange);
	//PlaySound("music//god", NULL, SND_LOOP | SND_ASYNC);
	
	iStart(); // it will start drawing

	return 0;
}

