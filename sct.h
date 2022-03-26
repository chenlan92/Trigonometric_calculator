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

#endif
