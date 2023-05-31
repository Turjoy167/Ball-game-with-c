# include "iGraphics.h"

int ball_x, ball_y;
int dx, dy;
int y_val;
int up;
int dow;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();

    iSetColor(255, 100, 10);
	iFilledCircle(ball_x, ball_y, 10);

	iSetColor(0, 10, 255);
	iFilledRectangle(10,y_val,10,100);

	iSetColor(0, 10, 255);
	iFilledRectangle(380,y_val,10,100);


	iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
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
	if(key == 'h')
	{
		 if(y_val>0) y_val = y_val - dow;
	}
	if(key=='u')
    {
        if(y_val+80<400) y_val = y_val + up;
    }
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
	//place your codes for other keys here
}

void ballChange()
{
	ball_x += dx;
	ball_y += dy;

	if((ball_y-10 <= y_val+80)&&(ball_y+10 >= y_val)&&(10+10 >= ball_x-10))
    {
        dx = -dx;
        dy = +dy;
    }
	if((ball_y-10 <= y_val+80)&&(ball_y+10 >= y_val)&&(ball_x+10 >= 380))
    {
        dx = -dx;
        dy = +dy;
    }
    if(ball_y<=0||ball_y>=400)
    {
        dy=-dy;
    }
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(5, ballChange);
	dx = 3;
	dy = 4;
	y_val = 300;
	up = 10;
	dow = 10;
	iInitialize(400, 400, "Ball Demo");

	return 0;
}
