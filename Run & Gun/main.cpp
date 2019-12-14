#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))

bool mclick= false,startGame=false,gameOver=false,dpress=false,apress=false,wpress=false,spress=false,bpress=false;
bool startScreen = true;
bool gameQuit = false,instructionsGame = false;
float mouseX ,mouseY;
double cameraHeight;
double cameraAngle;
int drawaxes;
double angle;
double m=0,n=162,o=155,p=240,q=150,r=-60;

void displayText(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);
	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,stringToDisplay[i]);
	}
}


void drawAxes()
{

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 170,0,0);
			glVertex3f(-170,0,0);

			glVertex3f(0,-170,0);
			glVertex3f(0, 170,0);

			glVertex3f(0,0, 170);
			glVertex3f(0,0,-170);
		}glEnd();

}

void Main_Road()
{
	glBegin(GL_QUADS);{
		glVertex3f( 170,0,2);
		glVertex3f( 170,-135,2);
		glVertex3f(-170,-135,2);
		glVertex3f(-170,0,2);
	}glEnd();
}

void Home_Road()
{
	glBegin(GL_QUADS);{

        glColor3f(0.0f, .9f, .8f);
		glVertex3f( 170,0,2);
		glColor3f(0.0f, 0.1f, .3f);
		glVertex3f( 170,-135,2);
        glColor3f(0.0f, 0.1f, .3f);
		glVertex3f(-170,-135,2);
        glColor3f(0.0f, 0.4f, 0.8f);
		glVertex3f(-170,0,2);
	}glEnd();
}

void Outside_Road()
{
	glBegin(GL_QUADS);{
		glVertex3f( 170,0,2);
		glVertex3f( 170,-10,2);
		glVertex3f(-170,-10,2);
		glVertex3f(-170,0,2);
	}glEnd();
}

void Inside_Road()
{
	glBegin(GL_QUADS);{
	    glColor3f(0,0,0);
		glVertex3f(-10,0,4);
		glVertex3f( 10,0,4);
		glVertex3f(10,-10,4);
		glVertex3f(-10,-10,4);
	}glEnd();
}

void Hill()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f); glVertex2d(0.0,20.0);
        glColor3f(0.0f, 0.3f, 0.0f); glVertex2d(-20.0,0.0);
        glColor3f(0.0f, 0.1f, 0.0f); glVertex2d(20.0,.0);
    glEnd();

}
void Roof()
{
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0,20.0);
        glVertex2d(-20.0,0.0);
        glVertex2d(20.0,.0);
    glEnd();

}

void Sun(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }
	glEnd();
}

void Sun_Rays()
{
    glLineWidth(10);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0,2.0);
        glVertex2d(4.0,2.0);
        glVertex2d(6.0,2.0);
        glVertex2d(10.0,2.0);
    glEnd();

}

void Cloud()
{
    glBegin(GL_POLYGON); // DRAWING POLYGON
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.0, 0.0) ;
        glColor3f(0.8, .7, 1.0);
        glVertex2f(0.0, 2.0) ;
        glColor3f(0.7, .7, .7);
        glVertex2f(2.0, 2.0) ;
        glVertex2f(2.0, 0.0);
        glVertex2f(4.0, 0.0) ;
        glVertex2f(4.0, -2.0) ;
        glColor3f(0.0f, 0.1f, 0.1f);
        glVertex2f(-2.0, -2.0);
        glColor3f(0.0f, 0.1f, 0.1f);
        glVertex2f(-2.0, 0.0) ;
    glEnd();

}

void Sky()
{
	glBegin(GL_QUADS);{
	    glColor3f(0.0f, 0.1f, .3f);
		glVertex3f( 170,0,2);
		glColor3f(0.0f, .9f, .8f);
		glVertex3f( 170,-135,2);
		glColor3f(0.0f, 0.8f, 0.8f);
		glVertex3f(-170,-135,2);
		glColor3f(0.0f, 0.4f, 0.8f);
		glVertex3f(-170,0,2);
	}glEnd();
}

