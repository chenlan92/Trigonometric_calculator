#ifndef SCT_H
#define SCT_H

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
 
//牛顿迭代法求开方
double k_sqrt(double a,double x0)
{ 
	
	double x1,y;
	x1=(x0+a/x0)/2.0;  
	if(fabs(x1-x0)>=10e-15)
		y = k_sqrt(a,x1);
	else  y=x1;
  return y;
}
double sqrt(double x)
{ 
	return k_sqrt(x, 1.0);
}
 
//区别于库函数的math.h中sin() 函数，所以采用t_sin()表示 
double t_sin(double x)
{
   double result=x,temp=x;
   double den=x,fac=1;
   int n=1,sign=1;
   while((temp>1e-15)||(temp<-1e-15))        
   {
       n++,fac*=n,den*=x;
       n++,fac*=n,den*=x;
       temp=den/fac;sign=-sign;
       result=sign>0?result+temp:result-temp;
   }
   return result;
} 
//t_cos() 
double t_cos(double x)
{
	x=PI / 2 - x;
	return sin(x);
}   
//t_tan()
double t_tan(double x)
{
	double result;
	result=t_sin(x)/t_cos(x);
	return result;
}
//t_sec 
double t_sec(double x)
{
	return 1.0/t_cos(x);
}
//t_csc 
double t_csc(double x)
{
	return 1.0/t_sin(x);
}
//t_cot
double t_cot(double x)
{
	return t_cos(x)/t_sin(x);
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
 //x!阶乘 
long factorial(int x)
{
	long result = 1;
	for(int i = 1; i <= x; i++)
		result *= i;
 
	return result;
}
//arcsin 
double t_asin(double x)
{	
	double a0=1.5707288,a1=-0.2121144,a2=0.0742610,a3 = -0.0187293;
	return	(PI/2 - sqrt(1 - x)*(a0 + a1*x + a2*pow(x,2) + a3*pow(x,3)));
	
}
 
 //arccos 
double t_acos(double x)
{
 
	if (fabs(x) < 0.5)
		return PI / 2 - t_asin(x);
	else
		return 2 * t_asin(sqrt((1-x)/2));
 
}
//t_atan
double t_atan( double x )
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
		result= PI/2-t_atan(1/x);
	}
	else if(x<0)
	{
		result= -t_atan(-x);
	}
	return result;
}
 
 



#endif
