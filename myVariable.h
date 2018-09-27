#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

/////////////////////////////////////////////////// variable  //////////////////////////////////////

int win_w = 1152, win_h = 864; //for window's width & hight
int gamestate=0;
int planeX=win_w/2,planeY=10; //X & Y cordinate of player's plane

int enemyx = 10;
int enemyy = win_h+50;
int bullety = planeY + 130;

int n = 12; /////////////////////number of enemy planes
int s = 0;
int life = 1;
char score[1000];
char lifes[100];

int planes, bullets,bombs;

int speed = 50;
int enemyspeed = 2;
int enemyheight = 140;
int enemywidth = 130;

int r=0, g=0,b=0;

bool start = false;
bool shoot = false;
bool blast = false;
bool over = false;

int home_blink=0,newgame_blink=0,highscore_blink=0,about_blink=0,option_blink=0,credit_blink=0;

///////////////////////////////////////////////////// For picture variable //////////////////////////////////////////////////////////////////////////

int cover[100]; ///////////*** For manu's background picture ***///////////////
int button[10];   ///////////***For manu button picture ***///////////////
int about,option[5],back,home;  //////*** For about,option,back,home  picture ***//////////
int background[20];  ////////*** For game play background picture ***//////////
int loadingPic[5];   ////////*** For loading background picture ***//////////
int plane[10];  ////////*** For players planes picture ***/////////////
int enemy[20];  ////////*** For enemy planes picture ***/////////////
int bullet[10]; ////////*** For bullet picture ***////////// 
int gameover; ///*** For gameover page ***//////////
int mission[5];
int blink[10];
int homeBlink;
int credit;
int highscore;
////////////////////////////////////////////////////// showing my image /////////////////////////////////////////////////////////////
void showImage(){
	
	///////////////////////////////////////////////loading page show/////////////////////////////////////////////
	loadingPic[0]=iLoadImage("loading\\loading 0.bmp");
	loadingPic[1]=iLoadImage("loading\\loading 1.bmp");
	loadingPic[2]=iLoadImage("loading\\loading 2.bmp");
	loadingPic[3]=iLoadImage("loading\\loading 3.bmp");

	////////////////////////////////////////////////cover image/ For manu's background picture//////////////////////////////////////////////////
	cover [0]=iLoadImage("cover\\cover_0.jpg");
	cover [1]=iLoadImage("cover\\cover_1.jpg");
	cover [2]=iLoadImage("cover\\cover_2.jpg");
	cover [3]=iLoadImage("cover\\cover_3.png");
	cover [4]=iLoadImage("cover\\cover_4.jpg");
	cover [5]=iLoadImage("cover\\cover_5.bmp");

	//////////////////////////////////////////////// images //////////////////////////////////////////////////
	about=iLoadImage("images\\ABOUTT.bmp");
	option[0]=iLoadImage("images\\CONTROL.bmp");
	option[1]=iLoadImage("images\\instruction.jpg");
	back=iLoadImage("images\\back.jpg");
	gameover=iLoadImage("images\\gameover.png");
	mission[0]=iLoadImage("images\\mission_1.png");
	credit=iLoadImage("images\\credit.png");
	highscore=iLoadImage("images\\highscore.png");

	////////////////////////////////////////////////button page loading//////////////////////////////////////////////////
    button [0]=iLoadImage("battons\\new game.png");
    button [1]=iLoadImage("battons\\high score.png");
    button [2]=iLoadImage("battons\\option.png");
    button [3]=iLoadImage("battons\\about.png");
	button [4]=iLoadImage("battons\\credit.png");
	home=iLoadImage("battons\\home.png");

	/////////////////////////////////////////////background picture///////////////////////////////////////////////////
	background[0]=iLoadImage("background\\sea_0.png");
	background[1]=iLoadImage("background\\sea_1.png");
	background[2]=iLoadImage("background\\background3.bmp");
	background[3]=iLoadImage("background\\background4.bmp");

	////////////////////////////////////////////play's plane////////////////////////////
	plane[0]=iLoadImage("plane\\plane1.png");
	////////////////////////////////////////////enemy's plane////////////////////////////
	enemy[1]=iLoadImage("enemy\\enemy_1.png");
	enemy[2]=iLoadImage("enemy\\enemy_2.png");
	enemy[3]=iLoadImage("enemy\\enemy_3.png");
	enemy[4]=iLoadImage("enemy\\enemy_4.png");
	enemy[5]=iLoadImage("enemy\\enemy_5.png");
	enemy[6]=iLoadImage("enemy\\enemy_6.png");
	enemy[7]=iLoadImage("enemy\\enemy_7.png");
	//////////////////////////////////////////// Bullet ////////////////////////////
	bullet[1]=iLoadImage("images\\bullet2.png");
	bullet[2]=iLoadImage("images\\bullet2.png");

	////////////////////////////////////// Blink /////////////////////////////
	blink[0]=iLoadImage("blink\\new game.png");
	blink[1]=iLoadImage("blink\\high score.png");
	blink[2]=iLoadImage("blink\\option.png");
	blink[3]=iLoadImage("blink\\about.png");
	blink[4]=iLoadImage("blink\\credit.png");
	homeBlink=iLoadImage("blink\\home.png");
}

#endif