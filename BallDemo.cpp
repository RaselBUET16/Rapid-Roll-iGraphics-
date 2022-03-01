# include "iGraphics.h"
#include<stdio.h>
//There is a problem in if(display=3) command,first fix it

int  ball_x1, ball_y1, ball_x2=110, ball_y2=-120, ball_x3=190, ball_y3=-240, ball_x4=270, ball_y4=-180, ball_x5=350, ball_y5=-60,ball_x6=0,ball_y6=-300,ball_x7=80,ball_y7=-360;
// disc for life lost
int disc_x=110,disc_y=-435;
int dx, dy;
//code for the bmp file as live;
int pic_x =ball_x6,pic_y=ball_y6;

int rec_x=200,rec_y=400; int rec_ys;
int score;
//for the score swoing
 char str[100];
 char lif[50];
 //for stop increasing the score when pause mood
char pause,resume;

int live=3;  //live for the ball

int fp=1;//variable for controlling the first page
//fp=1 for the first page ;2 for starting new game;3 for level page; 4 for instruction page

int level=2;//variable for the level..50 for easy,20 for medium,1 for hard level
int display=1; //variable for mouse cursor.1 for the first page cursor,,,2 for the level page cursor,
//for the ellips axis
int a=15,b=6;
int a1;

//only for the highscore file
char scor[1000];
char bestf[1000];
int l;
char l1[20];
//functions for the highscore and file
FILE *fp2;



void inputfile( int x)
{

char fileinput[1000];
    fp2=fopen("Highscore.txt","a");
    itoa(x,fileinput,10);
    char c;
    c=' ';
    fputc(c,fp2);
    fprintf(fp2,"%s",fileinput);
    fclose(fp2);
}


int best(){
    char scor[1000];
    char c;
  int k,j,i=0,bes,temp=0,a=0;
  fp2=fopen("Highscore.txt","r");
    for(i=0; ;i++)
    {
        c=fgetc(fp2);
        if(c==' ') {scor[i]='\0'; break;}
        else if(c==EOF) {scor[i]='\0';a=1;break;}
        scor[i]=c;
    }bes=atoi(scor);

    for(; ;)
    {
        if(a==0) for(k=0; ; k++)
    {
        c=fgetc(fp2);
        if(c==' ') {scor[k]='\0'; break;}
        else if(c==EOF) {scor[k]='\0';a=1;break;}
        scor[k]=c;
    } //if(c!= EOF) a=0;
    temp=atoi(scor);
    if(bes<temp) bes=temp;
    if(a==1) break;
    }

fclose(fp2);
return bes;
    }

    void ScoreReset()
    {
        char c='\0';
        fp2=fopen("Highscore.txt","w");
        fputc(c,fp2);
        fclose(fp2);
    }

    void BackGround() //for the first page
    {
        iSetColor(102,250,71);
   iFilledRectangle(0,0,600,400);
    iSetColor(102,247,82);
    iFilledRectangle(0,0,600,25);
     iSetColor(102,245,92);
    iFilledRectangle(0,25,600,25);
    iSetColor(102,243,102);
    iFilledRectangle(0,350,600,25);
 iSetColor(102,240,112);
    iFilledRectangle(0,50,600,25);
 iSetColor(102,238,122);
    iFilledRectangle(0,75,600,25);
 iSetColor(102,235,132);
    iFilledRectangle(0,100,600,25);
 iSetColor(102,233,142);
    iFilledRectangle(0,125,600,25);
 iSetColor(102,230,152);
    iFilledRectangle(0,150,600,25);
 iSetColor(102,227,162);
    iFilledRectangle(0,175,600,25);
 iSetColor(102,225,172);
    iFilledRectangle(0,200,600,25);
 iSetColor(102,223,182);
    iFilledRectangle(0,225,600,25);
 iSetColor(102,220,192);
    iFilledRectangle(0,250,600,25);
    iSetColor(102,217,202);
    iFilledRectangle(0,275,600,25);
    iSetColor(102,215,212);
    iFilledRectangle(0,300,600,25);
    iSetColor(102,213,222);
    iFilledRectangle(0,325,600,25);
    iSetColor(102,211,232);
    iFilledRectangle(0,350,600,25);
    iSetColor(102,208,242);
    iFilledRectangle(0,375,600,25);
    }


    void BackGround2() //for the game page
    {
         iSetColor(92,214,255);
   iFilledRectangle(0,0,400,400);
    iSetColor(102,219,255);
    iFilledRectangle(0,0,400,25);
     iSetColor(112,222,255);
    iFilledRectangle(0,25,400,25);
    iSetColor(122,223,255);
    iFilledRectangle(0,350,400,25);
 iSetColor(133,224,255);
    iFilledRectangle(0,50,400,25);
 iSetColor(143,227,255);
    iFilledRectangle(0,75,400,25);
 iSetColor(153,233,255);
    iFilledRectangle(0,100,400,25);
 iSetColor(163,232,255);
    iFilledRectangle(0,125,400,25);
 iSetColor(173,235,255);
    iFilledRectangle(0,150,400,25);
 iSetColor(184,237,255);
    iFilledRectangle(0,175,400,25);
 iSetColor(194,240,255);
    iFilledRectangle(0,200,400,25);
 iSetColor(204,242,255);
    iFilledRectangle(0,225,400,25);
 iSetColor(214,245,255);
    iFilledRectangle(0,250,400,25);
    iSetColor(224,247,255);
    iFilledRectangle(0,275,400,25);
    iSetColor(234,250,255);
    iFilledRectangle(0,300,400,25);
    iSetColor(244,253,255);
    iFilledRectangle(0,325,400,25);
    iSetColor(244,253,255);
    iFilledRectangle(0,350,400,25);
    iSetColor(244,253,255);
    iFilledRectangle(0,375,400,25);
    }


    void DiscInitialize()//for reset disc
    {
        ball_y1=0;ball_y2=-120; ball_y3=-240;
      ball_y4=-180;ball_y5=-60;ball_y6=-300;ball_y7=-360;
      disc_y=-435;
    }