void Building()
{
	glBegin(GL_QUADS);{
		glVertex3f( -10,0,2);
		glVertex3f( -10,20,2);
		glVertex3f(10,20,2);
		glVertex3f(10,0,2);
	}glEnd();
}

void Window()
{
	glBegin(GL_QUADS);{
	    glColor3f(.5,.5,.5);
		glVertex3f(-2.5,0,4);
		glColor3f(1,1,1);
		glVertex3f( 2.5,0,4);
		glColor3f(1,1,1);
		glVertex3f(2.5,-8,4);
		glColor3f(0,0,0);
		glVertex3f(-2.5,-8,4);
	}glEnd();
}

void Car_Body()
{
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0,5.0);
        glVertex2d(-5.0,0.0);
        glVertex2d(5.0,.0);
    glEnd();
}

void Eye()
{
glBegin(GL_TRIANGLES);
        glColor3f(0,0,0);
        glVertex2d(0.0,5.0);
        glColor3f(1,1,1);
        glVertex2d(-5.0,0.0);
        glColor3f(0,0,0);
        glVertex2d(5.0,.0);
    glEnd();
}
void Hand(){
        glBegin(GL_QUADS);{
		glVertex3f(-2.5,0,20);
		glVertex3f( 3.5,-1,20);
		glVertex3f(3.5,-2,20);
		glVertex3f(-2.5,-3,20);
	}glEnd();
}

void s_poly(float radius_x,float radius_y){

	int i = 0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }
	glEnd();
}

void bullet()
{
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0,5.0);
        glVertex2d(-5.0,0.0);
        glVertex2d(5.0,.0);
    glEnd();
}

void Car_Structure()
{
    //Car body start
	glPushMatrix();
	glTranslatef(-40,-117,20);
	glScalef(3,4,3);
	glRotatef(-72,0,1,1);
	Car_Body();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-36,-102,20);
	glScaled(2,3,1.5);
	glRotated(-29,0,1,1);
	Car_Body();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-34,-99,22);
	glRotatef(-34,0,1,1);
	Eye();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0.0, 0);
	glTranslatef(-30,-114,21);
	glScalef(2,2,0);
	Hand();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.2);
	glTranslatef(-26,-114,25);
	glScalef(2,1,1.5);
	glRotatef(-85,0,1,1);
	Eye();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.2);
	glTranslatef(-31,-130,25);
	glScalef(2,2.5,0);
	s_poly(2,2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-30.6,-128.6,27);
	glScalef(1.3,1.8,0);
	s_poly(2,2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.2);
	glTranslatef(-43,-128,25);
	glScalef(2.5,3.5,0);
	s_poly(2,2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-42.6,-126.5,27);
	glScalef(1.8,2.3,0);
	s_poly(2,2);
	glPopMatrix();
}

void Opponent_Car()
{
    glPushMatrix();
	Car_Structure();
	glPopMatrix();
}

void StartScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);

	glLineWidth(50);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-150,120 ,2);
		glVertex3f(150,120 ,2);
		glVertex3f(150,-120 ,2);
		glVertex3f(-150,-120,2);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-143,110 ,2);
		glVertex3f(143,110 ,2);
		glVertex3f(143,-110 ,2);
		glVertex3f(-143,-110,2);
	glEnd();
	glColor3f(1,1,0);
	glBegin(GL_QUADS);
		glVertex3f(-340,410 ,-4);
		glVertex3f(340,410 ,-4);
		glVertex3f(340,-410 ,-4);
		glVertex3f(-340,-410,-4);
	glEnd();

	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-20 ,75 ,2);
		glVertex3f(20 ,75 ,2);
		glVertex3f(20 ,55 ,2);
		glVertex3f(-20 ,55, 2);
	glEnd();

	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-20 ,15 ,2);
		glVertex3f(20 ,15 ,2);
		glVertex3f(20 ,-5 ,2);
		glVertex3f(-20 ,-5, 2);
	glEnd();

	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-20 ,-45 ,2);
		glVertex3f(20 ,-45 ,2);
		glVertex3f(20 ,-65 ,2);
		glVertex3f(-20 ,-65, 2);
	glEnd();

	if(mouseX>=604 && mouseX<=764 && mouseY>=193 && mouseY<=231){
		if(mclick){
			startGame = true ;
			gameOver = false;
			instructionsGame = false;
			startScreen = false;
			mclick = false;
		}
	} else
		glColor3f(1,0,1);
        displayText(-11.5,62,3 ,"Start Game");

	if(mouseX>=605 && mouseX<=763 && mouseY>=318 && mouseY<=357) {
		if(mclick){
			instructionsGame = true ;
			startGame = false ;
			gameOver = false;
			startScreen = false;
			mclick = false;
		}
	} else
		glColor3f(1 , 0, 1);
        displayText(-11.5 ,2 ,3 ,"Instructions");

	if(mouseX>=605 && mouseX<=762 && mouseY>=446 && mouseY<=482){
		if(mclick){
			mclick = false;
			exit(0);
		}
	}
	else
		glColor3f(1,0,1);
        displayText(-11.5 ,-58,3,"     Quit");

}

void GameOver()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);

	glLineWidth(50);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-150,120 ,2);
		glVertex3f(150,120 ,2);
		glVertex3f(150,-120 ,2);
		glVertex3f(-150,-120,2);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-143,110 ,2);
		glVertex3f(143,110 ,2);
		glVertex3f(143,-110 ,2);
		glVertex3f(-143,-110,2);
	glEnd();
	glColor3f(1,1,0);
	glBegin(GL_QUADS);
		glVertex3f(-340,410 ,-4);
		glVertex3f(340,410 ,-4);
		glVertex3f(340,-410 ,-4);
		glVertex3f(-340,-410,-4);
	glEnd();


	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-20 ,15 ,2);
		glVertex3f(20 ,15 ,2);
		glVertex3f(20 ,-5 ,2);
		glVertex3f(-20 ,-5, 2);
	glEnd();

	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-20 ,-45 ,2);
		glVertex3f(20 ,-45 ,2);
		glVertex3f(20 ,-65 ,2);
		glVertex3f(-20 ,-65, 2);
	glEnd();

    glColor3f(1 , 0, 1);
	displayText(-33 ,60 ,3 ,"       G A M E    O V E R ! ");

	if(mouseX>=664 && mouseX<=836 && mouseY>=320 && mouseY<=356) {
		if(mclick){
			startGame = true ;
			gameOver = false;
			instructionsGame = false;
			startScreen = false;
			mclick = false;

		}
	} else
		glColor3f(1 , 0, 1);
        displayText(-11.5 ,2 ,3 ,"   Restart");

	if(mouseX>=680 && mouseX<=830 && mouseY>=448 && mouseY<=482){
		if(mclick){
			mclick = false;
			exit(0);
		}
	}
	else
		glColor3f(1,0,1);
        displayText(-11.5 ,-58,3,"     Quit");

}

void GameScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);

	//Inside Road Start
	glPushMatrix();
	glTranslatef(m,0,1);
	glPushMatrix();
	glTranslatef(-150,-85,0);
	Inside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(-120,-85,0);
	Inside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(-90,-85,0);
	Inside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(-60,-85,0);
	Inside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(-30,-85,0);
	Inside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(30,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(60,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(90,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(120,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(150,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(180,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(210,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(240,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(270,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(300,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(330,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(360,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(390,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(420,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(450,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(480,-85,0);
	Inside_Road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(510,-85,0);
	Inside_Road();
    glPopMatrix();
    glPopMatrix();
    //Outside Road Start
	glPushMatrix();
	glTranslatef(0.0,-155.0,2.0);
    Outside_Road();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0,-20.0,2.0);
    Outside_Road();
    glPopMatrix();
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glTranslatef(0.0,-20.0,2.0);
    Main_Road();
    glPopMatrix();
    // Hills Start
    glPushMatrix();
    glTranslatef(n,0,0);
    glPushMatrix();
    glTranslatef(55,40,0);
    glPushMatrix();
	glTranslatef(-27,0,0);
    glScalef(1,3,0);
	Hill();
	glPopMatrix();
    glPushMatrix();
    glScalef(2,5,0);
	Hill();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25,0,0);
    glScalef(1,6,0);
	Hill();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50,0,0);
    glScalef(1,4,0);
	Hill();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(70,0,0);
    glScalef(1,5,0);
	Hill();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(90,0,0);
    glScalef(1,2.5,0);
	Hill();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
    //Sun Start
    glPushMatrix();
    glTranslatef(-140,140,0);
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(.5,-.5,0);
    Sun(9,8);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,.6,0);
    glTranslatef(0,0,-1);
    Sun(12,13);
    glPopMatrix();
    glPopMatrix();
    //Sky
    glPushMatrix();
    glTranslatef(0,170,-4);
    Sky();
    glPopMatrix();
    //Sun Rays
    glPushMatrix();
    glPushMatrix();
    glRotatef(-45,0,0,1);
    glTranslatef(-188,0,0);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(-130,-142,0);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-126,152,0);
    glRotatef(-135,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-138,150,0);
    glRotatef(90,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-146,145,0);
    glRotatef(145,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-148,135,0);
    glRotatef(-135,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-131,136.5,0);
    glRotatef(0,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-133,146.5,0);
    glRotatef(70,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-142,148.5,0);
    glRotatef(107,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-157,136.5,0);
    glRotatef(0,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-136.5,129.5,0);
    glRotatef(-75,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-146.5,130.5,0);
    glRotatef(-105,0,0,1);
    Sun_Rays();
    glPopMatrix();
    glPopMatrix();
    //Cloud Start
    glPushMatrix();
    glTranslatef(o,0,3);
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(-30,35,0);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(-20,40,0);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(-10,35,0);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(-54,30,-7);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(44,30,-7);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(30,38,-7);
    Cloud();
    glPopMatrix();
    glPushMatrix();
    glScalef(3,4,0);
    glTranslatef(20,34,-7);
    Cloud();
    glPopMatrix();
    glPopMatrix();

    //Small Hills
    glPushMatrix();
    glTranslatef(p,0,0);
    glPushMatrix();
    glTranslatef(-20,38,4);
    glScalef(1,2,0);
	Hill();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(-40,38,4);
	Hill();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(-55,38,4);
	Hill();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(-76,38,4);
    glScalef(1,3,0);
	Hill();
	glPopMatrix();
	glPopMatrix();
	//Home road Start
	glPushMatrix();
	glTranslatef(0,39,0);
	Home_Road();
	glPopMatrix();
	//Building start
	glPushMatrix();
	glTranslatef(q,0,0);
	glPushMatrix();
	glColor3f(0.1f, 0.0f, 0.1f);
	glTranslatef(-140,0,10);
	glScalef(2,4,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.0f, 0.1f);
	glTranslatef(-98,0,10);
	glScalef(2,3,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.0f, 0.1f);
	glTranslatef(-56,0,10);
	glScalef(2,2,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.5);
	glTranslatef(-70,0,10);
	glScalef(2,5,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.5);
	glTranslatef(-120,0,10);
	glScalef(2,5.5,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.0, 0.5);
	glTranslatef(-30,0,10);
	glScalef(1,3.5,0);
	Building();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10,0,10);
	glScalef(1,5,0);
	glColor3f(0.1f, 0.0f, 0.1f);
	Building();
	glPopMatrix();

	//Window Start
	glPushMatrix();
	glTranslatef(-150,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-125,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-150,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-150,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-150,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-125,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-125,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-125,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-130,100,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-105,78,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-105,100,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-80,90,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-80,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-57,90,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-57,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-57,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-84,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-84,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-84,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-108,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-108,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-108,50,10);
	Window();
	glPopMatrix();
    glPushMatrix();
	glTranslatef(-67,37,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-67,23,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-67,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-54,37,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-54,23,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-54,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-42,37,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-42,23,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-42,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-29,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-29,25,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-29,40,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-29,55,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-29,68,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15,90,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,10,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,30,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,50,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,70,10);
	Window();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,90,10);
	Window();
	glPopMatrix();
	glPopMatrix();
    glPushMatrix();
    glColor3f(0.2,0.3,0.1);
    Car_Structure();
    glPopMatrix();
    if(r<58){
	glPushMatrix();
	glScalef(-1,1,1);
	glColor3f(.6,0,0);
	Opponent_Car();
	glPopMatrix();
    }
   // else if(r>59){
        //gameOver= true;
    //}
	if(bpress){
	glPushMatrix();
	glTranslatef(r,0,0);
	glPushMatrix();
	glTranslatef(-26,-117,20);
	glRotatef(-90,0,0,1);
	bullet();
	glPopMatrix();
	glPopMatrix();
	}
}

void InstructionsScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 0);

	glColor3f(1,1,0);
	glBegin(GL_QUADS);
		glVertex3f(-340,410 ,0);
		glVertex3f(340,410 ,0);
		glVertex3f(340,-410 ,0);
		glVertex3f(-340,-410,0);
	glEnd();
	glLineWidth(100);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-143,110 ,2);
		glVertex3f(143,110 ,2);
		glVertex3f(143,-110 ,2);
		glVertex3f(-143,-110,2);
	glEnd();

	glColor3f(0,0,0);
	displayText(-110 ,70 ,1 ,"Instructions:");
	displayText(-90 ,40 ,1 ,"Key 'w' to move up.");
	displayText(-90 ,20 ,1 ,"Key 's' to move down.");
	displayText(-90 ,0 ,1 ,"Key 'd' to move right.");
	displayText(-90 ,-20 ,1 ,"Key 'a' to move left.");
	displayText(-90 ,-40 ,1 ,"Key 'b' to shoot bullet.");

	glColor3f(.1, .1, .3);
	glBegin(GL_QUADS);
		glVertex3f(-140 ,-85 ,2);
		glVertex3f(-110 ,-85 ,2);
		glVertex3f(-110 ,-105 ,2);
		glVertex3f(-140 ,-105, 2);
	glEnd();

	if(mouseX>=110 && mouseX<=230 && mouseY>=529 && mouseY<=566){
		if(mclick){
			startGame = false ;
			gameOver = false;
			instructionsGame = false;
			startScreen = true;
			mclick = false;
		}
	} else
		glColor3f(1,0,1);
        displayText(-129.5,-97,3 ,"Back");

}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,200,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	//drawAxes();
	if(startScreen)
        StartScreen();
	else if(startGame && !gameOver)
		GameScreen();

	else if(instructionsGame)
		InstructionsScreen();

	else if(gameOver)
		GameOver();
	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseX = x;
		mouseY = y;
		mclick = true;
	}
		/*printf("X: %f, Y: %f\n", mouseX, mouseY);
	} else
		mclick = false;
	display();*/
}

void keyboardPressed(unsigned char key, int x, int y)
{
	if(key == 'd'){
        dpress = true;
	}
	if(key == 'a'){
        apress = true;
	}
	if(key == 'w'){
        wpress = true;
	}
	if(key == 's'){
        spress = true;
	}
    if(key == 'b'){
        bpress = true;
	}
	display();

}

void animate(){
	if(m>-150)
    {
        m-=0.07;
    }
    else m=0;

    if(n>-250)
    {
        n-=0.08;
    }
    else n=162;

    if(o>-250)
    {
        o-=0.05;
    }
    else o=155;

	if(p>-250)
    {
        p-=0.10;
    }
    else p=240;

    if(q>-250)
    {
        q-=0.07;
    }
    else q=60;
    if(r<60)
    {
        r+=0.15;
    }
    else r=-0;

    glutPostRedisplay();

}

void init(){
	//codes for initialization
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1500, 700);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Run & Gun");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardPressed);
	//glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseClick);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}


