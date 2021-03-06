#include<windows.h>
#include "mex.h"

#define CLICK 1
#define DOWN 2
#define UP 3
#define LEFT 1
#define MIDDLE 2
#define RIGHT 3
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	void errmsg();
	if (nrhs < 2)
		mexErrMsgTxt("输入参数太少！\n");
	if (nrhs > 2)
		mexErrMsgTxt("输入参数太多！\n");
	if (nlhs > 0)
		mexErrMsgTxt("不需要返回值！\n");
	if (!mxIsDouble(prhs[0]) || !mxIsDouble(prhs[1]))
		errmsg();
	
	double key,mode;
	key = *(mxGetPr(prhs[0]));
	mode = *(mxGetPr(prhs[1]));
	
	if (key == LEFT)
	{
		if (mode == CLICK)
		{
            //mexPrintf("左键点击\n");
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		}
		else if (mode == DOWN)
		{
            //mexPrintf("左键按下\n");
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		}
		else if (mode == UP)
		{
            //mexPrintf("左键松开\n");
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		}
		else
		{
			errmsg();
		}
	}
	else if (key == MIDDLE)
	{
		if (mode == CLICK)
		{
            //mexPrintf("中键点击\n");
			mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
		}
		else if (mode == DOWN)
		{
            //mexPrintf("中键按下\n");
			mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
		}
		else if (mode == UP)
		{
            //mexPrintf("中键松开\n");
			mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
		}
		else
		{
			errmsg();
		}
	}
	else if (key == RIGHT)
	{
		if (mode == CLICK)
		{
            //mexPrintf("右键点击\n");
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		}
		else if (mode == DOWN)
		{
            //mexPrintf("右键按下\n");
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		}
		else if (mode == UP)
		{
            //mexPrintf("右键松开\n");
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		}
		else
		{
			errmsg();
		}
	}
	else
	{
		errmsg();
	}
}

void errmsg()
{
	//mexPrintf("输入参数不合法。\n");
	//mexPrintf("第一个参数key：%d表示左键，%d表示中键，%d表示右键。\n",LEFT,MIDDLE,RIGHT);
	//mexPrintf("第二个参数mode：%d表示点击，%d表示按下，%d表示松开。\n",CLICK,DOWN,UP);
	mexErrMsgTxt("输入参数不合法！\n");
}