/*
	function iDraw() is called again and again by the system.
*/

void iDraw()
{
	//place your drawing codes here
	//code for the opening page
	if(fp==1)
    {


	iClear();
	//iSetColor(194,122,82);
	//iFilledRectangle(0,0,600,400);
	BackGround();

	iSetColor(232,232,232);
	iFilledRectangle(225,41,150,50);//for instruction
	iSetColor(0,0,0);
	iText(250,61,"Instruction",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(232,232,232);
	iFilledRectangle(225,220,150,50);
	iSetColor(0,0,0);         //for level
	iText(270,240,"Level",GLUT_BITMAP_TIMES_ROMAN_24);
	//for showing the score level
	iSetColor(232,232,232);
	iFilledRectangle(390,230,90,30);
	iSetColor(0,0,0);
	if(level==2)
	iText(418,243,"Medium",GLUT_BITMAP_TIMES_ROMAN_10);

	else if(level==1)
     iText(422,243,"Easy",GLUT_BITMAP_TIMES_ROMAN_10);
    else
        iText(422,243,"Hard",GLUT_BITMAP_TIMES_ROMAN_10);

	iSetColor(232,232,232);
	iFilledRectangle(225,130,150,50);
	iSetColor(0,0,0);//for the highscore
	iText(243,150,"High Scores",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(232,232,232);
	iFilledRectangle(225,307,150,50);
	iSetColor(0,0,0);//for new game
	iText(243,327,"New Game",GLUT_BITMAP_TIMES_ROMAN_24);

	//for the exit button
	iSetColor(232,232,232);
	iFilledRectangle(425,10,150,50);
	iSetColor(0,0,0);//for new game
	iText(467,28,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

    }

   //code for ball and rectangle
   if(fp==2)
	{
	   iClear();

  BackGround2();

    iSetColor(0,0,204);
	iFilledRectangle(ball_x1,ball_y1,50,10);
    //iSetColor(0,255,0);
	iFilledRectangle(ball_x5,ball_y5,50,10);
//	iSetColor(250,110,050);
	iFilledRectangle(ball_x4,ball_y4,50,10);
	//iSetColor(120,240,120);
    iFilledRectangle(ball_x3,ball_y3,50,10);
  //  iSetColor(0,0,250);
    iFilledRectangle(ball_x2,ball_y2,50,10);
 //   iSetColor(120,240,0);
    iFilledRectangle(ball_x6,ball_y6,50,10);
   // iSetColor(240,190,120);
     iFilledRectangle(ball_x7,ball_y7,50,10);
     iSetColor(255,0,0);
     iFilledRectangle(disc_x,disc_y,50,10);
     //for the line in the screen
     iSetColor(255,128,0);
     iLine(401,0,401,400);
     //for the ball
    iFilledCircle(rec_x,rec_y,10);
	iSetColor(0,0,0);

    iText(10, 10, "Press p for pause, r for resume, END for exit.");
    iSetColor(232,232,232);

    //rectangle for the score
   iFilledRectangle(440,330,150,50);
   iSetColor(0,0,0);
    iText(450,350,"Score ",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 128, 0);
    iFilledRectangle(515,340,65,30);

    // code for lives
    iSetColor(232,232,232);
    iFilledRectangle(440,260,150,50);
    iSetColor(0,0,0);
    iText(450,275,"Life",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,128,0);
    iFilledRectangle(515,270,65,30);

    iSetColor(255,110,054);
    iRectangle(440,200,150,50);

    iSetColor(255,255,255);
    itoa(live,lif,10);
    iText(541,277,lif,GLUT_BITMAP_HELVETICA_18);
    //for HighScore
    iSetColor(232,232,232);
    iFilledRectangle(410,75,175,50);
    iSetColor(0,0,0);
    iText(415,93,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,128,0);
    iFilledRectangle(530,85,50,30);
    l=best();
    itoa(l,l1,10);
    iSetColor(255,255,255);
    iText(539,93,l1,GLUT_BITMAP_HELVETICA_18);




     iSetColor(0,250,200);

    if(live==3){
        iFilledCircle(465,225,25);
        iFilledCircle(515,225,25);
        iFilledCircle(565,225,25);

    }
    if(live==2){
        iFilledCircle(465,225,25);
        iFilledCircle(515,225,25);
    }
    if(live==1){
         iFilledCircle(465,225,25);
    }

    //code for showing score
    iSetColor(255,255,255);
    itoa(score,str,10);
    iText(535,349,str,GLUT_BITMAP_HELVETICA_18);



    iSetColor(255,0,0);
    iFilledEllipse(ball_x6+25,ball_y6+15,a,b);
    // codee for background colour





	}
	//code for the level page
	if(fp==3)
    {
        iClear();
       BackGround();
       iSetColor(232,232,232);
	iFilledRectangle(225,41,150,50);//for level easy
	 iSetColor(0,0,0);
	iText(264,58,"HARD",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(232,232,232);
	iFilledRectangle(225,174,150,50); //for level medium
	 iSetColor(0,0,0);
	iText(250,191,"MEDIUM",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(232,232,232);
	iFilledRectangle(225,307,150,50);//for hard level
	 iSetColor(0,0,0);
	iText(267,324,"EASY",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    //code for instruction page
    if(fp==4)
    {
        iClear();
      BackGround();
       iSetColor(225,0,0);
       iText(110,310,"Press Right Arrow and Left Arrow to",GLUT_BITMAP_TIMES_ROMAN_24);
       iText(110,280, "move and land safely,and eat hearts",GLUT_BITMAP_TIMES_ROMAN_24);
       iText(110,250," to gain extra life.Don't touch the ",GLUT_BITMAP_TIMES_ROMAN_24);
       iText(110,220,"RED disc,otherwise ball life will decrease",GLUT_BITMAP_TIMES_ROMAN_24);
              //for back button
     /*   iSetColor(255,110,050);
	iRectangle(225,174,150,50);//for back button
	iText(267,191,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);*/
	 iText(10, 10, "Press B for going on the first page",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(fp==5)
    {
        iClear();
        BackGround();
        iSetColor(0,225,0);
       // iRectangle(205,214,170,60);
        iText(216,235,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(225,0,125);
        iFilledRectangle(240,50,100,60);
        iSetColor(0,250,250);
        iText(255,71,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        //for showing score
        iSetColor(0,250,200);
   // iRectangle(205,150,150,50);
    iText(95,320,"YOUR SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(10,250,250);
         itoa(score,str,10);
    iText(264,321,str,GLUT_BITMAP_HELVETICA_18);

   inputfile(score);

    int a=best();

            iSetColor(0,150,250);
   // iRectangle(255,300,200,50);
    iText(325,320,"HIGH SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,150,250);
         itoa(a,bestf,10);
    iText(495,321,bestf,GLUT_BITMAP_HELVETICA_18);
    if(score>=a)
    {
        iSetColor(255,0,0);
        iText(135,205,"Congratulations for new High Score",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    }
    //for the highscore page
    if(fp==6)
    {
        iClear();
       BackGround();
        int a=best();

            iSetColor(0,150,250);
   // iRectangle(255,300,200,50);
    iText(190,220,"HIGH SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,150,250);
         itoa(a,bestf,10);
    iText(360,221,bestf,GLUT_BITMAP_HELVETICA_18);
    //for the back button
    iSetColor(232,232,232);
    iFilledRectangle(240,50,100,60);
   // iFilledRectangle(230,135,120,45);//for the reset button
        iSetColor(0,0,0);
        iText(255,71,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(110,151,"PRESS R FOR RESET HIGHSCORE",GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//for the first page
		if(display==1)
        {
            if ((mx> 225 && mx<375) && (my>307 && my<357)) {DiscInitialize();fp=2; display=6;}//game start
		//for starting the level
		if((mx>225 && mx<375) && (my>220 && my<270)) {fp=3;display=2;}
		//for the instruction page
		 if ((mx> 225 && mx<375) && (my>41 && my<91)) {fp=4; display=9;}
		 //for the highscore
		 if((mx> 225 && mx<375) && (my>130 && my<180)) {fp=6; display=11;}
		 //for the exit button
		 if((mx> 425 && mx<575) && (my>10 && my<60)) {exit(0);}
        }
        //for the level page
       if (display==2)
        {
            if((mx> 267 && mx<417) && (my>58 && my<108)){level=3; display=1;fp=1;} //hard level
            if((mx> 250 && mx<400) && (my>191 && my<241)) {level=2; display=1; fp=1;}// medium level
            if((mx> 264 && mx<414) && (my>324 && my<374)) {level=1; display=1; fp=1;} // easy level
        }

       //for the Game over page
       if(fp==5)
       {
           if((mx>=240 && mx<=340 ) && (my>=50 && my<=110)) {
               score=0;
               live=3;
             /*   ball_x1=0,ball_y1=0;ball_x2=110, ball_y2=-120, ball_x3=190,
                ball_y3=-240, ball_x4=270, ball_y4=-180, ball_x5=350,
                ball_y5=-60,ball_x6=0,ball_y6=-300,ball_x7=80,ball_y7=-360;*/display=1;fp=1;}
       }
       if(display==11)
       {
           if((mx>=240 && mx<=340 ) && (my>=50 && my<=110))
            {display=1;fp=1;}
          //  if((mx>=230 && mx<=350 ) && (my>=135 && my<=180))
               //  {ScoreReset(); display=1;fp=1;}
       }

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		pause='p';
		if(fp==2)
		{iPauseTimer(0);}

	}
	if(key == 'r')
	{
		pause='r';
		if(fp==2)
		{iResumeTimer(0);}

	}
	if((display==11) && (key=='r')) {ScoreReset();}

	  if(fp==4)
       {
           if(key=='b') {display=1;fp=1;}
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key==GLUT_KEY_RIGHT) if(pause!='p') rec_x+=15;
	if (key==GLUT_KEY_LEFT) if(pause!='p') rec_x-=15;
	//place your codes for other keys here
}


void ballChange(){
	//ball_x += dx;
	if(fp==2)
	{

        if(level==1)
    {

	dy=1;
	ball_y1 += dy;
	ball_y2 += dy;
	ball_y3 += dy;
	ball_y4 += dy;
	ball_y5 += dy;
	ball_y6 += dy;
	ball_y7 += dy;
	disc_y+=dy;


	/*if(ball_x > 400 || ball_x < 0)dx = -dx;*///if(ball_x > 400 ) ball_x=0;
	//if(ball_y > 400 || ball_y < 0)dy = -dy;
	if(ball_y1 > 400 ) {ball_y1=0; ball_x1=rand() %350; }//printf("x1=%d   y1=%d\n",ball_x1,ball_y1);
	if(ball_y2 > 400 ) {ball_y2=0;ball_x2=rand() %350;}//printf("x2=%d   y2=%d\n",ball_x2,ball_y2);
	if(ball_y3 > 400 ) {ball_y3=0;ball_x3=rand() %350;}//printf("x3=%d   y3=%d\n",ball_x3,ball_y3);
	if(ball_y4 > 400 ) {ball_y4=0;ball_x4=rand() %350;}//printf("x4=%d   y4=%d\n",ball_x4,ball_y4);
	if(ball_y5 > 400 ) {ball_y5=0;ball_x5=rand() %350;}//printf("x5=%d   y5=%d\n",ball_x5,ball_y5);
    if((ball_y6 > 400 ) && a!=0){ball_y6=0;ball_x6=rand() %350; }//printf("x6=%d   y6=%d\n",ball_x6,ball_y6);

     a1=a;
         if((rec_x>=ball_x6 && (rec_x<=ball_x6+50)) && (rec_y>=(ball_y6+19) && rec_y<=(ball_y6+20))) {a=0;b=0;}

        //life increment

         if(a1>a) if(live<3) live+=1;
        if((a==0) && (ball_y6 > 400 ) ) {a=15;b=6;}
    if(ball_y7 > 400 ) {ball_y7=0;ball_x7=rand() %350;}//printf("x7=%d   y7=%d\n",ball_x7,ball_y7);
    if(disc_y > 400 ) {disc_y=0;disc_x=rand() %350;}//printf("discx=%d   discy=%d\n",ball_x7,ball_y7);

     rec_ys=rec_y;
    //ball y decrease
    if (live==0) fp=5;
     if(rec_y<0){rec_y=400; rec_x=200; if(live>0) live-=1;}
     if(rec_y>410) {rec_y=400; rec_x=200; if(live>0) live-=1;}
     //printf("x=%d   y=%d\n",rec_x,rec_y);
     //ball lef or right shift
     if(rec_x>390) rec_x=390;
     if(rec_x<10) rec_x=10;
   /*  score++;*///printf("Score=%d\n",score);
     //balls y is equal when its x==recs x
     if ((rec_x>= (ball_x1-10) && rec_x<=(ball_x1+60)) && (rec_y>=(ball_y1+19) && rec_y<=(ball_y1+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x2-10) && rec_x<=(ball_x2+60)) && (rec_y>=(ball_y2+19) && rec_y<=(ball_y2+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x3-10) && rec_x<=(ball_x3+60)) && (rec_y>=(ball_y3+19) && rec_y<=(ball_y3+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x4-10) && rec_x<=(ball_x4+60)) && (rec_y>=(ball_y4+19) && rec_y<=(ball_y4+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x5-10) && rec_x<=(ball_x5+60)) && (rec_y>=(ball_y5+19) && rec_y<=(ball_y5+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x6-10) && rec_x<=(ball_x6+60)) && (rec_y>=(ball_y6+19) && rec_y<=(ball_y6+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x7-10) && rec_x<=(ball_x7+60)) && (rec_y>=(ball_y7+19) && rec_y<=(ball_y7+20))) rec_y+=1;
   else  if ((rec_x>= (disc_x-10) && rec_x<=(disc_x+60)) && (rec_y>=(disc_y+19) && rec_y<=(disc_y+20))) {rec_y=400;rec_x=200;if(live>0) live-=1;}
   else  rec_y-=1;
// printf("Live %d",live);
    }

    else if(level==3) // hard level
    {
       dy=2;
        ball_y1 += dy;
	ball_y2 += dy;
	ball_y3 += dy;
	ball_y4 += dy;
	ball_y5 += dy;
	ball_y6 += dy;
	ball_y7 += dy;
	disc_y+=dy;


	/*if(ball_x > 400 || ball_x < 0)dx = -dx;*///if(ball_x > 400 ) ball_x=0;
	//if(ball_y > 400 || ball_y < 0)dy = -dy;
	if(ball_y1 > 400 ) {ball_y1=0; ball_x1=rand() %350; }//printf("x1=%d   y1=%d\n",ball_x1,ball_y1);
	if(ball_y2 > 400 ) {ball_y2=0;ball_x2=rand() %350;}//printf("x2=%d   y2=%d\n",ball_x2,ball_y2);
	if(ball_y3 > 400 ) {ball_y3=0;ball_x3=rand() %350;}//printf("x3=%d   y3=%d\n",ball_x3,ball_y3);
	if(ball_y4 > 400 ) {ball_y4=0;ball_x4=rand() %350;}//printf("x4=%d   y4=%d\n",ball_x4,ball_y4);
	if(ball_y5 > 400 ) {ball_y5=0;ball_x5=rand() %350;}//printf("x5=%d   y5=%d\n",ball_x5,ball_y5);
    if((ball_y6 > 400 ) && a!=0){ball_y6=0;ball_x6=rand() %350; }//printf("x6=%d   y6=%d\n",ball_x6,ball_y6);

     a1=a;
         if((rec_x>=ball_x6 && (rec_x<=ball_x6+50)) && (rec_y>=(ball_y6+16) && rec_y<=(ball_y6+20))) {a=0;b=0;}

        //life increment

         if(a1>a) if(live<3) live+=1;
        if((a==0) && (ball_y6 > 400 ) ) {a=15;b=6;}
    if(ball_y7 > 400 ) {ball_y7=0;ball_x7=rand() %350;}//printf("x7=%d   y7=%d\n",ball_x7,ball_y7);
    if(disc_y > 400 ) {disc_y=0;disc_x=rand() %350;}//printf("discx=%d   discy=%d\n",ball_x7,ball_y7);

     rec_ys=rec_y;
    //ball y decrease
    if (live==0) fp=5;
     if(rec_y<0){rec_y=400; rec_x=200; if(live>0) live-=1;}
     if(rec_y>410) {rec_y=400; rec_x=200; if(live>0) live-=1;}
     //printf("x=%d   y=%d\n",rec_x,rec_y);
     //ball lef or right shift
     if(rec_x>390) rec_x=390;
     if(rec_x<10) rec_x=10;
   /*  score++;*///printf("Score=%d\n",score);
     //balls y is equal when its x==recs x
     if ((rec_x>= (ball_x1-10) && rec_x<=(ball_x1+60)) && (rec_y>=(ball_y1+16) && rec_y<=(ball_y1+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x2-10) && rec_x<=(ball_x2+60)) && (rec_y>=(ball_y2+16) && rec_y<=(ball_y2+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x3-10) && rec_x<=(ball_x3+60)) && (rec_y>=(ball_y3+16) && rec_y<=(ball_y3+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x4-10) && rec_x<=(ball_x4+60)) && (rec_y>=(ball_y4+16) && rec_y<=(ball_y4+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x5-10) && rec_x<=(ball_x5+60)) && (rec_y>=(ball_y5+16) && rec_y<=(ball_y5+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x6-10) && rec_x<=(ball_x6+60)) && (rec_y>=(ball_y6+16) && rec_y<=(ball_y6+20))) rec_y+=dy;
   else  if ((rec_x>= (ball_x7-10) && rec_x<=(ball_x7+60)) && (rec_y>=(ball_y7+16) && rec_y<=(ball_y7+20))) rec_y+=dy;
   else  if ((rec_x>= (disc_x-10) && rec_x<=(disc_x+60)) && (rec_y>=(disc_y+16) && rec_y<=(disc_y+20))) {rec_y=400;rec_x=200;if(live>0) live-=1;}
   else  rec_y-=2;
// printf("Live %d",live);
    }

    else //for the midume level
    {
        dy=1;
        ball_y1 += dy;
	ball_y2 += dy;
	ball_y3 += dy;
	ball_y4 += dy;
	ball_y5 += dy;
	ball_y6 += dy;
	ball_y7 += dy;
	disc_y+=dy;


	/*if(ball_x > 400 || ball_x < 0)dx = -dx;*///if(ball_x > 400 ) ball_x=0;
	//if(ball_y > 400 || ball_y < 0)dy = -dy;
	if(ball_y1 > 400 ) {ball_y1=0; ball_x1=rand() %350; }//printf("x1=%d   y1=%d\n",ball_x1,ball_y1);
	if(ball_y2 > 400 ) {ball_y2=0;ball_x2=rand() %350;}//printf("x2=%d   y2=%d\n",ball_x2,ball_y2);
	if(ball_y3 > 400 ) {ball_y3=0;ball_x3=rand() %350;}//printf("x3=%d   y3=%d\n",ball_x3,ball_y3);
	if(ball_y4 > 400 ) {ball_y4=0;ball_x4=rand() %350;}//printf("x4=%d   y4=%d\n",ball_x4,ball_y4);
	if(ball_y5 > 400 ) {ball_y5=0;ball_x5=rand() %350;}//printf("x5=%d   y5=%d\n",ball_x5,ball_y5);
    if((ball_y6 > 400 ) && a!=0){ball_y6=0;ball_x6=rand() %350; }//printf("x6=%d   y6=%d\n",ball_x6,ball_y6);

     a1=a;
         if((rec_x>=ball_x6 && (rec_x<=ball_x6+50)) && (rec_y>=(ball_y6+18) && rec_y<=(ball_y6+20))) {a=0;b=0;}

        //life increment

         if(a1>a) if(live<3) live+=1;
        if((a==0) && (ball_y6 > 400 ) ) {a=15;b=6;}
    if(ball_y7 > 400 ) {ball_y7=0;ball_x7=rand() %350;}//printf("x7=%d   y7=%d\n",ball_x7,ball_y7);
    if(disc_y > 400 ) {disc_y=0;disc_x=rand() %350;}//printf("discx=%d   discy=%d\n",ball_x7,ball_y7);

     rec_ys=rec_y;
    //ball y decrease
    if (live==0) fp=5;
     if(rec_y<0){rec_y=400; rec_x=200; if(live>0) live-=1;}
     if(rec_y>410) {rec_y=400; rec_x=200; if(live>0) live-=1;}
     //printf("x=%d   y=%d\n",rec_x,rec_y);
     //ball lef or right shift
     if(rec_x>390) rec_x=390;
     if(rec_x<10) rec_x=10;
   /*  score++;*///printf("Score=%d\n",score);
     //balls y is equal when its x==recs x
     if ((rec_x>= (ball_x1-10) && rec_x<=(ball_x1+60)) && (rec_y>=(ball_y1+18) && rec_y<=(ball_y1+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x2-10) && rec_x<=(ball_x2+60)) && (rec_y>=(ball_y2+18) && rec_y<=(ball_y2+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x3-10) && rec_x<=(ball_x3+60)) && (rec_y>=(ball_y3+18) && rec_y<=(ball_y3+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x4-10) && rec_x<=(ball_x4+60)) && (rec_y>=(ball_y4+18) && rec_y<=(ball_y4+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x5-10) && rec_x<=(ball_x5+60)) && (rec_y>=(ball_y5+18) && rec_y<=(ball_y5+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x6-10) && rec_x<=(ball_x6+60)) && (rec_y>=(ball_y6+18) && rec_y<=(ball_y6+20))) rec_y+=1;
   else  if ((rec_x>= (ball_x7-10) && rec_x<=(ball_x7+60)) && (rec_y>=(ball_y7+18) && rec_y<=(ball_y7+20))) rec_y+=1;
   else  if ((rec_x>= (disc_x-10) && rec_x<=(disc_x+60)) && (rec_y>=(disc_y+18) && rec_y<=(disc_y+20))) {rec_y=400;rec_x=200;if(live>0) live-=1;}
   else  rec_y-=2;
// printf("Live %d",live);
    }

    }


}
/*void recChange()
{

}*/
void Score()
{
   if(fp==2)
   {
    if(pause=='p')score+=0;
    else if(pause=='r') score+=1;
    else score+=1;
   }
}


int main()
{
	//place your own initialization codes here.

	iSetTimer(.000001, ballChange);
	iSetTimer(500,Score);
	//iSetTimer(10,recChange);
	dx = 1;
	dy = 1;
	iInitialize(600, 400, "Rapid Roll");


	return 0;
}

