#ifndef MYATAN_H
#define MYATAN_H

#include "stdio.h" 
#include "stdlib.h"  
 
#include "math.h"

#define PI        3.14159265358979323846
#define COEFF   6370693.4856530580439461631130889


//角度转弧度
double deg2rad(double deg)
{
    return (deg*PI)/180.0;
}
//弧度转角度 
double rad2deg(double rad)
{
    return rad*180/PI;
}

//x^n值 
double pow(double x, int n)
{
	double result = 1;
	if (n == 0)
		return 1;
	for (int i = 0; i < n; i++)
	{
		result*=x;
	}
 
	return result;
}


//myatan
double myatan( double x )
{
    double result;
	if(x==0)
	{
		result=0.0;
	}
	else if(0<x && x<1)
	{
		result= x/(1+0.28086*pow(x,2));
	}
	else if(x>=1)
	{
		result= PI/2-myatan(1/x);
	}
	else if(x<0)
	{
		result= -myatan(-x);
	}
	return result;
}
 
 



#endif
