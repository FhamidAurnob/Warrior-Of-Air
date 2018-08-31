#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED


int cover[100]; int button[10];
int about,option,back,home;
int background[20];
int loadingPic[5];
int plane[10];

////////////////////////////////////////////////////// showing my image /////////////////////////////////////////////////////////////
void showImage(){
	
	///////////////////////////////////////////////loading page show/////////////////////////////////////////////
	loadingPic[0]=iLoadImage("loading\\loading 0.bmp");
	loadingPic[1]=iLoadImage("loading\\loading 1.bmp");
	loadingPic[2]=iLoadImage("loading\\loading 2.bmp");
	loadingPic[3]=iLoadImage("loading\\loading 3.bmp");

	////////////////////////////////////////////////cover image//////////////////////////////////////////////////
	cover [0]=iLoadImage("cover\\cover 0.bmp");


	//////////////////////////////////////////////// mannu //////////////////////////////////////////////////
	about=iLoadImage("images\\ABOUTT.bmp");
	option=iLoadImage("images\\CONTROL.bmp");
	back=iLoadImage("images\\back.jpg");

	////////////////////////////////////////////////batton page loading//////////////////////////////////////////////////
    button [0]=iLoadImage("battons\\new game.png");
    button [1]=iLoadImage("battons\\high score.png");
    button [2]=iLoadImage("battons\\option.png");
    button [3]=iLoadImage("battons\\about.png");
	button [4]=iLoadImage("battons\\credit.png");
	home=iLoadImage("battons\\home.png");

	/////////////////////////////////////////////background picture///////////////////////////////////////////////////
	background[0]=iLoadImage("background\\background1.bmp");
	background[1]=iLoadImage("background\\background2.bmp");
	background[2]=iLoadImage("background\\background3.bmp");
	background[3]=iLoadImage("background\\background4.bmp");

	////////////////////////////////////////////plane////////////////////////////
	plane[0]=iLoadImage("plane\\plane1.png");

	

}

#endif